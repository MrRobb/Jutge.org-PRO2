//
//  max_min.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 7/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Estudiant.hh"
#include "vectorIOEstudiant.hh"

using namespace std;

void max_min_nota(const vector<Estudiant>& v, double& max, double& min){
  // Post: stores in the max and min marks
  max = -1;
  min = 11;
  int size = (int) v.size();
  for(int i = 0; i < size; ++i){
    if(v[i].te_nota() and v[i].consultar_nota() > max) max = v[i].consultar_nota();
    if(v[i].te_nota() and v[i].consultar_nota() < min) min = v[i].consultar_nota();
  }
}

void max_min_estudiant_amb_nota(const vector<Estudiant>& v, int& max, int& min){
  // Pre: At least one of the student have a valid mark
  // Post: stores in max and min the position in the vector of the student with a maximum and minimum marks
  max = v[0].consultar_DNI();
  min = v[0].consultar_DNI();
  int size = (int)v.size();
  
  for(int i = 0; i < size; ++i){
    // Si su nota es mayor que max
    if(v[max].te_nota() and v[i].te_nota() and v[i].consultar_nota() >= v[max].consultar_nota()){
      if(v[i].consultar_nota() > v[max].consultar_nota()) max = i;
      else if(v[i].consultar_DNI() < v[max].consultar_DNI()) max = i;
    }
    // Si su nota es menor que min
    if(v[min].te_nota() and v[i].te_nota() and v[i].consultar_nota() <= v[min].consultar_nota()){
      if(v[i].consultar_nota() < v[min].consultar_nota()) min = i;
      else if(v[i].consultar_DNI() < v[min].consultar_DNI()) min = i;
    }
    // Si max o min no tienen nota
    else if((!v[max].te_nota() or !v[min].te_nota())and v[i].te_nota()){
      if(!v[max].te_nota()) max = i;
      if(!v[min].te_nota()) min = i;
    }
  }
}

void max_min_estudiant(const vector<Estudiant>& v, int& max, int& min){
  // Pre: true
  // Post: stores in max and min the position in the vector of the student with a maximum and minimum marks, if any of them does not exist it stores a -1
  max = -1;
  min = -1;
  int size = (int) v.size();
  for(int i = 0; i < size; ++i){
    // Si no tienen nota aún
    if(max == -1 or min == -1){
      if(max == -1 and v[i].te_nota()) max = i;
      if(min == -1 and v[i].te_nota()) min = i;
    }
    else {
      if(v[i].te_nota() and v[i].consultar_nota() >= v[max].consultar_nota()){
        if(v[i].consultar_nota() > v[max].consultar_nota()) max = i;
        else if(v[i].consultar_DNI() < v[max].consultar_DNI()) max = i;
      }
      // Si su nota es menor que min
      if(v[i].te_nota() and v[i].consultar_nota() <= v[min].consultar_nota()){
        if(v[i].consultar_nota() < v[min].consultar_nota()) min = i;
        else if(v[i].consultar_DNI() < v[min].consultar_DNI()) min = i;
      }
    }
  }
}

int main() {
  // Read the vector
  vector<Estudiant> v;
  leer_vector_estudiant(v);

  // Comment the versions that you don't need
  
  // VERSION 1
  
  // Set the max and the min values (version 1)
  double max1,min1;
  max_min_nota(v,max1,min1);
  
  // Print (version 1)
  cout << "nota max: " << max1 << " nota min: " << min1 << endl;
  
  
  // VERSION 2
  
  // Set the max and the min values (version 2)
  int max2,min2;
  max_min_estudiant_amb_nota(v,max2,min2);
  
  // Print (version 2)
  cout << "estudiante con nota max: ";
  v[max2].escriure();
  cout << "estudiante con nota min: ";
  v[min2].escriure();
  
  
  // VERSION 3
  
  // Set the max and the min values (version 3)
  int max3,min3;
  max_min_estudiant(v,max3,min3);
  
  // Print (version 3)
  if(max3 == -1 or max3 == -1){
    cout << "no hay ningun estudiante con nota" << endl;
  } else {
    cout << "estudiante con nota max: ";
    v[max3].escriure();
    cout << "estudiante con nota min: ";
    v[min3].escriure();
    cout << endl;
  }
}
