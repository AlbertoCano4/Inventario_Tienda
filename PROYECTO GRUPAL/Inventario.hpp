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

class Inventario {
private:
    vector<Camiseta> camisetasEnInventario;
    vector<Sudadera> sudaderasEnInventario;
    vector<Pantalon> pantalonesEnInventario;
    vector<Bufanda> bufandasEnInventario;
    vector<GafasDeSol> gafasDeSolEnInventario;
    vector<Gorra> gorrasEnInventario;

public:
    Inventario();

    void anadirProductoDesdeAlmacen(const Almacen& almacen);

    void mostrarInventario() const;

    void guardarInventario(const string& archivoNombre) const;

    void cargarInventario(const string& archivoNombre);

    void consultarPorCategoria(const string& categoria) const;

    string generarCodigoTransaccion(const string& codigoProducto);

    void registrarCambio(const string& tiendaNombre);

    void registrarDevolucion(const string& tiendaNombre);

    void registrarVenta(const string& tiendaNombre);

private:
    void procesarDevolucion(Producto& producto, const string& tiendaNombre);

    void registrarDevolucionEnArchivo(const string& tipoOperacion, const string& tienda, const string& codigoProducto,
                                      int cantidad, float precioTotal, const string& codigoTransaccion);

    void procesarVenta(Producto& producto, const string& tiendaNombre);

    void registrarVentaEnArchivo(const string& tipoOperacion, const string& tienda, const string& codigoProducto,
                                 int cantidad, float precioTotal, const string& codigoTransaccion);

    void registrarCambioEnArchivo(const string& tienda, const string& codigoProductoSaliente,
                                   const string& codigoProductoEntrante, const string& codigoTransaccion);
};

#endif // INVENTARIO_HPP
