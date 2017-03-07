#include <iostream>
#include <vector>
#include "Estudiant.hh"

vector<Estudiant> simplificarVectorEstudiants1(const vector<Estudiant>& v){
    // Pre: Un vector con o sin estudiantes repetidos pero válidos.
    // Post: Devuelve un vector con los estudiantes simplificados.

    int nEst = v.size();
    vector<Estudiant> vfinal(nEst);

    int u = 0;
    for(int i = 0; i < nEst; ++i){

        // Si el estudiante es igual al anterior (exceptuando el primer estudiante)
        if(i != 0 and v[i].consultar_DNI() == v[i-1].consultar_DNI()){

            // Si ambos tienen nota, modificar el final
            if(v[i].te_nota() and vfinal[u-1].te_nota() and v[i].consultar_nota() > vfinal[u-1].consultar_nota()){
                vfinal[u-1].modificar_nota(v[i].consultar_nota());

            // Si sólo el primero tiene nota nota, añadírsela al segundo
            } else if(v[i].te_nota() and !vfinal[u-1].te_nota()) {
                vfinal[u-1].afegir_nota(v[i].consultar_nota());
            }

        // Si el estudiante no es igual al anterior, añadir al estudiante con su nota (si es que tiene)
        } else {
            vfinal[u] = Estudiant(v[i].consultar_DNI());
            if(v[i].te_nota()) vfinal[u].afegir_nota(v[i].consultar_nota());
            ++u;
        }
    }

    return vfinal;
}

void simplificarVectorEstudiants2(vector<Estudiant>& v){
    int nEst = v.size();

    for(int i = 1; i < nEst; ++i){
        if(v[i].consultar_DNI() == v[i-1].consultar_DNI()){
            if(v[i].te_nota() and v[i-1].te_nota() and v[i].consultar_nota() > v[i-1].consultar_nota()){
                // Eliminar dni estudiante (FALTA)
            } else if (v[i].te_nota() and !v[i-1].te_nota()){
                // Eliminar dni estudiante (FALTA)
            }
        }
    }

}

void escribirVectorSimplificado(const vector<Estudiant>& v){
    // Pre: vector simplificado con un número de estudiantes menor al tamaño del vector, cuyos
    //      estudiantes vacíos contienen un dni con valor 0.
    // Post: Escribe los estudiantes no vacíos del vector.

    int i = 0;
    int nEst = v.size();
    bool finish = false;
    // Escribir estudiantes hasta que se acabe el vector o hasta que se acaben los estudiantes
    while(i < nEst and !finish){
        if(v[i].consultar_DNI() != 0) v[i].escriure();
        else finish = true;
        ++i;
    }
}

int main(){
    // Crear vector
    int nEst;
    std::cin >> nEst;
    vector<Estudiant> v(nEst);

    // Leer estudiantes
    for(int i = 0; i < nEst; ++i) v[i].llegir();

    // Simplificar
    simplificarVectorEstudiants2(v);

    // Escribir estudiantes
    escribirVectorSimplificado(v);
}
