#include "Warehouse.hpp"
#include "Camiseta.hpp"
#include "sudadera.hpp"
#include "pantalon.hpp"
#include "bufanda.hpp"
#include "gafasdesol.hpp"
#include "gorra.hpp"

Warehouse::Warehouse() {
    // Inicializar con algunos productos predefinidos
    productos.push_back(Camiseta("C001", 19.99, 50, Temporada::VERANO, Genero::HOMBRE, Talla::M, TipoCamiseta::MANGA_CORTA, "Algodón", true));
    productos.push_back(Pantalon("P001", 29.99, 40, Temporada::INVIERNO, Genero::MUJER, Talla::L, TipoPantalon::CORTO, true));
    productos.push_back(Sudadera("S001", 39.99, 30, Temporada::INVIERNO, Genero::HOMBRE, Talla::XL, TipoSudadera::HOODIE, "Poliéster", true));
    productos.push_back(Bufanda("B001", 14.99, 20, Temporada::INVIERNO, Genero::MUJER, Estilo::CLASICO, true));
    productos.push_back(GafasDeSol("G001", 24.99, 60, Temporada::VERANO, Genero::HOMBRE, Estilo::MODERNO, "Redonda", true));
    productos.push_back(Gorra("GR001", 12.99, 25, Temporada::ANUAL, Genero::HOMBRE, Estilo::DEPORTIVO, "Béisbol", "Poliéster"));
}

void Warehouse::mostrarProductos() const {
    cout << "Productos disponibles en el almacén:" << endl;
    for (size_t i = 0; i < productos.size(); ++i) {
        cout << i + 1 << ". ";
        productos[i].mostrarInformacion();
        cout << "-------------------------" << endl;
    }
}

Producto& Warehouse::seleccionarProducto(size_t indice) {
    if (indice >= productos.size()) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return productos[indice];
}

size_t Warehouse::getCantidadProductos() const {
    return productos.size();
}

// Método para obtener productos por tipo
vector<Producto> Warehouse::obtenerProductosPorTipo(const string& tipo) const {
    vector<Producto> productosPorTipo;

    for (const auto& producto : productos) {
        if (producto.getTipoProducto() == tipo) {
            productosPorTipo.push_back(producto);
        }
    }

    return productosPorTipo;
}
