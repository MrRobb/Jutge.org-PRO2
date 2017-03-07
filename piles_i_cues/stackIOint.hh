#ifndef PILA_IO_INT
#define PILA_IO_INT

#include <iostream>
#include <stack>
using namespace std;

void llegir_stack_int(stack<int>& p, int marca);
/* Pre: p es vacia, en el canal estandar de entrada hay 0 o mas enteros 
   antes de "marca"  */
/* Post: p esta formada por los elementos leidos antes de "marca" */ 


void escriure_stack_int(stack<int> p);
/* Pre: cierto  */
/* Post: el contenido de p se ha escrito en el canal estandar de
   salida (la cima primero) */ 

#endif
