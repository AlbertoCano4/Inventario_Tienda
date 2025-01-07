#include "Menu.hpp"
#include <iostream>

using namespace std;

void menuConsultaInventario(Inventario& inventario) {
    int opcion;
    do {
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
    } while (opcion != 0);
}

void menuPrincipal(Tienda& tienda, const Almacen& almacen) {
    int opcion;
    do {
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
        cout << "-------------------------------------\n";

        switch (opcion) {
            case 1:
                menuConsultaInventario(tienda.getInventario());
                break;
            case 2:
                tienda.getInventario().registrarVenta(tienda.getNombre());
                break;
            case 3:
                tienda.getInventario().anadirProductoDesdeAlmacen(almacen);
                break;
            case 4:
                tienda.getInventario().registrarDevolucion(tienda.getNombre());
                break;
            case 5:
                tienda.getInventario().registrarCambio(tienda.getNombre());
                break;
            case 6:
                cout << "Saliendo del inventario de " << tienda.getNombre() << endl;
                return; // Volver al menú de tiendas
            case 0:
                cout << "Saliendo del sistema de gestión de tiendas" << endl;
                cout << "Cerrando sesión...\n";
                exit(0); // Terminar el programa
            default:
                cout << "Opción no válida. Inténtelo de nuevo.\n";
        }
    } while (true);
}

void menuTiendas(Tienda& madrid, Tienda& barcelona, const Almacen& almacen) {
    char opcion;
    string codigoVerificacion;
    Tienda* tiendaActual = nullptr;

    do {
        cout << "--------------------------------------" << endl;
        cout << "- GESTIÓN INVENTARIO TIENDAS -" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Seleccione una tienda:\n";
        cout << "1. Madrid\n";
        cout << "2. Barcelona\n";
        cout << "3. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1': // Madrid
                cout << "Ingrese el código de verificación para Madrid: ";
                cin >> codigoVerificacion;
                if (codigoVerificacion == "MAD20") {
                    tiendaActual = &madrid;
                    menuPrincipal(*tiendaActual, almacen);
                    tiendaActual->guardarInventario();
                } else {
                    cout << "Código de verificación incorrecto. Inténtelo de nuevo.\n";
                }
                break;

            case '2': // Barcelona
                cout << "Ingrese el código de verificación para Barcelona: ";
                cin >> codigoVerificacion;
                if (codigoVerificacion == "BCN22") {
                    tiendaActual = &barcelona;
                    menuPrincipal(*tiendaActual, almacen);
                    tiendaActual->guardarInventario();
                } else {
                    cout << "Código de verificación incorrecto. Inténtelo de nuevo.\n";
                }
                break;

            case '3': // Salir
                cout << "Saliendo del sistema de gestión de tiendas.\n";
                return;

            default:
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }

    } while (true);
}

void iniciarPrograma() {
    // Crear el almacén
    Almacen almacen;

    // Crear las tiendas
    Tienda madrid("Madrid", "inventarioMadrid.txt");
    Tienda barcelona("Barcelona", "inventarioBarcelona.txt");
    //Tienda Valencia("Valencia", "inventarioValencia.txt");
    //Tienda Sevilla("Sevilla", "inventarioSevilla.txt");
    //Tienda Bilbao("Bilbao", "inventarioBilbao.txt");

    // Mostrar el menú principal de tiendas
    menuTiendas(madrid, barcelona, almacen);
}
