#include "listIOint.hh"

void llegir_llista_int(list<int>& l, int marca){
  list<int>::iterator it = l.begin();
  int x; cin >> x; 
  while (x != marca) {
    l.insert(it, x);
    cin >> x;
  }
}

void escriure_llista_int(const list<int>& l) {
  if (not l.empty()) {
    list<int>::const_iterator it;
    cout << "[Primero] ";
    for (it = l.begin(); it != l.end(); ++it){
      cout << *it << " "; // si la lista no es de enteros
    }                     // quedara mejor si hacemos endl para cada elemento
    cout << "[Ultimo]";
  } 
  cout << endl;
}

