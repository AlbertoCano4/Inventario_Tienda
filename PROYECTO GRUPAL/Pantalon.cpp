#include "Pantalon.hpp"
#include <iostream>

using namespace std;

// Constructor
Pantalon::Pantalon(string cod, float precioV, int cant, Genero gen, Talla t, TipoPantalon tip, bool carg)
: Ropa(cod, precioV, cant, gen, t), tipo(tip), cargo(carg) {}

//Getters y setters
TipoPantalon Pantalon::getTipo() const{
    return tipo;
    }

void Pantalon::setTipo(TipoPantalon tip) {
    tipo = tip;
    }

bool Pantalon::getCargo(){
    return cargo;
    }

void Pantalon::setCargo(bool carg) {
    cargo = carg;
    }

//Método que muestra la info de los pantalones y que hereda la info que muestra la clase principal Ropa
void Pantalon::mostrarInformacion(){
        Ropa::mostrarInformacion();
        cout << "Tipo de Pantalón: " << static_cast<int>(tipo) << endl;
        cout << "Cargo: " << (cargo ? "Sí" : "No") << endl;
    }
