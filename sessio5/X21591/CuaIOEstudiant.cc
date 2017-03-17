#include "CuaIOEstudiant.hh"

void LlegirCuaEstudiant(queue<Estudiant> &q){
  int n; cin >> n;
  Estudiant est;
  for (int i = 0; i < n; ++i) {
    est.llegir();
    q.push(est);
  }
}
 
void EscriureCuaEstudiant(queue<Estudiant> q){
  while (!q.empty()) {
    q.front().escriure();
    q.pop();
  }
}
