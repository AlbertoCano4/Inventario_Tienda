#ifndef ROPA_HPP
#define ROPA_HPP

#include "producto.hpp"  // Incluimos la clase padre

class Ropa : public Producto {
protected:
    Talla talla;
    
public:
    // Constructor
    Ropa(std::string cod, float precioV, int cant, Genero gen, Talla t);
    
    // Destructor virtual
    virtual ~Ropa() = default;
    
    // Getters y Setters
    Talla getTalla() const;
    void setTalla(Talla t);
    
    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() override;
};

#endif // ROPA_HPP
