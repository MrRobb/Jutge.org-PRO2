#include <iostream>
using namespace std;

#include "vectorIOint.hh"

/* Buscar  */
void intercambio_pos_vector(vector<int>& v, int pos1, int pos2)
/* Pre: pos1 y pos2 deben ser >= 0 y < vector.size() */
/* Post: Intercambia dos posiciones de un vector */
{
  int aux;
  aux = v[pos1];
  v[pos1] = v[pos2];
  v[pos2] = aux;
}

int main()
{
  vector<int> v;
  leer_vector_int(v);
  int x,y;

  cout << "Escribe las dos posiciones a intercambiar:" << endl;
  cin >> x >> y;

  intercambio_pos_vector(v,x,y);

  escribir_vector_int(v);
}
