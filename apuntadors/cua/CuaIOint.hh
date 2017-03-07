#ifndef CUA_IO_INT
#define CUA_IO_INT

#include "Cua.hh"

void llegir_cua_int(Cua<int>& c, int marca)
{
  int n;
  cin >> n;
  while (n != marca){
    c.demanar_torn(n);
    cin >> n;
  }
}

void escriure_cua_int(Cua<int> c)
{
  cout << "[Primer] "<< endl;
  // el paso por valor, copia p correctamente ya que la clase tiene
  // creadora copiadora; podemos desencolar sin que se destruya la original
  while(!c.es_buida()){
    cout << c.primer() << endl;
    c.avancar();
  }
  cout << "[Ultim]"<<endl;
}

#endif
