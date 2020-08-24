#include <iostream>
#include "Data.h"

using namespace std;

int main()
{
    Data d1,d2;
    cout << "ENTRA LA DATA ACTUAL:" << endl;
    d1.llegir();
    cout<< "ENTRA LA DATA DE NAIXEMENT:"<<endl;
    d2.llegir();
    if(d1.es_aniversari(d2))cout<< "AVUI ES L'ANIVERSARI! FA "<<d1.calcul_edat(d2)<<" ANYS"<<endl;
    else if(d1.anys_complerts(d2))cout<< "TE "<<d1.calcul_edat(d2)<< " ANYS"<<endl;
    else cout<< "TE "<<d1.calcul_edat(d2)-1<< " ANYS"<<endl;
    return 0;
}
