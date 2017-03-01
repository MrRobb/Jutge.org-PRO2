#include <iostream>
#include <vector>
#include "Estudiant.hh"

int main(){
    // Crear vector
    int nEst;
    std::cin >> nEst;
    vector<Estudiant> v(nEst);

    // Leer estudiantes
    for(int i = 0; i < nEst; ++i){
        v[i].Estudiant::llegir();
    }

    // Crear vector de salida
    vector<Estudiant> vfinal(nEst);

    // Comprobar repeticiones de dni y modificar sus notas
    int u = 0;
    for(int i = 0; i < nEst; ++i){

        // Si el estudiante es igual al anterior (exceptuando el primer estudiante)
        if(i != 0 and v[i].Estudiant::consultar_DNI() == v[i-1].Estudiant::consultar_DNI()){

            // Si ambos tienen nota, modificar el final
            if(v[i].Estudiant::te_nota() and vfinal[u-1].Estudiant::te_nota() and v[i].Estudiant::consultar_nota() > vfinal[u-1].Estudiant::consultar_nota()){
                vfinal[u-1].Estudiant::modificar_nota(v[i].Estudiant::consultar_nota());
            
            // Si sólo el primero tiene nota nota, añadírsela al segundo
            } else if(v[i].Estudiant::te_nota() and !vfinal[u-1].Estudiant::te_nota()) {
                vfinal[u-1].Estudiant::afegir_nota(v[i].Estudiant::consultar_nota());
            }

        // Si el estudiante no es igual al anterior, añadir al estudiante con su nota (si es que tiene)
        } else {
            vfinal[u] = Estudiant(v[i].Estudiant::consultar_DNI());
            if(v[i].Estudiant::te_nota()) vfinal[u].Estudiant::afegir_nota(v[i].Estudiant::consultar_nota());
            ++u;
        }
    }

    // Escribir estudiantes
    int i = 0;
    bool finish = false;
    // Escribir estudiantes hasta que se acabe el vector o hasta que se acaben los estudiantes
    while(i < nEst and !finish){
        if(vfinal[i].Estudiant::consultar_DNI() != 0) vfinal[i].Estudiant::escriure();
        else finish = true;
        ++i;
    }
}