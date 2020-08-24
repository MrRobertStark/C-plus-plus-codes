#include <iostream>
#include "Agenda.h"
#include "Hora.h"
#include "Data.h"
#include "Esdeveniment.h"
//Entrada: Una sèrie de esdeveniments amb la seva data-hora(inicial i final)-esdeveniment
//sortida: a partir d'una data entrat per teclat es mostra la quantitat de temps total gastats per totes les activitats del mateix dia

using namespace std;

int main()
{
    Agenda agenda;
    cout<< "AFEGEIX ELS ESDEVENIMENTS:"<<endl;
    char ordre='S';
    while(ordre!='N')
    {
        agenda.afegir_esdeveniment();
        cout<<"VOLS AFEGIR UN ALTRE ESDEVENIMENT? (S/N):"<<endl;
        cin>>ordre;
    }
    agenda.buscar_data_i_estudiar_durada();
    return 0;
}
