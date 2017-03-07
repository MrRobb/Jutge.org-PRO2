/** @file Celula.hh
    @brief Especificación de la clase Celula
*/

#ifndef _CELULA_
#define _CELULA_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include "PRO2Excepcio.hh"
#endif

/*
 * Clase Celula
 */

/** @class Celula 
    @brief Representa el conjunto de características y
    operaciones de las células.

    Ofrece la operación de lucha entre células y las operaciones de
    lectura y escritura.

    Dado que vamos a necesitar leer árboles de células, definimos el
    concepto de célula vacía para disponer de un formato de entrada
    parecido al de las anteriores sesiones de laboratorio, en las que
    se emplea una "marca" para indicar la lectura de un árbol vacío.
*/
class Celula {

private:

  /** @brief Identificador especial para células vacias */
  static const int ID_VACIA = 0; 
  /** @brief Identificador de la célula */
  int id; 
  /** @brief Indice de tolerancia */
  int i_tol; // 
  /** @brief Parámetros de la célula  */
  vector<double> param; 

public:

  // Constructora
  /** @brief Creadora por defecto
      @pre cierto
      @post El resultado es una célula vacía, con índice de tolerancia cero y cero parámetros
      @coste Constante
  */
  Celula(); 

  // Consultoras

  /** @brief Consultora que determina el resultado de la lucha entre dos células
      @pre El parámetro implícito (c1) y c2 tienen el mismo número de parámetros
      @post Retorna el resultado de la lucha entre c1 y c2, que vale 
      1 si y solo si c1 vence a c2; 
      2 si y solo si c2 vence a c1; 
      3 si y solo si no vence ninguna de las dos 
      @coste Lineal respecto al número de parámetros de una célula
  */
  int lucha_celulas (const Celula& c2) const;

  /** @brief Consultora que indica si la célula es vacía 
      \pre cierto
      \post El resultado indica si la célula es vacía o no
      \coste Constante
  */
  bool es_vacia() const;

   /** @brief Consultora del número de parámetros de una célula 
      \pre cierto
      \post El resultado es el número de parámetros de una célula
      \coste Constante
  */
  int num_param();

 /** @brief Consultora del identificador especial de células vacías 
      \pre cierto
      \post El resultado es el identificador de célula vacía 
      \coste Constante
  */
  static int id_vacia();

  // Entrada / Salida

  /** @brief Operación de lectura
      \pre N>0, el canal de entrada estándar contiene un entero; si dicho entero no corresponde a un identificador de célula vacía, a continuación contiene otro  entero y N doubles
      \post El parámetro implícito pasa a tener un identificador (el primer entero del canal de entrada estándar); si éste no es el de una célula vacía, el p.i. también tendrá un índice de tolerancia y N parámetros nuevos, leídos del canal de entrada estándar
      \coste Lineal respecto a N (número de parámetros de una célula)
  */
  void leer(int N);

  /** @brief Operación de escritura
      \pre cierto
      \post Se ha escrito el identificador del parámetro implícito por el canal de salida estándard
      \coste Lineal respecto al número de parámetros de una célula
  */
  void escribir() const;
};
#endif

