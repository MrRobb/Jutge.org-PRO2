#include "vectorIOEstudiant.hh"

/* Leer vector */
void leer_vector_estudiant(vector<Estudiant>& v) {// version accion
  cout<<"Escribe el tamaño del vector:"<<endl;
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);
  
  for (int i=0; i<numEst;++i)
    v[i].llegir();
}

/* Escribir vector */
void escribir_vector_estudiant(const vector<Estudiant>& v) {
  for (int i=0; i<v.size();++i)
    v[i].escriure();
  cout << endl;
}
