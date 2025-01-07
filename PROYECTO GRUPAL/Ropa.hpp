#ifndef ROPA_HPP
#define ROPA_HPP

#include "Producto.hpp"

class Ropa : public Producto {
protected:
    Talla talla;

public:
    // Constructor Ropa
    Ropa(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t);

    // Función para mostrar la información de la ropa
    void mostrarInformacion() const override;

    // Getter de Talla
    Talla getTalla() const;

    virtual ~Ropa();
};

#endif // ROPA_HPP
