#ifndef COLA_IO_INT
#define COLA_IO_INT

#include <iostream>
#include <queue>
using namespace std;

void llegir_queue_int(queue<int>& q, int marca);
/* Pre: q es vacia, en el canal estandar de entrada hay 0 o mas enteros 
   antes de "marca" */                                        
/* Post: q esta formada por los elementos leidos antes de "marca" */ 

void escriure_queue_int(queue<int> q);
/* Pre: cierto  */
/* Post: el contenido de q se ha escrito en el canal estandar de
   salida (el "front" primero) */ 
#endif
