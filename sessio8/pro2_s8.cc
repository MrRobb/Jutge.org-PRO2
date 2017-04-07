/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
using namespace std;

int main ()
{
  Lavadora(lav);
  Cubeta(cub);
  
  int opcion;
  while (cin >> opcion) {
    // Inicialitzar
    if(opcion == -1){
      int pmax;
      bool col;
      cin >> pmax;
      col = readbool();
      lav.inicializar(pmax, col);
    }
    
    // Añadir a lavadora
    else if(opcion == -2){
      int pes;
      bool col;
      cin >> pes;
      col = readbool();
      Prenda p (pes, col);
      lav.anadir_prenda(p);
    }
    
    // Añadir a cubeta
    else if(opcion == -3){
      int pes;
      bool col;
      cin >> pes;
      col = readbool();
      Prenda p (pes, col);
      cub.anadir_prenda(p);
    }
    
    // Completar lavadora
    else if(opcion == -4){
      cub.completar_lavadora(lav);
    }
    
    // Lavar
    else if(opcion == -5){
      lav.lavado();
    }
    
    // Escribir cubeta
    else if(opcion == -6){
      cub.escribir();
    }
    
    // Escribir lavadora
    else if(opcion == -7){
      lav.escribir();
    }
    
    // Fin
    else {
      return 0;
    }
  }
}





















