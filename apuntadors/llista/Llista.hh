#ifndef LLISTA
#define LLISTA

#include "PRO2Excepcio.hh"
#include <iostream> // en principi, hauria de ser-hi nomes al LlistaIOint i 
// similars, pero l'aprofitem per tenir ben definit el NULL

template <class T> class Llista {

  // els costos temporals de les operacions publiques son els mateixos
  // que els de les operacions equivalents a l'especificació original;

private:
  struct node_llista {
    T info;
    node_llista* seg;
    node_llista* ant;
  }; 
  int longitud;
  node_llista* primer_node;
  node_llista* ultim_node;
  node_llista* act;
  // especificació operacions privades

  static node_llista* copia_node_llista(node_llista* m, node_llista* oact,
					node_llista*& u, node_llista*& a)
  /* Pre: cert */
  /* Post: si m es NULL, el resultat, u i a son NULL; en cas contrari,
     el resultat apunta al primer node d'una cadena de nodes que son
     copia de la cadena que te el node apuntat per m com a primer, u
     apunta a l'ultim node, a es o be NULL si oact no apunta a cap
     node de la cadena que comenca amb m o be apunta al node copia del
     node apuntat per oact */
  /* Cost temporal: proporcional al nombre de nodes que penjen d'm; cada
     node copiat aporta el cost de copiar la seva info */
  { 
    node_llista* n;
    if (m==NULL) {n=NULL; u=NULL; a=NULL;}
    else {
      n = new node_llista;
      n->info = m->info;
      n->ant = NULL;
      n->seg = copia_node_llista(m->seg, oact, u, a);
      if (n->seg == NULL) u = n; 
      else n->seg->ant = n;
      if (m == oact) a = n;
    }
    return n;
  }


  static void esborra_node_llista(node_llista* m) 
  /* Pre: cert */
  /* Post: no fa res si m és NULL, en cas contrari, allibera espai dels
     nodes de la cadena que te el node apuntat per m com a primer */
  /* Cost temporal: proporcional al nombre de nodes que penjen d'm */
  {     
    if (m != NULL) {
      esborra_node_llista(m->seg);
      delete m;
    }
  }


public:
  //  operacions publiques

  // Constructora

  Llista() 
  /* Pre: cert */
  /* Post: el resultat es una llista buida */
  {
    longitud = 0;
    primer_node = NULL;
    ultim_node = NULL;
    act = NULL;
  }

  Llista(const Llista &original) 
  /* Pre: cert */
  /* Post: El resultat es una copia d'original */
  {
    longitud = original.longitud;
    primer_node = copia_node_llista(original.primer_node, original.act,
				    ultim_node, act);  
  }

  // Destructora

  ~Llista() 
  // Destructora: Esborra automaticament els objectes locals en
  // sortir d'un ambit de visibilitat
  {
    esborra_node_llista(primer_node);
  }

  // Redefinicio de la asignacio

  Llista& operator=(const Llista& original) 
  /* Pre: cert */
  /* Post: El p.i. passa a ser una copia d'original i qualsevol contingut
     anterior del p.i. ha estat esborrat (excepte si el p.i. i original ja
     eren el mateix objecte) */
  {
    if (this != &original) {
      longitud = original.longitud;
      esborra_node_llista(primer_node);
      primer_node = copia_node_llista(original.primer_node, original.act,
				      ultim_node, act);
    }
    return *this;
  }

  // Modificadores

  void l_buida() 
  /* Pre: cert */
  /* Post: El p.i. passa a ser una llista sense elements i qualsevol
     contingut anterior del p.i. ha estat esborrat */
  {
    esborra_node_llista(primer_node);
    longitud = 0;
    primer_node = NULL;
    ultim_node = NULL;
    act = NULL;
  }
        
  void afegir(const T& x) 
  /* Pre: cert */
  /* Post: el p.i. es com el seu valor original, pero amb x afegit a
     l'esquerra del punt d'interes */
  {
    node_llista* aux;
    aux = new node_llista; // reserva espai pel nou element
    aux->info = x;
    aux->seg = act;
    if (longitud==0) {
      aux->ant = NULL;
      primer_node = aux;
      ultim_node = aux;
    }
    else if (act==NULL) {
      aux->ant = ultim_node;
      ultim_node->seg = aux;
      ultim_node = aux;
    }
    else if (act==primer_node) {
      aux->ant = NULL;
      act->ant = aux;
      primer_node = aux;
    }
    else {
      aux->ant = act->ant;
      (act->ant)->seg = aux;
      act->ant = aux;
    }
    ++longitud;
  }

  void eliminar()
  /* Pre: el p.i. es una llista no buida i el seu punt d'interes no esta a
     la dreta de tot */
  /* Post: El p.i. es com el p.i. original sense l'element on estava el
     punt d'interes i amb el nou punt d'interes avancat una posicio a la
     dreta */
  {
    node_llista* aux;
    aux = act; // conserva l'acces al node actual
    if (longitud==1) {
      primer_node = NULL;
      ultim_node = NULL;
    }
    else if (act==primer_node) {
      primer_node = act->seg;
      primer_node->ant = NULL;
    }
    else if (act==ultim_node) {
      ultim_node = act->ant;
      ultim_node->seg = NULL;
    }
    else {
      (act->ant)->seg = act->seg;
      (act->seg)->ant = act->ant;
    }
    act = act->seg; // avanca el punt d'interes
    delete aux; // allibera l'espai de l'element esborrat
    --longitud;
  }

  void concat(Llista& l) 
  /* Pre: l=L; l no es el mateix objecte que el p.i. */
  /* Post: el p.i. te els seus elements originals seguits pels de L, l es
     buida i el punt d'interes del p.i. queda situat a l'inici */
  {
    if (this != &l) {
      if (l.longitud>0) {  // si la llista l es buida no cal fer res
	if (longitud==0) {
	  primer_node = l.primer_node;
	  ultim_node = l.ultim_node;
	  longitud = l.longitud;
	}
	else {
	  ultim_node->seg = l.primer_node;
	  (l.primer_node)->ant = ultim_node;
	  ultim_node = l.ultim_node;
	  longitud+= l.longitud;
	}
	l.primer_node = NULL;
	l.ultim_node = NULL;
	l.act = NULL;
	l.longitud = 0;  
      }    
      act = primer_node;
    }
    else throw PRO2Excepcio ("Les dues llistes han de ser objectes diferents");
  }

  // Consultores 

  bool es_buida() const 
  /* Pre: cert */
  /* Post: El resultat indica si el p.i. es una llista buida o no */
  {
    return primer_node==NULL;
  }

  int mida() const 
  /* Pre: cert */
  /* Post: El resultat es el nombre d'elements de la llista p.i. */
  {
    return longitud;
  }

  // Noves operacions per a consultar i modificar l'element actual 
 
  T actual() const
  /* Pre: el p.i. es una llista no buida i el seu punt d'interes no
     esta a la dreta de tot */
  /* Post: el resultat es l'element actual del p.i. */
  { 
    return act->info;// equival a consultar *it si it es un iterador a l'actual
  }

  void modifica_actual(const T &x) 
  /* Pre: el p.i. es una llista no buida i el seu punt d'interes no
     esta a la dreta de tot */
  /* Post: el p.i. es com el seu valor original, pero amb x
     reemplacant l'element actual */
  {
    act->info = x; // equival a fer *it=x; si it is un iterador
  }

  // Noves operacions per a moure el punt d'interes

  void inici()
  /* Pre: cert */
  /* Post: el punt d'interès del p.i. esta situat a sobre del primer
     element de la llista o a la dreta de tot si la llista es buida */
  {
    act = primer_node; // equival a fer it=l.begin(); si it es un iterador a l'actual
  }

  void fi()
  /* Pre: cert */
  /* Post: el punt d'interes del p.i. esta situat a la dreta del tot */
  {
    act = NULL;  // equival a fer it=l.end(); si it es un iterador a l'actual
  }

  void avanca() 
  /* Pre: el punt d'interes del p.i. no està a la dreta de tot */
  /* Post: el punt d'interes del p.i. esta situat una posicio mes a la
     dreta que al valor original del p.i. */ 
  { 
    act = act->seg; // equival a fer ++it; si it es un iterador a l'actual
  }

  void retrocedeix() 
  /* Pre: el punt d'interes del p.i. no esta a sobre del primer
     element de la llista*/
  /* Post: el punt d'interes del p.i. esta situat una posicio mes a
     l'esquerra que al valor original del p.i. */ 
  {
    if (act==NULL) act=ultim_node;  
    else act = act->ant; // equival a fer --it; si it es un iterador a l'actual
  }

  bool dreta_de_tot() const
  /* Pre: cert */
  /* Post: el resultat indica si el punt d'interes del p.i. esta a la
     dreta de tot */
  {
    return act==NULL; // equival a comparar it==l.end() si it es un iterador a l'actual
  }

  bool sobre_el_primer() const 
  /* Pre: cert */
  /* Post: el resultat indica si el punt d'interès del p.i. esta a sobre del
     primer element del p.i. o esta a la dreta de tot si la llista es buida */
  {
    return act==primer_node; // equival a comparar it==l.begin() si it es un iterador a l'actual
  }

  // Extensio ------------------------------------------------

  void invertir ()
  /* Pre: cert */ 
  /* Post: el p.i. te els mateixos elements que a l'inici pero amb
     l'ordre invertit i el seu punt d'interes no s'ha mogut */
  {
    node_llista* n = primer_node;
    while (n != ultim_node) {
      /* Inv: els nodes anteriors al que apunta n en la cadena que
	 comenca a primer_node han intercanviat els seus punters a
	 l'anterior i al seguent node */
      node_llista* aux = n->seg;
      n->seg = n->ant;
      n->ant = aux;
      n = aux;
    }
    if (n!=NULL and n!=primer_node) {
      n->seg = n->ant;
      n->ant = NULL;
      ultim_node = primer_node;
      primer_node = n;
    }
  }

};

#endif
