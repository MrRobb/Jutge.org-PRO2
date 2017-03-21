//
//  program.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 20/3/17.
//

#include <iostream>
#include "LlistaIOEstudiant.hh"

using namespace std;

int BuscarDNIenLlistaEstudiant(list<Estudiant> &l, int dni){
  int count = 0;
  for(list<Estudiant>::iterator it = l.begin(); it != l.end(); ++it){
    Estudiant est;
    est = *it;
    if(est.consultar_DNI() == dni) ++count;
  }
  return count;
}

int main(){
  list<Estudiant> l;
  LlegirLlistaEstudiant(l);
  int dni; cin >> dni;
  int count = BuscarDNIenLlistaEstudiant(l, dni);
  cout << dni << ' ' << count << endl;
}
