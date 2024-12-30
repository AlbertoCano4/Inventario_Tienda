#ifndef MENU_HPP
#define MENU_HPP

using namespace std;

#include <vector>
#include <string>

#include "Producto.hpp"
#include "Ropa.hpp"
#include "camiseta.hpp"
#include "sudadera.hpp"
#include "pantalon.hpp"
#include "accesorio.hpp"
#include "gorra.hpp"
#include "gafasdesol.hpp"
#include "bufanda.hpp"
#include "Inventario.hpp"
#include "Warehouse.hpp"
#include "Tienda.hpp"



// Funciones Del MENU
void menuConsultaInventario(const vector<string>& ciudadesDisponibles);
void menuPrincipal(Tienda& tienda, Warehouse& warehouse, Inventario& inventario);
void iniciarPrograma();


#endif
