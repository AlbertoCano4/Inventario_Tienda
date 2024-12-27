#ifndef CAMISETA_HPP
#define CAMISETA_HPP

#include "Ropa.hpp"

enum class TipoCamiseta { MANGA_LARGA, MANGA_CORTA, TIRANTES };

class Camiseta : public Ropa {
private:
    TipoCamiseta tipo;
    std::string material;
    bool estampado;

public:
    // Constructor
    Camiseta(string cod, float precioV, int cant, Temporada temp,Genero gen, Talla t, TipoCamiseta tip, string mat, bool est);

    // Destructor
    virtual ~Camiseta() = default;

    // Getters y Setters
    TipoCamiseta getTipoCamiseta() const;
    void setTipo(TipoCamiseta t);
    string getMaterial() const;
    void setMaterial(std::string mat);
    bool getEstampado() const;
    void setEstampado(bool est);
    
    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() const override;


};

#endif // CAMISETA_HPP
