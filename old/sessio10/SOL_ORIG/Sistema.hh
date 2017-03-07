/** @file Sistema.hh
    @brief Especificación de la clase Sistema
*/

#ifndef _SISTEMA_
#define _SISTEMA_

#include "Organismo.hh"
//#include <queue> 

/*
 * Clase Sistema
 */

/** @class Sistema
    @brief Representa el sistema donde se desarrollan los experimentos. 

    Ofrece operaciones para introducir un organismo en el sistema, de lectura y escritura del sistema. 
*/

class Sistema {
  // Descripción: contiene los dos grupos de organismos que están presentes en el
  // sistema y las operaciones necesarias para gestionarlos

private:

  /* Para la buena gestión de un sistema, ésta clase requiere guardar de manera
     separada los organismos defensivos y los malignos. Como el número máximo de
     ambos no está acotado, usaremos sendas colas, que tendrán que estar ordenadas
     crecientemente por orden de identificador, para facilitar las operaciones del
     módulo. También será necesario guardar un natural con el identificador que se
     le asignará al próximo organismo que entre en el sistema. */

  /** @brief Cola de organismos defensivos. 

      Ordenada crecientemente por el id de sus componentes */
  queue<Organismo> def;  

  /** @brief Cola de organismos malignos.

      Ordenada crecientemente por el id de sus componentes */
  queue<Organismo> mal; 

  /** @brief Primer número disponible de identificador de organismo */
  int id; 

public:

  // Constructora
  /** @brief Creadora por defecto
      @pre cierto
      @post El resultado es un sistema en que no ha entrado ningún organismo
  */
  Sistema(); 

  // Destructora
  /** @brief Destructora por defecto
   */
  ~Sistema(); 

  // Modificadoras

  /** @brief Modificadora que gestiona el intento de entrada de un organismo en el sistema
      \pre o es un organismo sin identificador
      \post El parámetro implícito contiene el estado del sistema después del intento de entrada del 
      organismo o; o pasa a tener identificador y a contener el número de organismos que ha destruido;
      sobrevive indica si o queda vivo en el parámetro implícito o no 
  */
  void anadir_organismo(Organismo &o, bool &sobrevive);

  // Entrada / Salida

  /** @brief Operación de lectura
      \pre N>0 
      \post El parámetro implícito está formado por un grupo de organismos leídos por el canal de entrada estándard y formados por celulas de N parámetros
  */
  void leer(int N);

  /** @brief Operación de escritura
      \pre cierto
      \post Si tipo es cierto, se han escrito en el canal de salida estándard, por orden de identificador, los 
      organismos defensivos del parámetro implícito, en caso contrario se han escrito los malignos; 
      si estr es cierto, cada organismo se escribe con su estructura celular, 
      en caso contrario sólo se escribe su identificador
  */
  void escribir(bool tipo, bool estr) const; 

private:

  /** @brief Lucha de un organismo contra los organismos de una cola
      @pre c = C; C está ordenada crecientemente según los identificadores de sus organismos
      @post c contiene los organismos de C, ordenados crecientemente por 
      identificador y con su contador de víctimas actualizado, 
      excepto los que hayan muerto al enfrentarse con o; 
      sobrevive indica si o queda vivo despues de sus enfrentamientos;  
      o pasa a contener el número de organismos que ha destruido
  */
static void luchas_org_cola(queue<Organismo> &c, Organismo &o, bool &sobrevive);

  /** @brief Elimina todos los elementos de una cola de organismos
      @pre c = C; 
      @post c es vacía
  */
static void clear(queue<Organismo>& q);

  /** @brief Pasa los n primeros organismos de una cola al final de ésta, conservando el orden relativo
      @pre n = N <= c.size(), c = C; 
      @post c contiene los mismos elementos que C, pero los N primeros elementos de C están al final de c, en el orden relativo original; los restantes también conservan su orden relativo original
  */
static  void recolocar(int n, queue<Organismo> &c);
   
  /** @brief Operación de escritura de una cola de organismos
      @pre cierto
      @post Se han escrito en el canal estándar de salida los organismos de c, por orden de identificador;  si estr es cierto, cada organismo se escribe con su estructura celular, en caso contrario sólo se escribe su identificador
  */
static void escribir_sistema_cola(const queue<Organismo> &c, bool estr);
};

#endif

