#include "Sudadera.hpp"

Sudadera::Sudadera(string cod, float precioV, int cant, Temporada temp,Genero gen, Talla t, TipoSudadera tip, string mat, bool crem)
    : Ropa("Sudadera",cod, precioV, cant, temp,gen, t), tipo(tip), material(mat), cremallera(crem) {}

TipoSudadera Sudadera::getTipoSudadera() const {
    return tipo;
}

void Sudadera::setTipoSudadera(TipoSudadera tip) {
    tipo = tip;
}

string Sudadera::getMaterial() const {
    return material;
}

void Sudadera::setMaterial(std::string mat) {
    material = mat;
}

bool Sudadera::getCremallera() const {
    return cremallera;
}

void Sudadera::setCremallera(bool crem) {
    cremallera = crem;
}

void Sudadera::mostrarInformacion() const {
    Ropa::mostrarInformacion();
    cout << "Tipo: " << static_cast<int>(tipo) << "\n"
         << "Material: " << material << "\n"
         << "Cremallera: " << (cremallera ? "Sí" : "No") << endl;
}
