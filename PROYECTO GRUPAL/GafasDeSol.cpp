#include "GafasDeSol.hpp"
#include <iostream>

using namespace std;

// Constructor
GafasDeSol::GafasDeSol(string cod, float precioV, int cant, Genero gen, Temporada temp, string forma, bool uv)
: Accesorio(cod, precioV, cant, gen, temp), formaLente(forma), proteccionUV(uv) {}

//Getters y setters
string GafasDeSol::getFormaLente() const{
      return formaLente;
  }

  void GafasDeSol::setFormaLente(string form_lente) {
      formaLente = form_lente;
  }

  bool GafasDeSol::getProteccionUV(){
      return proteccionUV;
  }

  void GafasDeSol::setProteccionUV(bool protec_UV) {
      proteccionUV = protec_UV;
  }
//Método que muestra la info de las camisetas y que hereda la info que muestra la clase principal Ropa
void GafasDeSol::mostrarInformacion()  {
        Accesorio::mostrarInformacion();
        cout << "Forma de Lente: " << formaLente << endl;
        cout << "Protección UV: " << (proteccionUV ? "Sí" : "No") << endl;
    }

