#include "stackIOint.hh"

bool pertstack_rec(stack<int> &S, int i);
bool pertstack_it(stack<int> S, int i);

int main() 
{
  cout << "Escribe la pila, acabada en 0:" << endl;
  stack<int> p;
  llegir_stack_int(p,0);
  cout << "Escribe el elemento a buscar:" << endl;
  int valor=readint();
   
  stack<int> copia(p); // copiamos para no destruir p

  cout << "Version iterativa o recursiva (escribe 1 o 2):" << endl;
  int i =readint(); bool es_trobat;
  if (i==1) es_trobat = pertstack_it(p, valor);
  else if (i==2) es_trobat = pertstack_rec(copia, valor);
  else throw PRO2Excepcio("Hay que escribir 1 o 2");
 
  if( es_trobat)
    cout << "     Esta" << endl;
  else
    cout << "     No esta" << endl;
  cout << "Escribimos la pila original para ver que no se ha destruido:" << endl
;
  escriure_stack_int(p);
}

/*
  Notemos que la pila se pasa por referencia, y puede resultar modificada,
  aunque se trate de una funcion
  Si deseamos conservar la pila original, hay que pasar una copia 
  No pasamos la pila por valor para evitar el coste de las copias; tampoco por
  referencia constante porque es incompatible con desempilar
*/
bool pertstack_rec(stack<int> &s, int i)
/* Pre: s = S */
/* Post: El resultat diu si i es un element de S */
{
  bool ret;
  if(s.empty()) ret=false; 
  else 
    if (s.top() == i ) ret=true;
    else {
      s.pop(); 
      ret=pertstack_rec(s,i);
    }
  return ret;
}

bool pertstack_it(stack<int> s, int i)
/* Pre: s = S */
/* Post: El resultat diu si i es un element de S */
{
  bool ret=false;
  while (not s.empty() && not ret){
    ret = (s.top() == i);
    s.pop();
  }
  return ret;
}
