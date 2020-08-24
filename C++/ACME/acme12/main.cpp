#include <iostream>
#include "Hora.h"
#include "CuaComanda.h"

using namespace std;
//Entrada:
//Sortida:

void mostrar_comandes()
//Pre:
//Post:
{
    cout<<"OPCIONS:"<<endl;
    cout<< "1: ENTRAR UNA COMANDA"<<endl;
    cout<< "2: SERVIR UNA COMANDA "<<endl;
    cout<< "3: MOSTRAR LLISTA DE COMANDES PENDENTS "<<endl;
    cout<< "4: MOSTRAR NOMBRE DE COMANDES PENDENTS "<<endl;
    cout<< "5: MOSTRAR RESUM DE COMANDES SERVIDES"<<endl;
    cout<< "9: MOSTRAR EL MENU D'OPCIONS"<<endl;
    cout<< "0: SORTIR DEL PROGRAMA "<<endl;
}
int main()
{
    cout.setf(ios::fixed);
    cout.precision(1);
    int comanda=9,comandes_pendents=0,comandes_servides=0;
    CuaComanda registre;
    while(comanda!=0)
    {
        if(comanda==9)mostrar_comandes();
        else if(comanda==1)registre.inserir_comanda(comandes_pendents);
        else if(comanda==2)registre.servir_comanda(comandes_servides,comandes_pendents);
        else if(comanda==3)registre.mostrar_comandes();
        else if(comanda==4){cout<<"NOMBRE DE COMANDES PENDENTS:"<<endl;cout<<comandes_pendents<<endl;}
        else if(comanda==5)registre.resum_comandes_servides(comandes_servides);
        cout<<"OPCIO:"<<endl;
        cin>>comanda;
    }
    cout<< "FINAL DEL PROGRAMA";
    return 0;
}
