#include "bufanda.hpp"
#include <iostream>

Bufanda::Bufanda(string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, bool lana)
    : Accesorio(cod, precioV, cant, temp, gen, est), esDeLana(lana) {}

bool Bufanda::getEsDeLana() const {
    return esDeLana;
}

void Bufanda::setEsDeLana(bool lana) {
    esDeLana = lana;
}

void Bufanda::mostrarInformacion() const {
    Accesorio::mostrarInformacion();
    cout << "Es de lana: " << (esDeLana ? "Sí" : "No") << endl;
}
