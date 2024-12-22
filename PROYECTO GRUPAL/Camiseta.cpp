#include "Camiseta.hpp"
#include <iostream>

using namespace std;

// Constructor
Camiseta::Camiseta(string cod, float precioV, int cant, Genero gen, Talla t, TipoCamiseta tip, string mat, string est)
: Ropa(cod, precioV, cant, gen, t), tipo(tip), material(mat), estilo(est) {}

//Getters y setters
TipoCamiseta Camiseta::getTipo() const{
    return tipo;
  }

void Camiseta::setTipo(TipoCamiseta t){
    tipo = t;
  }

string Camiseta::getMaterial() const{
    return material;
  }

void Camiseta::setMaterial(string mat) {
    material = mat;
  }

string Camiseta::getEstilo() const{
    return estilo;
  }

void Camiseta::setEstilo(string est) {
    estilo = est;
  }

//Método que muestra la info de las camisetas y que hereda la info que muestra la clase principal Ropa
void Camiseta::mostrarInformacion(){
    Ropa::mostrarInformacion();
    cout << "Tipo de Camiseta: " << static_cast<int>(tipo) << endl;
    cout << "Material: " << material << endl;
    cout << "Estilo: " << estilo << endl;
}
