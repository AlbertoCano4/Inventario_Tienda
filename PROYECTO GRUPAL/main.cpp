/*
 Trabajo Proyectos de Programación
 Grupo formado por: Sofía Azpiroz, Paloma Belenguer, Alberto Cano, Ignacio Fernández, Gonzalo Ruiz.
 
 Inventario de tienda
 
 COSAS QUE AÑADIR:
 1. Añadir que la clase Inventario reconozca que existen varias tiendas
 2. Crear una clase almacen que tenga Q ilimitada de productos que vende la tienda
 3. Permitir que una tienda pueda pasar ropa a otra (Ej: Tienda de madrid sold out de producto x y la tienda de Barcelona no vende ese producto x, hacer una función que permita mandar ropa de una tienda a otra (restar a Barcelona y Sumar a madrid))
 4. Crear los Headers .hpp y .cpp de las clases
 5. Hacer que funcione bien venderProducto, aniadirProducto, cambiarProducto, devolverProducto --> Todo en la clase producto
 6. ¿DONDE PONEMOS LOS MÉTODOS DEL MENU PRINCIPAL en clase Producto o de clase Inventario?
 */

#include "Menu.hpp"

#include <iostream>
#include <vector>

using namespace std;

enum class Genero { MUJER, HOMBRE };
enum class Talla { S, M, L, XL, XXL };
enum class TipoCamiseta { MANGA_LARGA, MANGA_CORTA, TIRANTES };
enum class TipoSudadera { CREWNECK, HOODIE };
enum class TipoPantalon { LARGO, CORTO };
enum class Temporada { INVIERNO, VERANO, ANUAL };

// Clase producto de la que heradan Ropa y Accesorios
class Producto{
//Atributos clase Producto
protected:
    string codProducto;     // Clave Primaria
    float precioVenta;
    int cantidad;
    bool disponible;
    Genero genero;
    
public:
    //Constructor clase Producto
    Producto(string cod, float precioV, int cant, Genero gen)
            : codProducto(cod), precioVenta(precioV), cantidad(cant), disponible(cant > 0), genero(gen) {}
    
    //Getters y Setters
    string getCodProducto(){
        return codProducto;
    }
    

    void setCodProducto(string cod_prod){
        codProducto = cod_prod;
    }
    
    float getPrecioVenta(){
           return precioVenta;
    }

    void setPrecioVenta(float precio_venta) {
           precioVenta = precio_venta;
    }

    int getCantidad(){
           return cantidad;
    }

    void setCantidad(int cant) {
           cantidad = cant;
    }

    bool isDisponible(){
           return disponible;
    }

    void setDisponible(bool disp) {
           disponible = disp;
    }

    Genero getGenero(){
           return genero;
    }

    void setGenero(Genero gen) {
           genero = gen;
    }

    // Método virtual para que producto sea una clase abstracta y Opción 1 del Menú inicial
    virtual void mostrarInformacion() {
            cout << "Código de Producto: " << codProducto << endl;
            cout << "Precio de Venta: " << precioVenta << "€" << endl;
            cout << "Cantidad: " << cantidad << endl;
            cout << "Disponible: " << (disponible ? "Sí" : "No") << endl;
            cout << "Género: " << (genero == Genero::MUJER ? "Mujer" : "Hombre") << endl;
        }
    
    //Opción 2 del Menú inicial
    void venderProducto(){  //Vender significa reducir ese producto la Q vendida del inventario
        string codProductoVendido;
        int q;
        
        do{
            cout << "INTRODUZCA EL CÓDIGO DEL PRODUCTO QUE QUIERA VENDER: ";
            cin >> codProductoVendido;
            
            if (codProductoVendido != codProducto) {
                cout << "Ese prodecuto NO EXISTE, vuelve a introducir un código correcto" << endl;
            }
        }while(codProductoVendido != codProducto);
        
        cout << "El Producto que quieres vender es este:" << endl;
        mostrarInformacion();
        
        cout << "Quedan " << cantidad << "Unidades de ese producto" << endl;
        cout << "¿Cuánta cantidad de ese producto quieres vender?: ";
        cin >> q;
        
        cantidad -= q;
    }
    //Opción 3 del Menú inicial
    void aniadirProductoATienda(){ //Añadimos productos a la tienda
        string codProductoComprado;
        int q;
        
        do{
            cout << "INTRODUZCA EL CÓDIGO DEL PRODUCTO QUE QUIERA AÑADIR A TIENDA: ";
            cin >> codProductoComprado;
            
            if (codProductoComprado != codProducto) {
                cout << "Ese prodecuto NO EXISTE, vuelve a introducir un código correcto" << endl;
            }
        }while(codProductoComprado != codProducto);
        
        cout << "El Producto que quieres añadir es este: " << endl;
        mostrarInformacion();
        
        cout << "Quedan " << cantidad << "Unidades de ese producto" << endl;
        cout << "¿Cuánta cantidad de ese producto quieres añadir al almacen?: ";
        cin >> q;
        
        cantidad += q;
    }
    //Opción 4 del Menú inicial
    void devolucionProducto(){
        string codProductoDevuelto;
        int q;
        
        do{
            cout << "INTRODUZCA EL CÓDIGO DEL PRODUCTO QUE QUIERA DEVOLVER A TIENDA: ";
            cin >> codProductoDevuelto;
            
            if (codProductoDevuelto != codProducto) {
                cout << "Ese prodecuto NO EXISTE, vuelve a introducir un código correcto" << endl;
            }
        }while(codProductoDevuelto != codProducto);
        
        cout << "El Producto que quieres devolver es este: " << endl;
        mostrarInformacion();
        
        cout << "¿Cuánta cantidad de ese producto quieres añadir al almacen?: ";
        cin >> q;
        
        cantidad += q;
    }
    //Opción 5 del Menú inicial
    void cambioProducto(){
        string codProductoDevuelto, codProductoCambiado;
        
        do{
            cout << "INTRODUZCA EL CÓDIGO DEL PRODUCTO QUE QUIERA CAMBIAR A TIENDA: ";
            cin >> codProductoDevuelto;
            
            if (codProductoDevuelto != codProducto) {
                cout << "Ese prodecuto NO EXISTE, vuelve a introducir un código correcto" << endl;
            }
        }while(codProductoDevuelto != codProducto);
        
        cout << "¿Qué producto quieres darle al cliente por el cambio? " << endl;
        cout << "Estas son las opciones: " << endl;
        
        /* Esto hará que solo se podrán cambiar productos con el mismo precio de venta
         
         if(precioVentaA[] == precioVentaB[]){
            for (int i = 0; i < qProductosDeEseValor; i++) {
                mostrarInformacion[i]
            }
        }
         */
        
        cout << "Qué producto quiere el cliente: " << endl;
        cin >> codProductoCambiado;
        
        /*
         cantidadProductoDevuelto +=1
         cantidadProductoCambiado -=1
         */
    }
    
};

//Clase Ropa que hereda de Producto
class Ropa: public Producto{
// Atributo diferencial de accesorio
protected:
    Talla talla;
    
public:
    // Constructor Clase Ropa, heredando los atributos de clase principal Producto
    Ropa(string cod, float precioV, int cant, Genero gen, Talla t)
            : Producto(cod, precioV, cant, gen), talla(t) {}
    
    //Getters y Setters
    Talla getTalla(){
        return talla;
    }
    
    void setTalla(Talla t){
        talla = t;
    }
    
    //Método que muestra la info de las Ropa y que hereda la info que muestra la clase principal producto
        void mostrarInformacion() override {
            Producto::mostrarInformacion();
            cout << "Talla: " << static_cast<int>(talla) << endl;  // Convierte Talla a entero para mostrar el valor
        }
};

//Clase Camiseta que hereda de Ropa
class Camiseta : public Ropa{
private:
    TipoCamiseta tipo;
    string material;
    string estilo;

// Constructor Clase Camiseta, heredando los atributos de clase principal Ropa
public:
    Camiseta(string cod, float precioV, int cant, Genero gen, Talla t, TipoCamiseta tip, string mat, string est)
        : Ropa(cod, precioV, cant, gen, t), tipo(tip), material(mat), estilo(est) {}
    
    //Getters y setters
    TipoCamiseta getTipo(){
        return tipo;
      }

    void setTipo(TipoCamiseta t){
        tipo = t;
      }

    string getMaterial(){
        return material;
      }

    void setMaterial(string mat) {
        material = mat;
      }

    string getEstilo(){
        return estilo;
      }

    void setEstilo(string est) {
        estilo = est;
      }
    
    
    //Método que muestra la info de las camisetas y que hereda la info que muestra la clase principal Ropa
    void mostrarInformacion() override {
        Ropa::mostrarInformacion();
        cout << "Tipo de Camiseta: " << static_cast<int>(tipo) << endl;
        cout << "Material: " << material << endl;
        cout << "Estilo: " << estilo << endl;
    }
};

//Clase Sudadera que hereda de Ropa
class Sudadera : public Ropa{
private:
    TipoSudadera tipo;
    string material;
    bool cremallera;

// Constructor Clase Sudadera, heredando los atributos de clase principal Ropa
public:
    Sudadera(string cod, float precioV, int cant, Genero gen, Talla t, TipoSudadera tip, string mat, bool crem)
            : Ropa(cod, precioV, cant, gen, t), tipo(tip), material(mat), cremallera(crem) {}
    
    TipoSudadera getTipoSudadera(){
        return tipo;
    }
    //Getters y setters
    void setTipoSudadera(TipoSudadera tipo_sud){
        tipo = tipo_sud;
    }
    
    string getMaterial(){
        return material;
    }
    
    void setMaterial(string m){
        material = m;
    }
    
    bool getCremallera(){
        return cremallera;
    }
    
    void setCremallera(bool crem){
        cremallera = crem;
    }
     
    //Método que muestra la info de las sudaderas y que hereda la info que muestra la clase principal Ropa
    void mostrarInformacion() override {
        Ropa::mostrarInformacion();
        cout << "Tipo de Sudadera: " << static_cast<int>(tipo) << endl;
        cout << "Material: " << material << endl;
        cout << "Cremallera: " << (cremallera ? "Sí" : "No") << endl;
        }
};

//Clase Pantalon que hereda de Ropa
class Pantalon : public Ropa{
private:
    TipoPantalon tipo;
    bool cargo;

// Constructor Clase Pantalon, heredando los atributos de clase principal Ropa
public:
    Pantalon(string cod, float precioV, int cant, Genero gen, Talla t, TipoPantalon tip, bool carg)
            : Ropa(cod, precioV, cant, gen, t), tipo(tip), cargo(carg) {}
    //Getters y setters
    TipoPantalon getTipo(){
        return tipo;
        }

    void setTipo(TipoPantalon tip) {
        tipo = tip;
        }

    bool getCargo(){
        return cargo;
        }

    void setCargo(bool carg) {
        cargo = carg;
        }

    //Método que muestra la info de los pantalones y que hereda la info que muestra la clase principal Ropa
    void mostrarInformacion() override {
            Ropa::mostrarInformacion();
            cout << "Tipo de Pantalón: " << static_cast<int>(tipo) << endl;
            cout << "Cargo: " << (cargo ? "Sí" : "No") << endl;
        }
    
};

//Clase Accesorio que hereda de Producto
class Accesorio : public Producto{
protected:
    Temporada temporada;

//Constructor Clase Accesorio, heredando los atributos de clase principal Producto
public:
    Accesorio(string cod, float precioV, int cant, Genero gen, Temporada temp)
            : Producto(cod, precioV, cant, gen), temporada(temp) {}
    
    //Getters y setters
    Temporada getTemporada(){
        return temporada;
    }
    
    void setTemporada(Temporada temp){
        temporada = temp;
    }

    //Método que muestra la info de los accesorios y que hereda la info que muestra la clase principal Productos
    void mostrarInformacion() override {
        Producto::mostrarInformacion();
        cout << "Temporada: " << static_cast<int>(temporada) << endl;
        }
};

//Clase Gorra que hereda de Accesorio
class Gorra : public Accesorio{
private:
    string tipo;
    string material;

//Constructor Clase Gorra, heredando los atributos de clase principal Accesorio
public:
    Gorra(string cod, float precioV, int cant, Genero gen, Temporada temp, string tip, string mat)
            : Accesorio(cod, precioV, cant, gen, temp), tipo(tip), material(mat) {}
    
    //Getters y setters
    string getTipo(){
        return tipo;
        }

    void setTipo(string tip){
        tipo = tip;
        }

    string getMaterial(){
        return material;
        }

    void setMaterial(string mat_acc) {
        material = mat_acc;
        }

    //Método que muestra la info de las gorras y que hereda la info que muestra la clase principal Accesorios
    void mostrarInformacion() override {
            Accesorio::mostrarInformacion();
            cout << "Tipo de Gorra: " << tipo << endl;
            cout << "Material: " << material << endl;
        }
};

//Clase GafasDeSol que hereda de Accesorio
class GafasDeSol : public Accesorio{
private:
    string formaLente;
    bool proteccionUV;

//Constructor Clase GafasDeSol, heredando los atributos de clase principal Accesorio
public:
    GafasDeSol(string cod, float precioV, int cant, Genero gen, Temporada temp, string forma, bool uv)
            : Accesorio(cod, precioV, cant, gen, temp), formaLente(forma), proteccionUV(uv) {}
    
    //Getters y setters
     string getFormaLente(){
           return formaLente;
       }

       void setFormaLente(string form_lente) {
           formaLente = form_lente;
       }

       bool getProteccionUV(){
           return proteccionUV;
       }

       void setProteccionUV(bool protec_UV) {
           proteccionUV = protec_UV;
       }

    //Método que muestra la info de las GafasDeSol y que hereda la info que muestra la clase principal Accesorios
    void mostrarInformacion() override {
            Accesorio::mostrarInformacion();
            cout << "Forma de Lente: " << formaLente << endl;
            cout << "Protección UV: " << (proteccionUV ? "Sí" : "No") << endl;
        }
};

//Clase Bufanda que hereda de Accesorio
class Bufanda : public Accesorio{
private:
    string material;
    bool esDeLana;

//Constructor Clase Bufanda, heredando los atributos de clase principal Accesorio
public:
    Bufanda(string cod, string col, float precioV, int cant, Genero gen, Temporada temp, string mat, bool lana)
            : Accesorio(cod, precioV, cant, gen, temp), material(mat), esDeLana(lana) {}
    
    //Getters y setters
    string getMaterial(){
            return material;
        }

    void setMaterial(string mat_bufanda) {
            material = mat_bufanda;
        }

    bool getEsDeLana() {
            return esDeLana;
        }

    void setEsDeLana(bool es_lana) {
        esDeLana = es_lana;
        }

    //Método que muestra la info de las Bufanda y que hereda la info que muestra la clase principal Accesorios
    void mostrarInformacion() override {
        Accesorio::mostrarInformacion();
        cout << "Material: " << material << endl;
        cout << "Es de Lana: " << (esDeLana ? "Sí" : "No") << endl;
        }
};


class Inventario {
private:
    vector<Producto> productos; // Vector para almacenar productos en el inventario.
public:
    Inventario();
    
    //Opción 6 del Menú inicial
    void cambiarTienda(){
        // introduciendo una ciudad donde haya tiendas, cambia el inventario a esa tienda
    }
    
};

int main() {
    iniciarPrograma();
    return 0;
}
