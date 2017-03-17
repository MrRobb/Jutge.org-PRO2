#include "PilaIOParEstudiant.hh"

int pertstack_rec(stack<Estudiant>& p, Estudiant x, bool &b);

int main() 
{
  stack<Estudiant> p;
  llegirPilaEstudiant(p);
  Estudiant est; est.llegir();
  bool b = false;
  int nota = pertstack_rec(p, est, b);
  
  if(b){
    if(nota != -1){
      cout << "El estudiante está en la pila y su nota es" << nota << endl;
    } else {
      cout << "El estudiante está en la pila, pero no tiene nota" << endl;
    }
  } else {
    cout << "El estudiante no está en la pila" << endl;
  }
}

/*
  Notemos que en la version recursiva la pila se pasa por referencia,
  y puede resultar modificada aunque se trate de una funcion. Si
  deseamos conservar la pila original, hay que pasar una copia o
  reempilar la cima a la vuelta de la recursividad. No pasamos la pila
  por valor para evitar el coste de las copias; tampoco por referencia
  constante porque es incompatible con "pop"
*/
int pertstack_rec(stack<Estudiant> &p, Estudiant est, bool &b)
/* Pre: p = P */
/* Post: El resultat diu si x es un element de P */
{
  int nota_ret;
  if(p.empty()) b = false;
  else 
    if (p.top().consultar_DNI() == est.consultar_DNI()){
      if(p.top().te_nota()){
        nota_ret = p.top().consultar_nota();
      } else {
        nota_ret = -1;
      }
     
      b = true;
    }
    else {   
      p.pop();
      nota_ret = pertstack_rec(p,est,b);
    }
  return nota_ret;
}
