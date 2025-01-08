#ifndef ROPA_HPP
#define ROPA_HPP

#include "Producto.hpp" // Incluye la definición de la clase base Producto.

// Clase derivada que representa productos de tipo ropa.
class Ropa : public Producto {
protected:
    Talla talla; // Atributo específico de la ropa que indica la talla (por ejemplo, S, M, L, XL).
    
public:
    // Constructor de Ropa
    // Inicializa los atributos heredados de `Producto` y el atributo adicional `talla`.
    Ropa(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t);
    
    // Función para mostrar la información del producto.
    // Implementa el método virtual puro mostrarInformacion de Producto.
    void mostrarInformacion() const override;
    
    // Getter para la talla del producto.
    Talla getTalla() const;
    
    // Destructor virtual.
    // Se asegura de que los recursos de clases derivadas se liberen correctamente.
    virtual ~Ropa();
};

#endif
