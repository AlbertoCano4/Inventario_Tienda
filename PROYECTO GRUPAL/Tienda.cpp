#include "Tienda.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Inicializar los códigos de acceso para cada tienda
const int Tienda::codigosAcceso[] = {1234, 2345, 3456, 4567, 5678};

// Inicializar los nombres de las tiendas
const string Tienda::nombresTienda[] = {"Madrid", "Barcelona", "Valencia", "Sevilla", "Bilbao"};

// Constructor
Tienda::Tienda() : tiendaSeleccionada(TiendaEnum::None) {}

// Seleccionar tienda y validar código
void Tienda::seleccionarTienda() {
    while (true) {
        string entrada;
        cout << "¿Al inventario de qué tienda quieres acceder?: ";
        cin >> entrada;

        // Formatear la entrada a "Primera Letra Mayúscula"
        for (size_t i = 0; i < entrada.length(); ++i) {
            entrada[i] = (i == 0) ? toupper(entrada[i]) : tolower(entrada[i]);
        }

        // Verificar si la entrada coincide con alguna tienda
        int indice = -1;
        for (int i = 0; i < 5; ++i) {
            if (entrada == nombresTienda[i]) {
                tiendaSeleccionada = static_cast<TiendaEnum>(i);
                indice = i;
                break;
            }
        }

        if (indice == -1) {
            cout << "La tienda \"" << entrada << "\" no existe. Inténtalo de nuevo." << endl;
            continue;
        }

        // Solicitar el código de acceso
        while (true) {
            int codigoIngresado;
            cout << "Introduce el código de acceso para la tienda " << nombresTienda[indice] << ": ";
            cin >> codigoIngresado;

            if (codigoIngresado == codigosAcceso[indice]) {
                //cargarInventario(); // Cargar el inventario después de validar el código
                return;             // Salir del método una vez que todo esté correcto
            } else {
                cout << "Código incorrecto." << endl;
                cout << "1. Intentar de nuevo\n2. Cambiar de tienda\n3. Salir del programa" << endl;
                int opcion;
                cin >> opcion;

                if (opcion == 2) {
                    break; // Rompe el bucle del código y regresa al menú de selección de tienda
                } else if (opcion == 3) {
                    cout << "Saliendo del programa..." << endl;
                    exit(0);
                }
            }
        }
    }
}

// Obtener el nombre de la tienda seleccionada
const string& Tienda::getNombreTienda() const {
    if (tiendaSeleccionada == TiendaEnum::None) {
        static const string sinTienda = "Ninguna";
        return sinTienda;
    }
    return nombresTienda[static_cast<int>(tiendaSeleccionada)];
}

/*
void Tienda::cargarInventario() {
    if (tiendaSeleccionada == TiendaEnum::None) {
        cout << "No se ha seleccionado ninguna tienda. Por favor, selecciona una tienda primero." << endl;
        return;
    }

    ifstream archivo; // Declarar variable de tipo archivo para lectura
    string archivoInventario = "Inventario" + getNombreTienda() + ".txt";
    archivo.open(archivoInventario); // Abrir el archivo

    if (archivo.is_open()) {
        
        for(Inventario : inventario){
            
        }

        cout << "Datos cargados desde " << archivoInventario << " correctamente." << endl;
    } else {
        cout << "El archivo " << archivoInventario << " no se ha podido abrir." << endl;
    }

    archivo.close(); // Cerrar el archivo
}

void Tienda::actualizarInventario() {
    if (tiendaSeleccionada == TiendaEnum::None) {
        cout << "No se ha seleccionado ninguna tienda. Por favor, selecciona una tienda primero." << endl;
        return;
    }

    ofstream archivo; // Declarar variable de tipo archivo para escritura
    string archivoInventario = "Inventario" + getNombreTienda() + ".txt";
    archivo.open(archivoInventario); // Abrir el archivo

    if (archivo.is_open()) {
        const vector<Producto>& productos = inventario.getProductos(); // Obtener los productos del inventario

        for (const auto& producto : productos) {
            archivo << producto.id << ','
                    << producto.nombre << ','
                    << producto.cantidad << ','
                    << producto.precio << endl;
        }

        cout << "Datos guardados en " << archivoInventario << " correctamente." << endl;
    } else {
        cout << "El archivo " << archivoInventario << " no se ha podido abrir." << endl;
    }

    archivo.close(); // Cerrar el archivo
}
*/
