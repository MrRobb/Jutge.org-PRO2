#include "PilaIOint.hh"

int main(){

  Pila<int> p;
  cout << "Entra pila naturals (acabada per -1): " << endl;
  llegir_pila_int(p,-1);
  cout << "Entra número a buscar: " << endl;
  int x; cin >> x;
  cout << "Entra 1 para usar la version recursiva y cualquier otro entero para la iterativa: " << endl;
  int y; cin >> y;
  bool b;
 
  if (y==1) 
    b = p.cerca_pila(x);
  else 
    b = p.cerca_pila_it(x);

  if (b) cout << "esta" << endl;
  else cout << "no esta" << endl;
  cout << "pila p, despues de buscar (notad que no se destruye en ningun caso, aunque no se ha usado copia)" << endl;
  escriure_pila_int(p);

}
