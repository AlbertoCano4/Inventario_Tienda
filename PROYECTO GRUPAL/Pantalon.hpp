#ifndef PANTALON_HPP
#define PANTALON_HPP

#include "Ropa.hpp" // Incluye la definición de la clase base `Ropa`.

// Clase derivada que representa un pantalon, hereda de Ropa
class Pantalon : public Ropa {
private:
    TipoPantalon tipo;
    bool cargo;

public:
    // Constructor
    Pantalon(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t, TipoPantalon tip, bool carg);

    // Getters
    TipoPantalon getTipoPantalon() const;
    bool getCargo() const;

    // Setters
    void setTipo(TipoPantalon t);
    void setCargo(bool carg);

    // Mostrar información
    void mostrarInformacion() const override;

    // Destructor
    virtual ~Pantalon();
};

#endif 
