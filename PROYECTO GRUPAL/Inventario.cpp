#include "Inventario.hpp"
#include <iostream>
#include <cstdlib>  // Para srand() y rand()
#include <ctime>    // Para time()
#include <fstream>
#include <iomanip> // Para formatear la fecha y hora
#include <sstream>

using namespace std;

string Inventario::generarCodigoTransaccion(const string& codigoProducto) {
    // Inicializar la semilla de números aleatorios solo una vez
    static bool semillaInicializada = false;
    if (!semillaInicializada) {
        srand(time(nullptr));
        semillaInicializada = true;
    }

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

void Inventario::actualizarArchivoInventario(Tienda& tienda) {
    // Sincronizar el inventario de la tienda con el actual
    tienda.getInventario() = productos;

    // Delegar la tarea de guardar el inventario al método de la tienda
    tienda.guardarInventario();
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

void Inventario::ampliarInventario(const Warehouse& warehouse, Tienda& tienda) {
    try {
        cout << "Seleccione el tipo de producto que desea añadir al inventario:" << endl;
        cout << "1. Camisetas" << endl;
        cout << "2. Pantalones" << endl;
        cout << "3. Sudaderas" << endl;
        cout << "4. Bufandas" << endl;
        cout << "5. Gorras" << endl;
        cout << "6. Gafas de Sol" << endl;
        
        int opcion;
        cin >> opcion;
        
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
            throw invalid_argument("Error: Entrada no válida. Por favor, ingrese un número entero.");
        }
        
        string tipoProducto;
        switch (opcion) {
            case 1: tipoProducto = "Camiseta"; break;
            case 2: tipoProducto = "Pantalon"; break;
            case 3: tipoProducto = "Sudadera"; break;
            case 4: tipoProducto = "Bufanda"; break;
            case 5: tipoProducto = "Gorra"; break;
            case 6: tipoProducto = "Gafas de sol"; break;
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
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Error: Entrada no válida. Por favor, ingrese un número entero.");
        }
        
        if (seleccionProducto < 1 || seleccionProducto > static_cast<int>(productosSeleccionados.size())) {
            cout << "Selección no válida." << endl;
            return;
        }
        
        Producto productoSeleccionado = productosSeleccionados[seleccionProducto - 1];
        
        cout << "Ingrese la cantidad a añadir del producto \""
        << productoSeleccionado.getCodProducto() << "\": ";
        int cantidad;
        cin >> cantidad;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Error: Entrada no válida. Por favor, ingrese un número entero.");
        }
        
        if (cantidad <= 0) {
            cout << "Cantidad no válida." << endl;
            return;
        }
        
        // Verifica si el producto ya está en el inventario
        for (auto& producto : productos) {
            if (producto.getCodProducto() == productoSeleccionado.getCodProducto()) {
                producto.setCantidad(producto.getCantidad() + cantidad);
                cout << "Stock actualizado: " << cantidad << " unidades añadidas." << endl;
                
                // Actualizar el archivo del inventario
                actualizarArchivoInventario(tienda);
                return;
            }
        }
        
        // Si no existe, agregarlo como nuevo producto
        productoSeleccionado.setCantidad(cantidad);
        agregarProducto(productoSeleccionado);
        
        // Actualizar el archivo del inventario
        actualizarArchivoInventario(tienda);
        
        cout << "Producto añadido correctamente." << endl;
        
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}


void Inventario::aniadirStock(const string& codigo, int cantidad, Tienda& tienda) {
    for (auto& producto : productos) {
        if (producto.getCodProducto() == codigo) {
            producto.setCantidad(producto.getCantidad() + cantidad);
            cout << "Stock actualizado: " << cantidad << " unidades añadidas." << endl;

            // Actualizar el archivo del inventario
            actualizarArchivoInventario(tienda);
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

// Registrar una venta
void Inventario::registrarVenta(Tienda& tienda) {
    if (productos.empty()) {
        cout << "El inventario está vacío. No se pueden realizar ventas." << endl;
        return;
    }

    cout << "Ingrese el código del producto que desea vender: ";
    string codigoProducto;
    cin >> codigoProducto;

    for (auto& producto : productos) {
        if (producto.getCodProducto() == codigoProducto) {
            producto.mostrarInformacion();

            try {
                cout << "Ingrese la cantidad que desea vender: ";
                int cantidad;
                cin >> cantidad;

                if (cin.fail()) {
                    cin.clear(); // Limpiar el estado de error de cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
                    throw invalid_argument("Error: Entrada no válida. Por favor, ingrese un número entero.");
                }

                if (cantidad <= 0 || cantidad > producto.getCantidad()) {
                    cout << "Cantidad no válida. Debe ser entre 1 y " << producto.getCantidad() << "." << endl;
                    return;
                }

                float precioTotal = cantidad * producto.getPrecioVenta();
                string codigoTransaccion = generarCodigoTransaccion(codigoProducto); // Generar una sola vez

                // Actualizar inventario
                producto.setCantidad(producto.getCantidad() - cantidad);

                // Registrar la transacción en el vector
                string transaccion = codigoTransaccion + "," + codigoProducto + "," +
                                     producto.getTipoProducto() + "," + to_string(cantidad);
                transacciones.push_back(transaccion);

                // Registrar la venta en el archivo usando el nombre correcto de la tienda
                registrarVentaEnArchivo(tienda.getNombreTienda(), codigoProducto, cantidad, precioTotal, codigoTransaccion);

                cout << "Venta realizada con éxito." << endl;
                cout << "Detalles de la venta:" << endl;
                cout << " - Tipo de producto: " << producto.getTipoProducto() << endl;
                cout << " - Código del producto: " << producto.getCodProducto() << endl;
                cout << " - Cantidad vendida: " << cantidad << endl;
                cout << " - Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
                cout << " - Código de transacción: " << codigoTransaccion << endl;

                return;
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
                return; // Salir del método si hay un error
            }
        }
    }

    cout << "El producto con código \"" << codigoProducto << "\" no se encuentra en el inventario." << endl;
}

// Registrar la venta en el archivo ventas.txt
void Inventario::registrarVentaEnArchivo(const string& tienda, const string& codigoProducto, int cantidad, float precioTotal, const string& codigoTransaccion) {
    try {
        // Obtener la fecha y hora actual
        time_t ahora = time(nullptr);
        tm* tiempoLocal = localtime(&ahora);

        stringstream fechaHora;
        fechaHora << tiempoLocal->tm_year + 1900 << "-"
                  << setw(2) << setfill('0') << tiempoLocal->tm_mon + 1 << "-"
                  << setw(2) << setfill('0') << tiempoLocal->tm_mday << " "
                  << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":"
                  << setw(2) << setfill('0') << tiempoLocal->tm_min << ":"
                  << setw(2) << setfill('0') << tiempoLocal->tm_sec;

        // Abrir el archivo en modo de agregar (append)
        ofstream archivo;
        archivo.open("ventas.txt", ios::app);
        if (!archivo.is_open()) {
            throw runtime_error("Error: No se pudo abrir el archivo ventas.txt para registrar la venta.");
        }

        archivo << "Código de transacción: " << codigoTransaccion << endl;
        archivo << "Fecha y hora: " << fechaHora.str() << endl;
        archivo << "Tienda: " << tienda << endl; // Aquí se usa el nombre correcto de la tienda
        archivo << "Código de producto: " << codigoProducto << endl;
        archivo << "Cantidad: " << cantidad << endl;
        archivo << "Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
        archivo << "--------------------------------------" << endl;
        archivo.close();

        cout << "Venta registrada correctamente en el archivo ventas.txt." << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
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

void Inventario::devolucion() {
    // Solicitar el código de la transacción
    cout << "Ingrese el código de la transacción: ";
    string codigoTransaccion;
    cin >> codigoTransaccion;

    // Buscar la transacción en el vector
    string transaccionEncontrada;
    for (const auto& transaccion : transacciones) {
        if (transaccion.find(codigoTransaccion + ",") == 0) {
            transaccionEncontrada = transaccion;
            break;
        }
    }

    if (transaccionEncontrada.empty()) {
        cout << "No se encontró la transacción con el código: " << codigoTransaccion << endl;
        return;
    }

    // Extraer los datos de la transacción
    stringstream ss(transaccionEncontrada);
    string codigoProducto, tipoProducto;
    int cantidadVendida;
    float precioUnitario;
    getline(ss, codigoTransaccion, ',');
    getline(ss, codigoProducto, ',');
    getline(ss, tipoProducto, ',');
    ss >> cantidadVendida;

    // Calcular el precio total de la transacción
    for (const auto& producto : productos) {
        if (producto.getCodProducto() == codigoProducto) {
            precioUnitario = producto.getPrecioVenta();
            break;
        }
    }

    float precioTotal = cantidadVendida * precioUnitario;

    // Mostrar los detalles de la transacción
    cout << "Detalles de la transacción:" << endl;
    cout << " - Código del producto: " << codigoProducto << endl;
    cout << " - Tipo de producto: " << tipoProducto << endl;
    cout << " - Cantidad vendida: " << cantidadVendida << endl;
    cout << " - Precio total de la transacción: " << fixed << setprecision(2) << precioTotal << " €" << endl;

    // Solicitar la cantidad que se desea devolver
    try {
        cout << "Ingrese la cantidad que desea devolver (máximo " << cantidadVendida << "): ";
        int cantidadDevolver;
        cin >> cantidadDevolver;

        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
            throw invalid_argument("Error: Entrada no válida. Por favor, ingrese un número entero.");
        }

        if (cantidadDevolver <= 0 || cantidadDevolver > cantidadVendida) {
            cout << "Error: Cantidad no válida." << endl;
            return;
        }

        // Actualizar el inventario
        for (auto& producto : productos) {
            if (producto.getCodProducto() == codigoProducto) {
                producto.setCantidad(producto.getCantidad() + cantidadDevolver);
                break;
            }
        }

        // Calcular el importe a devolver
        float importeDevolucion = cantidadDevolver * precioUnitario;

        // Mostrar el mensaje final
        cout << "Devolución realizada con éxito." << endl;
        cout << "Se han devuelto " << cantidadDevolver << " unidades al inventario." << endl;
        cout << "Se ha reembolsado un total de " << fixed << setprecision(2) << importeDevolucion << " €." << endl;

    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}

void Inventario::realizarCambio() {
    cout << "Ingrese el código de la transacción: ";
    string codigoTransaccion;
    cin >> codigoTransaccion;

    // Buscar la transacción en el vector
    string transaccionEncontrada;
    for (const auto& transaccion : transacciones) {
        if (transaccion.find(codigoTransaccion + ",") == 0) {
            transaccionEncontrada = transaccion;
            break;
        }
    }

    if (transaccionEncontrada.empty()) {
        cout << "No se encontró la transacción con el código: " << codigoTransaccion << endl;
        return;
    }

    // Extraer los datos de la transacción
    stringstream ss(transaccionEncontrada);
    string codigoProducto, tipoProducto;
    int cantidadVendida;
    getline(ss, codigoTransaccion, ',');
    getline(ss, codigoProducto, ',');
    getline(ss, tipoProducto, ',');
    ss >> cantidadVendida;

    cout << "Producto vendido: " << codigoProducto << endl;
    cout << "Categoría del producto: " << tipoProducto << endl;
    cout << "Cantidad vendida: " << cantidadVendida << endl;

    try {
        // Solicitar la cantidad que se desea devolver
        cout << "Ingrese la cantidad que desea devolver (máximo " << cantidadVendida << "): ";
        int cantidadDevolver;
        cin >> cantidadDevolver;

        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
            throw invalid_argument("Error: Entrada no válida. Por favor, ingrese un número entero.");
        }

        if (cantidadDevolver <= 0 || cantidadDevolver > cantidadVendida) {
            cout << "Error: Cantidad no válida." << endl;
            return;
        }

        // Buscar productos del mismo tipo para el cambio
        vector<Producto> productosMismoTipo;
        for (const auto& prod : productos) {
            if (prod.getTipoProducto() == tipoProducto && prod.getCodProducto() != codigoProducto) {
                productosMismoTipo.push_back(prod);
            }
        }

        if (productosMismoTipo.empty()) {
            cout << "No hay productos disponibles de la misma categoría para realizar el cambio." << endl;
            return;
        }

        // Mostrar opciones de productos para cambiar
        cout << "Seleccione el producto por el que desea cambiarlo:" << endl;
        for (size_t i = 0; i < productosMismoTipo.size(); ++i) {
            cout << i + 1 << ". ";
            productosMismoTipo[i].mostrarInformacion();
        }

        int seleccionNuevo;
        cin >> seleccionNuevo;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Error: Entrada no válida. Por favor, ingrese un número entero.");
        }

        if (seleccionNuevo < 1 || seleccionNuevo > static_cast<int>(productosMismoTipo.size())) {
            cout << "Error: Selección no válida." << endl;
            return;
        }

        Producto& productoNuevo = productosMismoTipo[seleccionNuevo - 1];

        // Validar si hay suficiente stock del producto nuevo para realizar el cambio
        if (productoNuevo.getCantidad() < cantidadDevolver) {
            cout << "Error: No hay suficiente stock del producto seleccionado para realizar el cambio." << endl;
            return;
        }

        // Realizar el cambio
        cout << "Realizando cambio por " << cantidadDevolver << " unidades..." << endl;

        // Actualizar inventario
        for (auto& producto : productos) {
            if (producto.getCodProducto() == codigoProducto) {
                producto.setCantidad(producto.getCantidad() + cantidadDevolver); // Devolver al stock original
            }
            if (producto.getCodProducto() == productoNuevo.getCodProducto()) {
                producto.setCantidad(producto.getCantidad() - cantidadDevolver); // Restar del nuevo producto
            }
        }

        cout << "Cambio realizado con éxito." << endl;
        cout << "Producto original (devolución):" << endl;
        for (const auto& producto : productos) {
            if (producto.getCodProducto() == codigoProducto) {
                producto.mostrarInformacion();
            }
        }
        cout << "Producto nuevo (entregado):" << endl;
        for (const auto& producto : productos) {
            if (producto.getCodProducto() == productoNuevo.getCodProducto()) {
                producto.mostrarInformacion();
            }
        }
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
}
