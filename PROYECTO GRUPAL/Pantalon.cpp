#include "Pantalon.hpp"

// Constructor
Pantalon::Pantalon(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t, TipoPantalon tip, bool carg)
    : Ropa("Pantalon", cod, precioV, cant, temp, gen, t), tipo(tip), cargo(carg) {}

// Getter de TipoPantalon
TipoPantalon Pantalon::getTipoPantalon() const {
    return tipo;
}

// Setter de TipoPantalon
void Pantalon::setTipo(TipoPantalon t) {
    tipo = t;
}

// Getter de Cargo
bool Pantalon::getCargo() const {
    return cargo;
}

// Setter de Cargo
void Pantalon::setCargo(bool carg) {
    cargo = carg;
}

// Método para mostrar información
void Pantalon::mostrarInformacion() const {
    Ropa::mostrarInformacion();
    cout << "Tipo de Pantalón: " << tipoPantalonToString(tipo) << "\n";
    cout << "Cargo: " << (cargo ? "Sí" : "No") << "\n";
}

// Destructor
Pantalon::~Pantalon() {}
