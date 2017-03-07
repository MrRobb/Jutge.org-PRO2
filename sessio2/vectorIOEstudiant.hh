#ifndef VECTOR_IO_ESTUDIANT	// per evitar errors de compilacio
#define VECTOR_IO_ESTUDIANT	// quan aquest fitxer s'inclou molts cops

#include <iostream>
#include <vector>
#include "Estudiant.hh"

using namespace std;

/* Llegir vector d'estudiants */
void leer_vector_estudiant(vector<Estudiant>& v);
/* Pre:  hi ha preparats al canal estandar d'entrada un enter N 
   mes gran que 0 i N estudiants amb l'estructura <dni nota> */
/* Post: v te N elements que son successivament els N estudiants
   que hi eren al canal estandar d'entrada;*/

/* Escriure vector d'estudiants */
void escribir_vector_estudiant(const vector<Estudiant>& v);
/* Pre: cert */
/* Post: s'han escrit tots els elements del vector */

#endif
