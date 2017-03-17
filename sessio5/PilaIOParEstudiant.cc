
#include "PilaIOParEstudiant.hh"
#include "Estudiant.hh"
#include <iostream>

using namespace std;

void llegirPilaParInt(stack<Estudiant>& p){
  Estudiant est;
  while(est.consultar_DNI() != 0){
    p.push(est);
  }
}
// Pre: p és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han apilat a p els elements llegits fins al 0 0 (no inclòs)

void escriurePilaParInt(stack<Estudiant> p){
  while(!p.empty()){
    p.top().escriure();
    p.pop();
  }
}
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de p
