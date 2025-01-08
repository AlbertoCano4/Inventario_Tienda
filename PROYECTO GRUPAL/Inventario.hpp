#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "Producto.hpp"
#include "Almacen.hpp"
#include "Camiseta.hpp"
#include "Bufanda.hpp"
#include "Pantalon.hpp"
#include "Sudadera.hpp"
#include "Gorra.hpp"
#include "GafasDeSol.hpp"
#include "Definiciones.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>
#include <ctime>

using namespace std;

// Clase que representa el inventario de una tienda.
class Inventario {
private:
    // Vectores para almacenar productos organizados por categoría.
    vector<Camiseta> camisetasEnInventario;
    vector<Sudadera> sudaderasEnInventario;
    vector<Pantalon> pantalonesEnInventario;
    vector<Bufanda> bufandasEnInventario;
    vector<GafasDeSol> gafasDeSolEnInventario;
    vector<Gorra> gorrasEnInventario;
    
public:
    // Constructor por defecto.
    Inventario();
    
    // Añade productos desde el almacén al inventario.
    void anadirProductoDesdeAlmacen(const Almacen& almacen);
    
    // Muestra todos los productos en el inventario.
    void mostrarInventario() const;
    
    // Guarda el estado actual del inventario en un archivo.
    void guardarInventario(const string& archivoNombre) const;
    
    // Carga el inventario desde un archivo.
    void cargarInventario(const string& archivoNombre);
    
    // Consulta productos por categoría y los muestra.
    void consultarPorCategoria(const string& categoria) const;
    
    // Genera un código único para las transacciones.
    string generarCodigoTransaccion(const string& codigoProducto);
    
    // Registra un cambio de producto.
    void registrarCambio(const string& tiendaNombre);
    
    // Registra una devolución de producto.
    void registrarDevolucion(const string& tiendaNombre);
    
    // Registra una venta de producto.
    void registrarVenta(const string& tiendaNombre);
    
private:
    // Procesa la devolución de un producto.
    void procesarDevolucion(Producto& producto, const string& tiendaNombre);
    
    // Registra una devolución en un archivo.
    void registrarDevolucionEnArchivo(const string& tipoOperacion, const string& tienda, const string& codigoProducto, int cantidad, float precioTotal, const string& codigoTransaccion);
    
    // Procesa la venta de un producto.
    void procesarVenta(Producto& producto, const string& tiendaNombre);
    
    // Registra una venta en un archivo.
    void registrarVentaEnArchivo(const string& tipoOperacion, const string& tienda, const string& codigoProducto, int cantidad, float precioTotal, const string& codigoTransaccion);
    
    // Registra un cambio en un archivo.
    void registrarCambioEnArchivo(const string& tienda, const string& codigoProductoSaliente, const string& codigoProductoEntrante, const string& codigoTransaccion);
};

#endif // INVENTARIO_HPP
