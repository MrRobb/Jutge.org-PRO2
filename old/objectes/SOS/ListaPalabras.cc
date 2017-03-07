#include "ListaPalabras.hh"

struct palfrec
{
  Palabra par;
  int freq;
};

struct listOculta {
  vector<palfrec> paraules;
  int nparaules;
};
/*
* Implementacio Classe ListaPalabras
*/

/* Constructores */
ListaPalabras::ListaPalabras ()
{ 
  list = new listOculta;
  list->paraules = vector<palfrec>(MAXNUMPAL);
  list->nparaules = 0;
}

/* Consultores dels camps */
int
ListaPalabras::longitud_maxima ()
{
  return MAXNUMPAL;
}

int
ListaPalabras::longitud () const
{
  return list->nparaules;
}

int
ListaPalabras::max_frec () const
{
  int maxim = 0;

  for (int posPalabra = 0; posPalabra < list->nparaules; posPalabra++)
    {
      int freq = list->paraules[posPalabra].freq;
      if (freq > maxim) maxim = freq;
    }
  return maxim;
}

  /* Modificadores dels camps */

  /* Modificadora: si la paraula hi es, incrementa la seva frequencia;
     si no, la introdueix amb frequencia 1;
     no es pot superar la longitud MAXNUMPAL */

void
ListaPalabras::anadir_palabra (const Palabra & p)
{
//Miro si existeix la paraula

  int posPalabra = 0; bool b= false;
  while (posPalabra < list->nparaules and not b)
    {
      if (p.iguales(list->paraules[posPalabra].par)) b=true;
      else posPalabra++; 
    }
  if (not b)
    {cout << "nueva" << endl;
//comprovar que la llista no estigui plena
      if (list->nparaules == MAXNUMPAL)
	throw PRO2Excepcio ("Ya no se pueden anadir mas palabras");
//la paraula no hi es
      list->paraules[list->nparaules].par=p;
      list->paraules[list->nparaules].freq = 1;
      list->nparaules++;
    }
  else
    {cout << "ya estaba" << endl;
//la paraula hi es
      list->paraules[posPalabra].freq++;
    }
}

/* Lectura i escriptura */
void
ListaPalabras::escribir () const
{
  for (int i = 0; i < list->nparaules; i++)
    {
      list->paraules[i].par.escribir ();
      cout << " - " << list->paraules[i].freq << endl;
    }

}
