/** @file Estudiant.hh
    @brief Especificació de la classe Estudiant 
*/

#ifndef ESTUDIANT_HH
#define ESTUDIANT_HH

#ifndef NO_DIAGRAM          // aixo fa que el doxygen no inclogui  
#include "PRO2Excepcio.hh"  // aquestes classes als diagrames modulars, 
#include <iostream>         // mentre que el compilador de c++ 
#endif                      // si que les processa correctament        

class Estudiant {
    
  // Tipus de modul: dades

   
  /** @class  Estudiant
      @brief Representa un estudiant amb DNI, que pot tenir nota.
      
      Els DNI vàlids són enters no negatius. Les notes vàlides son les de l'interval 0..nota_maxima()

*/

private:
  int dni;
  double nota;
  bool amb_nota;
  static const int MAX_NOTA = 10;

  /* 
    Invariant de la representació:
    - 0 <= dni
    - si amb_nota, llavors 0 <= nota <= MAX_NOTA
  */ 
public:
  //Constructores
    
  /** @brief Creadora per defecte. 

      S'executa automáticament al declarar Estudiant e;
      \pre cert
      \post el resultat es un estudiant amb DNI = 0 i sense nota
  */
  Estudiant();

  /** @brief Creadora amb DNI. 

      S'executa automáticament al declarar Estudiant e2(e1);.
      \pre cert
      \post el resultat es un estudiant amb DNI = dni i sense nota
  */
  Estudiant(int dni);
 
    
  //Modificadores

  /** @brief Afegeix una nota a un estudiant sense nota

      \pre el parametre implicit no te nota, 0 <= <em>nota</em> <= nota_maxima()
      \post la nota del parametre implicit passa a ser <em>nota</em>
   */
  void afegir_nota(double nota);
  
  /** @brief Modifica la nota d'un estudiant amb nota

      \pre el parametre implicit te nota, 0 <= <em>nota</em> <= nota_maxima()
      \post la nota del parametre implicit passa a ser <em>nota</em>
   */
  void modificar_nota(double nota);
   
  //Consultores
    
  /** @brief Consulta del DNI d'un estudiant

      \pre cert
      \post el resultat es el DNI del parametre implicit
   */
  int consultar_DNI() const;
    
  /** @brief Consulta de ls nota d'un estudiant

      \pre el parametre implicit te nota 
      \post el resultat es la nota del parametre implicit
   */
  double consultar_nota() const;
    
  /** @brief Consulta de la nota màxima de la classe Estudiant

      \pre cert
      \post el resultat es la nota maxima dels elements de la classe
   */
  static double nota_maxima();
 
  /** @brief Comprovació de la nota d'un estudiant

      \pre cert
      \post el resultat indica si el parametre implicit te nota o no 
   */    
  bool te_nota() const;

  
  // Lectura i escriptura
    
  /** @brief Operació de lectura

      \pre hi ha preparats al canal estandard d'entrada un enter no negatiu 
     i un double
      \post el parametre implicit passa a tenir els atributs llegits
     del canal estandard d'entrada; si el double no pertany a l'interval
     [0..nota_maxima()], el p.i. es queda sense nota
   */    
  void llegir();

    
  /** @brief Operació d'escriptura

      \pre cert
      \post s'han escrit els atributs del parametre implicit
     al canal estandard de sortida; si no te nota escriu "NP"
   */    
  void escriure() const;
};
#endif
