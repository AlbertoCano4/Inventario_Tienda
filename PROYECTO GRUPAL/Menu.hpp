#ifndef MENU_HPP
#define MENU_HPP

using namespace std;

#include <vector>
#include <string>

// Funciones Del MENU
void menuInicioDeSesion(int codigo, const vector<string>& ciudadesDisponibles);
void menuConsultaInventario(const vector<string>& ciudadesDisponibles);
void menuPrincipal(int codigo, const vector<string>& ciudadesDisponibles);
void iniciarPrograma();


#endif
