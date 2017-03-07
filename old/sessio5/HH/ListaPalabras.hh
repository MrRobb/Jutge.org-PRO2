/** @file ListaPalabras.hh
    @brief Especificación de la clase ListaPalabras
*/

#ifndef LISTAPALABRAS_HH
#define LISTAPALABRAS_HH

#include "Palabra.hh"

/** @class  ListaPalabras

    @brief Representa una colección de palabras distintas, cada una con un
    entero mayor que 0 asociado.

    El entero representa el número de veces que la palabra se ha añadido a la
    lista, lo consideramos la <em>frecuencia</em> de dicha palabra
*/
class ListaPalabras
{

private:

public:
  /* Constructoras */

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una lista.

      \pre cierto
      \post El resultado es una lista vacía
  */ 
  ListaPalabras ();

  /* Modificadoras */

  /** @brief Añade una palabra a la lista

      \pre La longitud del parámetro implícito es menor que la longitud
      máxima o <em>p</em> ya está en él

      \post Si <em>p</em> está en el p.i. original, su frecuencia queda
      incrementada en 1; si no, p pasa a estar en el p.i., con frecuencia 1 */
  void anadir_palabra (const Palabra & p);


  /* Consultoras */
  /** @brief Consultora de la longitud máxima

      \pre cierto
      \post El resultado es la longitud máxima de una lista permitida por la
      implementación
  */ 
  static int longitud_maxima ();

  /** @brief Consultora de la longitud
      \pre cierto
      \post El resultado es la longitud del parámetro implícito
  */
  int longitud () const;


  /** @brief Consultora de la frecuencia de la palabra más frecuente
      \pre cierto
      \post El resultado es la frecuencia de la palabra más frecuente del 
      parámetro implícito
  */
  int max_frec () const;

  /* Lectura y escritura */
  /** @brief Operación de escritura
      \pre cierto
      \post Por el canal estándar de salida se ha escrito cada palabra del 
       parámetro implícito y su frecuencia (separadas por un espacio en blanco, 
       un par palabra-frecuencia en cada línea), en el orden en que cada palabra
       ha sido añadida por primera vez al p. i. */
  void escribir () const;

};

#endif
