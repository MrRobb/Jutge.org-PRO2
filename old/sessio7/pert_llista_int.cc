#include "listIOint.hh"


bool pert_llista_int(const list<int>& l, int x)
/* Pre: cert */
/* Post: El resultat indica si x hi es o no a l */
{
  bool b = false;
  list<int>::const_iterator it= l.begin();
  while ( it != l.end() and not b){
    if (*it == x) b= true;
    else ++it;
  }
  return b;
}

int main(){

  list<int> l;
  cout << "Entra llista enters (acabada per 0): " << endl;
  llegir_llista_int(l,0);

  cout << "Nœmero a cercar: ";
  int x = readint();
  bool b = pert_llista_int(l,x);
  if (b) cout << "Hi Žs" << endl;
  else cout << "No hi Žs" << endl;
  cout << "Escrivim la llista per veure que no s'ha modificat: " << endl;
  escriure_llista_int(l);

}
