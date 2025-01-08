#include "Menu.hpp"
#include <iostream>

using namespace std;

// Constantes globales específicas del sistema de tiendas.
const string CODIGO_MADRID = "MAD20"; // Código de acceso para la tienda de Madrid.
const string CODIGO_BARCELONA = "BCN22"; // Código de acceso para la tienda de Barcelona.
const int LIMITE_INTENTOS = 3; // Máximo de intentos permitidos al verificar el código de acceso.

void menuConsultaInventario(Inventario& inventario) {
    int opcion;
    do {
        try {
            // Interfaz de usuario para consultar productos por categoría.
            cout << "-------------------------------------\n";
            cout << "CONSULTAR INVENTARIO\n";
            cout << "-------------------------------------\n";
            cout << "1. CONSULTAR INVENTARIO COMPLETO\n";
            cout << "2. CONSULTAR CAMISETAS\n";
            cout << "3. CONSULTAR SUDADERAS\n";
            cout << "4. CONSULTAR PANTALONES\n";
            cout << "5. CONSULTAR GAFAS DE SOL\n";
            cout << "6. CONSULTAR BUFANDAS\n";
            cout << "7. CONSULTAR GORRAS\n";
            cout << "0. VOLVER AL MENÚ PRINCIPAL\n";
            cout << "-------------------------------------\n";
            cout << "¿QUÉ QUIERES HACER? ";
            cin >> opcion;
            cout << "-------------------------------------\n";
            
            // Validar entrada no válida
            if (cin.fail()) {
                cin.clear(); // Limpia el estado de error de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer de entrada
                throw invalid_argument("Error: Entrada no válida. Por favor, introduce un número entre 0 y 7.");
            }
            
            cout << "-------------------------------------\n";
            
            // Manejo de la opción seleccionada por el usuario.
            // métodos para consultar los productos por categoria o todo.
            switch (opcion) {
                case 1:
                    inventario.mostrarInventario();
                    break;
                case 2:
                    inventario.consultarPorCategoria("Camiseta");
                    break;
                case 3:
                    inventario.consultarPorCategoria("Sudadera");
                    break;
                case 4:
                    inventario.consultarPorCategoria("Pantalon");
                    break;
                case 5:
                    inventario.consultarPorCategoria("Gafas de sol");
                    break;
                case 6:
                    inventario.consultarPorCategoria("Bufanda");
                    break;
                case 7:
                    inventario.consultarPorCategoria("Gorra");
                    break;
                case 0:
                    cout << "Volviendo al menú principal...\n";
                    break;
                default:
                    cout << "Opción no válida. Inténtelo de nuevo.\n";
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        } catch (const out_of_range& e) {
            cout << e.what() << endl;
        }
    } while (opcion != 0); // El menú se repite hasta que el usuario elija salir.
}

void menuPrincipal(Tienda& tienda, const Almacen& almacen) {
    int opcion;
    do {
        try {
            // Interfaz de usuario para las gestiones principales.
            cout << "-------------------------------------\n";
            cout << "GESTIONES DEL INVENTARIO - TIENDA " << tienda.getNombre() << "\n";
            cout << "-------------------------------------\n";
            cout << "1. CONSULTAR INVENTARIO\n";
            cout << "2. REGISTRAR VENTA\n";
            cout << "3. AMPLIAR INVENTARIO\n";
            cout << "4. DEVOLUCIONES\n";
            cout << "5. CAMBIOS\n";
            cout << "6. CAMBIAR DE TIENDA\n";
            cout << "0. SALIR\n";
            cout << "-------------------------------------\n";
            cout << "¿QUÉ QUIERES HACER? ";
            cin >> opcion;

            // Validar si la entrada es válida (número entero).
            if (cin.fail()) {
                cin.clear(); // Limpia el estado de error de cin.
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer de entrada.
                throw invalid_argument("Error: Entrada no válida. Por favor, introduce un número entre 0 y 6.");
            }

            cout << "-------------------------------------\n";

            switch (opcion) {
                case 1:
                    // Acceso al submenú de consulta de inventarios.
                    menuConsultaInventario(tienda.getInventario());
                    break;
                case 2:
                    // Registra una venta.
                    tienda.getInventario().registrarVenta(tienda.getNombre());
                    break;
                case 3:
                    // Amplía el inventario desde el almacén.
                    tienda.getInventario().anadirProductoDesdeAlmacen(almacen);
                    break;
                case 4:
                    // Devuelve la cantidad de producto elegida por el cliente.
                    tienda.getInventario().registrarDevolucion(tienda.getNombre());
                    break;
                case 5:
                    // Cambia un producto comprado por el cliente por otro de la tienda.
                    tienda.getInventario().registrarCambio(tienda.getNombre());
                    break;
                case 6:
                    cout << "Saliendo del inventario de " << tienda.getNombre() << endl;
                    tienda.guardarInventario(); // Guardar inventario antes de cambiar de tienda.
                    return; // Volver al menú de tiendas.
                case 0:
                    cout << "Saliendo del sistema de gestión de tiendas" << endl;
                    tienda.guardarInventario(); // Guardar inventario antes de salir.
                    cout << "Cerrando sesión...\n";
                    exit(0); // Terminar el programa.
                default:
                    throw out_of_range("Error: Opción no válida. Introduce un número entre 0 y 6.");
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        } catch (const out_of_range& e) {
            cout << e.what() << endl;
        }
    } while (true);
}

// Verifica un código de acceso para una tienda específica.
bool verificarCodigo(const string& tienda, const string& codigoCorrecto) {
    string codigoIngresado; // Variable para almacenar el código ingresado por el usuario.
    int intentosRestantes = LIMITE_INTENTOS; // Número máximo de intentos permitidos.

    // Ciclo para permitir al usuario ingresar el código hasta que se agoten los intentos.
    while (intentosRestantes > 0) {
        cout << "Ingrese el código de verificación para " << tienda << ": ";
        cin >> codigoIngresado;

        // Comparar el código ingresado con el código correcto.
        if (codigoIngresado == codigoCorrecto) {
            cout << "Código correcto. Accediendo a la tienda " << tienda << ".\n";
            return true; // Acceso autorizado.
        } else {
            intentosRestantes--;  // Reducir el número de intentos restantes.
            cout << "Código incorrecto. Intentos restantes: " << intentosRestantes << "\n";
        }
    }
    // Si se agotan los intentos, bloquear el acceso y finalizar el programa.
    cout << "Demasiados intentos fallidos. Bloqueando el acceso al sistema.\n";
    exit(0); // Terminar el programa después de superar el límite de intentos
}

// Muestra el menú de selección de tiendas y permite navegar entre ellas.
void menuTiendas(Tienda& madrid, Tienda& barcelona, const Almacen& almacen) {
    char opcion; // Almacena la opción seleccionada por el usuario.
    Tienda* tiendaActual = nullptr; // Puntero para referenciar la tienda seleccionada.

    do {
        try {
            // Mostrar las opciones del menú de tiendas.
            cout << "--------------------------------------" << endl;
            cout << "- GESTIÓN INVENTARIO TIENDAS -" << endl;
            cout << "--------------------------------------" << endl;
            cout << "Seleccione una tienda:\n";
            cout << "1. Madrid\n";
            cout << "2. Barcelona\n";
            // otras tiendas que se incorporarán en el futuro
            cout << "3. Salir\n";
            cout << "Ingrese su opción: ";
            cin >> opcion;

            // Validar entrada no válida.
            if (cin.fail()) {
                cin.clear(); // Limpia el estado de error de cin.
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer de entrada.
                throw invalid_argument("Error: Entrada no válida. Por favor, introduce una opción válida (1-3).");
            }

            switch (opcion) {
                case '1': // Selección de la tienda de Madrid.
                    if (verificarCodigo("Madrid", CODIGO_MADRID)) { // Verifica el código de acceso para Madrid.
                        tiendaActual = &madrid; // Establece Madrid como la tienda actual.
                        menuPrincipal(*tiendaActual, almacen); // Llama al menú principal para gestionar la tienda.
                        tiendaActual->guardarInventario(); // Guarda el inventario al regresar del menú principal.
                    }
                    break;

                case '2': // Selección de la tienda de Barcelona.
                    if (verificarCodigo("Barcelona", CODIGO_BARCELONA)) { // Verifica el código de acceso para Barcelona.
                        tiendaActual = &barcelona; // Establece Barcelona como la tienda actual.
                        menuPrincipal(*tiendaActual, almacen); // Llama al menú principal para gestionar la tienda.
                        tiendaActual->guardarInventario(); // Guarda el inventario al regresar del menú principal.
                    }
                    break;
                    
                /*
                case 'x': // Otra ciudad
                if (verificarCodigo(Ciudad, CODIGO_CIUDAD)) {
                    tiendaActual = &ciudad;
                    menuPrincipal(*tiendaActual, almacen);
                    tiendaActual->guardarInventario();
                }
                break;
                     */

                case '3': // Opción para salir del sistema de gestión de tiendas.
                    cout << "Saliendo del sistema de gestión de tiendas.\n";
                    return; // Sale del menú de tiendas.

                default:
                    throw out_of_range("Error: Opción no válida. Introduce un número entre 1 y 3.");
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        } catch (const out_of_range& e) {
            cout << e.what() << endl;
        }
    } while (true);
}


// Inicia el programa principal, configurando las tiendas y el almacén.
void iniciarPrograma() {
    // Crear un objeto `Almacen` que representa el almacén general del sistema.
    Almacen almacen;

    // Crear objetos `Tienda` para Madrid y Barcelona, inicializando con nombres y archivos de inventario.
    Tienda madrid("Madrid", "inventarioMadrid.txt");
    Tienda barcelona("Barcelona", "inventarioBarcelona.txt");
    // creacion de otras ciudades
    // Tienda sevilla, valencia, bilbao...("sevilla, valencia, bilbao", "inventarioSevilla.txt, inventarioValenciaa.txt, inventarioBilbao.txt" )

    // Llamar al menú de tiendas para seleccionar y gestionar una tienda.
    menuTiendas(madrid, barcelona, almacen);
}
