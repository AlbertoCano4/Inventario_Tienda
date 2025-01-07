#ifndef TIENDA_HPP
#define TIENDA_HPP

#include "Inventario.hpp"
#include <string>

using namespace std;

class Tienda {
private:
    string nombre;
    Inventario inventario;
    string archivoInventario;

public:
    Tienda(const string& nombreTienda, const string& archivo);

    Inventario& getInventario();

    void guardarInventario() const;

    void cargarInventario();

    string getNombre() const;
};

#endif // TIENDA_HPP
