#ifndef TIENDA_HPP
#define TIENDA_HPP

#include "Inventario.hpp"
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
    Inventario inventario;
    static const int codigosAcceso[];
    static const string nombresTienda[];

public:
    Tienda();

    // Métodos de gestión
    void seleccionarTienda();                // Seleccionar tienda y validar código
    void cargarInventario();                 // Cargar el inventario de la tienda
    const string& getNombreTienda() const;   // Obtener el nombre de la tienda seleccionada
};

#endif // TIENDA_HPP
