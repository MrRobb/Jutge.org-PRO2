
#include "ArbIOint.hh"

void llegir_arbre_int(Arbre<int>& a, int marca){
/* Pre: a es buit; el canal estandar d'entrada conte el recorregut en preordre
   d'un arbre binari A d'enters marcat amb "marca" */  
/* Post: a = A */
  Arbre<int> a1;
  Arbre<int> a2;
  int x;
  cin >> x;
  if (x!= marca) {
    llegir_arbre_int(a1, marca);
    llegir_arbre_int(a2, marca);
    a.plantar(x,a1,a2);
  }
}

void escriure_arbre_int(Arbre<int>& a) {
/* Pre: cert */ 
/* Post: El canal estandar de sortida conte el recorregut en inordre d'a */
  if (not a.es_buit()) {
    Arbre<int> a1;
    Arbre<int> a2;
    int x = a.arrel();
    a.fills(a1,a2);
    escriure_arbre_int(a1); 
    cout << " " << x;
    escriure_arbre_int(a2);
    a.plantar(x,a1,a2);
  }
}
