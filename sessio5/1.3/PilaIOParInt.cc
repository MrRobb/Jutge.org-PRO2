
#include "PilaIOParInt.hh"
#include <iostream>

using namespace std;

void llegir_stack_int(stack<int>& p, int marca){
  int n;
  cin >> n;
  while (n != marca){
    p.push(n);
    cin >> n;
  }
}

void escriure_stack_int(stack<int> p){
  cout << "[Cim] ";
  // el paso por valor copia p correctamente ya que la clase tiene 
  // creadora copiadora
  while(not p.empty()){ 
    cout << p.top() << " ";
    p.pop(); // el que no haya salto de linea entre elementos 
  }          // solo interesa si la pila no es muy grande
  cout << "[Ultim]"<<endl;
}

void llegirPilaParInt(stack<ParInt>& p){
  ParInt par;
  while(par.llegir()){
    p.push(par);
  }
}
// Pre: p és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han apilat a p els elements llegits fins al 0 0 (no inclòs)

void escriurePilaParInt(stack<ParInt> p){
  while(!p.empty()){
    p.top().escriure();
    p.pop();
  }
}
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de p
