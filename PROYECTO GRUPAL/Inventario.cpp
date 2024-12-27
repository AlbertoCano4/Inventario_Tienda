#include "Inventario.hpp"
#include "Warehouse.hpp"
#include <iostream>
using namespace std;

void Inventario::ampliarInventario(const Warehouse& warehouse) {
    cout << "Seleccione el tipo de producto que desea añadir al inventario:" << endl;
    cout << "1. Camisetas" << endl;
    cout << "2. Pantalones" << endl;
    cout << "3. Sudaderas" << endl;
    cout << "4. Bufandas" << endl;
    cout << "5. Gafas de Sol" << endl;
    cout << "6. Gorras" << endl;

    int opcion;
    cin >> opcion;

    string tipoProducto;
    switch (opcion) {
        case 1: tipoProducto = "Camiseta"; break;
        case 2: tipoProducto = "Pantalon"; break;
        case 3: tipoProducto = "Sudadera"; break;
        case 4: tipoProducto = "Bufanda"; break;
        case 5: tipoProducto = "GafasDeSol"; break;
        case 6: tipoProducto = "Gorra"; break;
        default:
            cout << "Opción no válida." << endl;
            return;
    }

    // Obtener productos por tipo del warehouse
    vector<Producto> productosSeleccionados = warehouse.obtenerProductosPorTipo(tipoProducto);

    if (productosSeleccionados.empty()) {
        cout << "No hay productos disponibles de este tipo en el almacén." << endl;
        return;
    }

    // Mostrar productos disponibles
    cout << "Seleccione el producto que desea añadir al inventario:" << endl;
    for (size_t i = 0; i < productosSeleccionados.size(); ++i) {
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

    // Pedir cantidad
    cout << "Ingrese la cantidad a añadir del producto \""
         << productoSeleccionado.getCodProducto() << "\": ";
    int cantidad;
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "Cantidad no válida." << endl;
        return;
    }

    // Añadir al inventario
    aniadirStock(productoSeleccionado.getCodProducto(), cantidad);
    cout << "Se han añadido " << cantidad << " unidades del producto \""
         << productoSeleccionado.getCodProducto() << "\" al inventario." << endl;
}



void capturarCodigoYCantidad(string& codigoProducto, int& cantidad, const string& mensajeAccion) {
    cout << "Introduce el código del producto: ";
    cin >> codigoProducto;
    cout << "Introduce la cantidad " << mensajeAccion << ": ";
    cin >> cantidad;
}

void Inventario::mostrarProductos() {
    if (productos.empty()) {
        cout << "El inventario está vacío." << endl;
    } else {
        for (const auto& producto : productos) {
            producto.mostrarInformacion();
            cout << "-------------------" << endl;
        }
    }
}

void Inventario::venderProducto(const string& codigo, int cantidad) {
    for (auto& producto : productos) {
        if (producto.getCodProducto() == codigo) {
            if (producto.getCantidad() >= cantidad) {
                producto.setCantidad(producto.getCantidad() - cantidad);
                cout << "Venta realizada con éxito." << endl;
            } else {
                cout << "Stock insuficiente." << endl;
            }
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void Inventario::aniadirStock(const string& codigo, int cantidad) {
    for (auto& producto : productos) {
        if (producto.getCodProducto() == codigo) {
            producto.setCantidad(producto.getCantidad() + cantidad);
            cout << "Stock añadido con éxito." << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void Inventario::devolverProducto(const string& codigo, int cantidad) {
    for (auto& producto : productos) {
        if (producto.getCodProducto() == codigo) {
            producto.setCantidad(producto.getCantidad() + cantidad);
            cout << "Devolución realizada con éxito." << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}
