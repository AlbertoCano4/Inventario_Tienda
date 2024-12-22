#include "accesorio.hpp"
#include <iostream>

using namespace std;

// Constructor
Accesorio::Accesorio(string cod, float precioV, int cant, Genero gen, Temporada temp)
: Producto(cod, precioV, cant, gen), temporada(temp) {}
// Getters y Setters

Temporada Accesorio::getTemporada() const{
    return temporada;
}

void Accesorio::setTemporada(Temporada temp){
    temporada = temp;
}

// Implementación del método mostrarInformacion
void Accesorio::mostrarInformacion() {
    Producto::mostrarInformacion();  // Llamamos al método de la clase padre
    cout << "Temporada: " << static_cast<int>(temporada) << endl;
}
