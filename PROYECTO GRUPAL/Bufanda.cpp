#include "Bufanda.hpp"
#include <iostream>
using namespace std;

// Constructor de la clase Bufanda
Bufanda::Bufanda(string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, bool lana)
    : Accesorio("Bufanda", cod, precioV, cant, temp, gen, est), esDeLana(lana) {}

// Getter de esDeLana
bool Bufanda::getEsDeLana() const {
    return esDeLana;
}

// Setter de esDeLana
void Bufanda::setEsDeLana(bool lana) {
    esDeLana = lana;
}

// Implementación de mostrarInformacion
void Bufanda::mostrarInformacion() const {
    Accesorio::mostrarInformacion(); // Llama al método de la clase padre
    cout << "Es de lana: " << (esDeLana ? "Sí" : "No") << endl;
}
