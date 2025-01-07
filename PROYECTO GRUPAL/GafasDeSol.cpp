#include "GafasDeSol.hpp"

// Constructor
GafasDeSol::GafasDeSol(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, const string& forma, bool uv)
    : Accesorio("Gafas de Sol", cod, precioV, cant, temp, gen, est), formaLente(forma), proteccionUV(uv) {}

// Getter de FormaLente
string GafasDeSol::getFormaLente() const {
    return formaLente;
}

// Setter de FormaLente
void GafasDeSol::setFormaLente(const string& forma) {
    formaLente = forma;
}

// Getter de ProteccionUV
bool GafasDeSol::getProteccionUV() const {
    return proteccionUV;
}

// Setter de ProteccionUV
void GafasDeSol::setProteccionUV(bool uv) {
    proteccionUV = uv;
}

// Mostrar información
void GafasDeSol::mostrarInformacion() const {
    Accesorio::mostrarInformacion();
    cout << "Forma de Lente: " << formaLente << "\n";
    cout << "Protección UV: " << (proteccionUV ? "Sí" : "No") << "\n";
}

// Destructor
GafasDeSol::~GafasDeSol() {}
