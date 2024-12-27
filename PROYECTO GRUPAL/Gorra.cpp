#include "gorra.hpp"
#include <iostream>

Gorra::Gorra(string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, string tip, string mat)
    : Accesorio(cod, precioV, cant, temp, gen, est), tipo(tip), material(mat) {}

string Gorra::getTipo() const {
    return tipo;
}

void Gorra::setTipo(string tip) {
    tipo = tip;
}

string Gorra::getMaterial() const {
    return material;
}

void Gorra::setMaterial(string mat) {
    material = mat;
}

void Gorra::mostrarInformacion() const {
    Accesorio::mostrarInformacion();
    cout << "Tipo: " << tipo << "\n"
         << "Material: " << material << endl;
}
