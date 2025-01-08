#ifndef DEFINICIONES_HPP
#define DEFINICIONES_HPP

#include <string>
using namespace std;

// Enumeraciones para clasificar características de productos.
enum class Temporada { INVIERNO, VERANO, ANUAL };
enum class Genero { HOMBRE, MUJER };
enum class Talla { S, M, L, XL, XXL };
enum class TipoCamiseta { MANGA_CORTA, MANGA_LARGA, SIN_MANGAS };
enum class Estilo { MODERNO, CLASICO, DEPORTIVO, CASUAL };
enum class TipoSudadera { CREWNECK, HOODIE };
enum class TipoPantalon { LARGO, CORTO };

// Funciones para convertir enumeraciones a cadenas de texto.
string temporadaToString(Temporada temporada);
string generoToString(Genero genero);
string tallaToString(Talla talla);
string tipoCamisetaToString(TipoCamiseta tipo);
string estiloTostring(Estilo est);
string tipoSudaderaToString(TipoSudadera tipo);
string tipoPantalonToString(TipoPantalon tipo);

// Funciones para convertir cadenas de texto a enumeraciones.
Temporada stringToTemporada(const string& str);
Genero stringToGenero(const string& str);
Talla stringToTalla(const string& str);
TipoCamiseta stringToTipoCamiseta(const string& str);
Estilo stringToEstilo(const string& str);
TipoSudadera stringToTipoSudadera(const string& str);
TipoPantalon stringToTipoPantalon(const string& str);

#endif 
