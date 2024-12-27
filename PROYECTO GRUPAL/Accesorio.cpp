#include "accesorio.hpp"
#include <iostream>

using namespace std;

// Constructor de la clase Accesorio
Accesorio::Accesorio(string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est)
    : Producto(cod, precioV, cant, temp, gen), estilo(est) {}

// Getter de Estilo
Estilo Accesorio::getEstilo() const {
    return estilo;
}

// Setter de Estilo
void Accesorio::setEstilo(Estilo est) {
    estilo = est;
}

// Implementación del método mostrarInformacion
void Accesorio::mostrarInformacion() const {
    Producto::mostrarInformacion(); // Llama al método base
    cout << "Estilo: "
         << (estilo == Estilo::MODERNO ? "Moderno" : estilo == Estilo::CLASICO ? "Clásico" : estilo == Estilo::DEPORTIVO ? "Deportivo" : "Casual") << endl;
}
