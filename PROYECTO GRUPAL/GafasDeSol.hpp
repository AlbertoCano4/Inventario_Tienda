#ifndef GAFASDESOL_HPP
#define GAFASDESOL_HPP

#include "Accesorio.hpp" // Incluye la definición de la clase base Accesorio.

// Clase derivada que representa unas gafas de sol, hereda de Accesorio
class GafasDeSol : public Accesorio {
private:
    string formaLente;
    bool proteccionUV;

public:
    // Constructor
    GafasDeSol(const string& cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, const string& forma, bool uv);

    // Getters
    string getFormaLente() const;
    bool getProteccionUV() const;

    // Setters
    void setFormaLente(const string& forma);
    void setProteccionUV(bool uv);

    // Mostrar información
    void mostrarInformacion() const override;

    // Destructor
    virtual ~GafasDeSol();
};

#endif 
