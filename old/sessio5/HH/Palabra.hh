/** @file Palabra.hh
    @brief Especificación de la clase Palabra 
*/

#ifndef PALABRA_HH
#define PALABRA_HH

//#include "utils.PRO2"
//#include <vector>

/** @class  Palabra
    @brief Representa una lista indexada y acotada de caracteres alfanuméricos.

Los caracteres válidos son 'a'..'z', 'A'..'Z' y '0'..'9'. El resto son
considerados separadores de cara a la lectura  por el canal standard. 

Las operaciones de lectura requieren un parámetro que se usará para
distinguir un separador especial, que sirva por ejemplo para marcar el
final de un texto. Dicho separador especial puede ser cualquier
caracter ASCII del rango 0-127, "visible" y distinto de "a".."z",
"A".."Z" y "0".."9", como "$", "." o "+" (pero no el blanco, el salto
de línea o el tabulador, por no ser visibles, o "ç", "ñ", etc., por no
ser del rango 0-127).
*/
class Palabra
{
private:

  static const int MAXLONG = 20;
  vector<char> letras; 
  /** @invariant Invariante de la representacion:
       - 0 <= longitud <= letras.size() = MAXLONG
       - letras[0..longitud-1] no son separadores
  */
  int longitud;

public:
  /* Constructoras */

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una palabra.
      \pre cierto
      \post El resultado es una palabra sin caracteres y longitud 0 
  */     
  Palabra ();

  /* Modificadoras de los campos */

  /** @brief Añade un carácter nuevo al final de una palabra

      \pre <em>c</em> no es un separador; la longitud del parametro
     implícito es menor que la máxima permitida

      \post el parametro implícito queda como el original pero con <em>c</em>
      añadido al final
  */
  void anadir_letra (char c);



  /* Consultoras */

  /** @brief Consultora de la longitud máxima
      \pre cierto
      \post El resultado es la longitud máxima de una palabra permitida 
      por la implementación 
  */ 
  static int longitud_maxima ();

  /** @brief Consultora de la longitud
      \pre cierto
      \post El resultado es la longitud del parámetro implícito
  */
  int long_pal () const;

  /** @brief Comprobación de caracter separador
     \pre cierto 
     \post El resultado indica si c es un separador para la clase (c no puede 
     formar parte de una palabra) 
  */
  static bool es_separador (char c);  

  /** @brief Consultora del carácter i-ésimo
      \pre 1<=<em>i</em><=longitud del parámetro implícito
      \post El resultado es el carácter <em>i</em>-ésimo del parámetro implícito
  */
  char consultar_letra (int i) const;

  /** @brief Igualdad de palabras. 
      \pre cierto
      \post El resultado indica si <em>p</em> es igual al parámetro implícito 
  */
  bool iguales (const Palabra & p) const;


  /* Entrada / Salida */
 
  /** @brief Operación de lectura

      \pre En el canal standard de entrada hay uno o más caracteres 'a'..'z',
      'A'..'Z', '0'..'9' o x; x es un separador visible del rango (0-127)

      \post El parámetro implícito contiene el primer grupo de caracteres
      válidos leídos del canal standard de entrada, hasta el primer separador
      posterior a éstos; si antes del primer carácter válido aparece "x", se
      obtiene una palabra de longitud cero.
  */
  void leer (char x);

  /** @brief Operación de escritura

      \pre cierto

      \post Se han escrito los caracteres del parámetro implícito en el canal
      standard de salida. Si está vacío no se escribe nada.
  */
  void escribir () const;
};

#endif
