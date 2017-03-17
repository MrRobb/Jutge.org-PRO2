#include "PilaIOParInt.hh"

int pertstack_rec(stack<ParInt>& p, int x, bool &b);

int main() 
{
  stack<ParInt> p;
  llegirPilaParInt(p);
  
}

/*
  Notemos que en la version recursiva la pila se pasa por referencia,
  y puede resultar modificada aunque se trate de una funcion. Si
  deseamos conservar la pila original, hay que pasar una copia o
  reempilar la cima a la vuelta de la recursividad. No pasamos la pila
  por valor para evitar el coste de las copias; tampoco por referencia
  constante porque es incompatible con "pop"
*/
int pertstack_rec(stack<ParInt> &p, int x, bool &b)
/* Pre: p = P */
/* Post: El resultat diu si x es un element de P */
{
  int ret;
  if(p.empty()) b = false;
  else 
    if (p.top().primer() == x){
      ret = p.top().segon();
      b = true;
    }
    else {   
      p.pop();
      ret = pertstack_rec(p,x,b);
    }
  return ret;
}
