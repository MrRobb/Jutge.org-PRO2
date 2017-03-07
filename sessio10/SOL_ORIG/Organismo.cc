/** @file Organismo.cc
    @brief Código de la clase Organismo 
*/

#include "Organismo.hh"

// Sobre la notación de los comentarios:
// - hi(a): hijo izquierdo del arbol a
// - hd(a): hijo derecho del arbol a  

Organismo::Organismo() 
{
  id=0;
  maligno=false;
  victimas=0;
}

void Organismo::incrementar_victimas() 
{
  ++victimas;
}

void Organismo::anadir_id(int id) 
{
  this->id = id;
}

int Organismo::lucha_organismos(const Organismo &o2) const 
{
  // Ésta es la operación más importante del módulo. Dados dos organismos, hay
  // que decidir primero si van a luchar de verdad o no, es decir, si sus
  // estructuras celulares son simétricas o no. Por eso, introducimos la
  // operación auxiliar "simetricos" en la parte privada.  Notad que en la
  // cabecera de la operación "simetricos" decimos que los parámetros han de
  // ser árboles de Celula, pero la operación es independiente del tipo de los
  // elementos del árbol, ya que éstos nunca se llegan a consultar.  Asímismo,
  // debemos disponer de otra operación que aplique las luchas de las células
  // de dos árboles, sabiendo que son simétricos. Aquí sí es relevante el
  // hecho de que los árboles sean de células. Esta nueva operación privada se
  // llama "lucha_arboles".

  int n;
  Arbre<Celula> aux1(celulas);       // podemos prescindir de aux1 y aux2
  Arbre<Celula> aux2(o2.celulas);    // si simetricos y lucha_arboles
  if (simetricos(aux1, aux2)) {      // replantan sus parámetros para no
    aux1 = celulas;                  // destruirlos, pero entonces 
    aux2 = o2.celulas;               // lucha_organismos no puede ser const
    pair<int, int> m = lucha_arboles(aux1, aux2);
    if (m.first == m.second) n = 0;
    else if (m.first < m.second) n = 1;
    else n = 2; // m.first > m.second
  }
  else n = 3;
  return n;
}

bool Organismo::simetricos(Arbre<Celula> &a1, Arbre<Celula> &a2)
{
  bool b;
  if (a1.es_buit() or a2.es_buit()) b = a1.es_buit() and a2.es_buit();
  else {
    Arbre<Celula> fe1, fe2, fd1, fd2; 
    a1.fills(fe1,fd1); // fe1 = hi(A1); fd1 = hd(A2); a1 = buit 
    a2.fills(fe2,fd2); // fe2 = hi(A2); fd1 = hd(A2); a2 = buit
    b = simetricos(fe1, fd2);
    // HI1: b indica si hi(A1) y hd(A2) son simétricos
    if (b) { b = simetricos(fd1, fe2);
             // HI2: b indica si hd(A1) y hi(A2) son simétricos
    }
  }
  return b;
}

pair<int,int> Organismo::lucha_arboles(Arbre<Celula> &a1, Arbre<Celula> &a2)
{
  pair<int,int> n;

  if (a1.es_buit()) {
    n.first = 0; 
    n.second = 0;
  }
  else {
    int nraiz = a1.arrel().lucha_celulas(a2.arrel());
    n.first = 0; 
    if (nraiz == 1) ++n.first;
    n.second = 0;
    if (nraiz == 2) ++n.second;
    Arbre<Celula> fe1, fe2, fd1, fd2; 
    a1.fills(fe1,fd1); // fe1 = hi(A1); fd1 = hd(A2); a1 = buit 
    a2.fills(fe2,fd2); // fe2 = hi(A2); fd1 = hd(A2); a2 = buit
    pair<int,int> na = lucha_arboles(fe1, fd2);
    //       HI1: na.first = número de células de hi(A1) que vencen a su 
    //                       correspondiente en hd(A2);
    //            na.second = número de células de hd(A2) que vencen a su 
    //                        correspondiente en hi(A1)
    pair<int,int> nb = lucha_arboles(fd1, fe2);
    //       HI2: nb.first = número de células de hd(A1) que vencen a su 
    //                       correspondiente en hi(A2);
    //            nb.second = número de células de hi(A2) que vencen a su 
    //                        correspondiente en hd(A1)
    n.first += na.first + nb.first;
    n.second += nb.second + na.second;
  }
  return n;
}

bool Organismo::es_maligno() const 
{
  // Devuelve el valor del campo "maligno" del organismo correspondiente.
  return maligno;
}

int Organismo::num_victimas() const 
{
  // Devuelve el valor del campo "victimas" del organismo correspondiente.
  return victimas;
}

void Organismo::leer(int N) 
{
  // Esta operación simplemente lee la estructura celular del organismo e
  // inicializa el recuento de víctimas. Un árbol de células se lee igual que
  // un árbol de enteros. Suponemos que contamos con una marca de tipo Celula
  // para indicar que llegamos a un árbol vacío.

  if (N<=0) throw PRO2Excepcio("Las celulas del organismo han de tener N parametros (N>0)");

  celulas.a_buit();
  leer_arbol_celulas(N, celulas);
  maligno = readbool();
  victimas = 0;
}

void Organismo::leer_arbol_celulas(int N, Arbre<Celula> &a) 
{
  Arbre<Celula> a1, a2;
  Celula c;
  c.leer(N);
  if (not c.es_vacia()) {
    leer_arbol_celulas(N, a1);
    leer_arbol_celulas(N, a2);
    a.plantar(c, a1, a2);
  }
}

void Organismo::escribir(bool estr) const
{
  // Escribimos los campos del organismo.  Un árbol de células se escribe
  // igual que un árbol de enteros, suponiendo que (como es el caso) exista
  // una operación para escribir células.
  cout << id << " " << victimas;
  if (estr) {
    Arbre<Celula> copia(celulas);
    escribir_arbol_celulas_id(copia);
  }
  cout << endl;
}

void Organismo::escribir_arbol_celulas_id(Arbre<Celula> &a)
{
  if (not a.es_buit()) {
    Arbre<Celula> a1, a2;
    Celula aux = a.arrel();
    a.fills(a1,a2);    
    escribir_arbol_celulas_id(a1);
    cout << " ";
    aux.escribir();
    escribir_arbol_celulas_id(a2);
  }
}

