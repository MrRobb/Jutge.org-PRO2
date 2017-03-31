//
//  X83904.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 31/3/17.
//

#include <iostream>
#include <set>
#include <map>

using namespace std;

void readmap(map<string, int> &m){
  string s;
  while (cin >> s and s != ".") {
    m[s];
  }
}

void readset(set<string> &set7){
  string s;
  while (cin >> s and s != ".") {
    set7.insert(s);
  }
}

void updatemap(map<string, int> &m, set<string> &set7){
  for(set<string>::iterator it = set7.begin(); it != set7.end(); ++it){
    map<string, int>::iterator itmap = m.find((*it));
    (*itmap).second++;
  }
}

void printmap(map<string, int> &m, int n){
  cout << "Totes les activitats:";
  for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
    if((*it).second == n) cout << ' ' << (*it).first;
  }
  cout << endl;
  
  cout << "Cap activitat:";
  for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
    if((*it).second == 0) cout << ' ' << (*it).first;
  }
  cout << endl;
}

int main(){
  map<string, int> m;
  readmap(m);
  
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    set<string> set7;
    readset(set7);
    updatemap(m,set7);
  }
  
  printmap(m,n);
}
