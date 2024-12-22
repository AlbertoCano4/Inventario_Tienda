#ifndef GORRA_HPP
#define GORRA_HPP

#include "accesorio.hpp"  // Incluimos la clase padre (Producto-> Ropa -> Gorra)

class Gorra : public Accesorio {
private:
    string tipo;
    string material;
public:
    // Constructor
    Gorra(string cod, float precioV, int cant, Genero gen, Temporada temp, string tip, string mat);
    // Destructor virtual
    virtual ~Gorra() = default;
    
    // Getters y Setters
    string getTipo() const;
    void setTipoGorra(string tip);
    string getMaterial() const;
    void setMaterial(string mat_acc);
    
    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() override;
};

#endif // GORRA_HPP
