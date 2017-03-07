/** @file Sistema.cc
    @brief Código de la clase Sistema
*/

#include "Sistema.hh"

Sistema::Sistema()
{
  id = 1;
}

void Sistema::anadir_organismo(Organismo &o, bool &sobrevive)
{
// Proporciona su identificador al nuevo organismo y organiza las luchas de
// éste. Para ello, emplea la operación privada "luchas_org_cola" que lo enfrenta
// a los de la cola correspondiente y obtiene la información necesaria.
   o.anadir_id(id);
   ++id;
   if (o.es_maligno()) { 
      luchas_org_cola(def, o, sobrevive);
      if (sobrevive) mal.push(o);
   }
   else {
      luchas_org_cola(mal, o, sobrevive);
      if (sobrevive) def.push(o);
   }
}

void Sistema::luchas_org_cola(queue<Organismo> &c, Organismo &o, bool &sobrevive)
{
// Busca el primer organismo de la cola c que consigue matar al organismo o y
// borra (y cuenta) todos los que resultan destruidos por éste. Para que el
// borrado sea efectivo, los supervivientes se van añadiendo al final de la 
// cola. Al final, los que no hayan luchado se pasan al final la cola mediante
// una nueva operación privada auxiliar: "recolocar".

   Organismo actual; 
   int resultado; 
 
   sobrevive = true;
   int long_cola = c.size();
  
// Inv: sobrevive = ninguno de los elementos visitados de C destruye a o;
//      c = elementos no visitados de C seguidos por los elementos visitados
//      con su contador de víctimas actualizado, excepto los que hayan muerto 
//      al enfrentarse con o, en el mismo orden en que estaban en C;
//      long_cola = número de elementos no visitados de C;
//      o tiene actualizado su contador de víctimas
// 
// Cota: long_cola

   while (long_cola>0 and sobrevive) {
      actual = c.front();
      resultado = o.lucha_organismos(actual);
      switch (resultado) {
         case 0: {                    // los dos mueren
            sobrevive = false;        // no actualizamos las víctimas de actual 
            o.incrementar_victimas(); // porque éste ya no pertenece al sistema
            break;
         } 
         case 1: {                    // o muere, actual sobrevive
            sobrevive= false;
            actual.incrementar_victimas();
            c.push(actual);
            break;
         }
         case 2: {                    // o sobrevive, actual muere
            o.incrementar_victimas();
            break;
         }
         case 3: {                    // los dos sobreviven
            c.push(actual);
            break;
         }
      }
      c.pop();
      --long_cola;
   }

// Post1: Inv1 y (long_cola == 0 or not sobrevive)

// Falta pasar al final de c los elementos no visitados de C (por Inv1, son
// los long_cola primeros de c), para mantener el orden por identificador

   recolocar(long_cola,c);
}

void Sistema::recolocar(int n, queue<Organismo> &c)
{
  // Inv:  n<=N, c contiene los mismos elementos que C, pero los N-n primeros 
  //       elementos de C están al final de c, en el orden relativo original;
  //       los restantes también conservan su orden relativo original
  // Cota: n

  while (n>0) {
    c.push(c.front());
    c.pop();
    --n;
  } 
}

void Sistema::clear(queue<Organismo>& q)
{
  while (not q.empty()) q.pop();
}

void Sistema::leer(int N) 
{
// Esta operación actualiza todos los componentes de un sistema, leyéndolos
// del canal estándar; ofrece la posiblidad de leer y almacenar algunos
// organismos defensivos.  El número de éstos se proporciona al comienzo de
// la operación.

  if (N<=0) throw PRO2Excepcio("Las celulas de los organismos del sistema han de tener N parametros (N>0)");

  clear(def);
  clear(mal);  
  int num; // numero de organismos iniciales del sistema
  cin >> num;
  Organismo o;
  for (int i = 1; i <= num; ++i) {  
    o.leer(N); 
    o.anadir_id(i); 
    if (o.es_maligno()) mal.push(o);
    else def.push(o);
  }
  id = num+1;
}

void Sistema::escribir(bool tipo, bool estr) const
{
// Esta operación simplemente recorre la cola de los organismos pedidos,
// proporcionando la información requerida, mediante una operación privada
// auxiliar: "escribir_sistema_cola".

  if (tipo) escribir_sistema_cola(def, estr);
  else escribir_sistema_cola(mal, estr);
}

void Sistema::escribir_sistema_cola(const queue<Organismo> &c, bool estr)
{
  queue<Organismo> aux(c);
  while (not aux.empty()) {
    aux.front().escribir(estr);
    aux.pop();
  }
}

