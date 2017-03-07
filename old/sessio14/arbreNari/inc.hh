void inc_arbreNari (const T &k)
/* Pre: A Žs el valor inicial del p.i. */
/* Post: el p.i. Žs com A per˜ havent sumat k a tots els seus elements */
{
  inc_nodeNari(primer_node, k);
}

static void inc_nodeNari (node_arbreNari* n, const T &k)
/* Pre: cert */ 
/* Post: el node apuntat per n i tots els seus segŸents tenen al seu camp
   info la suma de k i el seu valor original */
{
  if (n!=NULL) {
    n->info += k;
    int s = (n->seg).size();
    for (int i=0; i<s; ++i) 
      inc_nodeNari(n->seg[i], k);
  }
}
