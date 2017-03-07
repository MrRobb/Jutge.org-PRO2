//
//  max_min.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 7/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void max_min(const vector<int>& v, int& max, int& min){
  // Post: stores in the max and min values
  max = v[0];
  min = v[0];
  int size = (int) v.size();
  for(int i = 0; i < size; ++i){
    if(v[i] > max) max = v[i];
    else if(v[i] < min) min = v[i];
  }
}

vector<int> readvector(){
  // Pre: Read a size n and then n integer values
  // Post: Returns the vector with size n and n integer values
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }
  return v;
}

int main() {
  // Read the vector
  vector<int> v = readvector();
  
  // Set the max and the min values
  int max,min;
  max_min(v,max,min);
  
  // Print
  cout << "max: " << max << ' ' << ", min: " << min << endl;
}
