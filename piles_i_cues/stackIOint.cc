
#include "stackIOint.hh"

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
