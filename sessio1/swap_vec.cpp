//
//  swap_vec.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 7/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include "iostream"
#include "vectorIOint.hh"

void swap_vec(vector<int> &v, int x, int y){
  int aux = v[x];
  v[x] = v[y];
  v[y] = aux;
}

int main(){
  
  // Leer vector
  vector<int> v;
  leer_vector_int(v);
  
  // Leer posiciones
  std::cout << "Inserta las posiciones a intercambiar [0...n-1]:" << endl;
  int x,y;
  std::cin >> x; std::cin >> y;
  
  // Intercambiar posiciones
  swap_vec(v,x,y);
  
  // Escribir vector
  escribir_vector_int(v);
  
}
