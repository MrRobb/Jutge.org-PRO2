#ifndef ARBIOINT_HH
#define ARBIOINT_HH

#include "Arbre.hh"
#include <iostream>

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


void llegir_arbre_int(Arbre<int>& a, int marca);


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

void escriure_arbre_int(Arbre<int>& a);

#endif
