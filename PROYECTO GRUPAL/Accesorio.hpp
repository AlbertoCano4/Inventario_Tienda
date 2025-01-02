#ifndef ACCESORIO_HPP
#define ACCESORIO_HPP

#include "Producto.hpp"  // Clase base Producto

enum class Estilo { MODERNO, CLASICO, DEPORTIVO, CASUAL };

// Clase abstracta Accesorio
class Accesorio : public Producto {
protected:
    Estilo estilo; // Estilo del accesorio

public:
    // Constructor
    Accesorio(string tipoProducto, string cod, float precioV, int cant, Temporada temp, Genero gen ,Estilo est);

    // Destructor virtual
    virtual ~Accesorio() = default;

    // Getters y Setters
    Estilo getEstilo() const;
    void setEstilo(Estilo est);

    // Método abstracto que sobreescribe el de Producto
    virtual void mostrarInformacion() const = 0; // Accesorio sigue siendo abstracta
};

#endif // ACCESORIO_HPP
