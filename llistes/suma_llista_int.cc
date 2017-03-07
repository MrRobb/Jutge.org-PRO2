#include "listIOint.hh"

int suma_llista_int(const list<int>& l)
/* Pre: cert */
/* Post: El resultat es la suma dels elements d'l */
{
  int s=0;
  for(list<int>::const_iterator it= l.begin();it != l.end(); ++it)
    s+=*it;
  return s;
}

int main(){

  list<int> l;
  cout << "Entra llista enters (acabada per 0): " << endl;
  llegir_llista_int(l,0);
  cout << "Suma: " <<  suma_llista_int(l) << endl;
}
