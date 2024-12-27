#include "Pantalon.hpp"

Pantalon::Pantalon(string cod, float precioV, int cant, Temporada temp, Genero gen, Talla t, TipoPantalon tip, bool carg)
    : Ropa("Pantalon",cod, precioV, cant, temp, gen, t), tipo(tip), cargo(carg) {}

TipoPantalon Pantalon::getTipoPantalon() const {
    return tipo;
}

void Pantalon::setTipo(TipoPantalon t) {
    tipo = t;
}

bool Pantalon::getCargo() const {
    return cargo;
}

void Pantalon::setCargo(bool carg) {
    cargo = carg;
}


void Pantalon::mostrarInformacion() const {
    Ropa::mostrarInformacion();
    cout << "Tipo: " << static_cast<int>(tipo) << "\n"
    << "Cargo: " << (cargo ? "Sí" : "No") << endl;
}
