#include <iostream>
#include <string>
#include <vector>
#include <fstream> // Para manejo de archivos
#include <unordered_map>
#include <ctime>    // Para time()
#include <sstream>
#include <algorithm> // Para transformar texto con toupper y tolower

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
    // Constructor Producto
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
    // Constructor Ropa
    Ropa(const string& tipoProducto, const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t)
        : Producto(tipoProducto, cod, precioV, cant, temp, gen), talla(t) {}
    
    // Función para mostrar la información de la ropa
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

    //Getter de Talla
    Talla getTalla() const { return talla; }
};

class Accesorio : public Producto {
protected:
    Estilo estilo; // Estilo del accesorio

public:
    // Constructor
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

    // Getter de Estilo
    Estilo getEstilo() const {
        return estilo;
    }
    
    // Setter de Estilo
    void setEstilo(Estilo est) { estilo = est;}

};

// Clase Camiseta que hereda de Ropa
class Camiseta : public Ropa {
private:
    TipoCamiseta tipo;
    string material;
    bool estampado;

public:
    // Constructor camiseta
    Camiseta(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t, TipoCamiseta tip, const string& mat, bool est)
        : Ropa("Camiseta", cod, precioV, cant, temp, gen, t), tipo(tip), material(mat), estampado(est) {}

    // Método mostrar la información
    void mostrarInformacion() const override {
        // Llamamos al método de la clase base para imprimir información general
        Ropa::mostrarInformacion();
        // Añadimos los datos específicos de camiseta
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

class GafasDeSol : public Accesorio {
private:
    string formaLente;
    bool proteccionUV;

public:
    // Constructor
    GafasDeSol(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, const string& forma, bool uv)
        : Accesorio("Gafas de Sol", cod, precioV, cant, temp, gen, est), formaLente(forma), proteccionUV(uv) {}

    // Getters y Setters
    string getFormaLente() const { return formaLente; }
    void setFormaLente(const string& forma) { formaLente = forma; }

    bool getProteccionUV() const { return proteccionUV; }
    void setProteccionUV(bool uv) { proteccionUV = uv; }

    // Mostrar información
    void mostrarInformacion() const override {
        Accesorio::mostrarInformacion();
        cout << "Forma de Lente: " << formaLente << "\n"
             << "Protección UV: " << (proteccionUV ? "Sí" : "No") << "\n";
    }

    // Destructor
    virtual ~GafasDeSol() {}
};

class Gorra : public Accesorio {
private:
    string tipo;    // Tipo de gorra
    string material; // Material de la gorra

public:
    // Constructor
    Gorra(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, const string& tip, const string& mat)
        : Accesorio("Gorra", cod, precioV, cant, temp, gen, est), tipo(tip), material(mat) {}

    // Getters y Setters
    string getTipo() const { return tipo; }
    void setTipo(const string& tip) { tipo = tip; }

    string getMaterial() const { return material; }
    void setMaterial(const string& mat) { material = mat; }

    // Mostrar información
    void mostrarInformacion() const override {
        Accesorio::mostrarInformacion();
        cout << "Tipo: " << tipo << "\n"
             << "Material: " << material << "\n";
    }

    // Destructor
    virtual ~Gorra() {}
};

// Clase Almacen
class Almacen {
private:
    vector<Camiseta> camisetasDisponibles;      // Productos de tipo Camiseta
    vector<Bufanda> bufandasDisponibles;        // Productos de tipo Bufanda
    vector<Sudadera> sudaderasDisponibles;      // Productos de tipo Sudadera
    vector<Pantalon> pantalonesDisponibles;     // Productos de tipo pantalon
    vector<GafasDeSol> gafasDeSolDisponibles;   // Productos de tipo Gafas de Sol
    vector<Gorra> gorrasDisponibles;            // Productos de tipo Gorra


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
        // Ejemplos de Gafas de Sol
        gafasDeSolDisponibles.push_back(GafasDeSol("G001", 79.99, 30, Temporada::VERANO, Genero::HOMBRE, Estilo::MODERNO, "Cuadrada", true));
        gafasDeSolDisponibles.push_back(GafasDeSol("G002", 59.99, 25, Temporada::ANUAL, Genero::MUJER, Estilo::CLASICO, "Redonda", false));
        
        // Ejemplos de Gorras
        gorrasDisponibles.push_back(Gorra("GR001", 19.99, 50, Temporada::VERANO, Genero::HOMBRE, Estilo::CASUAL, "Snapback", "Algodón"));
        gorrasDisponibles.push_back(Gorra("GR002", 24.99, 40, Temporada::VERANO, Genero::MUJER, Estilo::DEPORTIVO, "Visera", "Poliéster"));
    }

    const vector<Camiseta>& getCamisetas() const { return camisetasDisponibles; }
    const vector<Bufanda>& getBufandas() const { return bufandasDisponibles; }
    const vector<Sudadera>& getSudaderas() const { return sudaderasDisponibles; }
    const vector<Pantalon>& getPantalones() const { return pantalonesDisponibles; }
    const vector<GafasDeSol>& getGafasDeSol() const { return gafasDeSolDisponibles; }
    const vector<Gorra>& getGorras() const { return gorrasDisponibles; }

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
    vector<Camiseta> camisetasEnInventario;         // Camisetas
    vector<Sudadera> sudaderasEnInventario;         // Sudaderas
    vector<Pantalon> pantalonesEnInventario;        // Pantalones
    vector<Bufanda> bufandasEnInventario;           // Bufandas
    vector<GafasDeSol> gafasDeSolEnInventario;      // Gafas de sol
    vector<Gorra> gorrasEnInventario;               // Gorra
    
    
public:
    Inventario() {
        camisetasEnInventario.clear();
        bufandasEnInventario.clear();
        sudaderasEnInventario.clear();
        pantalonesEnInventario.clear();
        gafasDeSolEnInventario.clear();
        gorrasEnInventario.clear();
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
        // Buscar en las Gafas de Sol
        if (!productoEncontrado) {
            for (auto& gafasDeSol : gafasDeSolEnInventario) {
                if (gafasDeSol.getCodProducto() == codigo) {
                    gafasDeSol.setCantidad(gafasDeSol.getCantidad() + cantidad);
                    cout << "gafas De Sol " << codigo << " actualizada. Nueva cantidad: " << gafasDeSol.getCantidad() << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        // Buscar en las Gorras
        if (!productoEncontrado) {
            for (auto& gorra : gorrasEnInventario) {
                if (gorra.getCodProducto() == codigo) {
                    gorra.setCantidad(gorra.getCantidad() + cantidad);
                    cout << "Gorra " << codigo << " actualizada. Nueva cantidad: " << gorra.getCantidad() << "\n";
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
            for (const auto& gafas : almacen.getGafasDeSol()) {
                if (gafas.getCodProducto() == codigo) {
                    GafasDeSol nuevasGafas = gafas;
                    nuevasGafas.setCantidad(cantidad);
                    gafasDeSolEnInventario.push_back(nuevasGafas);
                    cout << "Gafas de Sol " << codigo << " añadidas al inventario. Cantidad: " << cantidad << "\n";
                    productoEncontrado = true;
                    break;
                }
            }
        }
        
        if (!productoEncontrado) {
            for (const auto& gorra : almacen.getGorras()) {
                if (gorra.getCodProducto() == codigo) {
                    Gorra nuevaGorra = gorra;
                    nuevaGorra.setCantidad(cantidad);
                    gorrasEnInventario.push_back(nuevaGorra);
                    cout << "Gorra " << codigo << " añadida al inventario. Cantidad: " << cantidad << "\n";
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
        
        cout << "\n=== Gafas de Sol ===\n";
        for (const auto& gafas : gafasDeSolEnInventario) {
            gafas.mostrarInformacion();
            cout << "-------------------\n";
        }
        
        cout << "\n=== Gorras ===\n";
        for (const auto& gorra : gorrasEnInventario) {
            gorra.mostrarInformacion();
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
        
        // Guardar cantidad de Gafas de Sol
        archivo << "GafasDeSol\n" << gafasDeSolEnInventario.size() << "\n";
        for (const auto& gafas : gafasDeSolEnInventario) {
            archivo << gafas.getCodProducto() << "\n"
            << gafas.getCantidad() << "\n"
            << gafas.getPrecioVenta() << "\n"
            << temporadaToString(gafas.getTemporada()) << "\n"
            << generoToString(gafas.getGenero()) << "\n"
            << estiloTostring(gafas.getEstilo()) << "\n"
            << gafas.getFormaLente() << "\n"
            << (gafas.getProteccionUV() ? "Sí" : "No") << "\n";
        }
        
        // Guardar cantidad de Gorras
        archivo << "Gorras\n" << gorrasEnInventario.size() << "\n";
        for (const auto& gorra : gorrasEnInventario) {
            archivo << gorra.getCodProducto() << "\n"
            << gorra.getCantidad() << "\n"
            << gorra.getPrecioVenta() << "\n"
            << temporadaToString(gorra.getTemporada()) << "\n"
            << generoToString(gorra.getGenero()) << "\n"
            << estiloTostring(gorra.getEstilo()) << "\n"
            << gorra.getTipo() << "\n"
            << gorra.getMaterial() << "\n";
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
        pantalonesEnInventario.clear();
        gafasDeSolEnInventario.clear();
        gorrasEnInventario.clear();
        
        string linea, codigo, temporadaStr, generoStr, tallaStr, tipoCamisetaStr, material, estampadoStr, estiloStr, lanaStr, tipoSudaderaStr, cremStr, tipoPantalonStr, cargoStr, formaLente, uv, tipoGorra, materialGorra;;
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
        
        // Cargar gafas de sol
        getline(archivo, linea); // "GafasDeSol"
        size_t numGafasDeSol;
        archivo >> numGafasDeSol;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        
        for (size_t i = 0; i < numGafasDeSol; i++) {
            getline(archivo, codigo);
            archivo >> cantidad >> precio;
            archivo.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(archivo, temporadaStr);
            getline(archivo, generoStr);
            getline(archivo, estiloStr);
            getline(archivo, formaLente);
            getline(archivo, uv);
            
            Temporada temporada = stringToTemporada(temporadaStr);
            Genero genero = stringToGenero(generoStr);
            Estilo estilo = stringToEstilo(estiloStr);
            bool proteccionUV = (uv == "Sí");
            
            gafasDeSolEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, estilo, formaLente, proteccionUV);
        }
        
        // Cargar gorras
        getline(archivo, linea); // "Gorras"
        size_t numGorras;
        archivo >> numGorras;
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        
        for (size_t i = 0; i < numGorras; i++) {
            getline(archivo, codigo);
            archivo >> cantidad >> precio;
            archivo.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(archivo, temporadaStr);
            getline(archivo, generoStr);
            getline(archivo, estiloStr);
            getline(archivo, tipoGorra);
            getline(archivo, materialGorra);
            
            Temporada temporada = stringToTemporada(temporadaStr);
            Genero genero = stringToGenero(generoStr);
            Estilo estilo = stringToEstilo(estiloStr);
            
            gorrasEnInventario.emplace_back(codigo, precio, cantidad, temporada, genero, estilo, tipoGorra, materialGorra);
        }
    }
    
    void consultarPorCategoria(const string& categoria) const {
        cout << "\n=== Consultando productos de la categoría: " << categoria << " ===\n";
        
        if (categoria == "Camiseta") {
            for (const auto& camiseta : camisetasEnInventario) {
                camiseta.mostrarInformacion();
                cout << "-------------------\n";
            }
        } else if (categoria == "Sudadera") {
            for (const auto& sudadera : sudaderasEnInventario) {
                sudadera.mostrarInformacion();
                cout << "-------------------\n";
            }
        } else if (categoria == "Pantalon") {
            for (const auto& pantalon : pantalonesEnInventario) {
                pantalon.mostrarInformacion();
                cout << "-------------------\n";
            }
        } else if (categoria == "Bufanda") {
            for (const auto& bufanda : bufandasEnInventario) {
                bufanda.mostrarInformacion();
                cout << "-------------------\n";
            }
        } else if (categoria == "Gafas de sol") {
            for (const auto& gafas : gafasDeSolEnInventario) {
                gafas.mostrarInformacion();
                cout << "-------------------\n";
            }
        } else if (categoria == "Gorra") {
            for (const auto& gorra : gorrasEnInventario) {
                gorra.mostrarInformacion();
                cout << "-------------------\n";
            }
        } else {
            cout << "Categoría no válida.\n";
        }
    }
    
    string generarCodigoTransaccion(const string& codigoProducto) {
        // Inicializar la semilla de números aleatorios solo una vez
        static bool semillaInicializada = false;
        if (!semillaInicializada) {
            srand(time(nullptr));
            semillaInicializada = true;
        }
        
        string codigo = "TX-" + codigoProducto;
        const char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const int numeroAleatorio = rand() % 10; // Número entre 0 y 9
        
        // Generar dos letras aleatorias
        char letra1 = letras[rand() % (sizeof(letras) - 1)];
        char letra2 = letras[rand() % (sizeof(letras) - 1)];
        
        // Construir el código
        codigo += letra1;
        codigo += to_string(numeroAleatorio);
        codigo += letra2;
        
        return codigo;
    }
    
    void registrarCambio(const string& tiendaNombre) {
        string codigoProductoCambiado, codigoProductoCambio;

        // Solicitar código del producto que se cambia
        cout << "Ingrese el código del producto que se cambia: ";
        cin >> codigoProductoCambiado;

        // Solicitar código del producto por el que se cambia
        cout << "Ingrese el código del producto por el que se cambia: ";
        cin >> codigoProductoCambio;

        Producto* productoSaliente = nullptr;
        Producto* productoEntrante = nullptr;

        // Buscar ambos productos en el inventario
        for (auto& camiseta : camisetasEnInventario) {
            if (camiseta.getCodProducto() == codigoProductoCambiado) {
                productoSaliente = &camiseta;
            }
            if (camiseta.getCodProducto() == codigoProductoCambio) {
                productoEntrante = &camiseta;
            }
        }

        for (auto& sudadera : sudaderasEnInventario) {
            if (sudadera.getCodProducto() == codigoProductoCambiado) {
                productoSaliente = &sudadera;
            }
            if (sudadera.getCodProducto() == codigoProductoCambio) {
                productoEntrante = &sudadera;
            }
        }
        
        for (auto& pantalon : pantalonesEnInventario) {
                if (pantalon.getCodProducto() == codigoProductoCambiado) {
                    productoSaliente = &pantalon;
                }
                if (pantalon.getCodProducto() == codigoProductoCambio) {
                    productoEntrante = &pantalon;
                }
            }

        for (auto& bufanda : bufandasEnInventario) {
            if (bufanda.getCodProducto() == codigoProductoCambiado) {
                productoSaliente = &bufanda;
            }
            if (bufanda.getCodProducto() == codigoProductoCambio) {
                productoEntrante = &bufanda;
            }
        }

        for (auto& gafas : gafasDeSolEnInventario) {
            if (gafas.getCodProducto() == codigoProductoCambiado) {
                productoSaliente = &gafas;
            }
            if (gafas.getCodProducto() == codigoProductoCambio) {
                productoEntrante = &gafas;
            }
        }

        for (auto& gorra : gorrasEnInventario) {
            if (gorra.getCodProducto() == codigoProductoCambiado) {
                productoSaliente = &gorra;
            }
            if (gorra.getCodProducto() == codigoProductoCambio) {
                productoEntrante = &gorra;
            }
        }

        // Validar si ambos productos exsiten
        if (!productoSaliente) {
            cout << "El producto con código \"" << codigoProductoCambiado << "\" no se encuentra en el inventario." << endl;
            return;
        }

        if (!productoEntrante) {
            cout << "El producto con código \"" << codigoProductoCambio << "\" no se encuentra en el inventario." << endl;
            return;
        }

        // Mostrar información de ambos productos
        cout << "--------------------------------------" << endl;
        cout << "Producto que se devuelve:" << endl;
        productoSaliente->mostrarInformacion();
        cout << "--------------------------------------" << endl;
        cout << "Producto que se lleva:" << endl;
        productoEntrante->mostrarInformacion();

        // Confirmar el cambio
        cout << "¿Desea confirmar el cambio? (s/n): ";
        char confirmacion;
        cin >> confirmacion;

        if (tolower(confirmacion) == 's') {
            // Ajustar cantidades
            productoSaliente->setCantidad(productoSaliente->getCantidad() + 1);
            productoEntrante->setCantidad(productoEntrante->getCantidad() - 1);

            // Generar un código de transacción
            string codigoTransaccion = generarCodigoTransaccion(productoSaliente->getCodProducto() + "-" + productoEntrante->getCodProducto());

            // Registrar el cambio en el archivo
            registrarCambioEnArchivo(tiendaNombre, productoSaliente->getCodProducto(), productoEntrante->getCodProducto(), codigoTransaccion);

            // Confirmar al usuario
            cout << "Cambio registrado exitosamente." << endl;
            cout << "Detalles del cambio:" << endl;
            cout << " - Código de transacción: " << codigoTransaccion << endl;
            cout << " - Código del producto cambiado: " << productoSaliente->getCodProducto() << endl;
            cout << " - Código del producto llevado: " << productoEntrante->getCodProducto() << endl;
        } else {
            cout << "Cambio cancelado." << endl;
        }
    }

    void registrarCambioEnArchivo(const string& tienda, const string& codigoProductoSaliente,
                                  const string& codigoProductoEntrante, const string& codigoTransaccion) {
        ofstream archivo("transacciones.txt", ios::app);
        if (!archivo) {
            cerr << "Error al abrir el archivo transacciones.txt." << endl;
            return;
        }
    
        time_t ahora = time(nullptr);
        tm* tiempoLocal = localtime(&ahora);

        archivo << "Código de transacción: " << codigoTransaccion << endl;
        archivo << "Tipo de operación: Cambio" << endl;
        archivo << "Fecha y hora: "
                << tiempoLocal->tm_year + 1900 << "-"
                << setw(2) << setfill('0') << tiempoLocal->tm_mon + 1 << "-"
                << setw(2) << setfill('0') << tiempoLocal->tm_mday << " "
                << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":"
                << setw(2) << setfill('0') << tiempoLocal->tm_min << ":"
                << setw(2) << setfill('0') << tiempoLocal->tm_sec << endl;
        archivo << "Tienda: " << tienda << endl;
        archivo << "Código del producto cambiado: " << codigoProductoSaliente << endl;
        archivo << "Código del producto llevado: " << codigoProductoEntrante << endl;
        archivo << "--------------------------------------" << endl;

        archivo.close();
    }
    
    void registrarDevolucion(const string& tiendaNombre) {
        string codigoProducto;
        cout << "Ingrese el código del producto que desea devolver: ";
        cin >> codigoProducto;
        
        // Buscar el producto en cada contenedor
        for (auto& camiseta : camisetasEnInventario) {
            if (camiseta.getCodProducto() == codigoProducto) {
                procesarDevolucion(camiseta, tiendaNombre);
                return;
            }
        }
        
        for (auto& sudadera : sudaderasEnInventario) {
            if (sudadera.getCodProducto() == codigoProducto) {
                procesarDevolucion(sudadera, tiendaNombre);
                return;
            }
        }
        
        for (auto& pantalon : pantalonesEnInventario) {
            if (pantalon.getCodProducto() == codigoProducto) {
                procesarDevolucion(pantalon, tiendaNombre);
                return;
            }
        }
        
        for (auto& bufanda : bufandasEnInventario) {
            if (bufanda.getCodProducto() == codigoProducto) {
                procesarDevolucion(bufanda, tiendaNombre);
                return;
            }
        }
        
        for (auto& gafas : gafasDeSolEnInventario) {
            if (gafas.getCodProducto() == codigoProducto) {
                procesarDevolucion(gafas, tiendaNombre);
                return;
            }
        }
        
        for (auto& gorra : gorrasEnInventario) {
            if (gorra.getCodProducto() == codigoProducto) {
                procesarDevolucion(gorra, tiendaNombre);
                return;
            }
        }
        
        // Si no se encontró el producto
        cout << "El producto con código \"" << codigoProducto << "\" no se encuentra en el inventario." << endl;
    }
    
    
    void procesarDevolucion(Producto& producto, const string& tiendaNombre) {
        producto.mostrarInformacion();
        
        int cantidad;
        cout << "Ingrese la cantidad que desea devolver: ";
        cin >> cantidad;
        
        // Validar cantidad
        if (cantidad <= 0 || cantidad > producto.getCantidad()) {
            cout << "Cantidad no válida. Debe estar entre 1 y " << producto.getCantidad() << "." << endl;
            return;
        }
        
        // Calcular el precio total
        float precioTotal = cantidad * producto.getPrecioVenta();
        
        // Confirmar la devolución
        cout << "El precio total es: " << fixed << setprecision(2) << precioTotal << " €" << endl;
        cout << "¿Desea confirmar la devolución? (s/n): ";
        char confirmacion;
        cin >> confirmacion;
        
        if (tolower(confirmacion) == 's') {
            // Actualizar inventario
            producto.setCantidad(producto.getCantidad() + cantidad);
            
            // Generar un código de transacción
            string codigoTransaccion = generarCodigoTransaccion(producto.getCodProducto());
            
            // Registrar la devolución en el archivo
            registrarDevolucionEnArchivo("Devolución", tiendaNombre, producto.getCodProducto(), cantidad, precioTotal, codigoTransaccion);
            
            // Confirmar al usuario
            cout << "Devolución registrada exitosamente." << endl;
            cout << "Detalles de la transacción:" << endl;
            cout << " - Código de transacción: " << codigoTransaccion << endl;
            cout << " - Cantidad devuelta: " << cantidad << endl;
            cout << " - Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
        } else {
            cout << "Devolución cancelada." << endl;
        }
    }
    
    void registrarDevolucionEnArchivo(const string& tipoOperacion, const string& tienda, const string& codigoProducto,
                                 int cantidad, float precioTotal, const string& codigoTransaccion) {
        ofstream archivo("transacciones.txt", ios::app);
        if (!archivo) {
            cerr << "Error al abrir el archivo transacciones.txt." << endl;
            return;
        }
        
        time_t ahora = time(nullptr);
        tm* tiempoLocal = localtime(&ahora);
        
        archivo << "Código de transacción: " << codigoTransaccion << endl;
        archivo << "Tipo de operación: " << tipoOperacion << endl;
        archivo << "Fecha y hora: "
        << tiempoLocal->tm_year + 1900 << "-"
        << setw(2) << setfill('0') << tiempoLocal->tm_mon + 1 << "-"
        << setw(2) << setfill('0') << tiempoLocal->tm_mday << " "
        << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":"
        << setw(2) << setfill('0') << tiempoLocal->tm_min << ":"
        << setw(2) << setfill('0') << tiempoLocal->tm_sec << endl;
        archivo << "Tienda: " << tienda << endl;
        archivo << "Código de producto: " << codigoProducto << endl;
        archivo << "Cantidad: " << cantidad << endl;
        archivo << "Precio unitario: " << fixed << setprecision(2) << precioTotal / cantidad << " €" << endl;
        archivo << "Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
        archivo << "--------------------------------------" << endl;
        
        archivo.close();
    }

    void registrarVenta(const string& tiendaNombre) {
        string codigoProducto;
        cout << "Ingrese el código del producto que desea vender: ";
        cin >> codigoProducto;
        
        // Buscar el producto en cada contenedor
        for (auto& camiseta : camisetasEnInventario) {
            if (camiseta.getCodProducto() == codigoProducto) {
                procesarVenta(camiseta, tiendaNombre);
                return;
            }
        }
        
        for (auto& sudadera : sudaderasEnInventario) {
            if (sudadera.getCodProducto() == codigoProducto) {
                procesarVenta(sudadera, tiendaNombre);
                return;
            }
        }
        
        for (auto& pantalon : pantalonesEnInventario) {
            if (pantalon.getCodProducto() == codigoProducto) {
                procesarVenta(pantalon, tiendaNombre);
                return;
            }
        }
        
        for (auto& bufanda : bufandasEnInventario) {
            if (bufanda.getCodProducto() == codigoProducto) {
                procesarVenta(bufanda, tiendaNombre);
                return;
            }
        }
        
        for (auto& gafas : gafasDeSolEnInventario) {
            if (gafas.getCodProducto() == codigoProducto) {
                procesarVenta(gafas, tiendaNombre);
                return;
            }
        }
        
        for (auto& gorra : gorrasEnInventario) {
            if (gorra.getCodProducto() == codigoProducto) {
                procesarVenta(gorra, tiendaNombre);
                return;
            }
        }
        
        // Si no se encontró el producto
        cout << "El producto con código \"" << codigoProducto << "\" no se encuentra en el inventario." << endl;
    }
    
    
    void procesarVenta(Producto& producto, const string& tiendaNombre) {
        producto.mostrarInformacion();
        
        int cantidad;
        cout << "Ingrese la cantidad que desea vender: ";
        cin >> cantidad;
        
        // Validar cantidad
        if (cantidad <= 0 || cantidad > producto.getCantidad()) {
            cout << "Cantidad no válida. Debe estar entre 1 y " << producto.getCantidad() << "." << endl;
            return;
        }
        
        // Calcular el precio total
        float precioTotal = cantidad * producto.getPrecioVenta();
        
        // Confirmar la venta
        cout << "El precio total es: " << fixed << setprecision(2) << precioTotal << " €" << endl;
        cout << "¿Desea confirmar la venta? (s/n): ";
        char confirmacion;
        cin >> confirmacion;
        
        if (tolower(confirmacion) == 's') {
            // Actualizar inventario
            producto.setCantidad(producto.getCantidad() - cantidad);
            
            // Generar un código de transacción
            string codigoTransaccion = generarCodigoTransaccion(producto.getCodProducto());
            
            // Registrar la venta en el archivo
            registrarVentaEnArchivo("Venta", tiendaNombre, producto.getCodProducto(), cantidad, precioTotal, codigoTransaccion);
            
            // Confirmar al usuario
            cout << "Venta registrada exitosamente." << endl;
            cout << "Detalles de la transacción:" << endl;
            cout << " - Código de transacción: " << codigoTransaccion << endl;
            cout << " - Cantidad vendida: " << cantidad << endl;
            cout << " - Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
        } else {
            cout << "Venta cancelada." << endl;
        }
    }
    
    void registrarVentaEnArchivo(const string& tipoOperacion, const string& tienda, const string& codigoProducto,
                                 int cantidad, float precioTotal, const string& codigoTransaccion) {
        ofstream archivo("transacciones.txt", ios::app);
        if (!archivo) {
            cerr << "Error al abrir el archivo transacciones.txt." << endl;
            return;
        }
        
        time_t ahora = time(nullptr);
        tm* tiempoLocal = localtime(&ahora);
        
        archivo << "Código de transacción: " << codigoTransaccion << endl;
        archivo << "Tipo de operación: " << tipoOperacion << endl;
        archivo << "Fecha y hora: "
        << tiempoLocal->tm_year + 1900 << "-"
        << setw(2) << setfill('0') << tiempoLocal->tm_mon + 1 << "-"
        << setw(2) << setfill('0') << tiempoLocal->tm_mday << " "
        << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":"
        << setw(2) << setfill('0') << tiempoLocal->tm_min << ":"
        << setw(2) << setfill('0') << tiempoLocal->tm_sec << endl;
        archivo << "Tienda: " << tienda << endl;
        archivo << "Código de producto: " << codigoProducto << endl;
        archivo << "Cantidad: " << cantidad << endl;
        archivo << "Precio unitario: " << fixed << setprecision(2) << precioTotal / cantidad << " €" << endl;
        archivo << "Precio total: " << fixed << setprecision(2) << precioTotal << " €" << endl;
        archivo << "--------------------------------------" << endl;
        
        archivo.close();
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

// Función para mostrar el menú de gestión del inventario
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
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo.\n";
        }
    } while (opcion != 6);
}

// Función principal para cambiar entre tiendas
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
                if (codigoVerificacion == "1234") {
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
                if (codigoVerificacion == "2345") {
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



void iniciarPrograma(){
    // Crear el almacén
    Almacen almacen;
    
    // Crear las tiendas
    Tienda madrid("Madrid", "inventarioMadrid.txt");
    Tienda barcelona("Barcelona", "inventarioBarcelona.txt");
    //Tienda Valencia("Valencia", "inventarioValencia.txt");
    //Tienda Sevilla("Sevilla", "inventarioSevilla.txt");
    //Tienda Bilbao("Bilbao", "inventarioBilbao.txt");

        
    // Mostrar el menú principal
    menuTiendas(madrid, barcelona, almacen);
}
    
    
int main() {
    
    iniciarPrograma();
    
    return 0;
}
