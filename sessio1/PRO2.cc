#include <iostream>
using namespace std;

int main() 
{
  cout << "Escull idioma / Escoge idioma (cat = 1; cast = 2): " << endl;
  char id;
  cin >> id;
  if (id == '1') {
    cout<<  "Hola! Escriu el teu nom: " << endl;
    string ent;
    cin >> ent;     
    cout <<"Enhorabona "<< ent <<"! El teu primer programa s'ha executat exitosament." << endl;
  }
  else {
    cout<<  "Hola! Escribe tu nombre: " << endl;
    string ent;      
    cin >> ent; 	 
    cout <<"Enhorabuena "<< ent <<"! Tu primer programa se ha ejecutado con éxito." <<endl;
  }
}

