#ifndef GAFASDESOL_HPP
#define GAFASDESOL_HPP

#include "accesorio.hpp"  // Incluimos la clase padre (Producto-> Ropa -> Gafas de sol)

class GafasDeSol : public Accesorio {
private:
    string formaLente;
    bool proteccionUV;
public:
    // Constructor
    GafasDeSol(string cod, float precioV, int cant, Genero gen, Temporada temp, string forma, bool uv);
    // Destructor virtual
    virtual ~GafasDeSol() = default;
    
    // Getters y Setters
    string getFormaLente() const;
    void setFormaLente(string form_lente);
    bool getProteccionUV();
    void setProteccionUV(bool protec_UV);
    
    // Método que sobreescribe el de la clase padre
    void mostrarInformacion() override;
};

#endif // GAFASDESOL_HPP
