#ifndef TIENDA_HPP
#define TIENDA_HPP

#include "Inventario.hpp" // Incluye la clase Inventario, que gestiona los productos de la tienda.
#include <string>

using namespace std;

// Declaración de la clase Tienda, que representa una tienda con su inventario asociado.
class Tienda {
private:
    string nombre; // Nombre de la tienda.
    string archivoInventario; // Ruta del archivo donde se guarda el inventario.
    Inventario inventario; // Objeto que gestiona los productos del inventario de la tienda.

public:
    
    // Constructor: Inicializa el nombre de la tienda y su archivo de inventario.
    // También carga automáticamente los datos del inventario desde el archivo.
    Tienda(const string& nombreTienda, const string& archivo);
    
    // Permite acceder y modificar los datos del inventario.
    Inventario& getInventario();

    // Asegura que los cambios en el inventario persistan en el sistema.
    void guardarInventario() const;

    // Sobrescribe el estado actual del inventario en memoria.
    void cargarInventario();

    // Devuelve el nombre de la tienda como una cadena de texto.
    string getNombre() const;
};

#endif 
