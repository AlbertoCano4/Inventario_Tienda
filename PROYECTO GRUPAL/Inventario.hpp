#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "Producto.hpp"
#include "Warehouse.hpp"
#include "Tienda.hpp" // Incluimos Tienda para poder interactuar con ella
#include <vector>
#include <string>

class Inventario {
private:
    std::vector<std::string> transacciones;  // Almacena cada transacción como una cadena
    std::vector<Producto> productos;         // Almacena objetos de productos

    // Método privado para generar códigos de transacción únicos
    std::string generarCodigoTransaccion(const std::string& codigoProducto);

public:
    // Constructor por defecto
    Inventario();
    void actualizarArchivoInventario(Tienda& tienda);

    // Métodos de consulta
    void consultarInventarioCompleto() const;                // Consultar todo el inventario
    void consultarPorCategoria(const std::string& categoria) const; // Consultar productos por categoría

    // Métodos de gestión de inventario
    void ampliarInventario(const Warehouse& warehouse, Tienda& tienda); // Ampliar inventario y guardar cambios
    void agregarProducto(const Producto& nuevoProducto);                // Añadir un nuevo producto al inventario
    void aniadirStock(const string& codigo, int cantidad, Tienda& tienda);         // Aumentar stock de un producto
    void restarCantidad(const std::string& codigo, int cantidad);       // Reducir stock de un producto
    void realizarCambio();                                              // Realizar un cambio de producto
    void devolucion();                                                  // Registrar una devolución

    // Métodos relacionados con ventas
    void registrarVenta();                                   // Registrar una nueva venta
    void registrarVentaEnArchivo(const std::string& tienda, const std::string& codigoProducto, int cantidad, float precioTotal); // Registrar una venta en el archivo

    // Métodos auxiliares
    void mostrarProductos() const;                          // Mostrar productos del inventario
};

#endif // INVENTARIO_HPP
