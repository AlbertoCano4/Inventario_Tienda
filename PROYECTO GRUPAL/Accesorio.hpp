#ifndef ACCESORIO_HPP
#define ACCESORIO_HPP

#include "Producto.hpp"

class Accesorio : public Producto {
protected:
    Estilo estilo; // Estilo del accesorio

public:
    // Constructor
    Accesorio(string tipoProducto, string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est);

    // Implementación del método mostrarInformacion
    void mostrarInformacion() const override;

    // Getter de Estilo
    Estilo getEstilo() const;

    // Setter de Estilo
    void setEstilo(Estilo est);

    virtual ~Accesorio();
};

#endif // ACCESORIO_HPP
