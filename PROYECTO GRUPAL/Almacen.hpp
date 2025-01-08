#ifndef ALMACEN_HPP
#define ALMACEN_HPP

#include "Camiseta.hpp"  // Incluye la definición de la clase Camiseta.
#include "Bufanda.hpp"   // Incluye la definición de la clase Bufanda.
#include "Sudadera.hpp"  // Incluye la definición de la clase Sudadera.
#include "Pantalon.hpp"  // Incluye la definición de la clase Pantalon.
#include "GafasDeSol.hpp" // Incluye la definición de la clase GafasDeSol.
#include "Gorra.hpp"     // Incluye la definición de la clase Gorra.
#include <vector>

using namespace std;

// Clase que representa un almacén con productos disponibles organizados por categorías.
class Almacen {
private:
    // Vectores que almacenan productos de diferentes categorías disponibles en el almacén.
    vector<Camiseta> camisetasDisponibles;      // Lista de camisetas en stock.
    vector<Bufanda> bufandasDisponibles;        // Lista de bufandas en stock.
    vector<Sudadera> sudaderasDisponibles;      // Lista de sudaderas en stock.
    vector<Pantalon> pantalonesDisponibles;     // Lista de pantalones en stock.
    vector<GafasDeSol> gafasDeSolDisponibles;   // Lista de gafas de sol en stock.
    vector<Gorra> gorrasDisponibles;            // Lista de gorras en stock.
    
public:
    // Constructor de la clase Almacen.
    // Inicializa el inventario con datos predeterminados.
    Almacen();
    
    // Métodos para obtener las listas de productos de cada categoría.
    // Devuelven referencias constantes a los vectores, evitando modificaciones externas.
    
    // Devuelve el vector de camisetas disponibles en el almacén.
    const vector<Camiseta>& getCamisetas() const;
    
    // Devuelve el vector de bufandas disponibles en el almacén.
    const vector<Bufanda>& getBufandas() const;
    
    // Devuelve el vector de sudaderas disponibles en el almacén.
    const vector<Sudadera>& getSudaderas() const;
    
    // Devuelve el vector de pantalones disponibles en el almacén.
    const vector<Pantalon>& getPantalones() const;
    
    // Devuelve el vector de gafas de sol disponibles en el almacén.
    const vector<GafasDeSol>& getGafasDeSol() const;
    
    // Devuelve el vector de gorras disponibles en el almacén.
    const vector<Gorra>& getGorras() const;
};

#endif
