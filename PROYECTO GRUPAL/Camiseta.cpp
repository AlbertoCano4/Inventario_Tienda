#include "Camiseta.hpp"

// Constructor Camiseta
Camiseta::Camiseta(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t, TipoCamiseta tip, const string& mat, bool est)
    : Ropa("Camiseta", cod, precioV, cant, temp, gen, t), tipo(tip), material(mat), estampado(est) {}

// Método para mostrar la información
void Camiseta::mostrarInformacion() const {
    // Llamamos al método de la clase base para imprimir información general
    Ropa::mostrarInformacion();
    // Añadimos los datos específicos de la camiseta
    cout << "Tipo de Camiseta: " << tipoCamisetaToString(tipo) << "\n";
    cout << "Material: " << material << "\n";
    cout << "Estampado: " << (estampado ? "Sí" : "No") << "\n";
}

// Getters
TipoCamiseta Camiseta::getTipo() const {
    return tipo;
}

string Camiseta::getMaterial() const {
    return material;
}

bool Camiseta::getEstampado() const {
    return estampado;
}

// Setters
void Camiseta::setMaterial(const string& mat) {
    material = mat;
}

void Camiseta::setEstampado(bool est) {
    estampado = est;
}

// Destructor
Camiseta::~Camiseta() {}
