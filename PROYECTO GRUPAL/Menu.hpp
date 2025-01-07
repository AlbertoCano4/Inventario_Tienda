#ifndef MENU_HPP
#define MENU_HPP

#include "Inventario.hpp"
#include "Tienda.hpp"
#include "Almacen.hpp"
#include "Producto.hpp"


// Prototipos de funciones de menú
void menuConsultaInventario(Inventario& inventario);
void menuPrincipal(Tienda& tienda, const Almacen& almacen);
void menuTiendas(Tienda& madrid, Tienda& barcelona, const Almacen& almacen);
void iniciarPrograma();

#endif // MENU_HPP
