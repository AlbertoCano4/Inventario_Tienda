#include "Menu.hpp"
#include <iostream>
#include <cctype>

void iniciarPrograma(){
    int codigo = 1234567890; // Código correcto
    vector<string> ciudades = {"Madrid", "Barcelona", "Valencia", "Sevilla", "Bilbao"}; // Lista de ciudades disponibles
    
    Warehouse warehouse;
    Inventario inventario;
        
    menuInicioDeSesion(codigo, ciudades);
    menuPrincipal(codigo, ciudades, warehouse, inventario);
}

void menuInicioDeSesion(int codigo, const vector<string>& ciudadesDisponibles){
    
    int codigo2;
    string ciudadIntroducida;
    
    cout << "--------------------------------------" << endl;
    cout << "-BIENVENIDO AL INVENTARIO DE XXXXXXXX-" << endl;
    cout << "--------------------------------------" << endl;
    
    bool ciudadValida = false;
    
    do{
        cout << "DE QUE TIENDA QUIERES CONOCER LOS DATOS: ";
        cin >> ciudadIntroducida;
        
        // Formatear la ciudad introducida
        ciudadIntroducida[0] = toupper(ciudadIntroducida[0]);
        for (size_t i = 1; i < ciudadIntroducida.length(); i++) {
            ciudadIntroducida[i] = tolower(ciudadIntroducida[i]);
        }
        
        // Verificar si la ciudad está en el vector de ciudades disponibles usando un bucle
        ciudadValida = false;  // Reiniciar la validación antes de cada verificación
        for (const string& ciudad : ciudadesDisponibles) {
            if (ciudadIntroducida == ciudad) {
                ciudadValida = true;
                break;  // Si se encuentra, detener el bucle
            }
        }
        
        if (!ciudadValida) {
            cout << "No tenemos tiendas en esa ciudad. Inténtelo de nuevo." << endl;
        } else {
            cout << ciudadIntroducida << " es una tienda del grupo XXXXXX." << endl;
        }
        
    } while (!ciudadValida);
    
    do {
        cout << "Ingrese credenciales para acceder al inventario:" << endl;
        cin >> codigo2;
        
        if (codigo2 != codigo) {
            cout << "Código incorrecto. Inténtelo de nuevo." << endl;
        }
        
    } while (codigo2 != codigo); // Repite el bucle hasta que el código sea correcto
    
    cout << "Acceso permitido." << endl;
}

void menuConsultaInventario(Inventario& inventario) {
    int opcion;
    do {
        cout << "-------------------------------------" << endl;
        cout << "CONSULTAR INVENTARIO" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. CONSULTAR INVENTARIO COMPLETO" << endl;
        cout << "2. CONSULTAR TODA LA ROPA" << endl;
        cout << "3. CONSULTAR TODOS LOS ACCESORIOS" << endl;
        cout << "4. CONSULTAR CAMISETAS" << endl;
        cout << "5. CONSULTAR SUDADERAS" << endl;
        cout << "6. CONSULTAR PANTALONES" << endl;
        cout << "7. CONSULTAR GAFAS DE SOL" << endl;
        cout << "8. CONSULTAR BUFANDAS" << endl;
        cout << "9. CONSULTAR GORRA" << endl;
        cout << "0. VOLVER AL MENÚ PRINCIPAL" << endl;
        cout << "-------------------------------------" << endl;
        cout << "QUE QUIERES HACER:" << endl;
        cin >> opcion;
        cout << "-------------------------------------" << endl;

        switch (opcion) {
            case 1:
                inventario.consultarInventarioCompleto();
                break;
            case 2:
                inventario.consultarPorCategoria("Ropa");
                break;
            case 3:
                inventario.consultarPorCategoria("Accesorio");
                break;
            case 4:
                inventario.consultarPorCategoria("Camiseta");
                break;
            case 5:
                inventario.consultarPorCategoria("Sudadera");
                break;
            case 6:
                inventario.consultarPorCategoria("Pantalon");
                break;
            case 7:
                inventario.consultarPorCategoria("GafasDeSol");
                break;
            case 8:
                inventario.consultarPorCategoria("Bufanda");
                break;
            case 9:
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


void menuPrincipal(int codigo, const vector<string>& ciudadesDisponibles, Warehouse& warehouse, Inventario& inventario) {
    int opcion;
    
    do {
        cout << "-------------------------------------" << endl;
        cout << "GESTIONES DEL INVENTARIO DE XXXXXXXX"  << endl;
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
        cout << "QUE QUIERES HACER:" << endl;
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
                
                break;
            case 5:
                inventario.realizarCambio();
                break;
            case 6:
                menuInicioDeSesion(codigo, ciudadesDisponibles);
                break;
            case 0:
                cout << "Cerrando sesión..." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
        
    } while (opcion != 0);
}

