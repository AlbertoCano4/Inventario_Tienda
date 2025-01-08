#include "Gorra.hpp"

// Constructor
// Llama al constructor de la clase base Accesorio para inicializar los atributos comunes.
// Inicializa los atributos específicos de Gorra: tipo y material.
Gorra::Gorra(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, const string& tip, const string& mat)
    : Accesorio("Gorra", cod, precioV, cant, temp, gen, est), tipo(tip), material(mat) {}

// Getter de Tipo
string Gorra::getTipo() const {
    return tipo;
}

// Setter de Tipo
void Gorra::setTipo(const string& tip) {
    tipo = tip;
}

// Getter de Material
string Gorra::getMaterial() const {
    return material;
}

// Setter de Material
void Gorra::setMaterial(const string& mat) {
    material = mat;
}

// Mostrar información
void Gorra::mostrarInformacion() const {
    Accesorio::mostrarInformacion(); // Llama al método de la clase base Accesorio para mostrar atributos comunes.
    cout << "Tipo: " << tipo << "\n";
    cout << "Material: " << material << "\n";
}

// Destructor
Gorra::~Gorra() {}
