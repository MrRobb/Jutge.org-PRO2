#include "iostream"
#include "Cjt_estudiants.hh"

void actualitzarConjuntEstudiantsOrdenats(Cjt_estudiants& conjunto1, const Cjt_estudiants& conjunto2){
    // Pre: els dos conjunts estàn ordenats per DNI d'estudiants, amb el mateixos estudians.
    // Post: Actualitza les notes dels estudiants del primer conjunt segons les notes dels estudiants del segon conjunt.
    Estudiant est1;
    Estudiant est2;

    int size = conjunto1.mida();

    for(int i = 0; i < size; ++i){
        est1 = conjunto1.consultar_iessim(i+1);
        est2 = conjunto2.consultar_iessim(i+1);

        // Si ambdós tenen nota, i la nota dels segon es millor, modificar la nota del primer
        if (est1.te_nota() and est2.te_nota() and est1.consultar_nota() < est2.consultar_nota()){
            est1.modificar_nota(est2.consultar_nota());
            conjunto1.modificar_iessim(i+1,est1);

        // Si el primer no té nota però el segon sí, afegir la nota del primer
        } else if(!est1.te_nota() and est2.te_nota()){
            est1.afegir_nota(est2.consultar_nota());
            conjunto1.modificar_iessim(i+1,est1);
        }
    }
}

int main(){

    // DECLARACIONES

    Cjt_estudiants conjunto1;
    Cjt_estudiants conjunto2;

    // LEER EL PRIMER CONJUNTO

    conjunto1.llegir();

    // LEER EL SEGUNDO CONJUNTO

    conjunto2.llegir();

    // ACTUALIZAR EL PRIMER CONJUNTO

    actualitzarConjuntEstudiantsOrdenats(conjunto1, conjunto2);

    // ESCRIBIR EL PRIMER CONJUNTO

    conjunto1.escriure();

}
