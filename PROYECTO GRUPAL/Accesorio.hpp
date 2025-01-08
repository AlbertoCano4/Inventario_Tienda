#ifndef ACCESORIO_HPP
#define ACCESORIO_HPP

#include "Producto.hpp" // Incluye la clase base Producto, de la que hereda Accesorio.

// Clase derivada que representa un accesorio.
// Hereda los atributos comunes de Producto y añade estilo.
class Accesorio : public Producto {
protected:
    Estilo estilo; // Estilo del accesorio
    
public:
    // Constructor
    // Inicializa los atributos heredados de Producto y el atributo específico estilo.
    Accesorio(string tipoProducto, string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est);
    
    // Implementación del método mostrarInformacion
    // Muestra todos los detalles del accesorio, incluyendo los atributos heredados y el estilo.
    void mostrarInformacion() const override;
    
    // Getter
    // Devuelve el estilo del accesorio.
    Estilo getEstilo() const;
    
    // Setter
    // Permite modificar el estilo del accesorio.
    void setEstilo(Estilo est);
    
    // Destructor virtual
    // Garantiza la destrucción de los objetos de esta clase y sus derivadas.
    virtual ~Accesorio();
};

#endif
