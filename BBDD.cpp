#include <iostream>
#include <string>
#include <vector>
#include <fstream> // Para manejo de archivos
#include <unordered_map>

using namespace std;

// Enumeraciones necesarias
enum class Temporada { INVIERNO, VERANO, ANUAL };
enum class Genero { HOMBRE, MUJER };
enum class Talla { S, M, L, XL, XXL };
enum class TipoCamiseta { MANGA_CORTA, MANGA_LARGA, SIN_MANGAS };
enum class Estilo { MODERNO, CLASICO, DEPORTIVO, CASUAL };
enum class TipoSudadera { CREWNECK, HOODIE };
enum class TipoPantalon { LARGO, CORTO };

// Clase base Producto
class Producto {
protected:
    string tipo;
    string codProducto;
    float precioVenta;
    int cantidad;
    Temporada temporada;
    Genero genero;

public:
    Producto(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen)
        : tipo(tipoProducto), codProducto(cod), precioVenta(precioV), cantidad(cant), temporada(temp), genero(gen) {}

    virtual void mostrarInformacion() const = 0; // Método virtual puro

    virtual ~Producto() {}

    // Getters
    string getCodProducto() const { return codProducto; }
    float getPrecioVenta() const { return precioVenta; }
    int getCantidad() const { return cantidad; }
    Temporada getTemporada() const { return temporada; }
    Genero getGenero() const { return genero; }

    // Setters
    void setCantidad(int cant) { cantidad = cant; }
};

// Clase Ropa que hereda de Producto
class Ropa : public Producto {
protected:
    Talla talla;

public:
    Ropa(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t)
        : Producto(tipoProducto, cod, precioV, cant, temp, gen), talla(t) {}

    void mostrarInformacion() const override {
        cout << "Tipo: " << tipo << "\n";
        cout << "Código del Producto: " << codProducto << "\n";
        cout << "Precio de Venta: " << precioVenta << "\n";
        cout << "Cantidad en Inventario: " << cantidad << "\n";
        cout << "Temporada: " << (temporada == Temporada::INVIERNO ? "Invierno" : (temporada == Temporada::VERANO ? "Verano" : "Anual")) << "\n";
        cout << "Género: " << (genero == Genero::MUJER ? "Mujer" : "Hombre") << "\n";
        cout << "Talla: " << (talla == Talla::S ? "S" : talla == Talla::M ? "M" : talla == Talla::L ? "L" : talla == Talla::XL ? "XL" : "XXL") << "\n";
    }

    virtual ~Ropa() {}

    Talla getTalla() const { return talla; }
};

class Accesorio : public Producto {
protected:
    Estilo estilo; // Estilo del accesorio

public:
    Accesorio(string tipoProducto, string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est)
        : Producto(tipoProducto, cod, precioV, cant, temp, gen), estilo(est) {}

    // Implementación del método mostrarInformacion
    void mostrarInformacion() const override {
        cout << "Tipo: " << tipo << "\n";
        cout << "Código del Producto: " << codProducto << "\n";
        cout << "Precio de Venta: " << precioVenta << "\n";
        cout << "Cantidad en Inventario: " << cantidad << "\n";
        cout << "Temporada: " << (temporada == Temporada::INVIERNO ? "Invierno" : (temporada == Temporada::VERANO ? "Verano" : "Anual")) << "\n";
        cout << "Género: " << (genero == Genero::MUJER ? "Mujer" : "Hombre") << "\n";
        cout << "Estilo: " << (estilo == Estilo::MODERNO ? "Moderno" : estilo == Estilo::CLASICO ? "Clásico" : estilo == Estilo::DEPORTIVO ? "Deportivo" : "Casual") << endl;
    }

    virtual ~Accesorio() {}

    Estilo getEstilo() const {
        return estilo;
    }
    void setEstilo(Estilo est) { estilo = est;}

};

// Clase Camiseta que hereda de Ropa
class Camiseta : public Ropa {
private:
    TipoCamiseta tipo;
    string material;
    bool estampado;

public:
    Camiseta(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t, TipoCamiseta tip, const string& mat, bool est)
        : Ropa("Camiseta", cod, precioV, cant, temp, gen, t), tipo(tip), material(mat), estampado(est) {}

    void mostrarInformacion() const override {
        Ropa::mostrarInformacion();
        cout << "Tipo de Camiseta: " << (tipo == TipoCamiseta::MANGA_CORTA ? "Manga Corta" : tipo == TipoCamiseta::MANGA_LARGA ? "Manga Larga" : "Sin Mangas") << "\n";
        cout << "Material: " << material << "\n";
        cout << "Estampado: " << (estampado ? "Sí" : "No") << "\n";
    }

    // Getters
    TipoCamiseta getTipo() const { return tipo; }
    string getMaterial() const { return material; }
    bool getEstampado() const { return estampado; }

    // Setters
    void setMaterial(const string& mat) { material = mat; }
    void setEstampado(bool est) { estampado = est; }

    ~Camiseta() {}
};

class Sudadera : public Ropa {
private:
    TipoSudadera tipo;
    string material;
    bool cremallera;

public:
    // Constructor
    Sudadera(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t,
             TipoSudadera tip, const string& mat, bool crem)
        : Ropa("Sudadera", cod, precioV, cant, temp, gen, t), tipo(tip), material(mat), cremallera(crem) {}

    // Getters y Setters
    TipoSudadera getTipoSudadera() const { return tipo; }
    void setTipoSudadera(TipoSudadera tip) { tipo = tip; }

    string getMaterial() const { return material; }
    void setMaterial(const string& mat) { material = mat; }

    bool getCremallera() const { return cremallera; }
    void setCremallera(bool crem) { cremallera = crem; }

    // Mostrar información
    void mostrarInformacion() const override {
        Ropa::mostrarInformacion();
        cout << "Tipo de Sudadera: " << (tipo == TipoSudadera::CREWNECK ? "Crewneck" : "Hoodie") << "\n";
        cout << "Material: " << material << "\n";
        cout << "Cremallera: " << (cremallera ? "Sí" : "No") << "\n";
    }

    // Destructor
    virtual ~Sudadera() {}
};

class Pantalon : public Ropa {
private:
    TipoPantalon tipo;
    bool cargo; // Indica si tiene bolsillos estilo cargo

public:
    // Constructor
    Pantalon(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t, TipoPantalon tip, bool carg)
        : Ropa("Pantalon", cod, precioV, cant, temp, gen, t), tipo(tip), cargo(carg) {}

    // Getters y Setters
    TipoPantalon getTipoPantalon() const { return tipo; }
    void setTipo(TipoPantalon t) { tipo = t; }

    bool getCargo() const { return cargo; }
    void setCargo(bool carg) { cargo = carg; }

    // Mostrar información
    void mostrarInformacion() const override {
        Ropa::mostrarInformacion();
        cout << "Tipo de Pantalón: " << (tipo == TipoPantalon::LARGO ? "Largo" : "Corto") << "\n";
        cout << "Cargo: " << (cargo ? "Sí" : "No") << "\n";
    }

    // Destructor
    virtual ~Pantalon() {}
};


class Bufanda : public Accesorio {
private:
    bool esDeLana;

public:
    Bufanda(string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, bool lana)
        : Accesorio("Bufanda", cod, precioV, cant, temp, gen, est), esDeLana(lana) {}

    void mostrarInformacion() const override {
        Accesorio::mostrarInformacion();
        cout << "Lana: " << (esDeLana ? "Sí" : "No") << "\n";
    }
    
    bool getEsDeLana() const { return esDeLana; }
    void setEsDeLana(bool lana) { esDeLana = lana; }

    ~Bufanda() {}
};

// Clase Almacen
class Almacen {
private:
    vector<Camiseta> camisetasDisponibles; // Productos de tipo Camiseta
    vector<Bufanda> bufandasDisponibles;   // Productos de tipo Bufanda
    vector<Sudadera> sudaderasDisponibles; // Productos de tipo Sudadera
    vector<Pantalon> pantalonesDisponibles;// Productos de tipo pantalon


public:
    Almacen() {
        // Camisetas disponibles
        camisetasDisponibles.push_back(Camiseta("C001", 29.99, 50, Temporada::VERANO, Genero::HOMBRE, Talla::M, TipoCamiseta::MANGA_CORTA, "Algodón", true));
        camisetasDisponibles.push_back(Camiseta("C002", 35.50, 30, Temporada::INVIERNO, Genero::MUJER, Talla::L, TipoCamiseta::MANGA_LARGA, "Poliéster", false));
        
        // Bufandas disponibles
        bufandasDisponibles.push_back(Bufanda("B001", 12.00, 50, Temporada::INVIERNO, Genero::HOMBRE, Estilo::CLASICO, true));
        bufandasDisponibles.push_back(Bufanda("B002", 8.00, 40, Temporada::INVIERNO, Genero::MUJER, Estilo::CASUAL, false));
        
        // Sudaderas disponibles
        sudaderasDisponibles.push_back(Sudadera("S001", 45.99, 20, Temporada::INVIERNO, Genero::HOMBRE, Talla::L, TipoSudadera::CREWNECK, "Algodón", true));
        sudaderasDisponibles.push_back(Sudadera("S002", 40.50, 15, Temporada::VERANO, Genero::MUJER, Talla::M, TipoSudadera::HOODIE, "Poliéster", false));
        // Pantalones disponibles
        pantalonesDisponibles.push_back(Pantalon("P001", 39.99, 25, Temporada::ANUAL, Genero::HOMBRE, Talla::L, TipoPantalon::LARGO, false));
        pantalonesDisponibles.push_back(Pantalon("P002", 49.99, 15, Temporada::INVIERNO, Genero::MUJER, Talla::M, TipoPantalon::CORTO, false));
    }

    const vector<Camiseta>& getCamisetas() const { return camisetasDisponibles; }
    const vector<Bufanda>& getBufandas() const { return bufandasDisponibles; }
    const vector<Sudadera>& getSudaderas() const { return sudaderasDisponibles; }
    const vector<Pantalon>& getPantalones() const { return pantalonesDisponibles; }

};

// Convertir enums a strings
string temporadaToString(Temporada temporada) {
    switch (temporada) {
        case Temporada::INVIERNO: return "Invierno";
        case Temporada::VERANO: return "Verano";
        case Temporada::ANUAL: return "Anual";
    }
    return "";
}

string generoToString(Genero genero) {
    return (genero == Genero::HOMBRE) ? "Hombre" : "Mujer";
}

string tallaToString(Talla talla) {
    switch (talla) {
        case Talla::S: return "S";
        case Talla::M: return "M";
        case Talla::L: return "L";
        case Talla::XL: return "XL";
        case Talla::XXL: return "XXL";
    }
    return "";
}

string tipoCamisetaToString(TipoCamiseta tipo) {
    switch (tipo) {
        case TipoCamiseta::MANGA_CORTA: return "Manga Corta";
        case TipoCamiseta::MANGA_LARGA: return "Manga Larga";
        case TipoCamiseta::SIN_MANGAS: return "Sin Mangas";
    }
    return "";
}

string estiloTostring(Estilo est) {
    switch (est) {
        case Estilo::MODERNO: return "Moderno";
        case Estilo::CLASICO: return "Clásico";
        case Estilo::DEPORTIVO: return "Deportivo";
        case Estilo::CASUAL: return "Casual";
    }
    return "";
}

string tipoSudaderaToString(TipoSudadera tipo) {
    switch (tipo) {
        case TipoSudadera::CREWNECK: return "Crewneck";
        case TipoSudadera::HOODIE: return "Hoodie";
    }
    return "";
}

string tipoPantalonToString(TipoPantalon tipo) {
    switch (tipo) {
        case TipoPantalon::LARGO: return "Largo";
        case TipoPantalon::CORTO: return "Corto";
    }
    return "";
}

// Convertir strings a enums
Temporada stringToTemporada(const string& str) {
    if (str == "Invierno") return Temporada::INVIERNO;
    if (str == "Verano") return Temporada::VERANO;
    return Temporada::ANUAL;
}

Genero stringToGenero(const string& str) {
    return (str == "Hombre") ? Genero::HOMBRE : Genero::MUJER;
}

Talla stringToTalla(const string& str) {
    if (str == "S") return Talla::S;
    if (str == "M") return Talla::M;
    if (str == "L") return Talla::L;
    if (str == "XL") return Talla::XL;
    return Talla::XXL;
}

TipoCamiseta stringToTipoCamiseta(const string& str) {
    if (str == "Manga Corta") return TipoCamiseta::MANGA_CORTA;
    if (str == "Manga Larga") return TipoCamiseta::MANGA_LARGA;
    return TipoCamiseta::SIN_MANGAS;
}

Estilo stringToEstilo(const string& str) {
    if (str == "Moderno") return Estilo::MODERNO;
    if (str == "Clásico") return Estilo::CLASICO;
    if (str == "Deportivo") return Estilo::DEPORTIVO;
    return Estilo::CASUAL;
}

TipoSudadera stringToTipoSudadera(const string& str) {
    return (str == "Crewneck") ? TipoSudadera::CREWNECK : TipoSudadera::HOODIE;
}

TipoPantalon stringToTipoPantalon(const string& str) {
    return (str == "Largo") ? TipoPantalon::LARGO : TipoPantalon::CORTO;
}

// Clase Inventario
class Inventario {
private:
    vector<Camiseta> camisetasEnInventario; // Camisetas
    vector<Sudadera> sudaderasEnInventario; // Sudaderas
    vector<Pantalon> pantalonesEnInventario;// Pantalones
    vector<Bufanda> bufandasEnInventario;   // Bufandas

public:
    Inventario() {
        camisetasEnInventario.clear();
        bufandasEnInventario.clear();
        sudaderasEnInventario.clear();
        pantalonesEnInventario.clear();

    }
    
    void anadirProductoDesdeAlmacen(const Almacen& almacen) {
        string codigo;
        int cantidad;
        
        cout << "Ingrese el código del producto que desea añadir: ";
        cin >> codigo;
        cout << "Ingrese la cantidad que desea añadir: ";
        cin >> cantidad;
        
        // Limpiar el buffer del cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        bool productoEncontrado = false;
        
        // Buscar en las camisetas
        for (auto& camiseta : camisetasEnInventario) {
            if (camiseta.getCodProducto() == codigo) {
                camiseta.setCantidad(camiseta.getCantidad() + cantidad);
                cout << "Camiseta " << codigo << " actualizado. Nueva cantidad: " << camiseta.getCantidad() << "\n";
                productoEncontrado = true;
                break;
            }
        }
        // Buscar en las Sudaderas
        if (!productoEncontrado) {
            for (auto& sudadera : sudaderasEnInventario) {
                if (sudadera.getCodProducto() == codigo) {
                    sudadera.setCantidad(sudadera.getCantidad() + cantidad);
                    cout << "Sudadera " << codigo << " actualizada. Nueva cantidad: " << sudadera.getCantidad() << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        // Buscar en los Pantalones
        if (!productoEncontrado) {
            for (auto& pantalon : pantalonesEnInventario) {
                if (pantalon.getCodProducto() == codigo) {
                    pantalon.setCantidad(pantalon.getCantidad() + cantidad);
                    cout << "Pantalon " << codigo << " actualizada. Nueva cantidad: " << pantalon.getCantidad() << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        // Buscar en las bufandas
        if (!productoEncontrado) {
            for (auto& bufanda : bufandasEnInventario) {
                if (bufanda.getCodProducto() == codigo) {
                    bufanda.setCantidad(bufanda.getCantidad() + cantidad);
                    cout << "Bufanda " << codigo << " actualizada. Nueva cantidad: " << bufanda.getCantidad() << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        // Si no está en el inventario, buscar en el almacén
        if (!productoEncontrado) {
            for (const auto& camiseta : almacen.getCamisetas()) {
                if (camiseta.getCodProducto() == codigo) {
                    Camiseta nuevaCamiseta = camiseta;
                    nuevaCamiseta.setCantidad(cantidad);
                    camisetasEnInventario.push_back(nuevaCamiseta);
                    cout << "Camiseta " << codigo << " añadido al inventario. Cantidad: " << cantidad << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        if (!productoEncontrado) {
            for (const auto& sudadera : almacen.getSudaderas()) {
                if (sudadera.getCodProducto() == codigo) {
                    Sudadera nuevaSudadera = sudadera;
                    nuevaSudadera.setCantidad(cantidad);
                    sudaderasEnInventario.push_back(nuevaSudadera);
                    cout << "Sudadera " << codigo << " añadida al inventario. Cantidad: " << cantidad << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        if (!productoEncontrado) {
            for (const auto& pantalon : almacen.getPantalones()) {
                if (pantalon.getCodProducto() == codigo) {
                    Pantalon nuevoPantalon = pantalon;
                    nuevoPantalon.setCantidad(cantidad);
                    pantalonesEnInventario.push_back(nuevoPantalon);
                    cout << "Pantalón " << codigo << " añadido al inventario. Cantidad: " << cantidad << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        if (!productoEncontrado) {
            for (const auto& bufanda : almacen.getBufandas()) {
                if (bufanda.getCodProducto() == codigo) {
                    Bufanda nuevaBufanda = bufanda;
                    nuevaBufanda.setCantidad(cantidad);
                    bufandasEnInventario.push_back(nuevaBufanda);
                    cout << "Bufanda " << codigo << " añadida al inventario. Cantidad: " << cantidad << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }

        if (!productoEncontrado) {
            cout << "Producto " << codigo << " no encontrado en el almacén.\n";
        }
    }
    
    void mostrarInventario() const {
        cout << "\n=== Estado del Inventario ===\n";
        
        cout << "\n=== Camisetas ===\n";
        for (const auto& camiseta : camisetasEnInventario) {
            camiseta.mostrarInformacion();
            cout << "-------------------\n";
        }
        
        cout << "\n=== Sudaderas ===\n";
        for (const auto& sudadera : sudaderasEnInventario) {
            sudadera.mostrarInformacion();
            cout << "-------------------\n";
        }
        
        cout << "\n=== Pantalones ===\n";
        for (const auto& pantalon : pantalonesEnInventario) {
            pantalon.mostrarInformacion();
            cout << "-------------------\n";
        }

        cout << "\n=== Bufandas ===\n";
        for (const auto& bufanda : bufandasEnInventario) {
            bufanda.mostrarInformacion();
            cout << "-------------------\n";
        }
    }
    
    void guardarInventario(const string& archivoNombre) const {
        ofstream archivo(archivoNombre);
        if (!archivo) {
            cerr << "Error al abrir el archivo " << archivoNombre << "\n";
            return;
        }
        
        // Guardar cantidad de camisetas
        archivo << "Camisetas\n" << camisetasEnInventario.size() << "\n";
        for (const auto& producto : camisetasEnInventario) {
            archivo << producto.getCodProducto() << "\n"
            << producto.getCantidad() << "\n"
            << producto.getPrecioVenta() << "\n"
            << temporadaToString(producto.getTemporada()) << "\n"
            << generoToString(producto.getGenero()) << "\n"
            << tallaToString(producto.getTalla()) << "\n"
            << tipoCamisetaToString(producto.getTipo()) << "\n"
            << producto.getMaterial() << "\n"
            << (producto.getEstampado() ? "Sí" : "No") << "\n";
        }
        
        // Guardar cantidad de bufandas
        archivo << "Bufandas\n" << bufandasEnInventario.size() << "\n";
        for (const auto& bufanda : bufandasEnInventario) {
            archivo << bufanda.getCodProducto() << "\n"
            << bufanda.getCantidad() << "\n"
            << bufanda.getPrecioVenta() << "\n"
            << temporadaToString(bufanda.getTemporada()) << "\n"
            << generoToString(bufanda.getGenero()) << "\n"
            << estiloTostring(bufanda.getEstilo()) << "\n"
            << (bufanda.getEsDeLana() ? "Sí" : "No") << "\n";
        }
        
        // Guardar cantidad de Sudaderas
        archivo << "Sudaderas\n" << sudaderasEnInventario.size() << "\n";
        for (const auto& sudadera : sudaderasEnInventario) {
            archivo << sudadera.getCodProducto() << "\n"
                    << sudadera.getCantidad() << "\n"
                    << sudadera.getPrecioVenta() << "\n"
                    << temporadaToString(sudadera.getTemporada()) << "\n"
                    << generoToString(sudadera.getGenero()) << "\n"
                    << tallaToString(sudadera.getTalla()) << "\n"
                    << tipoSudaderaToString(sudadera.getTipoSudadera()) << "\n" // Enum convertido a string
                    << sudadera.getMaterial() << "\n"
                    << (sudadera.getCremallera() ? "Sí" : "No") << "\n";
        }

        
        // Guardar cantidad de Pantalones
        archivo << "Pantalones\n" << pantalonesEnInventario.size() << "\n";
        for (const auto& pantalon : pantalonesEnInventario) {
            archivo << pantalon.getCodProducto() << "\n"
                    << pantalon.getCantidad() << "\n"
                    << pantalon.getPrecioVenta() << "\n"
                    << temporadaToString(pantalon.getTemporada()) << "\n"
                    << generoToString(pantalon.getGenero()) << "\n"
                    << tallaToString(pantalon.getTalla()) << "\n"
                    << tipoPantalonToString(pantalon.getTipoPantalon()) << "\n" // Enum convertido a string
                    << (pantalon.getCargo() ? "Sí" : "No") << "\n";
        }

        
        archivo.close();
        cout << "Inventario guardado en " << archivoNombre << "\n";
    }
    
    
    void cargarInventario(const string& archivoNombre) {
        ifstream archivo(archivoNombre);
        if (!archivo) {
            cerr << "Error al abrir el archivo " << archivoNombre << "\n";
            return;
        }
        
        camisetasEnInventario.clear();
        bufandasEnInventario.clear();
        sudaderasEnInventario.clear();
        
        string linea, codigo, temporadaStr, generoStr, tallaStr, tipoCamisetaStr, material, estampadoStr, estiloStr, lanaStr, tipoSudaderaStr, cremStr, tipoPantalonStr, cargoStr;
        int cantidad;
        float precio;
        
        // Cargar camisetas
        getline(archivo, linea); // "Camisetas"
        size_t numCamisetas;
        archivo >> numCamisetas;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        
        for (size_t i = 0; i < numCamisetas; i++) {
            getline(archivo, codigo);
            archivo >> cantidad >> precio;
            archivo.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(archivo, temporadaStr);
            getline(archivo, generoStr);
            getline(archivo, tallaStr);
            getline(archivo, tipoCamisetaStr);
            getline(archivo, material);
            getline(archivo, estampadoStr);
            
            Temporada temporada = stringToTemporada(temporadaStr);
            Genero genero = stringToGenero(generoStr);
            Talla talla = stringToTalla(tallaStr);
            TipoCamiseta tipoCamiseta = stringToTipoCamiseta(tipoCamisetaStr);
            bool estampado = (estampadoStr == "Sí");
            
            camisetasEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, talla, tipoCamiseta, material, estampado);
        }
        
        // Cargar bufandas
        getline(archivo, linea); // "Bufandas"
        size_t numBufandas;
        archivo >> numBufandas;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        
        for (size_t i = 0; i < numBufandas; i++) {
            getline(archivo, codigo);
            archivo >> cantidad >> precio;
            archivo.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(archivo, temporadaStr);
            getline(archivo, generoStr);
            getline(archivo, estiloStr);
            getline(archivo, lanaStr);
            
            Temporada temporada = stringToTemporada(temporadaStr);
            Genero genero = stringToGenero(generoStr);
            Estilo estilo = stringToEstilo(estiloStr);
            bool esDeLana = (lanaStr == "Sí");
            
            bufandasEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, estilo, esDeLana);
        }
        
        // Cargar sudaderas
        getline(archivo, linea); // "Sudaderas"
        size_t numSudaderas;
        archivo >> numSudaderas;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');

        for (size_t i = 0; i < numSudaderas; i++) {
            getline(archivo, codigo);
            archivo >> cantidad >> precio;
            archivo.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(archivo, temporadaStr);
            getline(archivo, generoStr);
            getline(archivo, tallaStr);
            getline(archivo, tipoSudaderaStr); // Leer tipo sudadera
            getline(archivo, material);
            getline(archivo, cremStr);

            Temporada temporada = stringToTemporada(temporadaStr);
            Genero genero = stringToGenero(generoStr);
            Talla talla = stringToTalla(tallaStr);
            TipoSudadera tipoSudadera = stringToTipoSudadera(tipoSudaderaStr); // Conversión
            bool cremallera = (cremStr == "Sí");

            sudaderasEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, talla, tipoSudadera, material, cremallera);
        }
        
        // Cargar pantalones
        getline(archivo, linea); // "Pantalones"
        size_t numPantalones;
        archivo >> numPantalones;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');

        for (size_t i = 0; i < numPantalones; i++) {
            getline(archivo, codigo);
            archivo >> cantidad >> precio;
            archivo.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(archivo, temporadaStr);
            getline(archivo, generoStr);
            getline(archivo, tallaStr);
            getline(archivo, tipoPantalonStr); // Leer tipo pantalón
            getline(archivo, cargoStr);

            Temporada temporada = stringToTemporada(temporadaStr);
            Genero genero = stringToGenero(generoStr);
            Talla talla = stringToTalla(tallaStr);
            TipoPantalon tipoPantalon = stringToTipoPantalon(tipoPantalonStr); // Conversión
            bool cargo = (cargoStr == "Sí");

            pantalonesEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, talla, tipoPantalon, cargo);
        }
    }
};
    
    // Clase Tienda
class Tienda {
private:
    string nombre;
    Inventario inventario;
    string archivoInventario;
    
public:
    Tienda(const string& nombreTienda, const string& archivo) : nombre(nombreTienda), archivoInventario(archivo) {
        inventario.cargarInventario(archivoInventario);
    }
    
    Inventario& getInventario() { return inventario; }
    
    void guardarInventario() const {
        inventario.guardarInventario(archivoInventario);
    }
    
    void cargarInventario() {
        inventario.cargarInventario(archivoInventario);
    }
    
    string getNombre() const { return nombre; }
};
    
    // Función para mostrar el menú de gestión del inventario
void menuGestionInventario(Tienda& tienda, const Almacen& almacen) {
    char opcion;
    do {
        cout << "\n--- Gestión del Inventario en " << tienda.getNombre() << " ---\n";
        cout << "1. Añadir producto desde el almacén\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case '1':
                tienda.getInventario().anadirProductoDesdeAlmacen(almacen);
                tienda.guardarInventario();
                break;
            case '2':
                tienda.getInventario().mostrarInventario();
                break;
            case '3':
                tienda.guardarInventario(); // Guardar automáticamente al salir
                cout << "Saliendo de la gestión del inventario en " << tienda.getNombre() << ".\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != '3');
}
    
    
    // Función principal para cambiar entre tiendas
void menuTiendas(Tienda& madrid, Tienda& barcelona, const Almacen& almacen) {
    char opcion;
    do {
        cout << "\n--- Gestión de Tiendas ---\n";
        cout << "1. Gestionar tienda Madrid\n";
        cout << "2. Gestionar tienda Barcelona\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        static Tienda* tiendaActual = nullptr;
        
        if (tiendaActual != nullptr) {
            // Guardar inventario de la tienda actual antes de cambiar
            tiendaActual->guardarInventario();
        }
        
        switch (opcion) {
            case '1':
                tiendaActual = &madrid;
                menuGestionInventario(madrid, almacen);
                break;
            case '2':
                tiendaActual = &barcelona;
                menuGestionInventario(barcelona, almacen);
                break;
            case '3':
                cout << "Saliendo del sistema de gestión de tiendas.\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != '3');
}
    
    
int main() {
    // Crear el almacén
    Almacen almacen;
    
    // Crear las tiendas
    Tienda madrid("Madrid", "inventarioMadrid.txt");
    Tienda barcelona("Barcelona", "inventarioBarcelona.txt");
    
    // Mostrar el menú principal
    menuTiendas(madrid, barcelona, almacen);
    
    return 0;
}

