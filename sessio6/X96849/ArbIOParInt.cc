
#include "ArbIOParInt.hh"

void llegir_arbre_parint(Arbre<ParInt>& a){
/* Pre: a es buit; el canal estandar d'entrada conte el recorregut en preordre
   d'un arbre binari A d'enters marcat amb "marca" */  
/* Post: a = A */
  Arbre<ParInt> a1;
  Arbre<ParInt> a2;
  ParInt p;
  p.llegir();
  if (p.primer() != 0 and p.segon() != 0) {
    llegir_arbre_parint(a1);
    llegir_arbre_parint(a2);
    a.plantar(p,a1,a2);
  }
}

void escriure_arbre_parint(Arbre<ParInt>& a) {
/* Pre: cert */ 
/* Post: El canal estandar de sortida conte el recorregut en inordre d'a */
  if (not a.es_buit()) {
    Arbre<ParInt> a1;
    Arbre<ParInt> a2;
    ParInt p = a.arrel();
    a.fills(a1,a2);
    escriure_arbre_parint(a1);
    cout << " ";
    p.escriure();
    escriure_arbre_parint(a2);
    a.plantar(p,a1,a2);
  }
}
