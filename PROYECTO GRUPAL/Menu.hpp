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



// Funciones Del MENU
void menuInicioDeSesion(int codigo, const vector<string>& ciudadesDisponibles);
void menuConsultaInventario(const vector<string>& ciudadesDisponibles);
void menuPrincipal(int codigo, const vector<string>& ciudadesDisponibles);
void iniciarPrograma();


#endif
