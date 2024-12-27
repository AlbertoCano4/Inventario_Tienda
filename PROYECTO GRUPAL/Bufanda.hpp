#ifndef BUFANDA_HPP
#define BUFANDA_HPP

#include "accesorio.hpp"

class Bufanda : public Accesorio {
private:
    bool esDeLana;

public:
    // Constructor
    Bufanda(string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, bool lana);

    // Destructor
    virtual ~Bufanda() = default;

    // Getters y Setters
    bool getEsDeLana() const;
    void setEsDeLana(bool lana);

    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() const override;
};

#endif // BUFANDA_HPP
