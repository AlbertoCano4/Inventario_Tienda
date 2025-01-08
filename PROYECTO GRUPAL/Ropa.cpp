#include "Ropa.hpp"

// Constructor de Ropa
// Llama al constructor de Producto para inicializar los atributos heredados.
// También inicializa el atributo específico talla.
Ropa::Ropa(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t)
    : Producto(tipoProducto, cod, precioV, cant, temp, gen), talla(t) {}

// Función para mostrar la información de la ropa
// Muestra todos los atributos del producto, incluyendo los heredados y los de ropa.
void Ropa::mostrarInformacion() const {
    cout << "Tipo: " << tipo << "\n";
    cout << "Código del Producto: " << codProducto << "\n";
    cout << "Precio de Venta: " << precioVenta << "\n";
    cout << "Cantidad en Inventario: " << cantidad << "\n";
    cout << "Temporada: " << temporadaToString(temporada) << "\n";
    cout << "Género: " << generoToString(genero) << "\n";
    cout << "Talla: " << tallaToString(talla) << "\n";
}

// Getter de Talla
// Devuelve la talla del producto.
Talla Ropa::getTalla() const {
    return talla;
}

// Destructor
// Virtual para asegurar la destrucción de objetos de clases derivadas.
Ropa::~Ropa() {}
