#ifndef COLA_IO_ESTUDIANT
#define COLA_IO_ESTUDIANT

#include <iostream>
#include <queue>
#include "Estudiant.hh"

using namespace std;

void LlegirCuaEstudiant(queue<Estudiant> &q);
// Pre: q és buida; el canal estandar d’entrada conté un enter
// n >=0 i n parells <enter, double>, que representen DNIs vàlids
// i notes (vàlides o no) d’estudiants
// Post: s’han afegit a q els n estudiants llegits)

void EscriureCuaEstudiant(queue<Estudiant> q);
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de q
#endif
