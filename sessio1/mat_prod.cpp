//
//  mat_prod.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 7/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matriz;

Matriz producto(const Matriz& m1, const Matriz& m2)
/* Pre: el n ́umero de columnas de m1 es igual al n ́umero de filas de m2 */ /* Post: el resultado es el producto de m1 y m2 */
{
  Matriz prod (m1.size(), vector<int> (m2[0].size()));
  
  for(int i = 0; i < m1.size(); ++i){
    for(int j = 0; j < m2[0].size(); ++j){
      for(int k = 0; k < m1[0].size(); ++k){
        prod[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  
  return prod;
}

int main(){
  
}
