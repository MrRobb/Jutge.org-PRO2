//
//  X39577.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 9/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include "iostream"
#include "vector"
#include "Estudiant.hh"

typedef std::vector<std::vector<Estudiant> > MatrixEstudiantes;

int main (){
  
  // Leer
  int Mestudiantes;
  int Nasignaturas;
  int SasigSeleccionadas;
  std::cin >> Mestudiantes >> Nasignaturas >> SasigSeleccionadas;
  
  // Crear vector de asignaturas seleccionadas
  std::vector<bool> vAsigSeleccionadas(Nasignaturas, false);
  for(int i = 0; i < SasigSeleccionadas; ++i){
    int x;
    cin >> x;
    vAsigSeleccionadas[x-1] = true;
  }
  
  // Crear matriz de datos de estudiantes y vector de medias
  MatrixEstudiantes m (Mestudiantes, std::vector<Estudiant> (Nasignaturas));
  std::vector<Estudiant> vMedias(Mestudiantes);
  
  // Rellenar matriz de estudiantes y vector de medias
  for(int i = 0; i < Mestudiantes; ++i){
    int dni;
    cin >> dni;
    double notaMedia = 0;
    
    for(int j = 0; j < Nasignaturas; ++j){
      // AĂąadir nota a la matriz de notas
      double nota;
      cin >> nota;
      m[i][j] = Estudiant(dni);
      m[i][j].Estudiant::afegir_nota(nota);
      
      // Sumar nota a la nota media
      if(vAsigSeleccionadas[j]){
        notaMedia += nota;
      }
    }
    
    // Dividir nota media entre las asignaturas y guardar en el vector
    notaMedia /= SasigSeleccionadas;
    vMedias[i] = Estudiant(dni);
    vMedias[i].Estudiant::afegir_nota(notaMedia);
  }
  
  // Imprimir
  for(int i = 0; i < Mestudiantes; ++i){
    vMedias[i].Estudiant::escriure();
  }
}
