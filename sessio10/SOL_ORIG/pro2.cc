/** @mainpage

    Ejemplo de práctica resuelta, con documentación <b> completa</b>
    (incluyendo elementos privados y código).

    El programa principal se encuentra en el módulo pro2.cc.
    Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un
    módulo para representar el Sistema en el que se desarrollarán los
    experimentos, otro para el tipo Organismo y otro para el tipo 
    Celula.

    Comentarios:

    - En una resolución normal, comenzaríamos por considerar las operaciones
    necesarias para el programa principal y las clasificaríamos en los
    diferentes módulos. Al pasar a su implementación, quizá descubriésemos que
    algún módulo necesita alguna operación adicional y la incorporaríamos en
    ese momento (sólo si es pública, es decir, si se usa en un módulo distinto
    al que pertenece). Sin embargo, en un documento de estas características,
    se presentan los módulos completamente acabados, sin necesidad de reflejar
    el proceso que ha dado lugar a su especificación final.

    - En cuanto a los diagramas modulares que aparecen en este proyecto, notad
    que la relación de uso entre Organismo y Celula no se obtiene a partir de
    la especificación de los elementos públicos del primero, sino de la de sus
    elementos privados.

*/

/** @file pro2.cc

    @brief Programa principal

    Estamos suponiendo que los datos leídos siempre son correctos, ya que
    no incluímos comprobaciones al respecto. Por último, puesto que los datos de
    los organismos y células son naturales (identificadores, ...) usaremos números
    negativos para las opciones.
*/

#include "Sistema.hh"
#include "Organismo.hh" // redundante, pero necesario para el diagrama
#ifndef NO_DIAGRAM
#include "readbool.hh"
#endif
int main() 
{
  int N; //  Número de parámetros de las células
  cin >> N; 
  Sistema S;
  S.leer(N);
  int op; // Código de operación
  cin >> op;
  while (op != -3) {
    if (op == -1 ) {
      Organismo O;
      O.leer(N);
      bool sobrevive;
      S.anadir_organismo(O, sobrevive);
      cout << "Entrada del nuevo organismo" << endl;
      cout << O.num_victimas() << " " << sobrevive << endl;  
    } 
    else if (op == -2) {
      bool tipo = readbool();     
      bool estr = readbool();
      if (tipo){
	if (estr) cout << "Defensivos del sistema con estructura" << endl;	
	else cout << "Defensivos del sistema sin estructura" << endl;
      }
      else {
	if (estr) cout << "Malignos del sistema con estructura" << endl;
	else cout << "Malignos del sistema sin estructura" << endl;
      }
      S.escribir(tipo, estr);
    }
    cin >> op;
  }
}

