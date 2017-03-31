#ifndef ARBIOINT_HH
#define ARBIOINT_HH

#include "Arbre.hh"
#include "Estudiant.hh"
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


void llegir_arbre_est(Arbre<Estudiant>& a);
// Pre: a és buit; el canal estandar d’entrada conté una seqüència
// de parells <int, double> que representa un arbre binari d’estudiants
// en preordre, on el parell 0 0 representa un arbre buit
// Post: a conté l’arbre que hi havia al canal estandar d’entrada


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

void escriure_arbre_est(Arbre<Estudiant>& a);
// Pre: a = A
// Post: s’han escrit al canal estandar de sortida els elements
// d’a recorreguts en inordre, a = A

#endif
