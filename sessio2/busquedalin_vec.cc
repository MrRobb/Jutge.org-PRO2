#include <iostream>
using namespace std;

#include "vectorIOEstudiant.hh"

/* Buscar  */    
int busqueda_lin_vec(const vector<Estudiant>& v, int x)
/* Pre: cierto */
/* Post: el resultado indica si x está en v */
{
  int tam = (int)v.size();
  int i = 0;
  while (i<tam) {
    if (v[i].consultar_DNI()==x) return i;
    ++i;
  }
  return -1;
}

int main()
{
  // Llegir vector
  vector<Estudiant> v;
  leer_vector_estudiant(v);
  
  // Busqueda
  cout << "Escribe el dni a buscar: " << endl;
  int x;
  cin >> x; 
  int i = busqueda_lin_vec(v,x);
  
  // Escriure resultat
  if (i >= 0 and v[i].te_nota())  cout << "El elemento " << x << " esta en el vector. Y su nota es: " << v[i].consultar_nota() << endl << endl;
  else if (i >= 0) cout << "El elemento " << x << " esta en el vector, pero no te nota." << endl << endl;
  else cout << "El elemento " << x << " no esta en el vector." << endl << endl;
  
  // Escriure vector
  cout << "Escribimos el vector para que se vea que no ha cambiado:" << endl;
  escribir_vector_estudiant(v);
}
