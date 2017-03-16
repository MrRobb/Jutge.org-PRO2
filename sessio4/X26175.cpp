//
//  X26175.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 10/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
  int dni = est.consultar_DNI();
  int pos = cerca_dicot(vest, 0, nest-1, dni);
  if(vest[pos].consultar_DNI() != dni){
    b = false;

    for(int i = nest-1; i >= pos; --i){
      vest[i+1] = vest[i];
    }

    ++nest;
    vest[pos] = est;

    if(est.te_nota()){
      int nota = est.consultar_nota();
      if(nota == 10){
        ++intervals[9];
      } else {
        ++intervals[nota];
      }
    }


  } else {
    b = true;
  }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
  int i = cerca_dicot(vest, 0, nest-1, dni);
  if(vest[i].consultar_DNI() == dni){
    b = true;

    // Arreglar intervals
    if(vest[i].te_nota()){
      int nota = vest[i].consultar_nota();

      if(nota == 10){
        --intervals[9];
      } else {
        --intervals[nota];
      }
    }

    // Borrar estudiante
    for(int j = i; j < nest-1; ++j) vest[j] = vest[j+1];
    --nest;

  } else {
    b = false;
  }
}
