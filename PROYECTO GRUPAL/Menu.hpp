#ifndef MENU_HPP
#define MENU_HPP

// Inclusión de los módulos necesarios para la gestión del inventario y las tiendas.
#include "Inventario.hpp"
#include "Tienda.hpp"
#include "Almacen.hpp"
#include "Producto.hpp"


// Declaración de las funciones relacionadas con los menús.

// Menú para consultar categorías de productos en el inventario.
void menuConsultaInventario(Inventario& inventario);
// Menú principal de una tienda específica.
void menuPrincipal(Tienda& tienda, const Almacen& almacen);
// Menú para seleccionar entre las tiendas disponibles.
void menuTiendas(Tienda& madrid, Tienda& barcelona, const Almacen& almacen);
// Punto de entrada principal del programa.
void iniciarPrograma();

#endif 
