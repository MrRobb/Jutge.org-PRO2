#include "ArbIOint.hh"
int main (){
 
  Arbre<int> a;
  cout << "Pon el arbol en preorden:" << endl;
  llegir_arbre_int(a,0);

  cout << "tam de a: " << a.tam() << endl;
  cout << "a:" << endl;
  escriure_arbre_int(a);
  cout  << endl;
}
