#include "Ropa.hpp"

// Constructor Ropa
Ropa::Ropa(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t)
    : Producto(tipoProducto, cod, precioV, cant, temp, gen), talla(t) {}

// Función para mostrar la información de la ropa
void Ropa::mostrarInformacion() const {
    cout << "Tipo: " << tipo << "\n";
    cout << "Código del Producto: " << codProducto << "\n";
    cout << "Precio de Venta: " << precioVenta << "\n";
    cout << "Cantidad en Inventario: " << cantidad << "\n";
    cout << "Temporada: " << temporadaToString(temporada) << "\n";
    cout << "Género: " << generoToString(genero) << "\n";
    cout << "Talla: " << tallaToString(talla) << "\n";
}

// Getter de Talla
Talla Ropa::getTalla() const {
    return talla;
}

// Destructor
Ropa::~Ropa() {}
