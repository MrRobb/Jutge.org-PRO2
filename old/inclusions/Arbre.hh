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

  // especificació operacions privades

  node_arbre* copia_node_arbre(node_arbre* m)
    /* Pre: cert */
    /* Post: el resultat és NULL si m és NULL; 
       en cas contrari, el resultat apunta al node arrel 
       d'una jerarquia de nodes que és una còpia de la 
       jerarquia de nodes que té el node apuntat per m com a arrel */
  {
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

  void esborra_node_arbre(node_arbre* m)
    /* Pre: cert */
    /* Post no fa res si m és NULL; en cas contrari, 
       allibera espai de tots els nodes de la 
       jerarquia que té el node apuntat per m com a arrel */
  {
    if (m != NULL) {
      esborra_node_arbre(m->segE);
      esborra_node_arbre(m->segD);
      delete m;
    }
  }

public:

  // especificació operacions públiques

  Arbre()
    /* Pre: cert */
    /* Post: el p.i. és un arbre buit */
  {
    primer_node= NULL;
  }

  Arbre(const Arbre& original)
    /* Pre: cert */
    /* Post: el p.i. és una còpia d'original */
  {
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

  void a_buit()
    /* Pre: cert */
    /* Post: el p.i. és un arbre buit */
  {
    esborra_node_arbre(primer_node);
    primer_node= NULL;
  }  
      
  void swap(Arbre &a)
    /* Pre: a=A, p.i. = P */
    /* Post: el p.i. passa a ser A; a passa a ser P */
  {
    node_arbre* aux;
    aux = a.primer_node;
    a.primer_node = primer_node;
    primer_node = aux;
  }

  void plantar(const T &x, Arbre &a1, Arbre &a2)
    /* Pre: el p.i. és buit, a1=A1, a2=A2 */
    /* Post: el p.i. té x com a arrel, A1 com a fill esquerre i A2 com a 
       fill dret; a1 i a2 són buits; si A1 i A2 són el mateix objecte, el
       fill dret n'és una còpia */
  {
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
      throw PRO2Excepcio ("El p.i. de plantar no pot coincidir amb els paràmetres");    
  }


  void fills (Arbre &fe, Arbre &fd)
    /* Pre: el p.i. no és buit i li diem A, fe i fd són buits */
    /* Post: fe és el fill esquerre d'A, fd és el fill dret d'A,
       el p.i. és buit */
  {
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
              ("Els dos paràmetres de fills no poden coincidir");      
    }
    else if (primer_node==NULL)
      throw PRO2Excepcio ("Un arbre buit no té fills");
    else   
      throw PRO2Excepcio 
        ("Els dos paràmetres de fills han de ser buits a la crida");  
  }

  T arrel() const
    /* Pre: el p.i. no és buit */
    /* Post: el resultat és l'arrel del p.i. */
  {
    if (primer_node!=NULL)
      return primer_node->info;    
    else
      throw PRO2Excepcio ("Un arbre buit no té arrel");
  }

  bool es_buit() const 
    /* Pre: cert */
    /* Post: el resultat indica si el p.i. és un arbre buit */
  {
    return (primer_node==NULL);
  }

};

#endif
