#ifndef COLA_IO_INT
#define COLA_IO_INT

#include "utils.PRO2"
#include <queue>

void llegir_queue_int(queue<int> &p, int marca)
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
 
void escriure_queue_int(queue<int> p)
{
  cout << "[Primer] ";
  // el paso por valor copia p correctamente ya que la clase tiene 
  // creadora copiadora
  queue<int> copia(p);
  while( not copia.empty()){
    cout << copia.front() << " ";
    copia.pop(); // el que no haya salto de linea entre elementos
  }              // solo interesa si la cola no es muy grande
  cout << "[Ultim]"<<endl;
}

#endif
