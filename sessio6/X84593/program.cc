//
//  program.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 24/3/17.
//

#include "ArbIOest.hh"
#include "Estudiant.hh"

using namespace std;

pair<int, int> buscarEstudiantArbre(Arbre<Estudiant> a, int dni, int depth){
  pair<int, int> p;
  p.first = -1;
  p.second = -1;
  
  if(!a.es_buit() and a.arrel().consultar_DNI() == dni){
    p.first = depth;
    if(a.arrel().te_nota()) p.second = a.arrel().consultar_nota();
  }
  
  else if(!a.es_buit()) {
    Arbre<Estudiant> a1;
    Arbre<Estudiant> a2;
    a.fills(a1, a2);
    p = buscarEstudiantArbre(a1, dni, depth+1);
    if(p.first == -1) p = buscarEstudiantArbre(a2, dni, depth+1);
  }
  
  return p;
}

int main(){
  Arbre<Estudiant> a;
  llegir_arbre_est(a);
  int dni;
  
  while (cin >> dni) {
    
    pair<int, int> p_depth_mark = buscarEstudiantArbre(a,dni,0);
    
    if(p_depth_mark.first == -1){
      cout << "L'estudiant " << dni << " no hi és" << endl;
    }
    else if(p_depth_mark.second == -1){
      cout << "L'estudiant " << dni << " té profunditat " << p_depth_mark.first << ", però no té nota" << endl;
    }
    else {
      cout << "L'estudiant " << dni << " té profunditat " << p_depth_mark.first << " i la seva nota és " << p_depth_mark.second << endl;
    }
  }
}
