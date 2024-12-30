#ifndef TIENDA_HPP
#define TIENDA_HPP

#include "Producto.hpp"
#include "Camiseta.hpp"
#include "Bufanda.hpp"
#include "Pantalon.hpp"
#include "sudadera.hpp"
#include "gorra.hpp"
#include "gafasdesol.hpp"

#include <vector>
#include <string>

enum class TiendaEnum {
    Madrid,
    Barcelona,
    Valencia,
    Sevilla,
    Bilbao,
    None
};

class Tienda {
private:
    TiendaEnum tiendaSeleccionada;
    std::vector<Producto> inventario; // Vector de productos como inventario
    static const int codigosAcceso[];
    static const std::string nombresTienda[];

public:
    Tienda();

    // Métodos de gestión
    void seleccionarTienda();                // Seleccionar tienda y validar código
    const std::string& getNombreTienda() const; // Obtener el nombre de la tienda seleccionada

    // Métodos para gestionar el inventario
    void cargarInventario();                 // Cargar inventario desde un archivo
    void guardarInventario();                // Guardar inventario en un archivo
    void mostrarInventario() const;          // Mostrar el inventario completo

    // Métodos auxiliares
    std::vector<Producto>& getInventario();  // Obtener referencia al inventario
};

#endif // TIENDA_HPP
