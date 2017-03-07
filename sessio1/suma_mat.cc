#include <iostream>
using namespace std;


#include "matrizIOint.hh" // contiene la declaracion 
                          // typedef vector <vector<int> > Matriz;
      
Matriz sumar_matriz_int(const Matriz& m1, const Matriz& m2)
{
  int fil = m1.size(); int col = m1[0].size(); 
  vector<vector<int> > suma(fil, vector<int>(col));  // para que se vea que el typedef
  for (int i=0; i<fil;++i) {                // produce nombres equivalentes
    for (int j=0; j<col;++j)
      suma[i][j]=m1[i][j]+m2[i][j];     
  }
  return suma;
}


int main()
{
  cout << "Primera matriz" << endl;
  Matriz m1;
  leer_matriz_int(m1);  
  cout << "Segunda matriz (ha de tener la misma dimension que la primera) " << endl;
  Matriz m2;
  leer_matriz_int(m2);  

  Matriz s = sumar_matriz_int(m1,m2);

  cout << "La matriz suma es: " << endl;
  escribir_matriz_int(s);
}
