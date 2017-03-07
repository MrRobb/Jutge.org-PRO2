#ifndef ARBRENARI_HH
#define ARBRENARI_HH

#include "PRO2Excepcio.hh"
#include <iostream>
#include <vector>

template <class T> class ArbreNari { 

  // el cost temporal de totes les operacions publiques es constant, tret
  // de la creadora copiadora, la destructora, la buidadora i l'assignacio,
  // per les quals es lineal respecte a la mida de l'arbre (cada element
  // aporta el cost de crear, esborrar o copiar la seva info) i plantar, 
  // fills i ArbreNari(x, n) que son lineals respecte a l'aritat de l'arbre

private:     
  struct node_arbreNari {
    T info;
    vector<node_arbreNari*> seg;
  };
  int N;
  node_arbreNari* primer_node;
  // especificaci� operacions privades
 
  static node_arbreNari* copia_node_arbreNari(node_arbreNari* m) { 
    /* Pre: cert */
    /* Post: el resultat �s NULL si m �s NULL; en cas contrari, el resultat 
       apunta al node arrel d'una jerarquia de nodes que �s una c�pia de la
       jerarquia de nodes que t� el node apuntat per m com a arrel */
    /* Cost temporal: proporcional al nombre de nodes que penjen d'm; cada
       node copiat aporta el cost de copiar la seva info */

    node_arbreNari* n;
    if (m==NULL) n = NULL;
    else {
      n = new node_arbreNari;
      n->info = m->info;
      int ari = m->seg.size();
      n->seg = vector<node_arbreNari*>(ari);
      for (int i=0; i<ari; ++i) 
	n->seg[i] = copia_node_arbreNari(m->seg[i]);
    }
    return n;
  }

  static void esborra_node_arbreNari(node_arbreNari* m) {  
    /* Pre: cert */
    /* Post no fa res si m �s NULL; en cas contrari, allibera espai de tots els nodes
       de la jerarquia que t� el node apuntat per m com a arrel */
    /* Cost temporal: proporcional al nombre de nodes que penjen d'm */
    if (m != NULL) {
      int ari = m->seg.size();
      for (int i=0; i<ari; ++i) 
	esborra_node_arbreNari(m->seg[i]);
      delete m;
    }
  }

public:
  // especificaci� operacions p�bliques

  ArbreNari(int n) {
    /* Pre: n>0 */
    /* Post: el p.i. �s un arbre buit d'aritat n */
    if (n>0) {
      N = n;
      primer_node= NULL;
    }
    else throw PRO2Excepcio("La n de la creadora buida ha de ser >0");
  }

  ArbreNari(const T& x, int n) {
    /* Pre: n>0 */
    /* Post: el p.i. �s un arbre amb arrel x i n fills buits */
    if (n>0) {
      N = n;
      primer_node= new node_arbreNari;
      primer_node->info = x;
      primer_node->seg = vector<node_arbreNari*>(N,NULL);
    }
    else throw PRO2Excepcio("La n de la creadora amb un element ha de ser >0");
  }

  ArbreNari(const ArbreNari& original) {
    /* Pre: n>0 */
    /* Post: el p.i. �s una c�pia d'original */
    N = original.N;
    primer_node = copia_node_arbreNari(original.primer_node);
  }

  ~ArbreNari() 
  // Destructora: Esborra autom�ticament els objectes locals en
  // sortir d'un �mbit de visibilitat
  {
    esborra_node_arbreNari(primer_node);
  }

  ArbreNari& operator=(const ArbreNari& original) 
  /* Pre: cert */
  /* Post: El p.i. passa a ser una c�pia d'original i qualsevol
     contingut anterior del p.i. ha estat esborrat 
     (excepte si el p.i. i original ja eren el mateix objecte) */
  {
    if (this != &original) {
      esborra_node_arbreNari(primer_node);
      N = original.N;
      primer_node = copia_node_arbreNari(original.primer_node);
    }
    return *this;
  }

  void a_buit() {
    /* Pre: cert */
    /* Post: el p.i. �s un arbre buit */
    esborra_node_arbreNari(primer_node);
    primer_node= NULL;
  }        

  void plantar(const T &x, vector<ArbreNari>& v) {
    /* Pre:  el p.i. �s buit; v.size() �s igual a l'aritat del p.i.,
       tots els components de v tenen la mateixa aritat que el p.i.
       i cap d'ells �s el mateix objecte que el p.i. */
    /* Post: el p.i. t� x com a arrel i els N elements originals
       de v com a fills, v passa a contenir arbres buits */
    if (primer_node==NULL){
      if (v.size()==N){ 
	bool error_ari, error_ig;
	error_ari = error_ig = false;
	int i = 0;
	while (i<v.size() and not error_ari and not error_ig) { 
	  error_ari = v[i].N != N;
	  error_ig =  this == &v[i];
	  if (not error_ari and not error_ig) ++i;
	}
	if (error_ari) throw PRO2Excepcio("Un dels arbres que vols plantar no te la mateixa aritat que el p.i.");
	if (error_ig) throw PRO2Excepcio("Un dels arbres que vols plantar es el mateix objecte que el p.i."); 
	node_arbreNari* aux= new node_arbreNari;
	aux->info= x;
	aux->seg = vector<node_arbreNari*>(N);
	for (int i=0; i<N; ++i) {
	  aux->seg[i] = v[i].primer_node;
	  v[i].primer_node = NULL;
	}
	primer_node= aux;
      }
      else throw PRO2Excepcio("Al plantar, el size del vector ha de ser igual a l'aritat de l'arbre");
    }
    else throw PRO2Excepcio("El p.i. de plantar ha de ser buit a la crida");
  }
  
  
  void fills(vector<ArbreNari>& v) {
    /* Pre:  el p.i. no �s buit i li diem A, v �s un vector buit */
    /* Post: el p.i. �s buit, v passa a contenir els N fills de l'arbre A  */
    if (primer_node!=NULL){
      if (v.size()==0){ 
	node_arbreNari* aux= primer_node;
	v = vector<ArbreNari>(N,ArbreNari(N));
	for (int i=0; i<N; ++i) 
	  v[i].primer_node = aux->seg[i];  
	primer_node= NULL;
	delete aux;
      }
      else throw PRO2Excepcio("No es pot passar a fills un vector no buit");
    }
    else throw PRO2Excepcio("El p.i. de fills no pot ser buit a la crida");
  }

  T arrel() const {
    /* Pre: el p.i. no �s buit */
    /* Post: el resultat �s l'arrel del p.i. */
    if (primer_node!=NULL)   return primer_node->info;
    else throw PRO2Excepcio("El p.i. d'arrel no pot ser buit a la crida");
  }

  bool es_buit() const {
    /* Pre: cert */
    /* Post: el resultat indica si el p.i. �s un arbre buit */
    return (primer_node==NULL);
  }

  int aritat() const {
    /* Pre: cert */
    /* Post: el resultat �s l'aritat del p.i. */
    return N;
  }
    
  // Extensions. Posar o treure comentari per fer-les servir

#include "inc.hh"
  //#include "arb_sum.hh"
  //#include "..."
};

#endif
