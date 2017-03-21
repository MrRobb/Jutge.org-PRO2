//
//  program.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 20/3/17.
//

#include <iostream>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"

using namespace std;

pair<int, int> BuscarIntEnLlistaParInt(list<ParInt> l, int n){
  pair<int, int> count_sum;
  count_sum.first = 0;
  count_sum.second = 0;
  
  for(list<ParInt>::iterator it = l.begin(); it != l.end(); ++it){
    ParInt p = *it;
    if(p.primer() == n){
      count_sum.first++;
      count_sum.second += p.segon();
    }
  }
  
  return count_sum;
}

int main(){
  list<ParInt> l;
  LlegirLlistaParInt(l);
  int n; cin >> n;
  pair<int, int> p = BuscarIntEnLlistaParInt(l, n);
  cout << n << ' ' << p.first << ' ' << p.second << endl;
}
