#include "queueIOint.hh"

bool pertqueue_rec(queue<int> &S, int i);
bool pertqueue_it(queue<int> S, int i);

int main() 
{
  cout << "Escribe la cola, acabada en 0:" << endl;
  queue<int> p;
  llegir_queue_int(p,0);
  cout << "Escribe el elemento a buscar:" << endl;
  int valor=readint();
   
  queue<int> copia(p); // copiamos para no destruir p

  cout << "Version iterativa o recursiva (escribe 1 o 2):" << endl;
  int i =readint(); bool es_trobat;
  if (i==1) es_trobat = pertqueue_it(copia, valor);
  else if (i==2) es_trobat = pertqueue_rec(copia, valor);
  else throw PRO2Excepcio("Hay que escribir 1 o 2");
 
  if(es_trobat)
    cout << "     Esta" << endl;
  else
    cout << "     No esta" << endl;
  cout << "Escribimos la cola original para ver que no se ha destruido:" << endl
;
  escriure_queue_int(p);
}

/*
  Notemos que la cola se pasa por referencia, y puede resultar modificada,
  aunque se trate de una funcion
  Si deseamos conservar la cola original, hay que pasar una copia 
  No pasamos la cola por valor para evitar el coste de las copias; tampoco por
  referencia constante porque es incompatible con pop
*/
bool pertqueue_rec(queue<int> &s, int i)
/* Pre: s = S */
/* Post: El resultat diu si i es un element de S */
{
  bool ret;
  if (s.empty()) ret=false; 
  else 
    if (s.front() == i) ret=true;
    else {
      s.pop(); 
      ret = pertqueue_rec(s,i);
    }
  return ret;
}

bool pertqueue_it(queue<int> s, int i)
/* Pre: s = S */
/* Post: El resultat diu si i es un element de S */
{
  bool ret=false;
  while (not s.empty() and not ret){
    ret = (s.front() == i);
    s.pop();
  }
  return ret;
}
