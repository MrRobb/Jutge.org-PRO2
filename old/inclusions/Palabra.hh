#ifndef PALABRA_HH
#define PALABRA_HH

#include "utils.PRO2"
#include <vector>

class Palabra
{
private:
  static const int MAXLONG = 20;
  vector<char> letras; 
  int longitud;

public:
   /* Constructoras */ 
  Palabra ();
 
  /* Modificadoras */
  void anadir_letra (char c);

  /* Consultoras  */
  static int longitud_maxima ();
  int long_pal () const;
  static bool es_separador (char c);  
  char consultar_letra (int i) const;
  bool iguales (const Palabra & p) const;

  /* Lectura y escritura */
 
  void leer (char marca);
  void escribir () const;

};

#endif
