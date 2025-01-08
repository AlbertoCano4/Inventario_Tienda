#ifndef BUFANDA_HPP
#define BUFANDA_HPP

#include "Accesorio.hpp" // Incluye la definición de la clase base Accesorio.

// Clase derivada que representa una bufanda, hereda de Accesorio
class Bufanda : public Accesorio {
private:
    bool esDeLana;

public:
    // Constructor
    Bufanda(string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, bool lana);

    // Mostrar información
    void mostrarInformacion() const override;

    // Getters
    bool getEsDeLana() const;

    // Setters
    void setEsDeLana(bool lana);

    // Destructor
    ~Bufanda();
};

#endif // BUFANDA_HPP
