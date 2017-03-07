#include <iostream>
using namespace std;

#include "vectorIOint.hh"

/* Buscar  */    
int busqueda_lin(const vector<int>& v, int x)
/* Pre: cierto */
/* Post: el resultado indica si x está en v */
{
  int tam = (int)v.size();
  int i = 0;
  while (i<tam) {
    if (v[i]==x) return i;
    ++i;
  }
  return -1;
}

int main()
{
  vector<int> v;
  leer_vector_int(v); 
  cout << "Escribe el elemento a buscar: " << endl;
  int x;
  cin >> x; 
  int i = busqueda_lin(v,x);
  if (i >= 0)  cout << "El elemento " << x << " esta en el vector. En la posición: " << i+1 << endl << endl;
  else cout << "El elemento " << x << " no esta en el vector." << endl << endl;
  
  
  cout << "Escribimos el vector para que se vea que no ha cambiado:" << endl;
  escribir_vector_int(v);
}
