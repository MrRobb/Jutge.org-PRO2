/** @file Prenda.hh
    @brief Especificación de la clase Prenda 
*/

#ifndef _PRENDA_HH_
#define _PRENDA_HH_

#include "utils.PRO2"

/** @class Prenda
    @brief Representa una prenda de ropa con atributos peso y color
*/
class Prenda
{
public:
  //Constructoras 

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una prenda.
      \pre cierto
      \post El resultado es una prenda sin valores determinados para sus atributos
  */   
  Prenda();

  /** @brief Creadora con valores concretos. 

      \pre pes>0 
      \post El resultado es una prenda con peso "pes" y color "col"
  */   
  Prenda(int pes, bool col);
  
  //Modificadoras

  /** @brief Modificadora de los atributos
      \pre pes>0
      \post El parámetro implícito pasa a tener peso "pes" y color "col" 
  */
  void modificar_prenda(int pes, bool col);
  
  //Consultoras

  /** @brief Consultora del peso
      \pre cierto
      \post El resultado es el peso del parámetro implícito
  */
  int consul_peso() const;
 
  /** @brief Consultora del color
      \pre cierto
      \post El resultado es el color del parámetro implícito
  */
  bool consul_color() const;


  //Escritura de prenda

  /** @brief Operación de escritura

      \pre cierto
      \post Se han escrito los atributos del parámetro implícito en el canal
      standard de salida. 
  */
  void escribir() const;

private:
  // incluimos los campos de la clase para que se vea que los elementos 
  // privados no aparecen en la documentación.  
  int peso;
  bool color;
};

#endif
