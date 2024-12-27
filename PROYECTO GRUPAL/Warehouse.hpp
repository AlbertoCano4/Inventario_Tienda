#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include "Producto.hpp"
#include <vector>
#include <string>

class Warehouse {
private:
    std::vector<Producto> productos;

public:
    Warehouse();
    void mostrarProductos() const;
    std::vector<Producto> obtenerProductosPorTipo(const std::string& tipo) const;
};

#endif // WAREHOUSE_HPP
