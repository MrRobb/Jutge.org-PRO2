#include "utils.PRO2"
#include "Palabra.hh"

int main()
{
  cout << "Vamos a comprobar que la copia de palabras y otras operaciones funcionan bien."<< endl<< endl;
  cout << "Escribe una palabra: ";
  Palabra p;  p.leer('.');
  cout << "La palabra leída es: '";
  p.escribir();  cout << "' y su longitud es ";
  cout << p.long_pal() << endl;

  Palabra p2;
  p2=p; cout << "La copia es '"; 
  p2.escribir(); cout << "' y su longitud es ";
  cout << p2.long_pal() << endl;
  if (p.iguales(p2)) cout << "Son iguales";
  else cout << "No son iguales";
  cout << endl;

  cout << "Escribe un caracter para ponerselo a la copia: ";    
  char k=readchar();
  p2.anadir_letra(k);

  cout << "La palabra original es '"; 
  p.escribir(); cout << "' y su longitud es ";
  cout << p.long_pal() << endl;

  cout << "La copia con el caracter adicional es '"; 
  p2.escribir(); cout << "' y su longitud es ";
  cout << p2.long_pal() << endl;

  if (p.iguales(p2)) cout << "Son iguales";
  else cout << "No son iguales";
  cout << endl;
}

