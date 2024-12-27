#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "Producto.hpp"
#include "Warehouse.hpp" // Incluye directamente Warehouse.hpp
#include <vector>
using namespace std;

class Inventario {
private:
    vector<Producto> productos;

public:
    void ampliarInventario(const Warehouse& warehouse);
    void mostrarProductos();
    void venderProducto(const string& codigo, int cantidad);
    void aniadirStock(const string& codigo, int cantidad);
    void devolverProducto(const string& codigo, int cantidad);
};

#endif // INVENTARIO_HPP
