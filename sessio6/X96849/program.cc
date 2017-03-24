//
//  program.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 24/3/17.
//

#include "ArbIOParInt.hh"

using namespace std;

pair<int, int> buscarElementArbre(Arbre<ParInt> a, int x, int depth){
  pair<int, int> p;
  p.first = -1;
  if(!a.es_buit() and a.arrel().primer() == x){
    p.first = depth;
    p.second = a.arrel().segon();
  }
  else if(!a.es_buit()) {
    Arbre<ParInt> a1;
    Arbre<ParInt> a2;
    a.fills(a1, a2);
    p = buscarElementArbre(a1, x, depth+1);
    if(p.first == -1) p = buscarElementArbre(a2, x, depth+1);
  }
  return p;
}

int main(){
  Arbre<ParInt> a;
  llegir_arbre_parint(a);
  int x;
  while (cin >> x) {
    pair<int, int> p_depth_second = buscarElementArbre(a,x, 0);
    if(p_depth_second.first == -1) cout << "-1" << endl;
    else cout << x << ' ' << p_depth_second.second  << ' ' << p_depth_second.first<< endl;
  }
}
