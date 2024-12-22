#ifndef PANTALON_HPP
#define PANTALON_HPP

#include "ropa.hpp"  // Incluimos la clase padre (Producto->Ropa ->Pantalon)

class Pantalon : public Ropa {
private:
    TipoPantalon tipo;
    bool cargo;
public:
    // Constructor
    Pantalon(string cod, float precioV, int cant, Genero gen, Talla t, TipoPantalon tip, bool carg);
    // Destructor virtual
    virtual ~Pantalon() = default;
    
    // Getters y Setters
    TipoPantalon getTipo() const;
    void setTipo(TipoPantalon t);
    bool getCargo();
    void setCargo(bool carg);
    
    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() override;
};

#endif // PANTALON_HPP
