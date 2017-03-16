//
//  X84760.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 16/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include "Cjt_estudiants.hh"
#include <algorithm>

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
  int dni = est.consultar_DNI();
  int i = cerca_dicot(vest, 0, nest-1, dni);
  
  if(i > -1 and dni > 0 and (i == nest or dni != vest[i].consultar_DNI())){
    b = false;
    
    for(int j = nest-1; j >= i; --j) vest[j+1] = vest[j];
    
    ++nest;
    vest[i] = est;
    recalcular_posicio_imax();
    
  } else {
    b = true;
  }
}

void Cjt_estudiants::eliminar_estudiants_sense_nota()
{
  vector<Estudiant> aux(nest);
  int howmany = 0;
  for (int i = 0; i < nest; ++i) {
    if (vest[i].te_nota()) {
      aux[howmany] = vest[i];
      ++howmany;
    }
  }
  nest = howmany;
  for (int i = 0; i < nest; ++i) {
    vest[i] = aux[i];
  }
  recalcular_posicio_imax();
}
