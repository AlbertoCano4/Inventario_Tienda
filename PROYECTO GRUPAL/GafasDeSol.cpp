#include "gafasdesol.hpp"
#include <iostream>

GafasDeSol::GafasDeSol(string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, string forma, bool uv)
    : Accesorio("Gafas de sol",cod, precioV, cant, temp, gen, est), formaLente(forma), proteccionUV(uv) {}

string GafasDeSol::getFormaLente() const {
    return formaLente;
}

void GafasDeSol::setFormaLente(string forma) {
    formaLente = forma;
}

bool GafasDeSol::getProteccionUV() const {
    return proteccionUV;
}

void GafasDeSol::setProteccionUV(bool uv) {
    proteccionUV = uv;
}

void GafasDeSol::mostrarInformacion() const {
    Accesorio::mostrarInformacion();
    cout << "Forma de lente: " << formaLente << "\n"
         << "Protección UV: " << (proteccionUV ? "Sí" : "No") << endl;
}
