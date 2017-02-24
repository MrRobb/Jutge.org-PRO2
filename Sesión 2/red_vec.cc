#include "Estudiant.hh"
#include "vectorIOEstudiant.hh"
#include <vector>

// Redondear, version funcion

Estudiant redondear_e_f(const Estudiant& est)
/* Pre: est tiene nota */
/* Post: el resultado es un estudiante como est pero con la nota redondeada */
{
  Estudiant est2(est.consultar_DNI());
  double notaR = ((int) (10.0 * (est.consultar_nota() + 0.05))) / 10.0;
  est2.afegir_nota(notaR);
  return est2;
}

// Redondear, version accion

void redondear_e_a(Estudiant& est)
/* Pre: est tiene nota */
/* Post: est pasa a tener su nota original redondeada */
{
  est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}

void redondear_ve_a(vector<Estudiant>& Vest){
  for(int i = 0; i < Vest.size(); ++i){
    if(Vest[i].te_nota()){
      redondear_e_a(Vest[i]);
    }
  }
}

int main()
{
  std::vector<Estudiant> Vest;
  
  // Llegir vector
  leer_vector_estudiants(Vest);
  redondear_ve_a(Vest);
  cout << "Estudiantes con las notas redondeadas <dni nota>:" << endl;
  escribir_vector_estudiants(Vest);
  
}
