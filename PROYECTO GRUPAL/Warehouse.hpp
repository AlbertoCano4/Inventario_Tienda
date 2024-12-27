#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include "Producto.hpp"
#include <vector>
using namespace std;

class Warehouse {
private:
    vector<Producto> productos; // Lista de productos disponibles en el almacén
    
public:
    Warehouse();
    void mostrarProductos() const;
    Producto& seleccionarProducto(size_t indice);
    size_t getCantidadProductos() const;
    vector<Producto> obtenerProductosPorTipo(const string& tipo) const; // Filtra productos por tipo
};

#endif // WAREHOUSE_HPP
