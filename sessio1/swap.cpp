//
//  swap.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 7/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include "iostream"

using namespace std;

void swapvalues(int& x, int& y){
  int aux = x;
  x = y;
  y = aux;
}

int main(){
  int x,y;
  
  cout << "Entra una x:" << endl;
  cin >> x;
  
  cout << "Entra una y:" << endl;
  cin >> y;
  
  swapvalues(x,y);
  
  cout << "x: " << x << " , y: " << y << endl;
}
