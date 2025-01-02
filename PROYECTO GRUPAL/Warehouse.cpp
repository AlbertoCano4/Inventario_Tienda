#include "Warehouse.hpp"
#include "Camiseta.hpp"
#include "Bufanda.hpp"
#include "Pantalon.hpp"
#include "Sudadera.hpp"
#include "Gorra.hpp"
#include "Gafasdesol.hpp"

#include <iostream>
using namespace std;

Warehouse::Warehouse() {
    productos.push_back(Camiseta("C001", 19.99, 50, Temporada::VERANO, Genero::HOMBRE, Talla::M, TipoCamiseta::MANGA_CORTA, "Algodón", true));
    productos.push_back(Camiseta("C002", 19.99, 40, Temporada::INVIERNO, Genero::MUJER, Talla::L, TipoCamiseta::MANGA_LARGA, "Algodón", true));
    productos.push_back(Pantalon("P001", 29.99, 40, Temporada::INVIERNO, Genero::MUJER, Talla::L, TipoPantalon::LARGO, true));
    productos.push_back(Bufanda("B001", 14.99, 20, Temporada::INVIERNO, Genero::MUJER, Estilo::CLASICO, true));
    productos.push_back(Sudadera("S001", 39.99, 30, Temporada::INVIERNO, Genero::HOMBRE, Talla::XL, TipoSudadera::HOODIE, "Poliéster", true));
    productos.push_back(Gorra("G001", 10.00, 20, Temporada::VERANO, Genero::MUJER, Estilo::DEPORTIVO, "Surfera", "Pana"));
    productos.push_back(GafasDeSol("GS001", 24.99, 15, Temporada::VERANO, Genero::MUJER, Estilo::MODERNO, "Redondas", true));
}

void Warehouse::mostrarProductos() const {
    for (const auto& producto : productos) {
        producto.mostrarInformacion();
        cout << "-------------------------" << endl;
    }
}

std::vector<Producto> Warehouse::obtenerProductosPorTipo(const string& tipo) const {
    vector<Producto> productosPorTipo;

    for (const auto& producto : productos) {
        if (producto.getTipoProducto() == tipo) {
            productosPorTipo.push_back(producto);
        }
    }

    return productosPorTipo;
}

