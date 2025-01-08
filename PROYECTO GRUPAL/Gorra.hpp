#ifndef GORRA_HPP
#define GORRA_HPP

#include "Accesorio.hpp" // Incluye la definición de la clase base Accesorio.

// Clase derivada que representa una gorra, hereda de Accesorio
class Gorra : public Accesorio {
private:
    string tipo;
    string material;

public:
    // Constructor
    Gorra(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, const string& tip, const string& mat);

    // Getters
    string getTipo() const;
    string getMaterial() const;

    // Setters
    void setTipo(const string& tip);
    void setMaterial(const string& mat);

    // Mostrar información
    void mostrarInformacion() const override;

    // Destructor
    virtual ~Gorra();
};

#endif 
