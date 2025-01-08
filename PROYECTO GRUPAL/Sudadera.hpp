#ifndef SUDADERA_HPP
#define SUDADERA_HPP

#include "Ropa.hpp" // Incluye la definición de la clase base `Ropa`.

// Clase derivada que representa una sudadera, hereda de Ropa
class Sudadera : public Ropa {
private:
    TipoSudadera tipo;
    string material;
    bool cremallera;

public:
    // Constructor
    Sudadera(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Talla t,
             TipoSudadera tip, const string& mat, bool crem);

    // Getters
    TipoSudadera getTipoSudadera() const;
    string getMaterial() const;
    bool getCremallera() const;

    // Setters
    void setTipoSudadera(TipoSudadera tip);
    void setMaterial(const string& mat);
    void setCremallera(bool crem);

    // Mostrar información
    void mostrarInformacion() const override;

    // Destructor
    virtual ~Sudadera();
};

#endif // SUDADERA_HPP
