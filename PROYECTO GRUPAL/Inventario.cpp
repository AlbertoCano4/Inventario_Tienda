#include "Inventario.hpp"
#include <iostream>
#include <cstdlib>  // Para srand() y rand()
#include <ctime>    // Para time()
#include <fstream>
#include <iomanip> // Para formatear la fecha y hora
#include <sstream>

using namespace std;

string Inventario::generarCodigoTransaccion(const string& codigoProducto) {
    string codigo = "TX-" + codigoProducto;
    const char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int numeroAleatorio = rand() % 10; // Número entre 0 y 9

    // Generar dos letras aleatorias
    char letra1 = letras[rand() % (sizeof(letras) - 1)];
    char letra2 = letras[rand() % (sizeof(letras) - 1)];

    // Construir el código
    codigo += letra1;
    codigo += to_string(numeroAleatorio);
    codigo += letra2;

    return codigo;
}

Inventario::Inventario() {
    // Inicialización vacía
    productos = {};
}

void Inventario::consultarInventarioCompleto() const {
    if (productos.empty()) {
        cout << "El inventario está vacío." << endl;
        return;
    }

    cout << "Inventario completo:" << endl;
    for (const auto& producto : productos) {
        producto.mostrarInformacion();
        cout << "-------------------" << endl;
    }
}

void Inventario::consultarPorCategoria(const std::string& categoria) const {
    bool encontrado = false;

    cout << "Productos en la categoría \"" << categoria << "\":" << endl;
    for (const auto& producto : productos) {
        if (producto.getTipoProducto() == categoria) {
            producto.mostrarInformacion();
            cout << "-------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No hay productos en la categoría \"" << categoria << "\" en el inventario." << endl;
    }
}

void Inventario::ampliarInventario(const Warehouse& warehouse) {
    cout << "Seleccione el tipo de producto que desea añadir al inventario:" << endl;
    cout << "1. Camisetas" << endl;
    cout << "2. Pantalones" << endl;
    cout << "3. Sudaderas" << endl;
    cout << "4. Bufandas" << endl;
    cout << "5. Gorras" << endl;
    cout << "6. Gafas de Sol" << endl;

    int opcion;
    cin >> opcion;

    string tipoProducto;
    switch (opcion) {
        case 1: tipoProducto = "Camiseta"; break;
        case 2: tipoProducto = "Pantalon"; break;
        case 3: tipoProducto = "Sudaderas"; break;
        case 4: tipoProducto = "Bufandas"; break;
        case 5: tipoProducto = "Gorras"; break;
        case 6: tipoProducto = "Gafas de Sol"; break;
        default:
            cout << "Opción no válida." << endl;
            return;
    }

    vector<Producto> productosSeleccionados = warehouse.obtenerProductosPorTipo(tipoProducto);

    if (productosSeleccionados.empty()) {
        cout << "No hay productos disponibles de este tipo en el almacén." << endl;
        return;
    }

    cout << "Seleccione el producto que desea añadir al inventario:" << endl;
    for (size_t i = 0; i < productosSeleccionados.size(); i++) {
        cout << i + 1 << ". ";
        productosSeleccionados[i].mostrarInformacion();
        cout << endl;
    }

    int seleccionProducto;
    cin >> seleccionProducto;

    if (seleccionProducto < 1 || seleccionProducto > static_cast<int>(productosSeleccionados.size())) {
        cout << "Selección no válida." << endl;
        return;
    }

    Producto productoSeleccionado = productosSeleccionados[seleccionProducto - 1];

    cout << "Ingrese la cantidad a añadir del producto \""
         << productoSeleccionado.getCodProducto() << "\": ";
    int cantidad;
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "Cantidad no válida." << endl;
        return;
    }

    // Verifica si el producto ya está en el inventario
    for (auto& producto : productos) {
        if (producto.getCodProducto() == productoSeleccionado.getCodProducto()) {
            producto.setCantidad(producto.getCantidad() + cantidad);
            cout << "Stock actualizado: " << cantidad << " unidades añadidas." << endl;
            return;
        }
    }

    // Si no existe, agregarlo como nuevo producto
    productoSeleccionado.setCantidad(cantidad);
    agregarProducto(productoSeleccionado);
}

void Inventario::aniadirStock(const string& codigo, int cantidad) {
    for (auto& producto : productos) {
        if (producto.getCodProducto() == codigo) {
            producto.setCantidad(producto.getCantidad() + cantidad);
            cout << "Stock actualizado: " << cantidad << " unidades añadidas." << endl;
            return;
        }
    }

    cout << "El producto con código \"" << codigo << "\" no está en el inventario. Añádelo como un nuevo producto." << endl;
}

void Inventario::agregarProducto(const Producto& nuevoProducto) {
    productos.push_back(nuevoProducto);
    cout << "Producto añadido al inventario: " << nuevoProducto.getCodProducto() << endl;
}

void Inventario::mostrarProductos() const {
    consultarInventarioCompleto();
}

void Inventario::registrarVenta() {
    if (productos.empty()) {
        cout << "El inventario está vacío. No se pueden realizar ventas." << endl;
        return;
    }

    cout << "Ingrese el código del producto que desea vender: ";
    string codigoProducto;
    cin >> codigoProducto;

    for (auto& producto : productos) {
        if (producto.getCodProducto() == codigoProducto) {
            cout << "Producto encontrado:" << endl;
            producto.mostrarInformacion();
            cout << "Cantidad disponible: " << producto.getCantidad() << endl;
            cout << "Precio unitario: " << producto.getPrecioVenta() << "€" << endl;

            cout << "Ingrese la cantidad que desea vender: ";
            int cantidad;
            cin >> cantidad;

            if (cantidad <= 0) {
                cout << "Cantidad no válida." << endl;
                return;
            }

            if (cantidad > producto.getCantidad()) {
                cout << "Stock insuficiente. Sólo hay " << producto.getCantidad() << " unidades disponibles." << endl;
                return;
            }

            float precioTotal = cantidad * producto.getPrecioVenta();
            cout << "Precio total: " << precioTotal << "€" << endl;

            cout << "¿Desea realizar la venta? (s/n): ";
            char confirmacion;
            cin >> confirmacion;

            if (tolower(confirmacion) == 's') {
                restarCantidad(codigoProducto, cantidad);
                cout << "Venta registrada con éxito. " << cantidad << " unidades vendidas del producto \"" << codigoProducto << "\"." << endl;
                cout << "Precio total: " << precioTotal << "€" << endl;

                // Registrar en el archivo
                registrarVentaEnArchivo(codigoProducto, cantidad, precioTotal);
            } else {
                cout << "Venta cancelada." << endl;
            }
            return;
        }
    }

    cout << "El producto con código \"" << codigoProducto << "\" no se encuentra en el inventario." << endl;
}

void Inventario::restarCantidad(const string& codigo, int cantidad) {
    for (auto& producto : productos) {
        if (producto.getCodProducto() == codigo) {
            producto.setCantidad(producto.getCantidad() - cantidad);
            return;
        }
    }

    cout << "El producto con código \"" << codigo << "\" no se encuentra en el inventario." << endl;
}

void Inventario::realizarCambio() {
    cout << "Ingrese el código de la transacción: ";
    string codigoTransaccion;
    cin >> codigoTransaccion;

    // Abrir el archivo de ventas
    ifstream archivo("ventas.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de ventas.txt." << endl;
        return;
    }

    string linea;
    bool encontrado = false;
    string codigoProducto;
    int cantidadVendida = 0;

    // Buscar la transacción en el archivo
    while (getline(archivo, linea)) {
        if (linea.find("Código de transacción: " + codigoTransaccion) != string::npos) {
            encontrado = true;

            // Leer las líneas siguientes para obtener los detalles
            for (int i = 0; i < 4; ++i) {
                getline(archivo, linea);
                if (linea.find("Código de producto:") != string::npos) {
                    codigoProducto = linea.substr(linea.find(":") + 2);
                } else if (linea.find("Cantidad:") != string::npos) {
                    cantidadVendida = stoi(linea.substr(linea.find(":") + 2));
                }
            }
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "No se encontró la transacción con el código: " << codigoTransaccion << endl;
        return;
    }

    cout << "Producto vendido: " << codigoProducto << endl;
    cout << "Cantidad vendida: " << cantidadVendida << endl;

    // Buscar el producto en el inventario
    Producto* producto = nullptr;
    for (auto& prod : productos) {
        if (prod.getCodProducto() == codigoProducto) {
            producto = &prod;
            break;
        }
    }

    if (!producto) {
        cout << "El producto no se encuentra en el inventario para realizar el cambio." << endl;
        return;
    }

    // Solicitar la cantidad que se desea devolver
    cout << "Ingrese la cantidad que desea devolver (máximo " << cantidadVendida << "): ";
    int cantidadDevolver;
    cin >> cantidadDevolver;

    if (cantidadDevolver <= 0 || cantidadDevolver > cantidadVendida) {
        cout << "Cantidad no válida." << endl;
        return;
    }

    // Buscar productos del mismo tipo
    string tipoProducto = producto->getTipoProducto();
    vector<Producto*> productosMismoTipo;
    for (auto& prod : productos) {
        if (prod.getTipoProducto() == tipoProducto && prod.getCodProducto() != codigoProducto) {
            productosMismoTipo.push_back(&prod);
        }
    }

    if (productosMismoTipo.empty()) {
        cout << "No hay productos disponibles del mismo tipo para realizar el cambio." << endl;
        return;
    }

    // Mostrar opciones de productos para cambiar
    cout << "Seleccione el producto por el que desea cambiarlo:" << endl;
    for (size_t i = 0; i < productosMismoTipo.size(); ++i) {
        cout << i + 1 << ". ";
        productosMismoTipo[i]->mostrarInformacion();
    }

    int seleccionNuevo;
    cin >> seleccionNuevo;

    if (seleccionNuevo < 1 || seleccionNuevo > static_cast<int>(productosMismoTipo.size())) {
        cout << "Selección no válida." << endl;
        return;
    }

    Producto* productoNuevo = productosMismoTipo[seleccionNuevo - 1];

    // Realizar el cambio
    cout << "Realizando cambio por " << cantidadDevolver << " unidades..." << endl;

    producto->setCantidad(producto->getCantidad() + cantidadDevolver);
    productoNuevo->setCantidad(productoNuevo->getCantidad() - cantidadDevolver);

    cout << "Cambio realizado con éxito." << endl;
    cout << "Stock actualizado:" << endl;
    producto->mostrarInformacion();
    productoNuevo->mostrarInformacion();
}

void Inventario::registrarVentaEnArchivo(const string& codigoProducto, int cantidad, float precioTotal) {
    ofstream archivo;
    archivo.open("ventas.txt");

    // Generar un código único personalizado
    string codigoTransaccion = generarCodigoTransaccion(codigoProducto);

    // Registrar fecha y hora
    time_t ahora = time(nullptr);
    tm* tiempoLocal = localtime(&ahora);

    stringstream fechaHora;
    fechaHora << tiempoLocal->tm_year + 1900 << "-"
              << setw(2) << setfill('0') << tiempoLocal->tm_mon + 1 << "-"
              << setw(2) << setfill('0') << tiempoLocal->tm_mday << " "
              << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":"
              << setw(2) << setfill('0') << tiempoLocal->tm_min << ":"
              << setw(2) << setfill('0') << tiempoLocal->tm_sec;
    
    if (archivo.is_open()) {
        // Escribir la transacción en el archivo
        archivo << "Código de transacción: " << codigoTransaccion << endl;
        archivo << "Fecha y hora: " << fechaHora.str() << endl;
        archivo << "Código de producto: " << codigoProducto << endl;
        archivo << "Cantidad: " << cantidad << endl;
        archivo << "Precio total: " << precioTotal << "€" << endl;
        archivo << "--------------------------------------" << endl;
    }
    else{
        cout << "Error al abrir o crear el archivo ventas.txt." << endl;
        return;
    }

    archivo.close();

    cout << "Venta registrada con el código de transacción: " << codigoTransaccion << endl;
}
