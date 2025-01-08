#include "Almacen.hpp"

// Constructor de la clase `Almacen`.
// Inicializa el inventario del almacén con productos predefinidos de diferentes categorías.
Almacen::Almacen() {
        // Camisetas disponibles para agrear.
        camisetasDisponibles.push_back(Camiseta("C001", 29.99, 50, Temporada::VERANO, Genero::HOMBRE, Talla::M, TipoCamiseta::MANGA_CORTA, "Algodón", true));
        camisetasDisponibles.push_back(Camiseta("C002", 35.50, 30, Temporada::INVIERNO, Genero::MUJER, Talla::L, TipoCamiseta::MANGA_LARGA, "Poliéster", false));
        
        // Bufandas disponibles para agrear.
        bufandasDisponibles.push_back(Bufanda("B001", 12.00, 50, Temporada::INVIERNO, Genero::HOMBRE, Estilo::CLASICO, true));
        bufandasDisponibles.push_back(Bufanda("B002", 8.00, 40, Temporada::INVIERNO, Genero::MUJER, Estilo::CASUAL, false));
        bufandasDisponibles.push_back(Bufanda("B003", 16.00, 40, Temporada::ANUAL, Genero::MUJER, Estilo::DEPORTIVO, true));

        // Sudaderas disponibles para agrear.
        sudaderasDisponibles.push_back(Sudadera("S001", 45.99, 20, Temporada::INVIERNO, Genero::HOMBRE, Talla::L, TipoSudadera::CREWNECK, "Algodón", true));
        sudaderasDisponibles.push_back(Sudadera("S002", 40.50, 15, Temporada::VERANO, Genero::MUJER, Talla::M, TipoSudadera::HOODIE, "Poliéster", false));
        // Pantalones disponibles para agrear.
        pantalonesDisponibles.push_back(Pantalon("P001", 39.99, 25, Temporada::ANUAL, Genero::HOMBRE, Talla::L, TipoPantalon::LARGO, false));
        pantalonesDisponibles.push_back(Pantalon("P002", 49.99, 15, Temporada::INVIERNO, Genero::MUJER, Talla::M, TipoPantalon::CORTO, false));
        // Ejemplos de Gafas de Sol para agrear.
        gafasDeSolDisponibles.push_back(GafasDeSol("G001", 79.99, 30, Temporada::VERANO, Genero::HOMBRE, Estilo::MODERNO, "Cuadrada", true));
        gafasDeSolDisponibles.push_back(GafasDeSol("G002", 59.99, 25, Temporada::ANUAL, Genero::MUJER, Estilo::CLASICO, "Redonda", false));
        
        // Ejemplos de Gorras para agrear.
        gorrasDisponibles.push_back(Gorra("GR001", 19.99, 50, Temporada::VERANO, Genero::HOMBRE, Estilo::CASUAL, "Snapback", "Algodón"));
        gorrasDisponibles.push_back(Gorra("GR002", 24.99, 40, Temporada::VERANO, Genero::MUJER, Estilo::DEPORTIVO, "Visera", "Poliéster"));
    }

    // Devuelve el vector de camisetas disponibles en el almacén.
    const vector<Camiseta>& Almacen::getCamisetas() const { return camisetasDisponibles; }
    // Devuelve el vector de bufandas disponibles en el almacén.
    const vector<Bufanda>& Almacen::getBufandas() const { return bufandasDisponibles; }
    // Devuelve el vector de sudaderas disponibles en el almacén.
    const vector<Sudadera>& Almacen::getSudaderas() const { return sudaderasDisponibles; }
    // Devuelve el vector de pantalones disponibles en el almacén.
    const vector<Pantalon>& Almacen::getPantalones() const { return pantalonesDisponibles; }
    // Devuelve el vector de gafas de sol disponibles en el almacén.
    const vector<GafasDeSol>& Almacen::getGafasDeSol() const { return gafasDeSolDisponibles; }
    // Devuelve el vector de gorras disponibles en el almacén.
    const vector<Gorra>& Almacen::getGorras() const { return gorrasDisponibles; }
