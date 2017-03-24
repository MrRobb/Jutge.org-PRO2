//
//  program.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernรกndez on 21/3/17.
//

#include <iostream>
#include <list>

using namespace std;

void eraseElementLlista(list<pair<int, int> > &l, int n){
  bool erased = false;
  list<pair<int, int> >::iterator it = l.begin();
  while(it != l.end() and !erased){
    if((*it).second == n) {
      it = l.erase(it);
      erased = true;
    }
    else {
      ++it;
    }
  }
}

void printlist(list<pair<int, int> > &l){
  int min = 0;
  int max = 0;
  int sum_avg = 0;
  
  for (list<pair<int, int> >::iterator it = l.begin(); it != l.end(); ++it) {
    if(it == l.begin() or (*it).second < min){
      min = (*it).second;
    }
    if(it == l.begin() or (*it).second > max){
      max = (*it).second;
    }
    sum_avg += (*it).second;
  }
  
  if(l.empty()) cout << '0' << endl;
  else cout << min << ' ' << max << ' ' << double(sum_avg)/double(l.size()) << endl;
}

int main(){
  pair<int, int> code;
  list<pair<int, int> > l;
  while (cin >> code.first and cin >> code.second and code.first != 0) {
    if(code.first == -1){
      l.insert(l.end(), code);
    } else {
      eraseElementLlista(l, code.second);
    }
    printlist(l);
  }
  
}
