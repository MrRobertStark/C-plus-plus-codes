#include <iostream>
#include <fstream>
#include <string>

#include "Registre.h"
#include "Paraula.h"
#include "Vector_Paraules.h"

using namespace std;

void emplenar_registre(ifstream&fitxer,Registre&registre)
//Pre:
//Post:
{
    Paraula p;
    while(not fitxer.eof())
    {
        p.llegir_paraula(fitxer);
        registre.afegir_paraula_al_registre(p);
    }
}

int main()
{
    cout << "ENTRA EL NOM DEL FITXER:" << endl;
    string nom_fitxer; cin>>nom_fitxer;
    ifstream fitxer(nom_fitxer.c_str());
    Registre registre;

    if(fitxer.fail())cout<< "NO S'HA TROBAT EL FITXER"<<endl;
    else emplenar_registre(fitxer,registre);

    cout<< "RECOMPTE DE LES PARAULES:"<<endl;
    registre.buscar_paraules_amb_minim_aparicions();

    int recompte=registre.recompte_paraules_diferents();
    cout<<"HI HA X "<<recompte<<" PARAULES DIFERENTS";
    return 0;
}
