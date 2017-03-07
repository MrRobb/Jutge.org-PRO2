#include "utils.PRO2"
#include "listIOint.hh"

int suma_llista_int(const list<int>& L)
/* Pre: cert */
/* Post: El resultat es la suma dels elements de L */
{
  int s=0;
  for(list<int>::const_iterator it= L.begin();it != L.end(); ++it)
    s+=*it;
  return s;
}

int main(){

  list<int> l;
  cout << "Entra llista enters (acabada per 0): " << endl;
  llegir_llista_int(l,0);
  cout << "Suma: " <<  suma_llista_int(l) << endl;
}
