// exemple d'us de la classe Llista

#include "LlistaIOint.hh"

int main(){
  Llista<int> l;
  cout << "Entra llista naturals (acabada per -1): " << endl;
  llegir_llista_int(l,-1);
  l.invertir();
  escriure_llista_int(l);
  cout << "La inversa escrita a l'inreves coincideix amb l'original" << endl;
  escriure_llista_int_rev(l);
}
