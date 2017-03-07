#include "Palabra.hh"

/*
* Implementacio de la classe Palabra
*/

/* 
  Nomes hi pot haver en una paraula els caracters a..z A..Z 0..9
  La resta es consideren separadors.
 
  Nomes son rellevants les lletres del vector situades en les
  posicions 0..longitud-1; la resta no es poden visitar excepte per
  ocupar-les, incrementant la seva longitud.
 
  Les operacions de lectura requereixen un parametre que es fara servir per
  distingir un separador especial, que serveixi d'exemple per marcar el
  final d'un text. Aquest separador especial pot ser qualsevol caracter
  "visible" diferent de a..z, A..Z i 0..9, per exemple '$', '.' o '*'
  (pero no el blanc, el salt de linia o el tabulador).
 
  Les posicions des de MAXLONG endavant no es poden ni consultar ni ocupar.
*/


/* Constructores */
Palabra::Palabra ()
{
  letras = vector<char> (MAXLONG);
  longitud = 0; 
}

/* Per reconeixer els caracters no valids */
bool Palabra::es_separador (char c)
{ 
  return (not(((47 < c) and (c < 58)) or	// nombres
	      ((64 < c) and (c < 91)) or	// majuscules
	      ((96 < c) and (c < 123))));	// minuscules
}


/* Modificadores dels camps */

void Palabra::anadir_letra (char c)
{
  if (longitud >= MAXLONG)
    throw PRO2Excepcio ("Palabra demasiado larga");
  if (es_separador (c)  ){ cout << c << " no es un caracter valido" << endl;
    throw PRO2Excepcio ("Has intentado anadir un caracter no valido");
  }
  letras[longitud] = c;
  longitud++;
}


/* Consultores dels camps */
int Palabra::longitud_maxima ()
{
  return MAXLONG;
}

int Palabra::long_pal () const
{
  return longitud;
}

char Palabra::consultar_letra (int i) const
{
  i--;
  if (i < 0)
    throw PRO2Excepcio ("Posicion negativa o cero");
  if (i >= longitud)
    throw PRO2Excepcio ("Posicion mayor que la longitud");
  
  return letras[i];
}


bool Palabra::iguales (const Palabra & p) const
{
  bool b;
  if (this->longitud != p.longitud) b = false;   
  else
    {
      b = true;
      int i = 0;
      while (i < this->longitud and b)
	{
	  b = letras[i] == p.letras[i];
	  i++;
	}
    }
  return b;
}


/* Entrada / Sortida */

void saltar_separador (char m)
  // s'atura en arribar al primer no separador o a la marca
{
  while (Palabra::es_separador (cin.peek ()) and cin.peek ()!=m)
      // and (cin.peek () != EOF)) //Per sequencies sense paraula final
    { 
      cin.ignore ();
    }
}


void Palabra::leer (char marca)
{
  if (not (((marca>=33)and (marca <= 47)) // de ! a /
	   or ((marca>=58)and (marca <= 64)) // de : a @
	   or ((marca>=91)and (marca <= 96)) // de [ a `
	   or ((marca>=123)and (marca <= 126)))) // de { a ~
	throw PRO2Excepcio ("Marca no valida");

  //Navega fins a la seguent paraula o la marca
  saltar_separador (marca);

  //iniciem la paraula
  longitud = 0;

 
  if  (cin.peek()== marca) cin.ignore();
  else { 
  //llegim la paraula
  while (not es_separador (cin.peek ()))
      // and (cin.peek () != EOF)) //Per sequencies sense paraula final
    {
      if (longitud >= MAXLONG)
	throw PRO2Excepcio ("Palabra demasiado larga");
     
      cin >> letras[longitud];
      longitud++;
    }
  }
}


void Palabra::escribir () const
{
  for (int i = 0; i < this->longitud; i++)
    {
      cout << letras[i];
    }
}
