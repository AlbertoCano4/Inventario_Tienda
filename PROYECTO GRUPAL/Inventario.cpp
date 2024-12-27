#include "Inventario.hpp"
#include <iostream>
using namespace std;

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
