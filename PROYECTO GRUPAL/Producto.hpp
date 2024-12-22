#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

using namespace std;

#include <iostream>
#include <string>

// Enumeraciones
enum class Genero { MUJER, HOMBRE };
enum class Talla { S, M, L, XL, XXL };
enum class TipoCamiseta { MANGA_LARGA, MANGA_CORTA, TIRANTES };
enum class TipoSudadera { CREWNECK, HOODIE };
enum class TipoPantalon { LARGO, CORTO };
enum class Temporada { INVIERNO, VERANO, ANUAL };

// Clase producto de la que herarán Ropa y Accesorios
class Producto {
//Atributos clase Producto
protected:
    string codProducto;     // Clave Primaria
    float precioVenta;
    int cantidad;
    bool disponible;
    Genero genero;
    
public:
    // Constructor clase Producto
    Producto(string cod, float precioV, int cant, Genero gen);
    
    // Destructor virtual para permitir herencia
    virtual ~Producto() = default;
    
    // Getters y Setters
    string getCodProducto() const;
    void setCodProducto(string cod_prod);
    float getPrecioVenta() const;
    void setPrecioVenta(float precio_venta);
    int getCantidad() const;
    void setCantidad(int cant);
    bool isDisponible() const;
    void setDisponible(bool disp);
    Genero getGenero() const;
    void setGenero(Genero gen);
    
    // Métodos de gestión de inventario
    virtual void mostrarInformacion();  // Método virtual
    void venderProducto();
    void aniadirProductoATienda();
    void devolucionProducto();
    void cambioProducto();
};

#endif // PRODUCTO_HPP
