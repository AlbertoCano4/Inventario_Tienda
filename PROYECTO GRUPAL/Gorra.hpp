#ifndef GORRA_HPP
#define GORRA_HPP

#include "Accesorio.hpp"

class Gorra : public Accesorio {
private:
    string tipo;    // Tipo de gorra
    string material; // Material de la gorra

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

#endif // GORRA_HPP
