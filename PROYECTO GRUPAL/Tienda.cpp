#include "Tienda.hpp"

Tienda::Tienda(const string& nombreTienda, const string& archivo)
    : nombre(nombreTienda), archivoInventario(archivo) {
    inventario.cargarInventario(archivoInventario);
}

Inventario& Tienda::getInventario() {
    return inventario;
}

void Tienda::guardarInventario() const {
    inventario.guardarInventario(archivoInventario);
}

void Tienda::cargarInventario() {
    inventario.cargarInventario(archivoInventario);
}

string Tienda::getNombre() const {
    return nombre;
}
