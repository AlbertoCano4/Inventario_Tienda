#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include "Definiciones.hpp"
#include <string>
#include <iostream>
#include <stdexcept> // Para manejar excepciones

using namespace std;

class Producto {
protected:
    string tipo;
    string codProducto;
    float precioVenta;
    int cantidad;
    Temporada temporada;
    Genero genero;

public:
    // Constructor
    Producto(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen);

    // Destructor virtual
    virtual ~Producto() {}

    // Método virtual puro para mostrar información
    virtual void mostrarInformacion() const = 0;

    // Getters
    string getCodProducto() const;
    float getPrecioVenta() const;
    int getCantidad() const;
    Temporada getTemporada() const;
    Genero getGenero() const;

    // Setters
    void setCantidad(int cant);

    // Operadores sobrecargados
    Producto& operator+=(int cantidadAdicional); // Sumar cantidad al inventario
    Producto& operator-=(int cantidadSalida);   // Restar cantidad del inventario
};

#endif // PRODUCTO_HPP
