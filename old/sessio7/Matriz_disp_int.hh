#include "utils.PRO2"
#include <vector>
#include <list>

class Matriz_disp_int{

// Tipo de modulo: datos
// Descripcion del tipo: representa matrices con implementacion dispersa
// (solo se almacenan los valores distintos de 0). 
// Las filas se guardan en un vector de listas de pares, de forma que  
// m[i][j] = x no es 0 si y solo si la lista de la posicion i del vector 
// contiene el par (j,x).
// Los pares de una lista estan ordenados crecientemente por su primer elemento

private:

  struct parint{
    int col;
    int val;
  };
  vector <list<parint> > filas; // elementos de la matriz
  int nfil;   // dimensiones de la matriz
  int ncol;

public:

  // Constructoras

  Matriz_disp_int (int m, int n);
  /* Pre: n>0 */ 
  /* Post: el resultado es una matriz de mXn con todos sus elementos iguales a 0 */
 
  // Modificadoras 

  void modif_pos (int i, int j, int x);
  /* Pre: 0<=i< num filas del parametro implicito;  0<=j< num columnas del 
     parametro implicito */
  /* Post: el parametro implicito queda como el original pero con x en la
     la posicion [i][j] */

  void suma (const Matriz_disp_int& m1, const Matriz_disp_int& m2);
  /* Pre: m1 y m2 son de la misma dimensión */
  /* Post: el parametro implicito es la suma de m1 y m2 */

  void producto (const Matriz_disp_int& m1, const Matriz_disp_int& m2,);
  /* Pre: el numero de columnas de m1 es igual al numero de filas de m2 */
  /* Post: el parametro implicito es el producto de m1 y m2 */

  // Consultoras

  int num_filas () const;
  /* Pre: cierto */ 
  /* Post: El resultado es el numero de filas del parametro implicito */
 
  int num_columnas () const;
  /* Pre: cierto */ 
  /* Post: El resultado es el numero de columnas del parametro implicito */

  int pos (int i, int j) const;
  /* Pre: 0<=i< num filas del parametro implicito;  0<=j< num columnas del 
     parametro implicito */ 
  /* Post: El resultado es el elemento [i][j] del parametro implicito */
 
 
  // Lectura y escritura
 
  void leer_matriz (int m, int n);
  /* Pre: el canal standard de entrada contiene pares de enteros que
     representan una matriz mXn representada de forma dispersa; al principio
     de cada fila aparece su numero de valores distintos de 0 */
  /* Post: El parametro implicito contiene la matriz formada por los pares
     del canal standard de entrada original; si m o n no coinciden con las
     dimensiones del p.i. este queda redimensionado */

  void escribir_matriz () const;
  /* Pre: cierto */
  /* Post: Se han escrito los valores del parametro implicito en el canal
     standard de salida, una fila por linea */
};
