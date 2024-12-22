#include "gorra.hpp"
#include <iostream>

using namespace std;

// Constructor
Gorra::Gorra(string cod, float precioV, int cant, Genero gen, Temporada temp, string tip, string mat)
: Accesorio(cod, precioV, cant, gen, temp), tipo(tip), material(mat) {}

//Getters y setters
string Gorra::getTipo() const{
    return tipo;
    }

void Gorra::setTipoGorra(string tip){
    tipo = tip;
    }

string Gorra::getMaterial() const{
    return material;
    }

void Gorra::setMaterial(string mat_acc) {
    material = mat_acc;
    }
//Método que muestra la info de las camisetas y que hereda la info que muestra la clase principal Ropa
void Gorra::mostrarInformacion()  {
        Accesorio::mostrarInformacion();
        cout << "Tipo de Gorra: " << tipo << endl;
        cout << "Material: " << material << endl;
    }

