#include "queueIOint.hh"

bool pertqueue_rec(queue<int>& q, int x);
bool pertqueue_it(queue<int> q, int x);

int main() 
{
  cout << "Escribe la cola, acabada en 0:" << endl;
  queue<int> q;
  llegir_queue_int(q,0);
  cout << "Escribe el elemento a buscar:" << endl;
  int valor; cin >> valor;    
  cout << "Version iterativa o recursiva (escribe 1 o 2):" << endl;
  int i; cin >> i; bool es_trobat;
  while (i!=1 and i!=2) {
    cout << "Hay que introducir 1 o 2" << endl;
    cin >> i;
  } 
 
  if (i==1) es_trobat = pertqueue_it(q, valor);
  else if (i==2) {
    queue<int> copia(q); // copiamos para no destruir q
    es_trobat = pertqueue_rec(copia, valor);
  }
  
  if(es_trobat)
    cout << "     Esta" << endl;
  else
    cout << "     No esta" << endl;
  cout << "Escribimos la cola original para ver que no se ha destruido:" << endl
;
  escriure_queue_int(q);
}

/*
  Notemos que en la version recursiva la cola se pasa por referencia,
  y puede resultar modificada aunque se trate de una funcion. Si
  deseamos conservar la cola original, hay que pasar una copia o
  reencolar el front a la vuelta de la recursividad. No pasamos la cola
  por valor para evitar el coste de las copias; tampoco por referencia
  constante porque es incompatible con "pop"
*/
bool pertqueue_rec(queue<int>& q, int x)
/* Pre: q = Q */
/* Post: El resultat diu si x es un element de Q */
{
  bool ret;
  if (q.empty()) ret=false; 
  else 
    if (q.front() == x) ret=true;
    else {
      q.pop(); 
      ret = pertqueue_rec(q,x);
    }
  return ret;
}

bool pertqueue_it(queue<int> q, int x)
/* Pre: q = Q */
/* Post: El resultat diu si x es un element de Q */
{
  bool ret=false;
  while (not q.empty() and not ret){
    ret = (q.front() == x);
    q.pop();
  }
  return ret;
}
