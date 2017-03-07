#include "Cjt_estudiants.hh"

double presentats (const Cjt_estudiants  &c)
/* Pre: c conté almenys un element */
/* Post: el resultat és el percentatge de presentats de c */
{
 int numEst = c.mida();
 int n = 0;
 for (int i=1; i<=numEst; ++i) if(c.consultar_iessim(i).te_nota()) ++n;
 /* n és el nombre d'estudiants de c amb nota */
 double p = n*100./numEst;
 return p;
}

int main()
{
  Cjt_estudiants c; 
  cout << "Introdueix la mida del conjunt, seguida dels estudiants" << endl;
  c.llegir();  
  double x =presentats(c);
  cout << "Presentats del conjunt: " << x << "%" << endl;
}

