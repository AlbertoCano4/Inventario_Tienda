#ifndef SUDADERA_HPP
#define SUDADERA_HPP

#include "ropa.hpp"  // Incluimos la clase padre (Producto-> Ropa -> Camiseta)

class Sudadera : public Ropa {
private:
    TipoSudadera tipo;
    string material;
    bool cremallera;
public:
    // Constructor
    Sudadera(string cod, float precioV, int cant, Genero gen, Talla t, TipoSudadera tip, string mat, bool crem);
    // Destructor virtual
    virtual ~Sudadera() = default;
    
    // Getters y Setters
    TipoSudadera getTipoSudadera() const;
    void setTipoSudadera(TipoSudadera tip);
    string getMaterial() const;
    void setMaterial(string mat);
    bool getCremallera();
    void setCremallera(bool crem);
    
    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() override;
};

#endif // SUDADERA_HPP
