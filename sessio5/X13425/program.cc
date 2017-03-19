#include "CuaIOParInt.hh"

using namespace std;

int main() 
{
  ParInt p;
  queue<ParInt> q1;
  queue<ParInt> q2;
  int cua1 = 0;
  int cua2 = 0;
  
  while (p.llegir()) {
    if(cua1 <= cua2){
      q1.push(p);
      cua1 += p.segon();
    } else {
      q2.push(p);
      cua2 += p.segon();
    }
  }
  
  escriureCuaParInt(q1);
  cout << endl;
  escriureCuaParInt(q2);
}
