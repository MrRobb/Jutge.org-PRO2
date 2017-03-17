//
//  X36902.cpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández on 17/3/17.
//  Copyright © 2017 Roberto Ariosa Hernández. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int main(){
  char c;
  stack<char> s;
  while(cin >> c and c != '.'){
    if(c == '(' or c == '['){
      s.push(c);
    } else if(!s.empty() and ((c == ')' and s.top() == '(') or (c == ']' and s.top() == '['))){
      s.pop();
    } else if(s.empty() and (c == ')' or c == ']')){
      s.push('.');
      c = '.';
    } else {
      c = '.';
    }
  }
  if(s.empty()) cout << "Correcte" << endl;
  else cout << "Incorrecte" << endl;
}
