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

std::string temporadaToString(Temporada temporada) {
    switch (temporada) {
        case Temporada::INVIERNO: return "Invierno";
        case Temporada::VERANO: return "Verano";
        case Temporada::ANUAL: return "Anual";
        default: return "Desconocida";
    }
}
std::string generoToString(Genero genero) {
    return genero == Genero::MUJER ? "Mujer" : "Hombre";
}
std::string estiloToString(Estilo estilo) {
    switch (estilo) {
        case Estilo::MODERNO: return "Moderno";
        case Estilo::CLASICO: return "Clasico";
        case Estilo::DEPORTIVO: return "Deportivo";
        case Estilo::CASUAL: return "Casual";
        default: return "Desconocido";
    }
}
std::string tipoCamisetaToString(TipoCamiseta tipo) {
    switch (tipo) {
        case TipoCamiseta::MANGA_LARGA: return "Manga Larga";
        case TipoCamiseta::MANGA_CORTA: return "Manga Corta";
        case TipoCamiseta::TIRANTES: return "Tirantes";
        default: return "Desconocido";
    }
}
std::string tipoPantalonToString(TipoPantalon tipo) {
    switch (tipo) {
        case TipoPantalon::LARGO: return "Largo";
        case TipoPantalon::CORTO: return "Corto";
        default: return "Desconocido";
    }
}
std::string tallaToString(Talla talla) {
    switch (talla) {
        case Talla::S: return "S";
        case Talla::M: return "M";
        case Talla::L: return "L";
        case Talla::XL: return "XL";
        case Talla::XXL: return "XXL";
        default: return "Desconocido";
    }
}
std::string tipoSudaderaToString(TipoSudadera tipo) {
    switch (tipo) {
        case TipoSudadera::CREWNECK: return "Crewneck";
        case TipoSudadera::HOODIE: return "Hoodie";
        default: return "Desconocido";
    }
}


// Cargar el inventario desde el archivo
void Tienda::cargarInventario() {
    string archivoInventario = "Inventario" + getNombreTienda() + ".txt";
    ifstream archivo(archivoInventario);
    
    if (!archivo.is_open()) {
        cout << "El archivo no se pudo abrir." << endl;
        return;
    }
    
    // Limpiar el inventario previo
    inventario.clear();
    
    string tipoSeccion;
    
    while (getline(archivo, tipoSeccion)) {
        if (tipoSeccion == "Camisetas:") {
            while (archivo.peek() != '\n' && !archivo.eof()) { //verifica si se puede seguir leyendo líneas dentro de camisetas
                string cod, material;
                string temporada, genero, talla, tipoCamiseta;
                float precio;
                int cantidad;
                bool estampado;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> talla >> tipoCamiseta >> material >> estampado;
                
                Camiseta c(cod, precio, cantidad,
                           temporada == "Invierno" ? Temporada::INVIERNO :
                           temporada == "Verano" ? Temporada::VERANO : Temporada::ANUAL,
                           genero == "Hombre" ? Genero::HOMBRE : Genero::MUJER,
                           talla == "S" ? Talla::S :
                           talla == "M" ? Talla::M :
                           talla == "L" ? Talla::L :
                           talla == "XL" ? Talla::XL : Talla::XXL,
                           tipoCamiseta == "Manga Corta" ? TipoCamiseta::MANGA_CORTA :
                           tipoCamiseta == "Manga Larga" ? TipoCamiseta::MANGA_LARGA : TipoCamiseta::TIRANTES,
                           material, estampado);
                
                inventario.push_back(c);
            }
        } else if (tipoSeccion == "Sudaderas:") {
            while (archivo.peek() != '\n' && !archivo.eof()) {
                string cod, material;
                string temporada, genero, talla, tipoSudadera;
                float precio;
                int cantidad;
                bool cremallera;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> talla >> tipoSudadera >> material >> cremallera;
                
                Sudadera s(cod, precio, cantidad,
                           temporada == "Invierno" ? Temporada::INVIERNO :
                           temporada == "Verano" ? Temporada::VERANO : Temporada::ANUAL,
                           genero == "Hombre" ? Genero::HOMBRE : Genero::MUJER,
                           talla == "S" ? Talla::S :
                           talla == "M" ? Talla::M :
                           talla == "L" ? Talla::L :
                           talla == "XL" ? Talla::XL : Talla::XXL,
                           tipoSudadera == "Crewneck" ? TipoSudadera::CREWNECK : TipoSudadera::HOODIE,
                           material, cremallera);
                
                inventario.push_back(s);
            }
        } else if (tipoSeccion == "Pantalones:") {
            while (archivo.peek() != '\n' && !archivo.eof()) {
                string cod, tipoPantalon;
                string temporada, genero, talla;
                float precio;
                int cantidad;
                bool cargo;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> talla >> tipoPantalon >> cargo;
                
                Pantalon p(cod, precio, cantidad,
                           temporada == "Invierno" ? Temporada::INVIERNO :
                           temporada == "Verano" ? Temporada::VERANO : Temporada::ANUAL,
                           genero == "Hombre" ? Genero::HOMBRE : Genero::MUJER,
                           talla == "S" ? Talla::S :
                           talla == "M" ? Talla::M :
                           talla == "L" ? Talla::L :
                           talla == "XL" ? Talla::XL : Talla::XXL,
                           tipoPantalon == "Largo" ? TipoPantalon::LARGO : TipoPantalon::CORTO, cargo);
                
                inventario.push_back(p);
            }
        } else if (tipoSeccion == "Bufandas:") {
            while (archivo.peek() != '\n' && !archivo.eof()) {
                string cod, estilo;
                string temporada, genero;
                float precio;
                int cantidad;
                bool esDeLana;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> estilo >> esDeLana;
                
                Bufanda b(cod, precio, cantidad,
                          temporada == "Invierno" ? Temporada::INVIERNO :
                          temporada == "Verano" ? Temporada::VERANO : Temporada::ANUAL,
                          genero == "Hombre" ? Genero::HOMBRE : Genero::MUJER,
                          estilo == "Moderno" ? Estilo::MODERNO :
                          estilo == "Clasico" ? Estilo::CLASICO :
                          estilo == "Deportivo" ? Estilo::DEPORTIVO : Estilo::CASUAL,
                          esDeLana);
                
                inventario.push_back(b);
            }
        } else if (tipoSeccion == "Gorras:") {
            while (archivo.peek() != '\n' && !archivo.eof()) {
                string cod, estilo, tipoGorra;
                string temporada, genero;
                float precio;
                int cantidad;
                string material;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> estilo >> tipoGorra >> material;
                
                Gorra g(cod, precio, cantidad,
                        temporada == "Invierno" ? Temporada::INVIERNO :
                        temporada == "Verano" ? Temporada::VERANO : Temporada::ANUAL,
                        genero == "Hombre" ? Genero::HOMBRE : Genero::MUJER,
                        estilo == "Moderno" ? Estilo::MODERNO :
                        estilo == "Clasico" ? Estilo::CLASICO :
                        estilo == "Deportivo" ? Estilo::DEPORTIVO : Estilo::CASUAL,
                        tipoGorra, material);
                
                inventario.push_back(g);
            }
        } else if (tipoSeccion == "GafasDeSol:") {
            while (archivo.peek() != '\n' && !archivo.eof()) {
                string cod, estilo, formaLente;
                string temporada, genero;
                float precio;
                int cantidad;
                bool proteccionUV;
                
                archivo >> cod >> precio >> cantidad >> temporada >> genero >> estilo >> formaLente >> proteccionUV;
                
                GafasDeSol gs(cod, precio, cantidad,
                              temporada == "Invierno" ? Temporada::INVIERNO :
                              temporada == "Verano" ? Temporada::VERANO : Temporada::ANUAL,
                              genero == "Hombre" ? Genero::HOMBRE : Genero::MUJER,
                              estilo == "Moderno" ? Estilo::MODERNO :
                              estilo == "Clasico" ? Estilo::CLASICO :
                              estilo == "Deportivo" ? Estilo::DEPORTIVO : Estilo::CASUAL,
                              formaLente, proteccionUV);
                
                inventario.push_back(gs);
            }
        }
    }
    
    archivo.close();
    cout << "Inventario cargado correctamente para la tienda " << getNombreTienda() << "." << endl;
}

    // Guardar el inventario en el archivo
void Tienda::guardarInventario() {
    string archivoInventario = "Inventario" + getNombreTienda() + ".txt";
    ofstream archivo(archivoInventario);
    
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo para guardar el inventario." << endl;
        return;
    }
    
    // Escribir encabezado
    archivo << "Inventario de la tienda de " << getNombreTienda() << endl;
    
    // Escribir las categorías de productos
    archivo << "Camisetas:" << endl;
    for (const auto& producto : inventario) {
        if (producto.getTipoProducto() == "Camiseta") {
            const Camiseta* camiseta = dynamic_cast<const Camiseta*>(&producto);
            if (camiseta) {
                archivo << camiseta->getCodProducto() << " "
                << camiseta->getPrecioVenta() << " "
                << camiseta->getCantidad() << " "
                << temporadaToString(camiseta->getTemporada()) << " "
                << generoToString(camiseta->getGenero()) << " "
                << tallaToString(camiseta->getTalla()) << " "
                << tipoCamisetaToString(camiseta->getTipoCamiseta()) << " "
                << camiseta->getMaterial() << " "
                << (camiseta->getEstampado() ? "Sí" : "No") << endl;
            }
        }
    }
    
    archivo << "Sudaderas:" << endl;
    for (const auto& producto : inventario) {
        if (producto.getTipoProducto() == "Sudadera") {
            const Sudadera* sudadera = dynamic_cast<const Sudadera*>(&producto);
            if (sudadera) {
                archivo << sudadera->getCodProducto() << " "
                << sudadera->getPrecioVenta() << " "
                << sudadera->getCantidad() << " "
                << temporadaToString(sudadera->getTemporada()) << " "
                << generoToString(sudadera->getGenero()) << " "
                << tallaToString(sudadera->getTalla()) << " "
                << tipoSudaderaToString(sudadera->getTipoSudadera()) << " "
                << sudadera->getMaterial() << " "
                << (sudadera->getCremallera() ? "Sí" : "No") << endl;
            }
        }
    }
    
    archivo << "Pantalones:" << std::endl;
    for (const auto& producto : inventario) {
        if (producto.getTipoProducto() == "Pantalon") {
            const Pantalon* pantalon = dynamic_cast<const Pantalon*>(&producto);
            if (pantalon) {
                archivo << pantalon->getCodProducto() << " "
                << pantalon->getPrecioVenta() << " "
                << pantalon->getCantidad() << " "
                << temporadaToString(pantalon->getTemporada()) << " " // Convierte Temporada a texto
                << generoToString(pantalon->getGenero()) << " "      // Convierte Genero a texto
                << tallaToString(pantalon->getTalla()) << " "        // Convierte Talla a texto
                << tipoPantalonToString(pantalon->getTipoPantalon()) << " " // Convierte TipoPantalon a texto
                << (pantalon->getCargo() ? "Sí" : "No")               // Convierte bool a texto
                << std::endl;
            }
        }
    }
    
    archivo << "Bufandas:" << std::endl;
    for (const auto& producto : inventario) {
        if (producto.getTipoProducto() == "Bufanda") {
            const Bufanda* bufanda = dynamic_cast<const Bufanda*>(&producto);
            if (bufanda) {
                archivo << bufanda->getCodProducto() << " "
                << bufanda->getPrecioVenta() << " "
                << bufanda->getCantidad() << " "
                << temporadaToString(bufanda->getTemporada()) << " " // Convierte Temporada a texto
                << generoToString(bufanda->getGenero()) << " "      // Convierte Genero a texto
                << estiloToString(bufanda->getEstilo()) << " "      // Convierte Estilo a texto
                << (bufanda->getEsDeLana() ? "Sí" : "No")              // Convierte bool a texto
                << std::endl;
            }
        }
    }
    
    archivo << "Gorras:" << std::endl;
    for (const auto& producto : inventario) {
        if (producto.getTipoProducto() == "Gorra") {
            const Gorra* gorra = dynamic_cast<const Gorra*>(&producto);
            if (gorra) {
                archivo << gorra->getCodProducto() << " "
                << gorra->getPrecioVenta() << " "
                << gorra->getCantidad() << " "
                << temporadaToString(gorra->getTemporada()) << " " // Convierte Temporada a texto
                << generoToString(gorra->getGenero()) << " "      // Convierte Genero a texto
                << estiloToString(gorra->getEstilo()) << " "      // Convierte Estilo a texto
                << gorra->getMaterial() <<
                std::endl;
            }
        }
    }
    
    archivo << "Gafas de sol:" << std::endl;
    for (const auto& producto : inventario) {
        if (producto.getTipoProducto() == "Gafas de sol") {
            const GafasDeSol* gafas = dynamic_cast<const GafasDeSol*>(&producto);
            if (gafas) {
                archivo << gafas->getCodProducto() << " "
                << gafas->getPrecioVenta() << " "
                << gafas->getCantidad() << " "
                << temporadaToString(gafas->getTemporada()) << " " // Convierte Temporada a texto
                << generoToString(gafas->getGenero()) << " "      // Convierte Genero a texto
                << estiloToString(gafas->getEstilo()) << " "      // Convierte Estilo a texto
                << gafas->getFormaLente() << " "
                << (gafas->getProteccionUV() ? "Sí" : "No")     // Convierte bool a texto
                << std::endl;
            }
        }
    }
    
    
    archivo.close();
    cout << "Inventario guardado correctamente para la tienda " << getNombreTienda() << "." << endl;
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

