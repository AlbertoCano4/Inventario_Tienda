#include "Ropa.hpp"
#include <iostream>

// Implementación de la clase Ropa
Ropa::Ropa(string tipoProducto, string cod, float precioV, int cant, Temporada temp,Genero gen, Talla t)
: Producto(tipoProducto, cod, precioV, cant, temp, gen), talla(t) {}

Ropa::~Ropa() {} // Destructor puro debe tener una implementación vacía

Talla Ropa::getTalla() const {
    return talla;
}

void Ropa::setTalla(Talla t) {
    talla = t;
}

// Implementación del método mostrarInformacion
void Ropa::mostrarInformacion() const {
    Producto::mostrarInformacion(); // Llama al método base
    cout << "Talla: " << (talla == Talla::S ? "S" : talla == Talla::M ? "M" : talla == Talla::L ? "L" : talla == Talla::XL ? "XL" : "XXL") << endl;
}
