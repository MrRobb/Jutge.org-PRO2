#ifndef PILA_IO_INT
#define PILA_IO_INT

#include "utils.PRO2"
#include "Pila.hh"

void llegir_pila_int(Pila<int> &p, int marca)
{
  int n;
  cin >> n;
  while (n != marca){
    p.empilar(n);
    cin >> n;
  }
}

void escriure_pila_int(Pila<int> p)
{
  cout << "[Cim] " << endl;
  // el paso por valor copia p correctamente ya que la clase tiene 
  // creadora copiadora
  while(not p.es_buida()){ 
    cout << p.cim() << endl;
    p.desempilar(); // el que no haya salto de linea solo interesa
  }                   // si la pila no es muy grande
  cout << "[Ultim]"<<endl;
}

#endif
