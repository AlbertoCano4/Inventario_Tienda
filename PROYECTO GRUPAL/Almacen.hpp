#ifndef ALMACEN_HPP
#define ALMACEN_HPP

#include "Producto.hpp"
#include "Camiseta.hpp"
#include "Bufanda.hpp"
#include "Pantalon.hpp"
#include "Sudadera.hpp"
#include "Gorra.hpp"
#include "GafasDeSol.hpp"
#include <vector>
using namespace std;

class Almacen {
private:
    vector<Camiseta> camisetasDisponibles;
    vector<Bufanda> bufandasDisponibles;
    vector<Sudadera> sudaderasDisponibles;
    vector<Pantalon> pantalonesDisponibles;
    vector<GafasDeSol> gafasDeSolDisponibles;
    vector<Gorra> gorrasDisponibles;

public:
    Almacen();

    const vector<Camiseta>& getCamisetas() const;
    const vector<Bufanda>& getBufandas() const;
    const vector<Sudadera>& getSudaderas() const;
    const vector<Pantalon>& getPantalones() const;
    const vector<GafasDeSol>& getGafasDeSol() const;
    const vector<Gorra>& getGorras() const;
};

#endif // ALMACEN_HPP
