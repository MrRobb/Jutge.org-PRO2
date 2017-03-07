#ifndef _CUBETA_HH_
#define _CUBETA_HH_

#include "Lavadora.hh"
#include <stack>

class Cubeta
{
public:
  Cubeta();
  Cubeta(const Cubeta& c);
  void anadir_prenda(const Prenda &p);
  void completar_lavadora(Lavadora &l);
  void escribir() const;

private:
  stack<Prenda> ropacolor;
  stack<Prenda> ropablanca;
  static void completar_lavadora_pila_rec(stack<Prenda> &p ,Lavadora &l);
  static void completar_lavadora_pila_it(stack<Prenda> &p,Lavadora &l);
  static void escribir_pila_prenda(const stack<Prenda>& p);
};
#endif
