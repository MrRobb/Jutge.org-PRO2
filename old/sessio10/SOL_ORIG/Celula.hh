/** @file Celula.hh
    @brief Especificación de la clase Celula
*/

#ifndef _CELULA_
#define _CELULA_

//#include "utils.PRO2"
//#include <vector>

/*
 * Clase Celula
 */

/** @class Celula 
    @brief Representa el conjunto de características y
    operaciones de las células.

    Ofrece la operación de lucha entre células y las operaciones de
    lectura y escritura.

    El hecho de que las células se lean en el contexto de la lectura
    de árboles de células que componen organismos nos induce a definir
    el concepto de célula vacía para poder leer árboles siguiendo un
    formato de entrada parecido al de la sesión 7 de laboratorio, "Uso
    de listas y árboles", en la que se define una "marca" para indicar
    subárbol vacío.
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
      @post El resultado es una célula vacía, con índice de tolerancia cero y un número de parámetros indeterminado
  */
  Celula(); 

  // Destructora
  /** @brief Destructora por defecto
   */
  ~Celula(); 

  // Consultoras

  /** @brief Consultora que determina el resultado de la lucha entre dos células
      @pre El parámetro implícito (c1) y c2 tienen el mismo número de parámetros
      @post Retorna el resultado de la lucha entre c1 y c2, que vale 
      1 si y solo si c1 vence a c2; 
      2 si y solo si c2 vence a c1; 
      3 si y solo si no vence ninguna de las dos 
  */
  int lucha_celulas (const Celula &c2) const;

  /** @brief Consultora que indica si la célula es vacía 
      \pre cierto
      \post El resultado indica si la célula es vacía o no
  */
  bool es_vacia() const;

  // Entrada / Salida

  /** @brief Operación de lectura
      \pre N>0
      \post El parámetro implícito pasa a tener un identificador, un índice de tolerancia y N parámetros nuevos, leídos del canal de entrada estándard, salvo si el identificador leído es el de una célula vacía 
  */
  void leer(int N);

  /** @brief Operación de escritura
      \pre cierto
      \post Se ha escrito el identificador del parámetro implícito por el canal de salida estándard
  */
  void escribir() const;
};
#endif

