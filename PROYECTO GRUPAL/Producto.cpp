#include "producto.hpp"
#include <iostream>

using namespace std;

// Constructor
Producto::Producto(string cod, float precioV, int cant, Genero gen)
    : codProducto(cod), precioVenta(precioV), cantidad(cant), disponible(cant > 0), genero(gen) {}

// Implementación de la función virtual mostrarInformacion
void Producto::mostrarInformacion() {
    cout << "Código de Producto: " << codProducto << endl;
    cout << "Precio de Venta: " << precioVenta << "€" << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Disponible: " << (disponible ? "Sí" : "No") << endl;
    cout << "Género: " << (genero == Genero::MUJER ? "Mujer" : "Hombre") << endl;
}

// Implementación de Getters y Setters
string Producto::getCodProducto() const {
    return codProducto;
}

void Producto::setCodProducto(string cod_prod) {
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

bool Producto::isDisponible() const {
    return disponible;
}

void Producto::setDisponible(bool disp) {
    disponible = disp;
}

Genero Producto::getGenero() const {
    return genero;
}

void Producto::setGenero(Genero gen) {
    genero = gen;
}

// Implementación de métodos de gestión de inventario
void Producto::venderProducto() {
    string codProductoVendido;
    int q;
    
    do {
        cout << "INTRODUZCA EL CÓDIGO DEL PRODUCTO QUE QUIERA VENDER: ";
        cin >> codProductoVendido;
        
        if (codProductoVendido != codProducto) {
            cout << "Ese producto NO EXISTE, vuelva a introducir un código correcto" << endl;
        }
    } while(codProductoVendido != codProducto);
    
    cout << "El Producto que quieres vender es este:" << endl;
    mostrarInformacion();
    
    cout << "Quedan " << cantidad << " Unidades de ese producto" << endl;
    cout << "¿Cuánta cantidad de ese producto quieres vender?: ";
    cin >> q;
    
    if (q <= cantidad) {
        cantidad -= q;
        disponible = (cantidad > 0);
    } else {
        cout << "No hay suficiente stock disponible." << endl;
    }
}

void Producto::aniadirProductoATienda() {
    string codProductoComprado;
    int q;
    
    do {
        cout << "INTRODUZCA EL CÓDIGO DEL PRODUCTO QUE QUIERA AÑADIR A TIENDA: ";
        cin >> codProductoComprado;
        
        if (codProductoComprado != codProducto) {
            cout << "Ese producto NO EXISTE, vuelva a introducir un código correcto" << endl;
        }
    } while(codProductoComprado != codProducto);
    
    cout << "El Producto que quieres añadir es este: " << endl;
    mostrarInformacion();
    
    cout << "Quedan " << cantidad << " Unidades de ese producto" << endl;
    cout << "¿Cuánta cantidad de ese producto quieres añadir al almacen?: ";
    cin >> q;
    
    cantidad += q;
    disponible = true;
}

void Producto::devolucionProducto() {
    string codProductoDevuelto;
    int q;
    
    do {
        cout << "INTRODUZCA EL CÓDIGO DEL PRODUCTO QUE QUIERA DEVOLVER A TIENDA: ";
        cin >> codProductoDevuelto;
        
        if (codProductoDevuelto != codProducto) {
            cout << "Ese producto NO EXISTE, vuelva a introducir un código correcto" << endl;
        }
    } while(codProductoDevuelto != codProducto);
    
    cout << "El Producto que quieres devolver es este: " << endl;
    mostrarInformacion();
    
    cout << "¿Cuánta cantidad de ese producto quieres añadir al almacen?: ";
    cin >> q;
    
    cantidad += q;
    disponible = true;
}

void Producto::cambioProducto() {
    string codProductoDevuelto;
    
    do {
        cout << "INTRODUZCA EL CÓDIGO DEL PRODUCTO QUE QUIERA CAMBIAR A TIENDA: ";
        cin >> codProductoDevuelto;
        
        if (codProductoDevuelto != codProducto) {
            cout << "Ese producto NO EXISTE, vuelva a introducir un código correcto" << endl;
        }
    } while(codProductoDevuelto != codProducto);
    
    cout << "El Producto que quieres cambiar es este: " << endl;
    mostrarInformacion();
    
    // Aquí se implementaría la lógica para mostrar productos del mismo precio
    // y realizar el cambio
}
