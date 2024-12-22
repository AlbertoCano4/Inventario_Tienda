#ifndef BUFANDA_HPP
#define BUFANDA_HPP

#include "accesorio.hpp"  // Incluimos la clase padre (Producto-> Ropa -> Bufanda)

class Bufanda : public Accesorio {
private:
    string material;
    bool esDeLana;
public:
    // Constructor
    Bufanda(string cod, string col, float precioV, int cant, Genero gen, Temporada temp, string mat, bool lana);
    // Destructor virtual
    virtual ~Bufanda() = default;
    
    // Getters y Setters
    string getMaterial() const;
    void setMaterial(string tip);
    bool getEsDeLana() ;
    void setEsDeLana(bool es_lana);
    
    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() override;
};

#endif // BUFANDA_HPP
