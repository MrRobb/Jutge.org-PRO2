#ifndef LISTA_IO_INT
#define LISTA_IO_INT
#include "utils.PRO2"
#include <list>
 
void  llegir_llista_int(list<int>& L, int marca){
  list<int>::iterator it = L.begin();
  int x = readint();
  while (x != marca) {
    L.insert(it, x);
    x = readint();
  }
}

void escriure_llista_int(const list<int> &L) {
  if (not L.empty()) {
    list<int>::const_iterator it;
    cout << "[Primero] ";
    for (it = L.begin(); it != L.end(); ++it){
      cout << *it << " "; // si la lista no es de enteros
    }                     // quedar‡ mejor si hacemos endl para cada elemento
    cout << "[òltimo]";
  } 
  cout << endl;
}
#endif
