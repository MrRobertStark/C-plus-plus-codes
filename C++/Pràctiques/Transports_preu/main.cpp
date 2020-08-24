#include <iostream>
using namespace std;

//Entrada: el preu del viatge de transport, els kms d'anada, el preu del carburant, el consum del cotxe
//Sortida: Calcula el preu final viatjant en bus i en cotxe
int main(){

    cout.setf(ios::fixed);
    cout.precision(2);
    const double MANTENIMENT = 0.2;
    cout<< "Preu viatge transport public [>0]: ";
    double preu_bus;
    cin>>preu_bus;
    cout<< "Kms anada [>=0]: ";
    double kms;
    cin>>kms;
    cout<< "Preu del carburant [>0]: ";
    double preu_gasoil;
    cin>>preu_gasoil ;
    cout<< "Consum cotxe en litres per 100 km [>0]: ";
    double consum_cotxe;
    cin>>consum_cotxe;
    double import_cotxe = kms*MANTENIMENT+consum_cotxe/100*preu_gasoil*kms;
    cout<< "Import transport public: "<< preu_bus <<endl;
    cout<< "Import cotxe: "<< import_cotxe <<endl;
    return 0;

}
