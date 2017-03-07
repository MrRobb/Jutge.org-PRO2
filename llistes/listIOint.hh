#ifndef LISTA_IO_INT
#define LISTA_IO_INT

#include <iostream>
#include <list>
using namespace std;

void llegir_llista_int(list<int>& l, int marca);
/* Pre: l es vacia, en el canal estandar de entrada hay 0 o mas enteros 
   antes de "marca"  */
/* Post: l esta formada por los elementos leidos antes de "marca", en el
   orden de lectura */ 


void escriure_llista_int(const list<int>& l);
/* Pre: cierto  */
/* Post: el contenido de l se ha escrito en el canal estandar de
   salida (el "begin" primero) */ 

#endif
