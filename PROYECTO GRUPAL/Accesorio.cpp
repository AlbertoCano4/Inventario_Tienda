#include "Accesorio.hpp"

// Constructor
Accesorio::Accesorio(string tipoProducto, string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est)
    : Producto(tipoProducto, cod, precioV, cant, temp, gen), estilo(est) {}

// Implementación del método mostrarInformacion
void Accesorio::mostrarInformacion() const {
    cout << "Tipo: " << tipo << "\n";
    cout << "Código del Producto: " << codProducto << "\n";
    cout << "Precio de Venta: " << precioVenta << "\n";
    cout << "Cantidad en Inventario: " << cantidad << "\n";
    cout << "Temporada: " << temporadaToString(temporada) << "\n";
    cout << "Género: " << generoToString(genero) << "\n";
    cout << "Estilo: " << estiloTostring(estilo) << endl;
}

// Getter de Estilo
Estilo Accesorio::getEstilo() const {
    return estilo;
}

// Setter de Estilo
void Accesorio::setEstilo(Estilo est) {
    estilo = est;
}

// Destructor
Accesorio::~Accesorio() {}
