#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"
#include <vector>

class Cjt_estudiants {

private:

  // Representa un conjunt ordenat per DNI d'estudiants.  
  // Es poden consultar i modificar els seus elements  
  // (de tipus Estudiant) donat un DNI o per posició en l'ordre.
  vector<Estudiant> vest;
  int nest;
  static const int MAX_NEST = 20;

  void ordenar_cjt_estudiants ();
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);

public:

  //Constructores

  Cjt_estudiants();

  //Destructora

  ~Cjt_estudiants();
   
  //Modificadores

  void afegir_estudiant(const Estudiant& est);

  void modificar_estudiant(const Estudiant& est);

  void modificar_iessim(int i, const Estudiant& est);

  //Consultores
	
  int mida() const;

  static int mida_maxima();

  bool existeix_estudiant(int dni) const;

  Estudiant consultar_estudiant(int dni) const;

  Estudiant consultar_iessim(int i) const;
		
  // Lectura i escriptura
	
  void llegir();

  void escriure() const;

};
#endif
