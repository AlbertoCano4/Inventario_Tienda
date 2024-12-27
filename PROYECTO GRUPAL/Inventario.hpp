#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "Producto.hpp"
#include "Warehouse.hpp"
#include <vector>
#include <string>

class Inventario {
private:
    std::vector<Producto> productos; // Almacena objetos de productos
    string generarCodigoTransaccion(const string& codigoProducto); // Método privado porque cada codigo es privado

public:
    Inventario(); // Constructor por defecto
    void consultarInventarioCompleto() const;
    void consultarPorCategoria(const std::string& categoria) const;
    void ampliarInventario(const Warehouse& warehouse);
    void mostrarProductos() const;
    void registrarVenta();
    void restarCantidad(const string& codigo, int cantidad);
    void aniadirStock(const std::string& codigo, int cantidad);
    void agregarProducto(const Producto& nuevoProducto); // Añadir un nuevo producto
    void registrarVentaEnArchivo(const string& codigoProducto, int cantidad, float precioTotal);
    void realizarCambio();
    
};

#endif // INVENTARIO_HPP
