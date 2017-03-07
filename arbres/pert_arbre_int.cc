#include "ArbIOint.hh"

bool cerca(Arbre<int>& a, int x)
/* Pre: a=A */
/* Post: El resultat indica si x es a l'arbre A o no */
{
  bool b;
  if (a.es_buit()) b=false;            // versió compacta:
  else if (a.arrel()==x) b=true;       // if (a.es_buit()) return false;   
  else{                                // if (a.arrel()==x) return true;   
    Arbre<int> a1,a2;                  // return cerca(a1,x) or cerca(a2,x)
    a.fills(a1,a2);
    b=cerca(a1,x);
    if (not b) b= cerca(a2,x);
  }
  return b;
}

int main(){

  Arbre<int> a;
  llegir_arbre_int(a,0);
  int n;
  Arbre<int> b(a);
  cout << "Escrivim b per veure que es igual que a" << endl;
  escriure_arbre_int(b);
  cout << endl;
  cout << "Numero a cercar: ";
  cin >> n;
  bool es = cerca(b,n);
  if (es) cout << "Hi es" << endl;
  else cout << "No hi es" << endl;
  cout << "Escrivim b per veure que s'ha destruit durant l'operacio" << endl;
  escriure_arbre_int(b);
  cout << endl;
  cout << "Escrivim a per veure que no s'ha modificat durant l'operacio" << endl;
  escriure_arbre_int(a);
  cout << endl;
}
