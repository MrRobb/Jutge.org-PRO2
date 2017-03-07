#ifndef VECTOR_IO_INT	// per evitar errors de compilacio
#define VECTOR_IO_INT	// quan aquest fitxer s'inclou molts cops	

#include <iostream>
#include <vector>

using namespace std;

/* Llegir vector */
void leer_vector_int(vector<int>& v);
/* Pre:  hi ha preparats al canal estandar d'entrada un enter N 
   mes gran que 0 i N enters qualssevol */
/* Post: v te N elements que son successivament els N enters
   qualssevol que hi eren al canal estandar d'entrada; se n'han
   avançat N i els N enters */

/* Escriure vector */
void escribir_vector_int(const vector<int>& v);
/* Pre: cert */
/* Post: s'han escrit tots els elements del vector */

#endif
