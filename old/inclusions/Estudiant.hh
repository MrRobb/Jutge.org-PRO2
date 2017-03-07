#ifndef ESTUDIANT_HH
#define ESTUDIANT_HH

#include "utils.PRO2"

class Estudiant {

private:    
  int dni;
  double nota;
  bool amb_nota;
  static const int MAX_NOTA = 10;

public:


  /* Constructores */
  Estudiant();
  Estudiant(int dni);

  /* Destructora por defecte */
  ~Estudiant();

  /* Modificadores */
  void afegir_nota(double nota);
  void modificar_nota(double nota);

 /* Consultores */
  bool te_nota() const;
  double consultar_nota() const;
  static double nota_maxima();
  int consultar_DNI() const;

  /* Entrada / Sortida */
  void llegir();
  void escriure() const;
};
#endif
