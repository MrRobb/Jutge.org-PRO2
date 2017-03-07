#include <iostream>
using namespace std;

int main()
{
  cout << "Entra una secuencia de nombres enteros: " << endl;
  
  int sum = 0;
  
  int x;
  while (cin >> x and x != 0) {
    sum += x;
  }
  
  cout << "La suma de la secuencia es " << sum <<endl;
}

