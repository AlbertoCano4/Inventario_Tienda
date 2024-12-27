#include "Producto.hpp"

// Constructor
Producto::Producto(string tipoProducto, string cod, float precioV, int cant, Temporada temp, Genero gen)
    : tipo(tipoProducto), codProducto(cod), precioVenta(precioV), cantidad(cant), temporada(temp), genero(gen) {}

// Getter para el tipo
string Producto::getTipoProducto() const {
    return tipo;
}

// Getters y Setters
string Producto::getCodProducto() const {
    return codProducto;
}

void Producto::setCodProducto(const string& cod_prod) {
    codProducto = cod_prod;
}

float Producto::getPrecioVenta() const {
    return precioVenta;
}

void Producto::setPrecioVenta(float precio_venta) {
    precioVenta = precio_venta;
}

int Producto::getCantidad() const {
    return cantidad;
}

void Producto::setCantidad(int cant) {
    cantidad = cant;
}

Genero Producto::getGenero() const {
    return genero;
}

void Producto::setGenero(Genero gen) {
    genero = gen;
}

Temporada Producto::getTemporada() const {
    return temporada;
}

void Producto::setTemporada(Temporada temp) {
    temporada = temp;
}

// Método mostrarInformacion
void Producto::mostrarInformacion() const {
    cout << "Tipo: " << tipo << endl;
    cout << "Código del Producto: " << codProducto << endl;
    cout << "Precio de Venta: " << precioVenta << endl;
    cout << "Cantidad en Inventario: " << cantidad << endl;
    cout << "Temporada: " << (temporada == Temporada::INVIERNO ? "Invierno" : (temporada == Temporada::VERANO ? "Verano" : "Anual")) << endl;
    cout << "Género: " << (genero == Genero::MUJER ? "Mujer" : "Hombre") << endl;
}

// Métodos de gestión de inventario
void Producto::venderProducto(int cantidadVendida) {
    if (cantidadVendida > cantidad) {
        cout << "No hay suficiente stock disponible para vender." << endl;
    } else {
        cantidad -= cantidadVendida;
        cout << "Se han vendido " << cantidadVendida << " unidades. Stock restante: " << cantidad << "." << endl;
    }
}

void Producto::aniadirProductoATienda(int cantidadAnadida) {
    cantidad += cantidadAnadida;
    cout << "Se han añadido " << cantidadAnadida << " unidades al inventario. Stock actual: " << cantidad << "." << endl;
}

void Producto::devolucionProducto(int cantidadDevuelta) {
    cantidad += cantidadDevuelta;
    cout << "Se han devuelto " << cantidadDevuelta << " unidades. Stock actual: " << cantidad << "." << endl;
}
