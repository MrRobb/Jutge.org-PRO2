#include "ArbIOint.hh"

int mida(Arbre<int>& a)
/* Pre: a=A */
/* Post: El resultat es el nombre de nodes de l'arbre A */
{
  if (a.es_buit()) return 0;
  else{
    Arbre<int> a1,a2;
    a.fills(a1,a2);
    int y=mida(a1);
    int z=mida(a2);   
    return y+z+1;
  }
}

int main(){

  Arbre<int> a;
  llegir_arbre_int(a,0);
  int n;
  Arbre<int> b(a);
  cout << "Escrivim b per veure que es igual que a" << endl;
  escriure_arbre_int(b);
  cout << endl;
  cout << "Mida: " << mida(b) << endl;
  cout << "Escrivim b per veure que s'ha destru•t durant l'operaci—" << endl;
  escriure_arbre_int(b);
  cout << endl;
  cout << "Escrivim a per veure que no s'ha modificat durant l'operaci—" << endl;
  escriure_arbre_int(a);
  cout << endl;
}
