#include "Camiseta.hpp"

Camiseta::Camiseta(string cod, float precioV, int cant, Temporada temp,Genero gen, Talla t, TipoCamiseta tip, string mat, bool est)
: Ropa(cod, precioV, cant, temp ,gen, t), tipo(tip), material(mat), estampado(est) {}

TipoCamiseta Camiseta::getTipo() const {
    return tipo;
}

void Camiseta::setTipo(TipoCamiseta t) {
    tipo = t;
}

string Camiseta::getMaterial() const {
    return material;
}

void Camiseta::setMaterial(string mat) {
    material = mat;
}

bool Camiseta::getEstampado() const {
    return estampado;
}

void Camiseta::setEstampado(bool est) {
    estampado = est;
}

void Camiseta::mostrarInformacion() const {
    Ropa::mostrarInformacion();
    cout << "Tipo: " << static_cast<int>(tipo) << "\n"
    << "Material: " << material << "\n"
    << "Estampado: " << (estampado ? "Sí" : "No") << endl;
}
