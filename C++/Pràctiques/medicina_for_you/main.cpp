#include <iostream>
using namespace std;

//A partir de la dosi recomanada, la concentració i el pes del pacient aquest programa diu la quantitat de medicament a subministrar

int main(){

    cout.setf(ios::fixed);
    cout.precision(1);
    cout<< "Dosi en mg recomanada per kg [>0]: ";
    double dosi_recomanada;
    cin>> dosi_recomanada;
    cout<< "Concentracio del medicament mg/ml [>0]: ";
    double concentracio;
    cin>> concentracio;
    cout<< "Pes del pacient en kg [>0]: ";
    double pes;
    cin>> pes;
    double subministrament = dosi_recomanada*pes/concentracio;
    cout<< "Cal subministrar "<< subministrament << " ml de medicament"<<endl;
    return 0;

}
