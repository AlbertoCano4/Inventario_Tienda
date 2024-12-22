#include "Sudadera.hpp"
#include <iostream>

using namespace std;

// Constructor
Sudadera::Sudadera(string cod, float precioV, int cant, Genero gen, Talla t, TipoSudadera tip, string mat, bool crem)
        : Ropa(cod, precioV, cant, gen, t), tipo(tip), material(mat), cremallera(crem) {}

//Getters y setters
TipoSudadera Sudadera::getTipoSudadera() const{
    return tipo;
  }

void Sudadera::setTipoSudadera(TipoSudadera tip){
    tipo = tip;
  }

string Sudadera::getMaterial() const{
    return material;
  }

void Sudadera::setMaterial(string mat) {
    material = mat;
  }

bool Sudadera::getCremallera(){
    return cremallera;
  }

void Sudadera::setCremallera(bool crem) {
    cremallera = crem;
  }

//Método que muestra la info de las camisetas y que hereda la info que muestra la clase principal Ropa
void Sudadera::mostrarInformacion(){
    Ropa::mostrarInformacion();
    cout << "Tipo de Sudadera: " << static_cast<int>(tipo) << endl;
    cout << "Material: " << material << endl;
    cout << "Cremallera: " << (cremallera ? "Sí" : "No") << endl;
}
