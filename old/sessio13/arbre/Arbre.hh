#ifndef ARBRE_HH
#define ARBRE_HH

#include "utils.PRO2"

template <class T> class Arbre { 

private:     

  struct node_arbre {
    T info;
    node_arbre* segE;
    node_arbre* segD;
  };

  node_arbre* primer_node;

  // especificaci— operacions privades

static node_arbre* copia_node_arbre(node_arbre* m) { 
    /* Pre: cert */
    /* Post: el resultat Žs NULL si m Žs NULL;
       en cas contrari, el resultat apunta al node arrel 
       d'una jerarquia de nodes que Žs una c˜pia de la
       jerarquia de nodes que tŽ el node apuntat per m com a arrel */
    node_arbre* n;
    if (m==NULL) n=NULL;
    else {
      n = new node_arbre;
      n->info = m->info;
      n->segE = copia_node_arbre(m->segE);
      n->segD = copia_node_arbre(m->segD);
    }
    return n;
  }

static void esborra_node_arbre(node_arbre* m) {  
    /* Pre: cert */
    /* Post no fa res si m Žs NULL; en cas contrari,
       allibera espai de tots els nodes de la 
       jerarquia que tŽ el node apuntat per m com a arrel */
    if (m != NULL) {
      esborra_node_arbre(m->segE);
      esborra_node_arbre(m->segD);
      delete m;
    }
  }

public:

  // especificaciŽ operacions pœbliques

  Arbre() {
    /* Pre: cert */
    /* Post: el p.i. Žs un arbre buit */
    primer_node= NULL;
  }

  Arbre(const Arbre& original) {
    /* Pre: cert */
    /* Post: el p.i. Žs una c˜pia d'original */
    if (this != &original)     
      primer_node = copia_node_arbre(original.primer_node);
  }

  ~Arbre() {
    esborra_node_arbre(primer_node);
  }

  Arbre& operator=(const Arbre& original) {
    if (this != &original) {
      esborra_node_arbre(primer_node);
      primer_node = copia_node_arbre(original.primer_node);
    }
    return *this;
  }

  void a_buit() {
    /* Pre: cert */
    /* Post: el p.i. Žs un arbre buit */
    esborra_node_arbre(primer_node);
    primer_node= NULL;
  }        

  void plantar(const T &x, Arbre &a1, Arbre &a2) {
    /* Pre: el p.i. Žs buit, a1=A1, a2=A2 */
    /* Post: el p.i. tŽ x com a arrel,
       A1 com a fill esquerre i A2 com a fill dret; 
       a1 i a2 s—n buits */
    if (this != &a1 and this != &a2) {
      if (primer_node==NULL) {
        node_arbre* aux;
        aux= new node_arbre;
        aux->info= x;
        aux->segE= a1.primer_node;
        if (a1.primer_node == a2.primer_node) aux->segD= copia_node_arbre(a1.primer_node);
        else  aux->segD= a2.primer_node;
        primer_node= aux;
        a1.primer_node= NULL;
        a2.primer_node= NULL;
      }
      else
        throw PRO2Excepcio ("El p.i. de plantar ha de ser buit a la crida");
    }
    else
      throw PRO2Excepcio ("El p.i. de plantar no pot coincidir amb els parametres");
  }


  void fills (Arbre &fe, Arbre &fd) {
    /* Pre: el p.i. no Žs buit i li diem A, fe i fd s—n buits */
    /* Post: fe Žs el fill esquerre d'A, fd Žs el fill dret d'A,
       el p.i. Žs buit */
    if (primer_node!=NULL and fe.primer_node==NULL
        and fd.primer_node==NULL) {
      if (&fe != &fd) {       
        node_arbre* aux;
        aux= primer_node;
        fe.primer_node= aux->segE;
        fd.primer_node= aux->segD;
        primer_node= NULL;
        delete aux;
      }
      else 
        throw PRO2Excepcio 
              ("Els dos parametres de fills no poden coincidir");
    }
    else if (primer_node==NULL)
      throw PRO2Excepcio ("Un arbre buit no te fills");
    else   
      throw PRO2Excepcio 
        ("Els dos parametres de fills han de ser buits a la crida");
  }

  T arrel() const {
    /* Pre: el p.i. no Žs buit */
    /* Post: el resultat Žs l'arrel del p.i. */
    if (primer_node!=NULL)
      return primer_node->info;    
    else
      throw PRO2Excepcio ("Un arbre buit no te arrel");
  }

  bool es_buit() const {
    /* Pre: cert */
    /* Post: el resultat indica si el p.i. Žs un arbre buit */
    return (primer_node==NULL);
  }

 // Extensi— -----------------------------------------------------

  void inc (const T &k) { 
    /* Pre: a=A; el tipus T tŽ l'operaci— suma */
    /* Post: a Žs com A per˜ havent sumat k a tots els seus elements */
    inc_node(primer_node, k);
  }

  static void inc_node (node_arbre* n, T k){
    /* Pre: cert */ 
    /* Post: el node apuntat per n i tots els seus segŸents tenen al seu camp
       info la suma de k i el seu valor original */
    if (n!=NULL) {
      n->info += k;
      inc_node(n->segE, k);
      inc_node(n->segD, k);
    }
  }

  void subst (T x, const Arbre &as) {
    /* Pre: a=A; el tipus T tŽ l'operaci— == */
    /* Post: a Žs com A per˜ havent substituit les fulles que contenien x
         per l'arbre as */
    subst_node(primer_node, x, as.primer_node);
      }

  static void subst_node (node_arbre* &n, T x, node_arbre* ns) {
    /* Pre: cert */ 
    /* Post: els nodes de la jerarquia de nodes que comença al node apuntat per n
   tals que el seu camp info valia x i no tenien segŸents han estat substitu•ts
   per una c˜pia de la jeraquia de nodes que comena al node apuntat per ns */
    if (n!=NULL) {
      if (n->info == x and n->segE == NULL and n->segD == NULL) 
	n= copia_node_arbre(ns);
      else {
	subst_node(n->segE, x, ns);
	subst_node(n->segD, x, ns);
      }
    }
  }
 
 int tam ()
    /* Pre: cert */
    /* Post: el resultat es el nombre de nodes del p.i. */
  {
    return tam_node(primer_node);
  }

 static int tam_node (node_arbre* n)
    /* Pre: cert */
    /* Post: el resultat es el nombre de nodes descendents d'n, ell mateix incl˜s */
  {
    int t;
    if (n == NULL) t=0;
    else t=1+ tam_node(n->segE) +tam_node(n->segD);  
    return t;
  }

};

#endif
