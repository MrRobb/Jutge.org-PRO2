#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l){
  ParInt p;
  while (p.llegir()) {
    l.push_back(p);
  }
}
// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)

void EscriureLlistaParInt(const list<ParInt>& l){
  ParInt p;
  for(list<ParInt>::const_iterator it = l.begin(); it != l.end(); ++it){
    p = *it;
    p.escriure();
  }
}
// Pre: cert
// Post: s’han escrit al canal estandar els elements de l
