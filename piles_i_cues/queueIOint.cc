#include "queueIOint.hh"

void llegir_queue_int(queue<int>& q, int marca){
  int n;
  cin >> n;
  while (n != marca){
    q.push(n);
    cin >> n;
  }
}
 
void escriure_queue_int(queue<int> q){
  cout << "[Primer] ";
  // el paso por valor copia q correctamente ya que la clase tiene 
  // creadora copiadora
  while(not q.empty()){
    cout << q.front() << " ";
    q.pop(); // el que no haya salto de linea entre elementos
  }              // solo interesa si la cola no es muy grande
  cout << "[Ultim]"<<endl;
}
