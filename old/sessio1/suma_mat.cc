#include "utils.PRO2"
#include <vector>

typedef vector <vector<int> > Matriz;

void leerMatriz_int(Matriz& m)
{
  cout<<"Escribe las dimensiones de la matriz :"<<endl;
  cout<<"   num filas: ";
  int numfil=readint();   
  cout<<"   num columnas: ";
  int numcol=readint(); 
  m=  Matriz (numfil, vector<int>(numcol));
   
  cout<<"Escribe los elementos de la matriz"<<endl;  
  for (int i=0; i<numfil;++i)
    {
      cout<<"   fila " << i+1 <<" : ";  
      for (int j=0; j<numcol;++j)
	m[i][j]=readint();
    }
 
}

void escribirMatriz_int(const Matriz& m) 
{
  for (int i=0; i<m.size();++i)
    {
      for (int j=0; j<m[0].size();++j) // truco para saber el número
	cout << m[i] [j] << " ";       // de columnas; sólo es útil si
      cout << endl;                    // todas son de la misma dimensión 
    }
}

      
Matriz sumar_Matriz_int(const Matriz& m1, const Matriz& m2)
{
  int fil = m1.size(); int col = m1[0].size(); 
  vector< vector<int> > suma (fil, vector<int>(col));  // para que se vea que el typedef
  for (int i=0; i<fil;++i)                // produce nombres equivalentes
    {
      for (int j=0; j<col;++j)
	suma[i][j]=m1[i][j]+m2[i][j];     
    }
  return suma;
}


int main ()
{
  cout << "Primera matriz" << endl;
  Matriz m1;
  leerMatriz_int(m1);  
  cout << "Segunda matriz (ha de tener la misma dimension que la primera) " << endl;
  Matriz m2;
  leerMatriz_int(m2);  

  Matriz s= sumar_Matriz_int(m1,m2);

  cout << "La matriz suma es: " << endl;
  escribirMatriz_int(s);
}
