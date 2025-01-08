#include "Accesorio.hpp"

// Constructor
// Llama al constructor de la clase base Producto para inicializar los atributos comunes.
// También inicializa el atributo específico estilo.
Accesorio::Accesorio(string tipoProducto, string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est)
    : Producto(tipoProducto, cod, precioV, cant, temp, gen), estilo(est) {}

// Implementación del método mostrarInformacion
// Muestra todos los detalles del accesorio, incluidos producto.
void Accesorio::mostrarInformacion() const {
    cout << "Tipo: " << tipo << "\n";
    cout << "Código del Producto: " << codProducto << "\n";
    cout << "Precio de Venta: " << precioVenta << "\n";
    cout << "Cantidad en Inventario: " << cantidad << "\n";
    cout << "Temporada: " << temporadaToString(temporada) << "\n";
    cout << "Género: " << generoToString(genero) << "\n";
    cout << "Estilo: " << estiloTostring(estilo) << endl;
}

// Getter de Estilo, devuelve el estilo del accesorio.
Estilo Accesorio::getEstilo() const {
    return estilo;
}

// Setter de Estilo, modifica el estilo del accesorio.
void Accesorio::setEstilo(Estilo est) {
    estilo = est;
}

// Destructor
// Virtual para garantizar la destrucción de objetos de clases derivadas.
Accesorio::~Accesorio() {}
