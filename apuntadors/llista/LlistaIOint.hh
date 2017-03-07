#ifndef LLISTA_IO_INT
#define LLISTA_IO_INT

#include  "Llista.hh"

void llegir_llista_int(Llista<int>& l, int marca)
{
  int n;
  cin >> n;
  while (n != marca){
    l.afegir(n);
    cin >> n;
  }
}


void escriure_llista_int(Llista<int> l)
{
  cout << "[Primer] " << endl;
  l.inici();
  while (not l.dreta_de_tot()){
    cout << l.actual() << endl;
    l.avanca();
  }
  cout << "[Ultim]"<<endl;
}

void escriure_llista_int_rev(Llista<int> l)
{
  cout << "[Ultim] " << endl;
  if (not l.es_buida()){
    l.fi();  l.retrocedeix();
    while (not l.sobre_el_primer()){
      cout << l.actual() << endl;
      l.retrocedeix();
    }
    cout << l.actual() << endl;
  }
  cout << "[Primer]"<<endl;
}

#endif
