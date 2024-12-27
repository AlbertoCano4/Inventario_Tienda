#ifndef GAFASDESOL_HPP
#define GAFASDESOL_HPP

#include "accesorio.hpp"

class GafasDeSol : public Accesorio {
private:
    string formaLente;
    bool proteccionUV;

public:
    // Constructor
    GafasDeSol(string cod, float precioV, int cant, Temporada temp, Genero gen, Estilo est, string forma, bool uv);

    // Destructor
    virtual ~GafasDeSol() = default;

    // Getters y Setters
    string getFormaLente() const;
    void setFormaLente(string forma);
    bool getProteccionUV() const;
    void setProteccionUV(bool uv);

    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() const override;
};

#endif // GAFASDESOL_HPP
