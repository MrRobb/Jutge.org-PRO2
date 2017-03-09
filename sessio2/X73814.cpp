//
//  simplify_students.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 9/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Estudiant.hh"

int main(){
  // Crear vector
  int nEst;
  std::cin >> nEst;
  vector<Estudiant> v(nEst);
  
  // Leer estudiantes
  for(int i = 0; i < nEst; ++i){
    v[i].llegir();
  }
  
  // Crear vector de salida
  vector<Estudiant> vfinal(nEst);
  
  // Comprobar repeticiones de dni y modificar sus notas
  int u = 0;
  for(int i = 0; i < nEst; ++i){
    
    // Si el estudiante es igual al anterior (exceptuando el primer estudiante)
    if(i != 0 and v[i].consultar_DNI() == v[i-1].consultar_DNI()){
      
      // Si ambos tienen nota, modificar el final
      if(v[i].te_nota() and vfinal[u-1].te_nota() and v[i].consultar_nota() > vfinal[u-1].consultar_nota()){
        vfinal[u-1].modificar_nota(v[i].consultar_nota());
        
        // Si sólo el primero tiene nota nota, añadírsela al segundo
      } else if(v[i].te_nota() and !vfinal[u-1].te_nota()) {
        vfinal[u-1].afegir_nota(v[i].consultar_nota());
      }
      
      // Si el estudiante no es igual al anterior, añadir al estudiante con su nota (si es que tiene)
    } else {
      vfinal[u] = Estudiant(v[i].consultar_DNI());
      if(v[i].te_nota()) vfinal[u].afegir_nota(v[i].consultar_nota());
      ++u;
    }
  }
  
  // Escribir estudiantes
  int i = 0;
  bool finish = false;
  // Escribir estudiantes hasta que se acabe el vector o hasta que se acaben los estudiantes
  while(i < nEst and !finish){
    if(vfinal[i].consultar_DNI() != 0) vfinal[i].escriure();
    else finish = true;
    ++i;
  }
}
