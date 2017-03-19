#include <iostream>
#include "ParInt.hh"
using namespace std;

ParInt::ParInt(){
  p=0;s=0;
}

ParInt::ParInt(int a,int b){
  p=a;s=b;
}

int ParInt::primer() const{
  return p;
}

int ParInt::segon() const{
  return s;
}

bool ParInt::operator==(const ParInt& par) const{
  return p==par.p and s==par.s;
}

bool ParInt::operator!=(const ParInt& par) const{
  return p!=par.p or s!=par.s;
}

bool ParInt::llegir(){
  cin >> p >> s;
  return (p!=0 or s!=0); 
}

void ParInt::escriure(){
  cout << p << ' ' << s << endl;
}
