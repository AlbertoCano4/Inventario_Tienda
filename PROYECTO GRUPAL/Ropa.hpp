#ifndef ROPA_HPP
#define ROPA_HPP

#include "Producto.hpp"

enum class Talla { S, M, L, XL, XXL };

class Ropa : public Producto {
protected:
    Talla talla;

public:
    // Constructor
    Ropa(string tipoProducto, string cod, float precioV, int cant, Temporada temp,Genero gen, Talla t);

    // Destructor virtual puro
    virtual ~Ropa() = 0;

    // Getters y Setters
    Talla getTalla() const;
    void setTalla(Talla t);

    // Método que sobreescribe el de la clase padre
    virtual void mostrarInformacion() const = 0;
};

#endif // ROPA_HPP
