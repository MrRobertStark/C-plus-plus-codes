#include <iostream>
using namespace std;

//Entrada: preu inicial, nombre de llibres encarregat
//Sortida: Preu final de la comanda tenint en compte l'impost i el recàrrec per enviament amb una precisió de dos decimals

int main(){

    cout.setf(ios::fixed);
    cout.precision(2);
    const int IVA = 21;
    const int RECARREC = 2;
    cout<< "Preu total dels llibres [>=0]: ";
    double preu_total;
    cin>> preu_total;
    cout<< "Nombre de llibres [>=0]: ";
    int nombre_llibres;
    cin>>nombre_llibres;
    double import_final = preu_total+preu_total*IVA/100.0+nombre_llibres*RECARREC;
    cout<< "Import final de l'encarrec: "<<import_final<<endl;
    return 0;

}
