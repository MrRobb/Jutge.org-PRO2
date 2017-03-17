#ifndef PILA_IO_INT
#define PILA_IO_INT
#endif

#include <iostream>
#include <stack>
#include "ParInt.hh"

using namespace std;

void llegir_stack_int(stack<int>& p, int marca);
/* Pre: p es vacia, en el canal estandar de entrada hay 0 o mas enteros 
   antes de "marca"  */
/* Post: p esta formada por los elementos leidos antes de "marca" */ 


void escriure_stack_int(stack<int> p);
/* Pre: cierto  */
/* Post: el contenido de p se ha escrito en el canal estandar de
   salida (la cima primero) */ 

void llegirPilaParInt(stack<ParInt>& p);
// Pre: p és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han apilat a p els elements llegits fins al 0 0 (no inclòs)

void escriurePilaParInt(stack<ParInt> p);
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de p
