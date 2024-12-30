#include "Menu.hpp"
#include <iostream>

void iniciarPrograma() {
    Tienda tienda;
    Warehouse warehouse;
    Inventario inventario;

    cout << "--------------------------------------" << endl;
    cout << "- BIENVENIDO AL INVENTARIO DE XXXXXXXX -" << endl;
    cout << "--------------------------------------" << endl;
    // Selección inicial de tienda
    tienda.seleccionarTienda();

    // Entrar al menú principal
    menuPrincipal(tienda, warehouse, inventario);
}

void menuConsultaInventario(Inventario& inventario) {
    int opcion;
    do {
        cout << "-------------------------------------" << endl;
        cout << "CONSULTAR INVENTARIO" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. CONSULTAR INVENTARIO COMPLETO" << endl;
        cout << "2. CONSULTAR CAMISETAS" << endl;
        cout << "3. CONSULTAR SUDADERAS" << endl;
        cout << "4. CONSULTAR PANTALONES" << endl;
        cout << "5. CONSULTAR GAFAS DE SOL" << endl;
        cout << "6. CONSULTAR BUFANDAS" << endl;
        cout << "7. CONSULTAR GORRA" << endl;
        cout << "0. VOLVER AL MENÚ PRINCIPAL" << endl;
        cout << "-------------------------------------" << endl;
        cout << "¿QUÉ QUIERES HACER? ";
        cin >> opcion;
        cout << "-------------------------------------" << endl;

        switch (opcion) {
            case 1:
                inventario.consultarInventarioCompleto();
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
                cout << "Volviendo al menú principal..." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != 0);
}

void menuPrincipal(Tienda& tienda, Warehouse& warehouse, Inventario& inventario) {
    int opcion;

    do {
        cout << "-------------------------------------" << endl;
        cout << "GESTIONES DEL INVENTARIO - TIENDA " << tienda.getNombreTienda() << endl;
        cout << "-------------------------------------" << endl;
        cout << "POSIBLES OPCIONES:" << endl;
        cout << "1. CONSULTAR INVENTARIO" << endl;
        cout << "2. REGISTRAR VENTA" << endl;
        cout << "3. AMPLIAR INVENTARIO" << endl;
        cout << "4. DEVOLUCIONES" << endl;
        cout << "5. CAMBIOS" << endl;
        cout << "6. CAMBIAR DE TIENDA" << endl;
        cout << "0. CERRAR SESIÓN" << endl;
        cout << "-------------------------------------" << endl;
        cout << "¿QUÉ QUIERES HACER? ";
        cin >> opcion;
        cout << "-------------------------------------" << endl;

        switch (opcion) {
            case 1:
                menuConsultaInventario(inventario);
                break;
            case 2:
                inventario.registrarVenta();
                break;
            case 3:
                inventario.ampliarInventario(warehouse);
                break;
            case 4:
                inventario.devolucion();
                break;
            case 5:
                inventario.realizarCambio();
                break;
            case 6:
                cout << "Cambiando de tienda..." << endl;
                tienda.seleccionarTienda(); // Volver a seleccionar la tienda
                // inventario = Inventario();  // Reiniciar el inventario
                // tienda.cargarInventario();  // Cargar el inventario de la
                break;
            case 0:
                cout << "Cerrando sesión..." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != 0);
}
