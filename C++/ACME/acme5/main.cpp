#include <iostream>
#include "Esdeveniment.h"
#include "Data.h"
#include "Hora.h"

using namespace std;

const char EOS='N';

int main()
{
    Esdeveniment e1,e2;
    char ordre;
    int n=1;
    cout << "ENTRA ELS ESDEVENIMENTS:" << endl;
    e1.llegir();
    cout<< "VOLS ENTRAR UN ALTRE ESDEVENIMENT? (S/N):"<<endl;
    cin>>ordre;
    while(ordre!=EOS)
    {
        e2.llegir();
        if(e1.es_mes_llarg(e2))e1=e2;
        n++;
        cout<< "VOLS ENTRAR UN ALTRE ESDEVENIMENT? (S/N):"<<endl;
        cin>>ordre;
    }
    cout<< "HAS ENTRAT "<<n<<" ESDEVENIMENTS"<<endl;
    cout<< "L'ESDEVENIMENT MES LLARG ES:"<<endl;
    e1.mostrar_esdeveniment();
    return 0;
}
