#ifndef PILA_IO_INT
#define PILA_IO_INT

#include "utils.PRO2"
#include <stack>

void llegir_stack_int(stack<int> &p, int marca)
/* Pre: p es vacia */
/* Post: p esta formada por los elementos leidos antes de la marca */ 
{
  int n;
  cin >> n;
  while (n != marca){
    p.push(n);
    cin >> n;
  }
}

void escriure_stack_int(stack<int> p)
{
  cout << "[Cim] " << endl;
  // el paso por valor copia p correctamente ya que la clase tiene 
  // creadora copiadora
  while(not p.empty()){ 
    cout << p.top() << endl;
    p.pop(); // el que no haya salto de linea entre elementos 
  }          // solo interesa si la pila no es muy grande
  cout << "[Ultim]"<<endl;
}

#endif
