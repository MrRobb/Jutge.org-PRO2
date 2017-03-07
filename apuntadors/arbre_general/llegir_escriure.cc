#include "ArbGIOint.hh"

int main(){
  ArbreGen<int> a;
  cout << "Posa els valors de l'arbre general en preordre" << endl;
  llegir_arbre_int(a,0);
  cout << "Escrivim l'arbre general en preordre" << endl;
  escriure_arbre_int(a);
  cout << endl;
}
