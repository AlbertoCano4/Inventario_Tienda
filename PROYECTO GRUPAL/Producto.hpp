#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include "Definiciones.hpp"
#include <string>
#include <iostream>
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
    // Constructor Producto
    Producto(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen)
        : tipo(tipoProducto), codProducto(cod), precioVenta(precioV), cantidad(cant), temporada(temp), genero(gen) {}

    virtual void mostrarInformacion() const = 0; // Método virtual puro

    virtual ~Producto() {}

    // Getters
    string getCodProducto() const { return codProducto; }
    float getPrecioVenta() const { return precioVenta; }
    int getCantidad() const { return cantidad; }
    Temporada getTemporada() const { return temporada; }
    Genero getGenero() const { return genero; }

    // Setters
    void setCantidad(int cant) { cantidad = cant; }
};

#endif // PRODUCTO_HPP
