#include "Definiciones.hpp"

// Convertir enums a strings
string temporadaToString(Temporada temporada) {
    switch (temporada) {
        case Temporada::INVIERNO: return "Invierno";
        case Temporada::VERANO: return "Verano";
        case Temporada::ANUAL: return "Anual";
    }
    return "";
}

string generoToString(Genero genero) {
    return (genero == Genero::HOMBRE) ? "Hombre" : "Mujer";
}

string tallaToString(Talla talla) {
    switch (talla) {
        case Talla::S: return "S";
        case Talla::M: return "M";
        case Talla::L: return "L";
        case Talla::XL: return "XL";
        case Talla::XXL: return "XXL";
    }
    return "";
}

string tipoCamisetaToString(TipoCamiseta tipo) {
    switch (tipo) {
        case TipoCamiseta::MANGA_CORTA: return "Manga Corta";
        case TipoCamiseta::MANGA_LARGA: return "Manga Larga";
        case TipoCamiseta::SIN_MANGAS: return "Sin Mangas";
    }
    return "";
}

string estiloTostring(Estilo est) {
    switch (est) {
        case Estilo::MODERNO: return "Moderno";
        case Estilo::CLASICO: return "Clásico";
        case Estilo::DEPORTIVO: return "Deportivo";
        case Estilo::CASUAL: return "Casual";
    }
    return "";
}

string tipoSudaderaToString(TipoSudadera tipo) {
    switch (tipo) {
        case TipoSudadera::CREWNECK: return "Crewneck";
        case TipoSudadera::HOODIE: return "Hoodie";
    }
    return "";
}

string tipoPantalonToString(TipoPantalon tipo) {
    switch (tipo) {
        case TipoPantalon::LARGO: return "Largo";
        case TipoPantalon::CORTO: return "Corto";
    }
    return "";
}

// Convertir strings a enums
Temporada stringToTemporada(const string& str) {
    if (str == "Invierno") return Temporada::INVIERNO;
    if (str == "Verano") return Temporada::VERANO;
    return Temporada::ANUAL;
}

Genero stringToGenero(const string& str) {
    return (str == "Hombre") ? Genero::HOMBRE : Genero::MUJER;
}

Talla stringToTalla(const string& str) {
    if (str == "S") return Talla::S;
    if (str == "M") return Talla::M;
    if (str == "L") return Talla::L;
    if (str == "XL") return Talla::XL;
    return Talla::XXL;
}

TipoCamiseta stringToTipoCamiseta(const string& str) {
    if (str == "Manga Corta") return TipoCamiseta::MANGA_CORTA;
    if (str == "Manga Larga") return TipoCamiseta::MANGA_LARGA;
    return TipoCamiseta::SIN_MANGAS;
}

Estilo stringToEstilo(const string& str) {
    if (str == "Moderno") return Estilo::MODERNO;
    if (str == "Clásico") return Estilo::CLASICO;
    if (str == "Deportivo") return Estilo::DEPORTIVO;
    return Estilo::CASUAL;
}

TipoSudadera stringToTipoSudadera(const string& str) {
    return (str == "Crewneck") ? TipoSudadera::CREWNECK : TipoSudadera::HOODIE;
}

TipoPantalon stringToTipoPantalon(const string& str) {
    return (str == "Largo") ? TipoPantalon::LARGO : TipoPantalon::CORTO;
}
