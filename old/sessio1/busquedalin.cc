#include "utils.PRO2"
#include <vector>


/* Leer vector */
void leerVector_int(vector<int>& v) // version accion
{
  cout<<"Escribe el tamaño del vector:"<<endl;
 
  int numEst=readint();
  v = vector<int> (numEst);
  
  cout<<"Escribe los elementos del vector:"<<endl;  
  for (int i=0; i<numEst;++i)
    {
       v[i] = readint();
    }
 }

/* Escribir vector */
void escribirVector_int(const vector<int>& v)
{
  for (int i=0; i<v.size();++i)
    {
      cout << v[i] << " ";
    }
  cout << endl;
}

/* Buscar  */    
bool busqueda_lin(const vector<int> &v, int x)
/* Pre: cierto */
/* Post: el resultado indica si x está en v */
{
  int tam = v.size();
  int i =0;
  bool b = false;
  while (i<tam and not b) {
    if (v[i]==x) b=true; 
    else ++i;
  }
  return b;
}

int main ()
{
  vector<int> v;
  leerVector_int(v); 
  cout << "Escribe el elemento a buscar: " << endl;
  int x = readint();
  bool b= busqueda_lin(v,x);
  if (b)  cout << "El elemento " << x << " esta en el vector." << endl << endl;
  else cout << "El elemento " << x << " no esta en el vector." << endl << endl;
  cout << "Escribimos el vector para que se vea que no ha cambiado:" << endl;
  escribirVector_int(v);
}
