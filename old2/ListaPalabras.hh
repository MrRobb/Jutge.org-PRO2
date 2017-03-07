#ifndef LISTAPALABRAS_HH
#define LISTAPALABRAS_HH

#include "Palabra.hh"

/*
* Clase ListaPalabras
*/

struct listOculta; 

class ListaPalabras
{

private:

  listOculta * list;
  static const int MAXNUMPAL = 20;
/* MAXNUMPAL se podria incluir como campo normal, para poder manejar
     distintos maximos segun la situacion */
 
public:
  /* Constructoras */   
  ListaPalabras ();

  /* Modificadoras  */
  void anadir_palabra (const Palabra & p);

  /* Consultoras */
  static int longitud_maxima ();
  int longitud () const;
  int max_frec () const;

  /* Lectura y escritura */
  void escribir () const;

};

#endif
