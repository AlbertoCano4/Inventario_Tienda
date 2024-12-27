#ifndef GORRA_HPP
#define GORRA_HPP

#include "accesorio.hpp"

class Gorra : public Accesorio {
private:
    string tipo;
    string material;

public:
    // Constructor
    Gorra(string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, string tip, string mat);

    // Destructor
    virtual ~Gorra() = default;

    // Getters y Setters
    string getTipo() const;
    void setTipo(string tip);
    string getMaterial() const;
    void setMaterial(string mat);

    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() const override;
};

#endif // GORRA_HPP
