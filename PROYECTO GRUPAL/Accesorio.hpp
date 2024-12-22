#ifndef ACCESORIO_HPP
#define ACCESORIO_HPP

#include "producto.hpp"  // Incluimos la clase padre

class Accesorio : public Producto {
protected:
    Temporada temporada;
    
public:
    // Constructor
    Accesorio(string cod, float precioV, int cant, Genero gen, Temporada temp);
    // Destructor virtual
    virtual ~Accesorio() = default;
    
    // Getters y Setters
    Temporada getTemporada() const;
    void setTemporada(Temporada temp);
    
    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() override;
};

#endif // ACCESORIO_HPP
