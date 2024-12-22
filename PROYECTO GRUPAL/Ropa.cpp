#include "ropa.hpp"
#include <iostream>

using namespace std;

// Constructor
Ropa::Ropa(string cod, float precioV, int cant, Genero gen, Talla t)
    : Producto(cod, precioV, cant, gen), talla(t) {}

// Getters y Setters
Talla Ropa::getTalla() const {
    return talla;
}

void Ropa::setTalla(Talla t) {
    talla = t;
}

// Implementación del método mostrarInformacion
void Ropa::mostrarInformacion() {
    Producto::mostrarInformacion();  // Llamamos al método de la clase padre
    cout << "Talla: " << static_cast<int>(talla) << endl;
}
