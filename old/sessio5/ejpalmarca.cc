#include "Palabra.hh"

int main()
{
  cout << "Vamos a contar las palabras que hay en un texto."<< endl;
  cout << "Escribe un texto acabado en un punto."<< endl;
  cout << "Todo lo que no sea letras sin diacríticos, números o el punto, es considerado un separador."<< endl << endl;

  Palabra p; 
  p.leer('.');          
  int cont = 0;
  while (p.long_pal()!=0) {
	  cont++;
	  p.leer('.');
      }
  cout << "el texto contiene " << cont << " palabras" << endl;
}

