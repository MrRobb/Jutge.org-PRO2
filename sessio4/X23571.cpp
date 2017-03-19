//
//  X23571.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 19/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include "Cjt_estudiants.hh"


int Cjt_estudiants::posicio_nota(double nota_b) const {
  Estudiant est(0);
  est.afegir_nota(nota_b);
  int i = cerca_dicot_per_nota_dni(vest, 0, nest-1, est);
  return i;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &trobat)
{
  int dni = est.consultar_DNI();
  int idni = cerca_lineal_per_dni(vest, 0, nest-1, dni);
  int i = cerca_dicot_per_nota_dni(vest, 0, nest-1, est);
  if(idni >= nest and dni > 0 and nest != MAX_NEST){
    trobat = false;
    
    for(int j = nest-1; j >= i; --j) vest[j+1] = vest[j];
    
    vest[i] = est;
    ++nest;
    if(!est.te_nota()) ++primer_est_amb_nota;
    
  } else {
    trobat = true;
  }
}

void Cjt_estudiants::escriure_i(double nota_i, double nota_s) const
{
  int i = posicio_nota(nota_i);
  int s = posicio_nota(nota_s);
  
  for(int j = i; j < s; j++){
    vest[j].escriure();
  }
  
  while(s < nest and vest[s].consultar_nota() == nota_s) vest[s++].escriure();
}

