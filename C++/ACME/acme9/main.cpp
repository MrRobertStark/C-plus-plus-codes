#include <iostream>
#include "Gloria.h"

using namespace std;

const char EOP='s';

int main()
{
    Gloria registre; char comanda;
    cout<< "REGISTRES TEMPORAL GLORIA"<<endl;cout<<endl;

    cout<< "Opcio [a/m/c/r/s]:"<<endl;
    cin>>comanda;
    while(comanda!=EOP)
    {
        if(comanda=='a')registre.actualitzar();
        else if(comanda=='m')registre.mostrar_tots_els_informes();
        else if(comanda=='c')registre.mostrar_poblacio_amb_mes_incidencies();
        else if(comanda=='r')registre.mostrar_informes_per_llindar();
        cout<<endl;
        cout<< "Opcio [a/m/c/r/s]:"<<endl;
        cin>>comanda;
    }
    return 0;
}
