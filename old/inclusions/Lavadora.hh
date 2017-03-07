#ifndef _LAVADORA_HH_
#define _LAVADORA_HH_

#include "Prenda.hh"
#include <list>

class Lavadora
{
public:
  Lavadora();
 
  void inicializar_lavadora(int pmax, bool col);
  void anadir_prenda (const Prenda &p);
  void lavado ();
  bool esta_inicializada() const;
  bool consultar_color_lavadora() const;
  int consultar_peso_lavadora() const;
  int consultar_peso_maximo() const;
  void escribir() const;

private:
  list<Prenda> prendas;
  bool col;
  int pes;
  bool ini;
  int pesmax;
};
#endif
