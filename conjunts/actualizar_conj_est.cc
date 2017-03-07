/*
 * Este fichero muestra algunas de las funcionalidades de la clase set
 * (conjunto) de STL introducidas en el correspondiente pdf de la web de PRO2.
 *
 * Retomamos un ejercicio de la sesion 2 (Actualizacion de un conjunto de
 * estudiantes) y lo adaptamos para resolverlo usando sets. Notad que hay
 * grandes diferencias entre las soluciones de ambas versiones, debidas sobre
 * todo a la ausencia en la clase set de una modificadora por posicion.
 *
 * Concretamente, a la hora de actualizar un estudiante de un set<Estudiant>
 * nos vemos obligados a borrarlo y volverlo a añadir; mostramos dos formas de
 * hacerlo, una de ellas solo válida en c++11.  Recordad que el comando p2++ ya
 * incorpora la directiva para usar esta version del compilador, pero si usais
 * g++ a secas este programa dará error.
 *
 * Notad tambien que este programa requiere una version especial de la clase
 * Estudiant, que incluimos en esta carpeta. 
 */

#include <iostream>
#include <set>
#include "Estudiant.hh"

using namespace std;

typedef set<Estudiant> Cjt_estudiants;

// se escribe un estudiante en cada linea 
void escribir (const Cjt_estudiants& c){
  Cjt_estudiants::const_iterator it = c.begin();
  while(it != c.end() ){
    it->escriure(); 
    ++it;
  }
  cout << endl;
}

// se leen e insertan estudiantes hasta que llegue uno con dni =0
void leer (Cjt_estudiants& c){
  Estudiant e; e.llegir();
  while(e.consultar_DNI()!=0){
    c.insert(e);
    e.llegir();
  }
}

void actualizar(Cjt_estudiants& c1, const Cjt_estudiants& c2)
/* Pre: cierto */
/* Post: todo estudiante de c1 que tambien este en c2, pasa a tener la
   nota de su aparicion en c2 si esta es mejor que la de c1; el resto queda
   como estaba */
{
  // VERSION SIN find; se recorren los dos sets sincronizadamente,
  // actualizando c1 cuando toque; la version con find se puede hacer
  // como ejercicio, es mas sencilla pero menos eficiente

  Cjt_estudiants::iterator it1 = c1.begin();
  Cjt_estudiants::iterator it2 = c2.begin();

  while (it1 != c1.end() and it2!=c2.end()){
    if (*it1 < *it2) ++it1; // operador < de Estudiant
    else if (*it1 > *it2) ++it2; // operador > de Estudiant
    else  { // mismo dni
      if (it2->te_nota()){ 
	// el de c2 tiene nota; en caso contrario no hay que hacer nada
	if (not it1->te_nota()) { 
	  // si el de c1 no tiene nota siempre se actualiza	   
	  Estudiant e(it1->consultar_DNI());
	  e.afegir_nota(it2->consultar_nota());
	  Cjt_estudiants::iterator itaux = it1;  //
	  ++it1;                                 // actualizacion de c1,
	  c1.erase(itaux);                       // estilo c++98, ineficiente
	  c1.insert(e);                          // c1.insert(it1,e) es un poco 
	  ++it2;                                 // mejor, pero no demasiado
	}
	else if (it2->consultar_nota()> it1->consultar_nota()) {
	  // si los dos tienen nota hay que comparar
	  Estudiant e(it1->consultar_DNI()); 
	  e.afegir_nota(it2->consultar_nota());
	  it1=c1.erase(it1);    // estilo c++11, eficiente
	  it1=c1.insert(it1,e); // compilar con p2++ !!!
	  ++it2;  ++it1;
	}
	else {++it1; ++it2;}
      } 
      else  {++it1; ++it2;}
    }
  }
}

int main (){
  Cjt_estudiants c1, c2;
  cout << "primer conjunto (c1):" << endl;  leer(c1); 
  cout << "segundo conjunto (c2):" << endl;  leer(c2);
  actualizar(c1,c2);
  cout << "c1 actualizado:" << endl;
  escribir(c1);
}
