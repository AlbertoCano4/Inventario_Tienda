#include "Sudadera.hpp"

// Constructor Pantalon
// Inicializa los atributos heredados de Ropa y los atributos específicos de sudadera (tipo de sudadera, material y si tienen o no cremallera).
Sudadera::Sudadera(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t,
                   TipoSudadera tip, const string& mat, bool crem)
    : Ropa("Sudadera", cod, precioV, cant, temp, gen, t), tipo(tip), material(mat), cremallera(crem) {}

// Getters
TipoSudadera Sudadera::getTipoSudadera() const {
    return tipo;
}

string Sudadera::getMaterial() const {
    return material;
}

bool Sudadera::getCremallera() const {
    return cremallera;
}

// Setters
void Sudadera::setTipoSudadera(TipoSudadera tip) {
    tipo = tip;
}

void Sudadera::setMaterial(const string& mat) {
    material = mat;
}

void Sudadera::setCremallera(bool crem) {
    cremallera = crem;
}

// Mostrar información
void Sudadera::mostrarInformacion() const {
    Ropa::mostrarInformacion();  // Llamamos al método de la clase base (Ropa) para imprimir información general
    cout << "Tipo de Sudadera: " << tipoSudaderaToString(tipo) << "\n";
    cout << "Material: " << material << "\n";
    cout << "Cremallera: " << (cremallera ? "Sí" : "No") << "\n";
}

// Destructor
Sudadera::~Sudadera() {}
