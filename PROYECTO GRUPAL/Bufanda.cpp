#include "Bufanda.hpp"
#include <iostream>

using namespace std;

// Constructor
Bufanda::Bufanda(string cod, string col, float precioV, int cant, Genero gen, Temporada temp, string mat, bool lana)
: Accesorio(cod, precioV, cant, gen, temp), material(mat), esDeLana(lana) {}

//Getters y setters
string Bufanda::getMaterial() const{
        return material;
    }

void Bufanda::setMaterial(string mat_bufanda) {
        material = mat_bufanda;
    }

bool Bufanda::getEsDeLana() {
        return esDeLana;
    }

void Bufanda::setEsDeLana(bool es_lana) {
    esDeLana = es_lana;
    }

//Método que muestra la info de las Bufanda y que hereda la info que muestra la clase principal Accesorios
void Bufanda::mostrarInformacion() {
    Accesorio::mostrarInformacion();
    cout << "Material: " << material << endl;
    cout << "Es de Lana: " << (esDeLana ? "Sí" : "No") << endl;
    }

