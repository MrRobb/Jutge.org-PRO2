//
//  gest_conj_improved.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 9/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

using namespace std;

void round_estudiants(Cjt_estudiants &v){
  int size = (int) v.mida();
  for(int i = 1; i <= size; ++i){
    if(v.consultar_iessim(i).te_nota()){
      double nota = v.consultar_iessim(i).consultar_nota();
      nota *= 10;
      if(nota >= int(nota)+0.5){
        Estudiant est = Estudiant(v.consultar_iessim(i).consultar_DNI());
        est.afegir_nota(double(int(nota)+1)/10);
        v.modificar_iessim(i, est);
      } else {
        Estudiant est = Estudiant(v.consultar_iessim(i).consultar_DNI());
        est.afegir_nota(double(int(nota))/10);
        v.modificar_iessim(i, est);
      }
    }
  }
}

int main(){
  // Read vector
  Cjt_estudiants(v);
  v.llegir();
  
  // Loop actions
  int action;
  while(cin >> action and action != -6){
    
    // Add
    if(action == -1){
      Estudiant(est);
      est.llegir();
      bool b;
      v.afegir_estudiant(est, b);
      if(!b) cout << "el estudiante " << est.consultar_DNI() << " ya estaba  " << endl;
    }
    
    // Consult mark by ID
    else if(action == -2){
      int dni;
      cin >> dni;
      bool b;
      Estudiant est(dni);
      v.consultar_estudiant(est,b);
      if(b){
        if(est.te_nota()){
          cout << "el estudiante " << dni << " tiene nota " << est.consultar_nota() << endl;
        }
        else {
          cout << "el estudiante " << dni << " no tiene nota " << endl;
        }
      }
      else cout << "el estudiante " << dni << " no está" << endl;
        
      
    }
    
    // Modify mark
    else if(action == -3){
      Estudiant(est);
      est.llegir();
      bool b;
      v.modificar_estudiant(est,b);
      if(!b) cout << "el estudiante 555 no está" << endl;
    }
    
    // Round mark all students
    else if(action == -4){
      round_estudiants(v);
    }
    
    // Write
    else if(action == -5){
      v.escriure();
    }
    
    // Exit
    else if(action == -6){
      
    }
  }
  
}
