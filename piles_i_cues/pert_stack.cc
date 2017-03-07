#include "stackIOint.hh"

bool pertstack_rec(stack<int>& p, int x);
bool pertstack_it(stack<int> p, int x);

int main() 
{
  cout << "Escribe la pila, acabada en 0:" << endl;
  stack<int> p;
  llegir_stack_int(p,0);
  cout << "Escribe el elemento a buscar:" << endl;
  int valor; cin >> valor;  

  cout << "Version iterativa o recursiva (escribe 1 o 2):" << endl;
  int i; cin >> i; bool es_trobat;
  while (i!=1 and i!=2) {
    cout << "Hay que introducir 1 o 2" << endl;
    cin >> i;
  } 
 if (i==1) es_trobat = pertstack_it(p, valor);
  else if (i==2) {
    stack<int> copia(p); // copiamos para no destruir p
    es_trobat = pertstack_rec(copia, valor);
  }
 
  if(es_trobat)
    cout << "     Esta" << endl;
  else
    cout << "     No esta" << endl;
  cout << "Escribimos la pila original para ver que no se ha destruido:" << endl
;
  escriure_stack_int(p);
}

/*
  Notemos que en la version recursiva la pila se pasa por referencia,
  y puede resultar modificada aunque se trate de una funcion. Si
  deseamos conservar la pila original, hay que pasar una copia o
  reempilar la cima a la vuelta de la recursividad. No pasamos la pila
  por valor para evitar el coste de las copias; tampoco por referencia
  constante porque es incompatible con "pop"
*/
bool pertstack_rec(stack<int> &p, int x)
/* Pre: p = P */
/* Post: El resultat diu si x es un element de P */
{
  bool ret;
  if(p.empty()) ret=false; 
  else 
    if (p.top() == x) ret=true;
    else {   
      p.pop(); 
      ret=pertstack_rec(p,x);    
    }
  return ret;
}

bool pertstack_it(stack<int> p, int x)
/* Pre: p = P */
/* Post: El resultat diu si x es un element de P */
{
  bool ret=false;
  while (not p.empty() and not ret){ // alt:
    ret = (p.top() == x); // if (p.top() == x) ret=true;
    p.pop();              // else p.pop();
  }
  return ret;
}
