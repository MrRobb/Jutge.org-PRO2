/** @file Cjt_estudiants.hh
    @brief Especificació de la classe Cjt_estudiants
*/

#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"

#ifndef NO_DIAGRAM       // aixo fa que el doxygen no inclogui      
#include <vector>	 // aquestes classes als diagrames modulars,
#endif			 // mentre que el compilador de c++ 	       
			 // si que les processa correctament        

/** @class Cjt_estudiants

    @brief Representa un conjunt d'estudiants ordenat per DNI.
    Es poden consultar i modificar els seus elements (de tipus Estudiant)
    donat un estudiant concret o per posicio a l'ordre
    */
class Cjt_estudiants {

private:
    
  vector<Estudiant> vest;
  int nest;
  static const int MAX_NEST = 20;
  /*
    Invariant de la representacio:
    - vest[0..nest-1] esta ordenat de manera estrictament creixent
      pels DNI dels estudiants
    - 0 <= nest <= vest.size() = MAX_NEST
  */

  /** @brief Ordena un conjunt d'estudianta

      \pre cert

      \post els elements rellevants del parametre implicit estan ordenats
     creixentment pels seus DNI
  */
  void ordenar_cjt_estudiants();
 
  /** @brief Cerca un DNI dins d'un conjunt d'estudianta

      \pre vest[left..right] esta ordenat creixentment per DNI,
     0<=left, right<vest.size()

      \post si a vest[left..right] hi ha un element amb DNI = x, el resultat es
     una posicio que el conte; si no, el resultat es -1
  */
  static int cerca_dicot(const vector<Estudiant>& vest, int left, int right, int x);


public:

  //Constructores

  /** @brief Creadora per defecte. 

      S'executa automaticament al declarar Cjt_estudiants c;
      \pre cert
      \post el resultat es un conjunt d'estudiants buit
  */
  Cjt_estudiants();
   
  //Modificadores

  /** @brief Afegeix un estudiant a un conjunt

      \pre el parametre implicit no conte cap estudiant amb el DNI d'est;
     el nombre d'estudiants del p.i. es mes petit que la mida maxima permesa
      \post s'ha afegit l'estudiant est al parametre implicit
   */
  void afegir_estudiant(const Estudiant& est);
    
  /** @brief Modifica un estudiant dins d'un conjunt

      \pre existeix un estudiant al parametre implicit amb el DNI d'est
      \post l'estudiant del parametre implicit original amb el dni d'est, ha quedat substituit per est
   */
  void modificar_estudiant(const Estudiant& est);
  
  /** @brief Modifica l'i-esim estudiant dins d'un conjunt

      \pre 1 <= i <= mida(), l'element i-esim del conjunt en ordre creixent per DNI conte un estudiant amb el mateix DNI que est
      \post l'estudiant est ha substituit l'estudiant i-esim del parametre implicit 
   */    
  void modificar_iessim(int i, const Estudiant& est);
  
    //Consultores
	
  /** @brief Consulta la mida d'un conjunt d'estudiants

      \pre cert
      \post el resultat es la mida del parametre implicit
   */
  int mida() const;
    
  /** @brief Consulta de la mida maxima de la classe Cjt_estudiants

      \pre cert
      \post el resultat es la mida maxima dels elements de la classe
   */
  static int mida_maxima();
    
  /** @brief Cerca d'un estudiant a un conjunt

      \pre dni >= 0
      \post el resultat indica si existeix un estudiant al parametre implicit
     amb DNI = dni 
   */
  bool existeix_estudiant(int dni) const;
    
  /** @brief Consulta d'un estudiant a un conjunt

      \pre existeix un estudiant al parametre implicit amb DNI = dni
      \post el resultat es l'estudiant amb DNI = dni que conte el parametre implicit
   */
  Estudiant consultar_estudiant(int dni) const;

  /** @brief Consulta de l'estudiant i-esim d'un conjunt

      \pre 1 <= i <= mida()
      \post el resultat es l'estudiant i-essim del parametre implicit en ordre creixent per DNI 
   */
  Estudiant consultar_iessim(int i) const;

    
  // Lectura i escriptura
	
 /** @brief Operacio de lectura

      \pre estan preparats al canal estandard d'entrada un enter (entre 0 i la
      mida maxima permesa per a la classe), que representa el nombre d'elements
      que llegirem, i les dades de tal nombre d'estudiants diferents 
      \post el parametre implicit conte el conjunt d'estudiants llegits
      del canal estandard d'entrada
 */    
  void llegir();

/** @brief Operacio d'escriptura

    \pre cert
    \post s'han escrit pel canal estandard de sortida els estudiants del
     parametre implicit en ordre ascendent per DNI
   */        
  void escriure() const;
};
#endif
