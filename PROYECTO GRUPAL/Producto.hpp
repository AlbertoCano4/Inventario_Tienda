#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include "Definiciones.hpp" // Incluye definiciones necesarias, como Temporada y Genero.
#include <string>
#include <iostream>
#include <stdexcept> // Para manejar excepciones

using namespace std;

// Clase base abstracta que representa un producto genérico.
class Producto {
protected:
    string tipo;          // Tipo del producto (por ejemplo: camiseta, bufanda).
    string codProducto;   // Código único que identifica al producto.
    float precioVenta;    // Precio de venta del producto.
    int cantidad;         // Cantidad disponible en el inventario.
    Temporada temporada;  // Temporada asociada al producto (verano, invierno, etc.).
    Genero genero;        // Género asociado al producto (hombre, mujer, unisex).
    
    
public:
    // Constructor
    // Permite inicializar los atributos principales de un producto.
    Producto(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen);
    
    // Destructor virtual
    // Se utiliza para asegurar que se destruyan las clases derivadas.
    virtual ~Producto() {}
    
    // Método virtual puro
    // Obliga a las clases derivadas a implementar el método mostrarInformacion.
    virtual void mostrarInformacion() const = 0;
    
    // Getters
    string getCodProducto() const; // Devuelve el código único del producto.
    float getPrecioVenta() const; // Devuelve el precio de venta del producto.
    int getCantidad() const;      // Devuelve la cantidad disponible en el inventario.
    Temporada getTemporada() const; // Devuelve la temporada del producto.
    Genero getGenero() const;       // Devuelve el género del producto.
    
    // Setters
    void setCantidad(int cant); // Establece la cantidad disponible en el inventario.

    // Operadores sobrecargados
    Producto& operator+=(int cantidadAdicional); // Sumar cantidad al inventario
    Producto& operator-=(int cantidadSalida);   // Restar cantidad del inventario
};

#endif
