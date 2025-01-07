#include "Producto.hpp"

// Constructor de Producto
Producto::Producto(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen)
    : tipo(tipoProducto), codProducto(cod), precioVenta(precioV), cantidad(cant), temporada(temp), genero(gen) {}

// Implementación de los Getters
string Producto::getCodProducto() const { return codProducto; }

float Producto::getPrecioVenta() const { return precioVenta; }

int Producto::getCantidad() const { return cantidad; }

Temporada Producto::getTemporada() const { return temporada; }

Genero Producto::getGenero() const { return genero; }

// Implementación de los Setters
void Producto::setCantidad(int cant) {
    if (cant < 0) {
        throw invalid_argument("La cantidad no puede ser negativa.");
    }
    cantidad = cant;
}

// Implementación del operador +=
Producto& Producto::operator+=(int cantidadAdicional) {
    if (cantidadAdicional < 0) {
        throw invalid_argument("La cantidad a añadir no puede ser negativa.");
    }
    this->cantidad += cantidadAdicional;
    return *this;
}

// Implementación del operador -=
Producto& Producto::operator-=(int cantidadSalida) {
    if (cantidadSalida < 0) {
        throw invalid_argument("La cantidad a restar no puede ser negativa.");
    }
    if (cantidadSalida > this->cantidad) {
        throw invalid_argument("No hay suficientes productos en el inventario para restar esta cantidad.");
    }
    this->cantidad -= cantidadSalida;
    return *this;
}
