#include "ArbNIOint.hh"

int main (){
  cout << "Escriu l'aritat:" << endl;
  ArbreNari<int> a(readint());
  cout << "Posa l'arbre en preordre:" << endl;

  llegir_arbre_int(a,0);

  ArbreNari<int> b(a);
  cout << "b en preordre:" << endl;
  escriure_arbre_int(b);
  cout << endl;
  cout << "escriu la k:" << endl;
  int k = readint();
  b.inc_arbreNari(k);
  cout << "a en preordre:" << endl;
  escriure_arbre_int(a);
  cout << endl;
  cout << "b en preordre:" << endl;
  escriure_arbre_int(b);
  cout << endl;
  ArbreNari<int> c(100,3);
  cout << "c en preordre:" << endl;
  escriure_arbre_int(c);
  cout << endl;
 }
