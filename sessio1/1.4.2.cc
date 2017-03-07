#include <iostream>
#include <vector>

using namespace std;

#include "vectorIOint.hh"

/* Buscar  */
bool busqueda_lin(const vector<int>& v, int x)
/* Pre:  */
/* Post: el resultado indica si x está en v */
{
  int tam = v.size();
  int i = 0;
  bool b = -1;
  while (i<tam and b < 0) {
    if (v[i]==x) b=i;
    else ++i;
  }
  return b;
}

int main()
{
  vector<int> v;
  leer_vector_int(v);
  cout << "Escribe el elemento a buscar: " << endl;
  int x;
  cin >> x;
  bool b = busqueda_lin(v,x);
  if (b >= 0)  cout << "El elemento " << x << " esta en el vector." << endl << endl;
  else cout << "El elemento " << x << " no esta en el vector." << endl << endl;
  cout << "Escribimos el vector para que se vea que no ha cambiado:" << endl;
  escribir_vector_int(v);
}
