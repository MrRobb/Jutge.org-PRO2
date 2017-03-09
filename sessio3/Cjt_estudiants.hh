#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"
#include <vector>

class Cjt_estudiants {

private:

  // Tipus de modul: dades
  // Descripcio del tipus: representa un conjunt ordenat per DNI d'estudiants
  // Es poden consultar i modificar els seus elements (de tipus Estudiant)
  // donat un DNI o per posicio en l'ordre
    
  vector<Estudiant> vest;
  int nest;
  static const int MAX_NEST = 20;
  /*
    Invariant de la representacio:
    - vest[0..nest-1] esta ordenat de manera estrictament creixent 
      pels DNI dels estudiants
    - 0 <= nest <= vest.size() = MAX_NEST
  */

  void ordenar_cjt_estudiants();
  /* Pre: cert */
  /* Post: els elements rellevants del parametre implicit estan ordenats
     creixentment pels seus DNI */
    
  static int cerca_dicot(const vector<Estudiant>& vest, int left, int right, int x);
  /* Pre: vest[left..right] esta ordenat creixentment per DNI,
     0<=left, right<vest.size() */
  /* Post: si a vest[left..right] hi ha un element amb DNI = x, el resultat es
     una posicio que el conte; si no, el resultat es -1 */

public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: el resultat es un conjunt d'estudiants buit */

  //Destructora

  ~Cjt_estudiants();
   
  //Modificadores

  void afegir_estudiant(const Estudiant& est, bool& b);
  /* Pre: el par`ametre impl ́ıcit no est`a ple */
  /* Post: b indica si el par`ametre impl ́ıcit original cont ́e un estudiant amb el
   dni d’est; si b=fals, s’ha afegit l’estudiant est al par`ametre impl ́ıcit */
  
  void modificar_estudiant(const Estudiant& est, bool& b);
  /* Pre: cert  */
  /* Post: b indica si l'estudiant ha estat substituit o no, degut a si hi era al 
     conjunto o no. Si b == true, l'estudiant del parametre implicit original amb 
     el dni d'est, ha quedat substituit per est */
    
  void modificar_iessim(int i, const Estudiant& est);
  /* Pre: 1 <= i <= nombre d'estudiants del parametre implicit,
     l'element i-essim del conjunt en ordre creixent per DNI conte
     un estudiant amb el mateix DNI que est */
  /* Post: l'estudiant est ha substituit l'estudiant i-essim
     del parametre implicit */
  
    //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: el resultat es el nombre d'estudiants del parametre implicit */
    
  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat es el nombre maxim d'estudiants que pot arribar
     a tenir el parametre implicit */
    
  bool existeix_estudiant(int dni) const;
  /* Pre: dni >= 0 */
  /* Post: el resultat indica si existeix un estudiant al par‡metre implicit
     amb DNI = dni */
    
  void consultar_estudiant(Estudiant &est, bool &b) const;
  /* Pre: cert */
  /* Post: b indica si l'estudiant s'ha trobat o no dins del conjunt. 
     Si b == true, el resultat es l'estudiant amb DNI = dni que conte el
     parametre implicit */
    
  Estudiant consultar_iessim(int i) const;
  /* Pre: 1 <= i <= nombre d'estudiants que conte el parametre implicit */
  /* Post: el resultat es l'estudiant i-essim del parametre implicit
     en ordre creixent per DNI */
    
  // Lectura i escriptura
	
  void llegir();
  /* Pre: estan preparats al canal estandard d'entrada un enter (entre 0 i la
     mida maxima permesa per a la classe), que representa el nombre d'elements
     que llegirem, i les dades de tal nombre d'estudiants diferents */
  /* Post: el parametre implicit conte el conjunt d'estudiants llegits
     del canal estandard d'entrada */
    
  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal estandard de sortida els estudiants del
     parametre implicit en ordre ascendent per DNI */
};
#endif
