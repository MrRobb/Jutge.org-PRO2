#include "ArbIOint.hh"
int main (){
 
  Arbre<int> a;
  cout << "Posa l'arbre en preordre:" << endl;
  llegir_arbre_int(a,0);

  cout << "mida d'a: " << a.tam() << endl;
  cout << "a:" << endl;
  escriure_arbre_int(a);
  cout  << endl;
}
