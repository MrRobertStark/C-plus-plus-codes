#include <iostream>
#include <fstream>
#include <string>

#include "Paraula.h"
#include "registre.h"
#include "vector_paraules.h"

using namespace std;

void emplenar_registre(ifstream&fitxer,registre&diccionari)
//Pre:
//Post:
{
    while(not fitxer.eof())diccionari.implementar_paraula_al_registre(fitxer);
}

int main()
{
    cout << "ENTRA EL NOM DEL FITXER:" << endl;
    string nom_fitxer;cin>>nom_fitxer;
    ifstream fitxer(nom_fitxer.c_str());
    registre diccionari;

    if(not fitxer.fail())emplenar_registre(fitxer,diccionari);
    else cout<< "NO S'HA TROBAT EL FITXER"<<endl;

    cout<< "RECOMPTE DE LES PARAULES:"<<endl;
    diccionari.buscar_paraules_amb_llindar();

    int comptador=diccionari.consultar_paraules_totals();
    cout<<"HI HA "<<comptador<<" PARAULES DIFERENTS";
    return 0;
}
