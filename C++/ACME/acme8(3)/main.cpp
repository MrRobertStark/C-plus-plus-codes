#include <iostream>
#include <fstream>
#include <string>
#include "Vector_paraules.h"
#include "Vector_abecedari.h"

using namespace std;

const int MAX_ELEMENTS=25000;

void emplenar_taula(ifstream&fitxer,Vector_paraules&registre)
//Pre:
//Post:
{
    Paraula p;
    while(registre.consultar_paraules_totals()<MAX_ELEMENTS&&not fitxer.eof())
    {
        p.llegir_paraula(fitxer);
        registre.implementar_paraula_dins_registre(p);
    }
}

int main()
{
    cout << "ENTRA EL NOM DEL FITXER:" << endl;
    string nom_fitxer; cin>>nom_fitxer;
    ifstream fitxer(nom_fitxer.c_str());
    Vector_paraules registre;

    if(fitxer.fail())cout<< "NO S'HA TROBAT EL FITXER"<<endl;
    else emplenar_taula(fitxer,registre);

    cout<< "RECOMPTE DE LES PARAULES:"<<endl;
    registre.mostrar_paraula_per_llindar();

    int recompte=registre.consultar_paraules_totals();
    cout<<"HI HA "<<recompte<<" PARAULES DIFERENTS";
    return 0;
}
