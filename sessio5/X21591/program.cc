//
//  program.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 17/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include <iostream>
#include "CuaIOEstudiant.hh"

int nota_dni(queue<Estudiant> q, int dni, bool &b){
  while(!q.empty()){
    if(q.front().consultar_DNI() == dni){
      b = true;
      if(q.front().te_nota()){
        return q.front().consultar_nota();
      } else {
        return -1;
      }
    } else {
      q.pop();
    }
  }
  b = false;
  return -1;
}

using namespace std;

int main(){
  queue<Estudiant> q;
  LlegirCuaEstudiant(q);
  
  int dni; cin >> dni;
  bool b = false;
  
  int nota = nota_dni(q, dni, b);
  
  EscriureCuaEstudiant(q);
  
  if(b){
    if(nota != -1){
      cout << "La nota es " << nota << endl;
    } else {
      cout << "No te nota" << endl;
    }
  } else {
    cout << "No trobat" << endl;
  }
}
