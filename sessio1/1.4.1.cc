#include <iostream>

using namespace std;

void intercambio (int& x, int& y){
  x = x+y;
  y = x-y;
  x = x-y;
}

void intercambio2 (int& x, int& y){
  int aux = x;
  x = y;
  y = aux;
}

int main(){
  int x,y;
  cout << "Entra dos enters, el primer per x i el segon per y" << endl;
  cin >> x >> y;
  intercambio(x,y);
  cout << "Los valores intercambiados de x e y son: x = " << x << " e y = " << y << endl;
}
