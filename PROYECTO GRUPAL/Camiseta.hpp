#ifndef CAMISETA_HPP
#define CAMISETA_HPP

#include "Ropa.hpp" // Incluye la definición de la clase base `Ropa`.

// Clase derivada que representa una Camiseta, hereda de Ropa
class Camiseta : public Ropa {
private:
    TipoCamiseta tipo;
    string material;
    bool estampado;

public:
    // Constructor Camiseta
    Camiseta(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t, TipoCamiseta tip, const string& mat, bool est);

    // Método para mostrar la información
    void mostrarInformacion() const override;

    // Getters
    TipoCamiseta getTipo() const;
    string getMaterial() const;
    bool getEstampado() const;

    // Setters
    void setMaterial(const string& mat);
    void setEstampado(bool est);

    ~Camiseta();
};

#endif // CAMISETA_HPP
