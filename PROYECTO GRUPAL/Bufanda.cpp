#include "Bufanda.hpp"

// Constructor
// Llama al constructor de la clase base Accesorio para inicializar los atributos comunes.
// Inicializa el atributo adicional esDeLana.
Bufanda::Bufanda(string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, bool lana)
    : Accesorio("Bufanda", cod, precioV, cant, temp, gen, est), esDeLana(lana) {}

// Mostrar información
void Bufanda::mostrarInformacion() const {
    Accesorio::mostrarInformacion(); // Llama al métodoAccesorio para mostrar atributos comunes.
    cout << "Lana: " << (esDeLana ? "Sí" : "No") << "\n";
}

// Getter de esDeLana
bool Bufanda::getEsDeLana() const {
    return esDeLana;
}

// Setter de esDeLana
void Bufanda::setEsDeLana(bool lana) {
    esDeLana = lana;
}

// Destructor
Bufanda::~Bufanda() { }
