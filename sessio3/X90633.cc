//
//  X90633.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 10/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include "Cjt_estudiants.hh"
#include <algorithm>

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b){
  int dni = est.consultar_DNI();
  int pos = cerca_dicot(vest, 0, nest-1, dni);
  
  if((dni > 0 and pos >= 0 and pos < nest and vest[pos].consultar_DNI() != dni) or (dni > 0 and pos == nest)){
    b = false;
    
    for(int i = nest-1; i >= pos; --i){
      vest[i+1] = vest[i];
    }
    
    vest[pos] = est;
    ++nest;
    
    if(vest[pos].te_nota()){
      suma_notes += vest[pos].consultar_nota();
      ++nest_amb_nota;
    }
    
    
  } else {
    b = true;
  }
}

bool comp (const Estudiant &a, const Estudiant &b){
  return a.consultar_DNI() < b.consultar_DNI();
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b){
  int pos = cerca_dicot(vest, 0, nest-1, dni);
  if(pos >= 0 and pos < nest and vest[pos].consultar_DNI() == dni){
    b = true;
    
    if(vest[pos].te_nota()){
      suma_notes -= vest[pos].consultar_nota();
      --nest_amb_nota;
    }
    
    vest[pos] = vest[nest-1];
    --nest;
    
    sort(vest.begin(), vest.begin()+nest, comp);
    
  } else {
    b = false;
  }
}
