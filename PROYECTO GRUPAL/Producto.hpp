#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <iostream>
#include <string>
using namespace std;

// Enumeraciones
enum class Genero { MUJER, HOMBRE };
enum class Temporada { INVIERNO, VERANO, ANUAL };

// Clase base Producto
class Producto {
protected:
    string codProducto;     // Clave primaria
    float precioVenta;      // Precio del producto
    int cantidad;           // Cantidad en inventario
    Temporada temporada;    // Temporada asociada al producto
    Genero genero;          // Género del producto (Mujer, Hombre)

public:
    // Constructor clase Producto
    Producto(string cod, float precioV, int cant, Temporada temp, Genero gen);

    // Destructor virtual para permitir herencia
    virtual ~Producto() = default;

    // Getters y Setters
    string getCodProducto() const;
    void setCodProducto(const string& cod_prod);
    float getPrecioVenta() const;
    void setPrecioVenta(float precio_venta);
    int getCantidad() const;
    void setCantidad(int cant);
    Genero getGenero() const;
    void setGenero(Genero gen);
    Temporada getTemporada() const;
    void setTemporada(Temporada temp);

    // Métodos virtuales
    virtual void mostrarInformacion() const; // Método virtual puro (obliga a las subclases a implementarlo)

    // Métodos de gestión de inventario
    void venderProducto(int cantidadVendida);
    void aniadirProductoATienda(int cantidadAnadida);
    void devolucionProducto(int cantidadDevuelta);
};

#endif // PRODUCTO_HPP
