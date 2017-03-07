/*
 * Programa de prova de la classe map (diccionari).
 *
 * Es treballa amb un map amb clau de classe standard (string) i valor definit
 * per l'usuari (un struct amb dos double).
 *
 * Es proven diverses opcions d'afegir i esborrar elements, cerques amb find i
 * us d'iteradors.
 *
 */

#include <string>
#include <map>
#include <iostream>

using namespace std;

struct info_persona {
  double edat;
  double pes;
  void mostra() const{
    cout << edat << " " << pes << endl; 
  }
};

void consulta(const map<string, info_persona>& d) {
  // el map pot ser const perque dins de l'operacio no es fa servir []
  map<string, info_persona>::const_iterator it;
  for (it=d.begin(); it!=d.end(); ++it){
    cout << it->first << " "; 
    it->second.mostra();
  }
}

int main() {
   map<string, info_persona> d;
   // la clau del map es una string que representa el nom d'una persona; 
   // el valor es la resta d'informacio d'aquesta persona

   // access estil vector: cost logaritmic

   cout << "El diccionari té mida " << d.size() << endl;
   cout << "L'Albert pesa " << d["Albert"].pes << " kilos" << endl;
   // noteu que la instruccio anterior ha afegit un element al map,
   // amb valors per defecte d'info_persona

   cout << "El diccionari té mida " << d.size() << endl;

   d["Albert"].pes=5; 

   d["Micaela"].edat = 3;
   d["Micaela"].pes = 18;

   cout << "El diccionari té mida " << d.size() << endl;

   // cerca a un map amb l'operacio find
   map<string, info_persona>::iterator it = d.find("Albert");
   if (it == d.end()) cout << "L'Albert no hi és" << endl;
   else cout << "L'Albert te " <<  it->second.edat << " anys i pesa " << it->second.pes << " kilos" << endl;

   if (it != d.end()) ++it->second.edat; // aquesta modificacio te cost constant
   // el find que ha retornat it te cost logaritmic

   // insert i erase nomes amb un pair <clau,valor>: cost logaritmic
   info_persona info;
   info.edat = 18;
   info.pes = 64;
   d.insert(make_pair("Manel", info)); 
   d.insert(pair<string, info_persona>("Enric", info)); 
   cout << "map despres d'inserir 'Enric' i 'Manel'" << endl;
   consulta(d);
   d.erase("Albert");
   cout << "map despres d'esborrar 'Albert'" << endl;
   consulta(d);
   it = d.find("Albert");
   if (it == d.end()) cout << "L'Albert no hi és" << endl;
   else cout << "L'Albert pesa " << it->second.pes << " kilos" << endl;

   // insert i erase amb iterador: cost constant (l'insert nomes es
   // constant si l'iterador es "bo"
   it = d.begin();
   map<string, info_persona>::iterator it2 = it;
   ++it;
   d.erase(it2); // esborrem el primer element; it apunta al nou primer element
   info.edat = 2;
   info.pes = 10;
   d.insert(it,make_pair("Albert", info)); // "ajudem" l'insert a posar 'Albert'
                                           //  al seu lloc (cost constant)
   cout << "map despres d'esborrar 'Enric' i afegir 'Albert' amb nova info" << endl;
   consulta(d);


   // al c++11 es pot fer el mateix sense l'iterador it2
   //
   // it = d.erase(it);
   // info.edat = 2;
   // info.pes = 10;
   // d.insert(it,make_pair("Albert", info));
}

