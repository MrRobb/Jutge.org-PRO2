#ifndef _PRENDA_HH_
#define _PRENDA_HH_

#include "utils.PRO2"

class Prenda
{
public:
  //Constructoras
  Prenda();
  Prenda(int,bool);
  
  //Modificadoras
  void modificar_prenda(int, bool);
  
  //Consultoras
  int consul_peso() const;
  bool consul_color() const;


  //Escritura de prenda
  void escribir() const;

private:
  int peso;
  bool color;
};

#endif
