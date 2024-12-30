#include "Tienda.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

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
// Cargar el inventario desde el archivo
void Tienda::cargarInventario(){
    string archivoInventario = "Inventario_" + getNombreTienda() + ".txt";
    ifstream archivo(archivoInventario);
    
    if (!archivo.is_open()) {
        cout << "El archivo no se pudo abrir." << endl;
        return;
    }
    
    // Limpiar el inventario previo
    inventario.clear();
    
    string tipoSeccion;
    archivo.ignore(100, '\n'); // Ignorar la primera línea ("Inventario de la tienda...")
    
    while (archivo >> tipoSeccion) {
        if (tipoSeccion == "Camisetas:") {
            for (int i = 0; i < 10; i++) { // Cambia 10 por el número esperado de productos
                string cod, temporada, genero, talla, manga, material;
                float precio;
                int cantidad;
                bool estampado;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> talla >> manga >> material >> estampado;
                
                // Crear una camiseta
                Camiseta c(cod, precio, cantidad,
                           temporada == "VERANO" ? Temporada::VERANO :
                           temporada == "INVIERNO" ? Temporada::INVIERNO : Temporada::ANUAL,
                           genero == "HOMBRE" ? Genero::HOMBRE : Genero::MUJER,
                           talla == "S" ? Talla::S :
                           talla == "M" ? Talla::M :
                           talla == "L" ? Talla::L :
                           talla == "XL" ? Talla::XL : Talla::XXL,
                           manga == "MANGA_CORTA" ? TipoCamiseta::MANGA_CORTA :
                           manga == "MANGA_LARGA" ? TipoCamiseta::MANGA_LARGA : TipoCamiseta::TIRANTES,
                           material, estampado);
                
                inventario.push_back(c);
            }
        } else if (tipoSeccion == "Sudaderas:") {
            for (int i = 0; i < 10; i++) {
                string cod, temporada, genero, talla, tipo, material;
                float precio;
                int cantidad;
                bool cremallera;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> talla >> tipo >> material >> cremallera;
                
                Sudadera s(cod, precio, cantidad,
                           temporada == "VERANO" ? Temporada::VERANO :
                           temporada == "INVIERNO" ? Temporada::INVIERNO : Temporada::ANUAL,
                           genero == "HOMBRE" ? Genero::HOMBRE : Genero::MUJER,
                           talla == "S" ? Talla::S :
                           talla == "M" ? Talla::M :
                           talla == "L" ? Talla::L :
                           talla == "XL" ? Talla::XL : Talla::XXL,
                           tipo == "HOODIE" ? TipoSudadera::HOODIE : TipoSudadera::CREWNECK,
                           material, cremallera);
                
                inventario.push_back(s);
            }
        } else if (tipoSeccion == "Pantalones:") {
            for (int i = 0; i < 10; i++) {
                string cod, temporada, genero, talla, tipo;
                float precio;
                int cantidad;
                bool cargo;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> talla >> tipo >> cargo;
                
                Pantalon p(cod, precio, cantidad,
                           temporada == "VERANO" ? Temporada::VERANO :
                           temporada == "INVIERNO" ? Temporada::INVIERNO : Temporada::ANUAL,
                           genero == "HOMBRE" ? Genero::HOMBRE : Genero::MUJER,
                           talla == "S" ? Talla::S :
                           talla == "M" ? Talla::M :
                           talla == "L" ? Talla::L :
                           talla == "XL" ? Talla::XL : Talla::XXL,
                           tipo == "LARGO" ? TipoPantalon::LARGO : TipoPantalon::CORTO, cargo);
                
                inventario.push_back(p);
            }
        } else if (tipoSeccion == "Bufandas:") {
            for (int i = 0; i < 10; i++) {
                string cod, temporada, genero, estilo;
                float precio;
                int cantidad;
                bool esDeLana;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> estilo >> esDeLana;
                
                Bufanda b(cod, precio, cantidad,
                          temporada == "VERANO" ? Temporada::VERANO :
                          temporada == "INVIERNO" ? Temporada::INVIERNO : Temporada::ANUAL,
                          genero == "HOMBRE" ? Genero::HOMBRE : Genero::MUJER,
                          estilo == "MODERNO" ? Estilo::MODERNO :
                          estilo == "CLASICO" ? Estilo::CLASICO :
                          estilo == "DEPORTIVO" ? Estilo::DEPORTIVO : Estilo::CASUAL,
                          esDeLana);
                
                inventario.push_back(b);
            }
        } else if (tipoSeccion == "Gorras:") {
            for (int i = 0; i < 10; i++) {
                string cod, temporada, genero, estilo, tipo, material;
                float precio;
                int cantidad;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> estilo >> tipo >> material;
                
                Gorra g(cod, precio, cantidad,
                        temporada == "VERANO" ? Temporada::VERANO :
                        temporada == "INVIERNO" ? Temporada::INVIERNO : Temporada::ANUAL,
                        genero == "HOMBRE" ? Genero::HOMBRE : Genero::MUJER,
                        estilo == "MODERNO" ? Estilo::MODERNO :
                        estilo == "CLASICO" ? Estilo::CLASICO :
                        estilo == "DEPORTIVO" ? Estilo::DEPORTIVO : Estilo::CASUAL,
                        tipo, material);
                
                inventario.push_back(g);
            }
        } else if (tipoSeccion == "GafasDeSol:") {
            for (int i = 0; i < 10; i++) {
                string cod, temporada, genero, estilo, formaLente;
                float precio;
                int cantidad;
                bool proteccionUV;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> estilo >> formaLente >> proteccionUV;
                
                GafasDeSol gs(cod, precio, cantidad,
                              temporada == "VERANO" ? Temporada::VERANO :
                              temporada == "INVIERNO" ? Temporada::INVIERNO : Temporada::ANUAL,
                              genero == "HOMBRE" ? Genero::HOMBRE : Genero::MUJER,
                              estilo == "MODERNO" ? Estilo::MODERNO :
                              estilo == "CLASICO" ? Estilo::CLASICO :
                              estilo == "DEPORTIVO" ? Estilo::DEPORTIVO : Estilo::CASUAL,
                              formaLente, proteccionUV);
                
                inventario.push_back(gs);
            }
        }
        
        archivo.close();
        cout << "Inventario cargado correctamente para la tienda " << getNombreTienda() << "." << endl;
    }
    
    // Guardar el inventario en el archivo
    void Tienda::guardarInventario(){
        if (tiendaSeleccionada == TiendaEnum::None) {
            cout << "No se ha seleccionado ninguna tienda. Por favor, selecciona una tienda primero." << endl;
            return;
        }
        
        string archivoInventario = "Inventario_" + getNombreTienda() + ".txt";
        ofstream archivo(archivoInventario);
        
        if (!archivo.is_open()) {
            cout << "El archivo no se pudo abrir." << endl;
            return;
        }
        
        // Escribir encabezado
        archivo << "Inventario de la tienda de " << getNombreTienda() << endl;
        
        // Categorías y su correspondiente escritura en el archivo
        archivo << "Camisetas:" << endl;
        for (const auto& producto : inventario) {
            if (producto.getTipoProducto() == "Camiseta") {
                archivo << producto.getCodProducto() << " "
                << producto.getPrecioVenta() << " "
                << producto.getCantidad() << " "
                << producto.getTemporada() << " "
                << producto.getGenero() << " "
                << producto.getTalla() << " "
                << producto.getTipoEspecifico() << " "
                << producto.getMaterial() << " "
                << producto.tieneCaracteristicaExtra() << endl;
            }
        }
        
        archivo << "Sudaderas:" << endl;
        for (const auto& producto : inventario) {
            if (producto.getTipoProducto() == "Sudadera") {
                archivo << producto.getCodProducto() << " "
                << producto.getPrecioVenta() << " "
                << producto.getCantidad() << " "
                << producto.getTemporada() << " "
                << producto.getGenero() << " "
                << producto.getTalla() << " "
                << producto.getTipoEspecifico() << " "
                << producto.getMaterial() << " "
                << producto.tieneCaracteristicaExtra() << endl;
            }
        }
        
        archivo << "Pantalones:" << endl;
        for (const auto& producto : inventario) {
            if (producto.getTipoProducto() == "Pantalon") {
                archivo << producto.getCodProducto() << " "
                << producto.getPrecioVenta() << " "
                << producto.getCantidad() << " "
                << producto.getTemporada() << " "
                << producto.getGenero() << " "
                << producto.getTalla() << " "
                << producto.getTipoEspecifico() << " "
                << producto.tieneCaracteristicaExtra() << endl;
            }
        }
        
        archivo << "Bufandas:" << endl;
        for (const auto& producto : inventario) {
            if (producto.getTipoProducto() == "Bufanda") {
                archivo << producto.getCodProducto() << " "
                << producto.getPrecioVenta() << " "
                << producto.getCantidad() << " "
                << producto.getTemporada() << " "
                << producto.getGenero() << " "
                << producto.getEstilo() << " "
                << producto.tieneCaracteristicaExtra() << endl;
            }
        }
        
        archivo << "Gorras:" << endl;
        for (const auto& producto : inventario) {
            if (producto.getTipoProducto() == "Gorra") {
                archivo << producto.getCodProducto() << " "
                << producto.getPrecioVenta() << " "
                << producto.getCantidad() << " "
                << producto.getTemporada() << " "
                << producto.getGenero() << " "
                << producto.getEstilo() << " "
                << producto.getTipoEspecifico() << " "
                << producto.getMaterial() << endl;
            }
        }
        
        archivo << "GafasDeSol:" << endl;
        for (const auto& producto : inventario) {
            if (producto.getTipoProducto() == "GafasDeSol") {
                archivo << producto.getCodProducto() << " "
                << producto.getPrecioVenta() << " "
                << producto.getCantidad() << " "
                << producto.getTemporada() << " "
                << producto.getGenero() << " "
                << producto.getEstilo() << " "
                << producto.getTipoEspecifico() << " "
                << producto.tieneCaracteristicaExtra() << endl;
            }
        }
        
        archivo.close();
        cout << "Inventario guardado correctamente para la tienda " << getNombreTienda() << "." << endl;
    }
}
    
    
    
    
    // Mostrar el inventario completo
    void Tienda::mostrarInventario() const {
        if (inventario.empty()) {
            cout << "El inventario está vacío." << endl;
            return;
        }
        
        cout << "Inventario de la tienda " << getNombreTienda() << ":" << endl;
        for (const auto& producto : inventario) {
            producto.mostrarInformacion();
            cout << "-------------------------" << endl;
        }
    }
    
    // Obtener referencia al inventario
    vector<Producto>& Tienda::getInventario() {
        return inventario;
    }

*/
