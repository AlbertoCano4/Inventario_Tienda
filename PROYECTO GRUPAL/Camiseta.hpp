#ifndef CAMISETA_HPP
#define CAMISETA_HPP

#include "ropa.hpp"  // Incluimos la clase padre (Producto-> Ropa -> Camiseta)

class Camiseta : public Ropa {
private:
    TipoCamiseta tipo;
    string material;
    string estilo;
public:
    // Constructor
    Camiseta(string cod, float precioV, int cant, Genero gen, Talla t, TipoCamiseta tip, string mat, string est);
    // Destructor virtual
    virtual ~Camiseta() = default;
    
    // Getters y Setters
    TipoCamiseta getTipo() const;
    void setTipo(TipoCamiseta t);
    string getMaterial() const;
    void setMaterial(string mat);
    string getEstilo() const;
    void setEstilo(string est);
    
    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() override;
};

#endif // ROPA_HPP
