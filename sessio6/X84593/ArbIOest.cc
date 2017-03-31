
#include "ArbIOest.hh"

void llegir_arbre_est(Arbre<Estudiant>& a){
/* Pre: a es buit; el canal estandar d'entrada conte el recorregut en preordre
   d'un arbre binari A d'enters marcat amb "marca" */  
/* Post: a = A */
  Arbre<Estudiant> a1;
  Arbre<Estudiant> a2;
  Estudiant est;
  est.llegir();
  if (est.consultar_DNI() != 0) {
    llegir_arbre_est(a1);
    llegir_arbre_est(a2);
    a.plantar(est,a1,a2);
  }
}

void escriure_arbre_est(Arbre<Estudiant>& a){
/* Pre: cert */ 
/* Post: El canal estandar de sortida conte el recorregut en inordre d'a */
  if (not a.es_buit()) {
    Arbre<Estudiant> a1;
    Arbre<Estudiant> a2;
    Estudiant est = a.arrel();
    a.fills(a1,a2);
    escriure_arbre_est(a1);
    cout << " ";
    est.escriure();
    escriure_arbre_est(a2);
    a.plantar(est,a1,a2);
  }
}
