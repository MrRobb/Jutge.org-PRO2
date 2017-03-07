#ifndef LLISTA
#define LLISTA

#include "utils.PRO2"

template <class T> class Llista {
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
  // especificaci— operacions privades

static node_llista* copia_node_llista(node_llista* m, node_llista* oact,
				 node_llista* &u, node_llista* &a)
    /* Pre: cert */
    /* Post: si m Žs NULL, el resultat, u i a s—n NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que s—n c˜pia de la cadena que tŽ el node apuntat per m
       com a primer, u apunta a l'œltim node, a Žs o bŽ NULL si oact
       no apunta a cap node de la cadena que comena amb m o bŽ apunta
       al node c˜pia del node apuntat per oact */
  { 
    node_llista* n;
    if (m==NULL) {n=NULL; u=NULL; a=NULL;}
    else {
      n = new node_llista;
      n->info = m->info;
      n->ant=NULL;
      n->seg = copia_node_llista(m->seg, oact, u, a);
      if (n->seg == NULL) u = n; 
      else n->seg->ant = n;
      if (m == oact) a = n;
    }
    return n;
  }


static void esborra_node_llista(node_llista* m) 
    /* Pre: cert */
    /* Post: no fa res si m Žs NULL, en cas contrari, allibera espai dels
       nodes de la cadena que tŽ el node apuntat per m com a primer */
  {     
    if (m != NULL) {
      esborra_node_llista(m->seg);
      delete m;
    }
  }


public:
  //  operacions pœbliques

  // Constructora

  Llista() 
    /* Pre: cert */
    /* Post: el resultat Žs una llista buida */
  {
    longitud= 0;
    primer_node= NULL;
    ultim_node= NULL;
    act= NULL;
  }

  Llista(const Llista &original) 
    /* Pre: cert */
    /* Post: El resultat Žs una c˜pia d'original */
  {
    longitud= original.longitud;
    primer_node = copia_node_llista(original.primer_node, original.act,
				       ultim_node, act);  
  }

  // Destructora

  ~Llista() 
    // Destructora: Esborra automˆticament els objectes locals en
    // sortir d'un ˆmbit de visibilitat
  {
    esborra_node_llista(primer_node);
  }

  // Redefinici— de l'asignaci—

  Llista& operator=(const Llista& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una c˜pia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat 
       (excepte si el p.i. i original ja eren el mateix objecte) */
  {
    if (this != &original) {
      longitud= original.longitud;
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
    longitud= 0;
    primer_node= NULL;
    ultim_node= NULL;
    act= NULL;
  }
        
  void afegir (const T& x) 
    /* Pre: cert */
    /* Post: el p.i. Žs com el seu valor original, per˜ amb x
       afegit a l'esquerra del punt d'inters */
  {
    node_llista* aux;
    aux= new node_llista; // reserva espai per al nou element
    aux->info= x;
    aux->seg= act;
    if (longitud==0) {
      aux->ant= NULL;
      primer_node= aux;
      ultim_node= aux;
    }
    else if (act==NULL) {
      aux->ant= ultim_node;
      ultim_node->seg= aux;
      ultim_node= aux;
    }
    else if (act==primer_node) {
      aux->ant= NULL;
      act->ant= aux;
      primer_node= aux;
    }
    else {
      aux->ant= act->ant;
      (act->ant)->seg= aux;
      act->ant= aux;
    }
    ++longitud;
  }

  void eliminar()
    /* Pre: el p.i. Žs una llista no buida i el seu punt d'inters no Žs a la dreta de tot */
    /* Post: El p.i. Žs com el p.i. original sense l'element on estava el punt d'inters
       i amb el nou punt d'inters avanat una posici— a la dreta */
  {
    node_llista* aux;
    aux= act; // conserva l'accŽs al node actual
    if (longitud==1) {
      primer_node= NULL;
      ultim_node= NULL;
    }
    else if (act==primer_node) {
      primer_node= act->seg;
      primer_node->ant= NULL;
    }
    else if (act==ultim_node) {
      ultim_node= act->ant;
      ultim_node->seg= NULL;
    }
    else {
      (act->ant)->seg= act->seg;
      (act->seg)->ant= act->ant;
    }
    act= act->seg; // avança el punt d'inters
    delete aux; // allibera l'espai de l'element esborrat
    --longitud;
  }

  void concat(Llista& l) 
    /* Pre: l=L */
    /* Post: el p.i. tŽ els seus elements originals seguits pels de
       L, l Žs buida i el punt d'inters del p.i. queda situat a l'inici */
  {
    if (l.longitud>0) {  // si la llista l Žs buida, no cal fer res
      if (longitud==0) {
	primer_node= l.primer_node;
	ultim_node= l.ultim_node;
	longitud= l.longitud;
      }
      else {
	ultim_node->seg= l.primer_node;
	(l.primer_node)->ant= ultim_node;
	ultim_node= l.ultim_node;
	longitud+= l.longitud;
      }
      l.primer_node= NULL;
      l.ultim_node= NULL;
      l.act= NULL;
      l.longitud= 0;  
    }    
    act= primer_node;

  }

  // Consultores 

  bool es_buida() const 
    /* Pre: cert */
    /* Post: El resultat indica si el p.i. Žs una llista buida o no */
  {
    return primer_node==NULL;
  }

  int mida() const 
    /* Pre: cert */
    /* Post: El resultat Žs el nombre d'elements de la llista p.i. */
  {
    return longitud;
  }

  // Noves operacions per a consultar i modificar l'element actual 
 
  T actual() const
    /* Pre: el p.i. Žs una llista no buida i el seu punt d'inters no Žs a la dreta de tot */
    /* Post: el resultat Žs l'element actual del p.i. */
  { 
    return act->info;// equival a consultar *it si it es un iterador a l'actual
  }

  void modifica_actual(const T &x) 
    /* Pre: el p.i. Žs una llista no buida i el seu punt d'inters no Žs a la dreta de tot */
    /* Post: el p.i. Žs com el seu valor original, per˜ amb x reemplaant l'element actual */
  {
    act->info= x; // equival a fer *it=x; si it Žs un iterador
  }

  // Noves operacions per a moure el punt d'inters

  void inici()
    /* Pre: cert */
    /* Post: el punt d'inters del p.i. estˆ situat a sobre del primer element de la llista
       o a la dreta de tot si la llista Žs buida */
  {
    act= primer_node; // equival a fer it=l.begin(); si it Žs un iterador a l'actual
  }

  void fi()
    /* Pre: cert */
    /* Post: el punt d'inters del p.i. estˆ situat a la dreta del tot */
  {
    act= NULL;  // equival a fer it=l.end(); si it Žs un iterador a l'actual
  }

  void avanca() 
    /* Pre: el punt d'inters del p.i. no Žs a la dreta de tot */
    /* Post: el punt d'interès del p.i. estˆ situat una posici— mŽs a la dreta que al
       valor original del p.i. */ 
  { 
    act= act->seg; // equival a fer ++it; si it Žs un iterador a l'actual
  }

  void retrocedeix() 
    /* Pre: el punt d'inters del p.i. no Žs a sobre del primer element de la llista*/
    /* Post: el punt d'inters del p.i. estˆ situat una posici— mŽs a l'esquerra que
       al valor original del p.i. */ 
  {
    if (act==NULL) act=ultim_node;  
    else act= act->ant; // equival a fer --it; si it Žs un iterador a l'actual
  }

  bool dreta_de_tot() const
    /* Pre: cert */
    /* Post: el resultat indica si el punt d'inters del p.i. Žs a la dreta de tot */
  {
    return act==NULL; // equival a comparar it==l.end() si it Žs un iterador a l'actual
  }

  bool sobre_el_primer() const 
    /* Pre: cert */
    /* Post: el resultat indica si el punt d'inters del p.i. Žs a sobre del
       primer element del p.i. o estˆ a la dreta de tot si la llista Žs buida */
  {
    return act==primer_node; // equival a comparar it==l.begin() si it Žs un iterador a l'actual
  }

  // Extensi— ------------------------------------------------
  void invertir ()
    /* Pre: cert */ 
    /* Post: el p.i. tŽ els mateixos elements que a l'inici per˜ amb l'ordre invertit
       i el seu punt d'inters no s'ha mogut */
  {
    node_llista* n = primer_node;
    while (n != ultim_node) {
      /* Inv: els nodes anteriors al que apunta n en la cadena que comena a primer_node
	 han intercanviat els seus punters a l'anterior i al segŸent node */
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
