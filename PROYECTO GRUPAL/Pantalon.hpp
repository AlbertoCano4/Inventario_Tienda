#ifndef PANTALON_HPP
#define PANTALON_HPP

#include "ropa.hpp"

enum class TipoPantalon { LARGO, CORTO };

class Pantalon : public Ropa {
private:
    TipoPantalon tipo;
    bool cargo;

public:
    // Constructor
    Pantalon(string cod, float precioV, int cant, Temporada temp, Genero gen, Talla t, TipoPantalon tip, bool carg);

    // Destructor
    virtual ~Pantalon() = default;

    // Getters y Setters
    TipoPantalon getTipoPantalon() const;
    void setTipo(TipoPantalon t);
    bool getCargo() const;
    void setCargo(bool carg);

    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() const override;
};

#endif // PANTALON_HPP
