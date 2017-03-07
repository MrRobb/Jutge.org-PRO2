/** @file Organismo.hh
    @brief Especificación de la clase Organismo 
*/

#ifndef _ORGANISMO_
#define _ORGANISMO_

#include "Celula.hh"
//#include "Arbre.hh"

/*
 * Clase Organismo
 */

/** @class Organismo
    @brief Representa la información y las operaciones asociadas a un organismo.

    Sus operaciones son las modificadoras de identificador y de número de organismos destruidos, las consultoras de si un organismo es maligno y la de su número de víctimas, la que devuelve el resultado de una lucha de dos organismos, la de lectura (única que produce un organismo nuevo) y la de escritura.

    Notad que hemos declarado las operaciones auxiliares como \em private y \em static. Recordad que las operaciones \em static no admiten calificadores como \em const */

class Organismo {

  // Descripción: contiene la estructura celular y las operaciones de un organismo

private:

  /* Un Organismo se representa mediante sus estructura celular, que tendrá
     forma arborescente, su identificador, su condición o no de maligno y su 
     número de víctimas. */

  /** @brief Estructura celular del organismo */
  Arbre<Celula> celulas; // 
  /** @brief Identificador del organismo */
  int id; 
  /** @brief Indica si es maligno (true) o defensivo (false) */
  bool maligno; // 
  /** @brief Número de víctimas del organismo */
  int victimas; 

public:

  // Constructora
  /** @brief Creadora por defecto
      \pre cierto
      \post El resultado es un organismo defensivo, con id=0, sin células y sin victimas
  */
  Organismo(); 

  // Destructora
  /** @brief Destructora por defecto
   */
  ~Organismo(); 

  // Modificadoras

  /** @brief Modificadora del identificador
      \pre cierto
      \post El parámetro implícito pasa a tener a <em>id</em> como identificador
  */
  void anadir_id(int id);

  /** @brief Modificadora del número de víctimas
      \pre cierto 
      \post El parámetro implícito pasa a tener una víctima más en su cuenta
  */
  void incrementar_victimas();

  // Consultoras

  /** @brief Consultora del resultado de la lucha entre dos organismos
      \pre El parámetro implícito (o1) y o2 están compuestos por células con el mismo número de parámetros
      \post Retorna el resultado de la lucha entre o1  y o2, que vale
      0 si y solo si o1 y o2 resultan destruidos; 
      1 si y solo si o1 resulta destruido y o2 no;
      2 si y solo si o1 no resulta destruido y o2 sí;
      3 si y solo si ni o1 ni o2 resultan destruidos
  */
  int lucha_organismos(const Organismo &o2) const;

  /** @brief Consultora de la malignidad del organismo
      \pre cierto
      \post El resultado es cierto si el parametro implícito es un organismo maligno y 
      falso en caso contrario
  */
  bool es_maligno() const;

  /** @brief Consultora del número de víctimas
      \pre cierto
      \post El resultado es el número de organismos destruidos por el parámetro implícito
  */
  int num_victimas() const;

  // Entrada / Salida
  /** @brief Operación de lectura
      \pre N>0
      \post El parámetro implícito es un organismo tomado del canal de entrada estándard formado por células de N parámetros
  */
  void leer(int N);

  /** @brief Operación de escritura
      \pre cierto
      \post Se ha escrito el identificador del parámetro implícito y el número de rivales que ha
      destruido por el canal de salida estándard; si estr es cierto también se ha escrito su estructura celular
  */
  void escribir(bool estr) const;


private:

  /** @brief Comprobación de simetría de dos árboles 
      \pre a1 = A1; a2 = A2
      \post El resultado indica si A1 y A2 son simétricos
  */
static bool simetricos(Arbre<Celula> &a1, Arbre<Celula> &a2);

  /** @brief Lucha de dos árboles de células
      \pre a1 y a2 son simétricos y están compuestos por células con el mismo número de parámetros; a1 = A1; a2 = A2
      \post El primer componente del resultado es el número de células de A1 que vencen a su correspondiente en A2; el segundo es el número de células de A2 que vencen a su correspondiente en A1
  */
static pair<int,int> lucha_arboles(Arbre<Celula> &a1, Arbre<Celula> &a2);

  /** @brief Operación de lectura de un árbol de células
      \pre  N > 0; a es vacío
      \post a contiene el árbol de células leído de la entrada
  */   
static void leer_arbol_celulas(int N, Arbre<Celula> &a);

  /** @brief Operación de escritura de un árbol de células
      \pre  cierto
      \post Se ha escrito a por el canal de salida estándard
  */   
static void escribir_arbol_celulas_id(Arbre<Celula> &a);

};
#endif

