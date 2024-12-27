#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "Producto.hpp"
#include "Warehouse.hpp"
#include <vector>
#include <string>

class Inventario {
private:
    std::vector<Producto> productos; // Almacena objetos de productos

public:
    Inventario(); // Constructor por defecto
    void consultarInventarioCompleto() const;
    void consultarPorCategoria(const std::string& categoria) const;
    void ampliarInventario(const Warehouse& warehouse);
    void mostrarProductos() const;
    void venderProducto(const std::string& codigo, int cantidad);
    void aniadirStock(const std::string& codigo, int cantidad);
    void agregarProducto(const Producto& nuevoProducto); // Añadir un nuevo producto
};

#endif // INVENTARIO_HPP
