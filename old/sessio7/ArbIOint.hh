#ifndef ARBIOINT_HH
#define ARBIOINT_HH

#include "Arbre.hh"

// Lectura d'un arbre binari d'enters, accio.  Els elements
// s'introdueixen en preordre: primer l'arrel, despres el subarbre
// esquerre i per ultim el dret. Els arbres buits es
// representen amb la marca.

/* Exemple: l'arbre 

       1
     /   \
    2     3
     \
      4

   es llegeix 1 2 0 4 0 0 3 0 0 (o amb els numeros en distintes linies) */


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

// Escriptura d'un arbre binari d'enteros, accio.  Els elements
// s'escriuen en inordre: primer el subarbre 
// esquerre, despres l'arrel i per ultim el dret.

/* Exemple: l'arbre 

     1
   /   \
  2     3
   \
    4

   s'escriu 2 4 1 3 */

void escriure_arbre_int(Arbre<int> &a) {
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

#endif
