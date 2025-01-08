#include "Producto.hpp"

// Constructor de Producto
// Inicializa un producto con sus atributos básicos: tipo, código, precio de venta, cantidad, temporada y género.
Producto::Producto(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen)
    : tipo(tipoProducto), codProducto(cod), precioVenta(precioV), cantidad(cant), temporada(temp), genero(gen) {}

// Implementación de los Getters
// Devuelve el código único del producto.
string Producto::getCodProducto() const { return codProducto; }

// Devuelve el precio de venta del producto.
float Producto::getPrecioVenta() const { return precioVenta; }

// Devuelve la cantidad disponible en el inventario.
int Producto::getCantidad() const { return cantidad; }

// Devuelve la temporada asociada al producto (por ejemplo: verano, invierno, anual).
Temporada Producto::getTemporada() const { return temporada; }

// Devuelve el género asociado al producto (por ejemplo: hombre, mujer).
Genero Producto::getGenero() const { return genero; }

// Implementación de los Setters
// Establece la cantidad de productos disponibles en el inventario.
// Lanza una excepción si la cantidad es negativa.
void Producto::setCantidad(int cant) {
    if (cant < 0) {
        throw invalid_argument("La cantidad no puede ser negativa.");
    }
    cantidad = cant;
}

// Operador sobrecargado +=
// Aumenta la cantidad del producto en el inventario.
// Lanza una excepción si la cantidad a añadir es negativa.
// Retorna el propio objeto (*this) para permitir encadenar operaciones.
Producto& Producto::operator+=(int cantidadAdicional) {
    if (cantidadAdicional < 0) {
        throw invalid_argument("La cantidad a añadir no puede ser negativa.");
    }
    this->cantidad += cantidadAdicional; // Aumenta la cantidad actual del producto.
    return *this; // Devuelve el objeto actual para permitir poder hacer en una misma operacion += y -=
}

// Operador sobrecargado -=
// Disminuye la cantidad del producto en el inventario.
// Lanza una excepción si la cantidad a restar es negativa o mayor que la cantidad disponible.
// Retorna el propio objeto (*this) para permitir encadenar operaciones.
Producto& Producto::operator-=(int cantidadSalida) {
    if (cantidadSalida < 0) {
        throw invalid_argument("La cantidad a restar no puede ser negativa.");
    }
    if (cantidadSalida > this->cantidad) {
        throw invalid_argument("No hay suficientes productos en el inventario para restar esta cantidad.");
    }
    this->cantidad -= cantidadSalida; // Disminuye la cantidad actual del producto.
    return *this; // Devuelve el objeto actual para permitir poder hacer en una misma operacion -= y +=
}

