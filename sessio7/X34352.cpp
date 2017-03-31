//
//  program.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 31/3/17.
//

#include <iostream>
#include <map>

using namespace std;

int main(){
  pair<char, string> p;
  map<string, int> m;
  while (cin >> p.first and cin >> p.second) {
    if(p.first == 'a'){
      m[p.second]++;
    } else {
      cout << m[p.second] << endl;
    }
  }
}
