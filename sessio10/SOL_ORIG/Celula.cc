/** @file Celula.cc
    @brief Código de la clase Celula
*/

#include "Celula.hh"

Celula::Celula() 
{
  // Inicializa una célula con el id de célula vacía
  id = ID_VACIA;
  i_tol = 0;
}

int Celula::lucha_celulas (const Celula& c2) const 
{

  if (param.size()!=c2.param.size()) throw PRO2Excepcio("Las dos células han de tener el mismo número de parámetros");

  // Se trata de obtener la diferencia entre el número de posiciones de la primera
  // célula que superan a las de la segunda y viceversa. Después se compara dicha
  // diferencia con los indicadores de tolerancia.
  int i = 0; 
  int dif = 0;

  // Inv: dif = diferencia entre el número de posiciones en [0..i-1] en que c1 supera a c2 
  // y viceversa, 0<=i<=param.size()
  
  while (i < param.size()) {
    if (param[i] > c2.param[i]) ++dif;
    else if (param[i] < c2.param[i]) --dif;
    ++i;
  }
  // Post1: dif = diferencia entre el número de posiciones totales en que 
  // c1 supera a c2 y viceversa 
  int n = 3;
  if (dif > c2.i_tol) n = 1;
  else if (dif < -i_tol) n = 2;
  return n;
}

bool Celula::es_vacia() const 
{
  return id == ID_VACIA;
}

int Celula::num_param(){
  return param.size();
}

int Celula::id_vacia() 
{
  return ID_VACIA;
}

void Celula::leer(int N) 
{
  // Simplemente lee todos los componentes de la célula teniendo en cuenta que si 
  // el identificador es cero se trata de una celula "marca" y no es necesario continuar leyendo.

  if (N<=0) throw PRO2Excepcio("La celula ha de tener N parametros (N>0)");

  cin >> id;
  if (id != ID_VACIA) {
    cin >> i_tol;
    param = vector<double> (N);
    for (int i = 0; i < N; ++i) {
      cin >> param[i];
    }
  }
}

void Celula::escribir() const 
{
  // Análogamente, se trata sólo de escribir los componentes que nos interesan,
  // en este caso, según el enunciado, el identificador de la célula.
  cout << id;
}

