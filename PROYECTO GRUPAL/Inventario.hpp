#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "Producto.hpp"
#include "Warehouse.hpp"
#include <vector>
#include <string>

class Inventario {
private:
    vector<string> transacciones;  // Almacena cada transacción como una cadena
    std::vector<Producto> productos; // Almacena objetos de productos

    // Método privado para generar códigos de transacción únicos
    std::string generarCodigoTransaccion(const std::string& codigoProducto);

public:
    // Constructor por defecto
    Inventario();

    // Métodos de consulta
    void consultarInventarioCompleto() const;                // Consultar todo el inventario
    void consultarPorCategoria(const std::string& categoria) const; // Consultar productos por categoría

    // Métodos de gestión de inventario
    void ampliarInventario(const Warehouse& warehouse);      // Añadir productos desde el almacén
    void agregarProducto(const Producto& nuevoProducto);     // Añadir un nuevo producto al inventario
    void aniadirStock(const std::string& codigo, int cantidad); // Aumentar stock de un producto
    void restarCantidad(const std::string& codigo, int cantidad); // Reducir stock de un producto
    void realizarCambio();
    void devolucion();

    // Métodos relacionados con ventas
    void registrarVenta();                                   // Registrar una nueva venta
    void registrarVentaEnArchivo(const std::string& tienda, const std::string& codigoProducto, int cantidad, float precioTotal); // Registrar una venta en el archivo de transacciones

    // Métodos auxiliares
    void mostrarProductos() const;                          // Mostrar productos del inventario
};

#endif // INVENTARIO_HPP
