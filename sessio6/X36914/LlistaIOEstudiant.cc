#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l){
  Estudiant est;
  est.llegir();
  while(est.consultar_DNI() != 0){
    l.push_back(est);
    est.llegir();
  }
}
// Pre: l és buida; el canal estandar d’entrada conté parelles
// de valors <enter, double>, acabat per un parell 0 0
// Post: s’han afegit al final de l els estudiants llegits fins al 0 0 (no inclòs)

void EscriureLlistaEstudiant(list<Estudiant>& l){
  Estudiant est;
  for(list<Estudiant>::iterator it = l.begin(); it != l.end(); ++it){
    est = *it;
    est.escriure();
  }
}
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l
