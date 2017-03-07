/*
 * Programa de prova de la classe map (diccionari).
 *
 * Es treballa amb un map amb clau definida per l'usuari (un struct
 * amb tres int) i valor de tipus basic standard (int).
 *
 * Es prova la definicio d'un ordre determinat per a la clau amb un
 * operator< i la cerca avançada amb lower_bound
 * 
 */

#include <map>
#include <iostream>
 
using namespace std;

struct Data {
  int dia;
  int mes;
  int any;

  bool operator<(const Data& d) const 
  // indica si el p.i. es anterior a d en ordre cronologic
{
    if (any != d.any) return any < d.any;   
    else if (mes != d.mes) return mes < d.mes;
    else return dia < d.dia;
  }

  void mostra() const{
    cout << dia << "/" << mes << "/" << any;
  }
};

void consulta(const map<Data, int>& d, map<Data, int>::const_iterator it) {
  // Pre: it ha de fer referencia a un element de d o ser d.end()
  // Post: s'han escrit al canal estandar de sortida els elements de d 
  // a partir d'it
  map<Data, int>::const_iterator it2;
  for (it2=it; it2!=d.end(); ++it2){
    it2->first.mostra();
    cout << ": " << it2->second << endl;  
  }
}

int main() {
  map<Data, int> visitants;
  // el map associa un enter a cada data, que representa per exemple
  // el nombre de visitants d'un museu a la data en questio

  Data data1, data2, data3;
  // donem valor a tres dates

  data1.dia = 1;
  data1.mes = 1;   
  data1.any = 2015;

  data2.dia = 2;
  data2.mes = 1;   
  data2.any = 2015;

  data3.dia = 8;
  data3.mes = 1;   
  data3.any = 2015; 

  // associem el nombre de visitants de cada data al map   
  visitants[data2] = 142;
  visitants[data3] = 21;
  visitants[data1] = 0; // es un dia festiu

  // escrivim tots els elements del map des de la posicio begin; noteu
  // com s'escriuen en ordre cronologic, independentment de quan hi
  // han entrat

  consulta(visitants, visitants.begin());
  cout << endl;

  // volem recorrer el map a partir d'una data concreta que pot no ser-hi al
  // map; el punt de començament del recorregut es detecta amb l'operacio
  // lower_bound aplicada a la data desitjada
 
  Data reis;
  reis.dia = 6;
  reis.mes = 1;   
  reis.any = 2015;
  map<Data, int>::const_iterator i_reis = visitants.lower_bound(reis);
  consulta(visitants, i_reis);
  cout << endl;
}

