#include "Tienda.hpp"

// Constructor de la clase Tienda.
// Inicializa una tienda con su nombre y el archivo asociado a su inventario.
// Carga automáticamente el inventario desde el archivo especificado.
Tienda::Tienda(const string& nombreTienda, const string& archivo)
    : nombre(nombreTienda), archivoInventario(archivo) {
    inventario.cargarInventario(archivoInventario); // Carga los datos del inventario desde el archivo.
}

// Permite acceder y modificar el inventario desde otros módulos.
Inventario& Tienda::getInventario() {
    return inventario;
}

// Guarda el inventario actual de la tienda en su archivo asociado.
// Este método asegura que los cambios en el inventario se persistan.
void Tienda::guardarInventario() const {
    inventario.guardarInventario(archivoInventario); // Escribe el inventario en el archivo.
}

// Recarga el inventario desde el archivo asociado.
// Esto sincroniza el estado del inventario con su archivo.
void Tienda::cargarInventario() {
    inventario.cargarInventario(archivoInventario);
}

// Getter que devuelve el nombre de la tienda.
string Tienda::getNombre() const {
    return nombre;
}
