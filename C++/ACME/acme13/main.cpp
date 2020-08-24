#include <iostream>

#include "AgendaDinamica.h"
#include "Hora.h"
#include "Data.h"
#include "Esdeveniment.h"
#include <string>

#include<limits>

using namespace std;

void emplenar_informacio(Hora&inici,Hora&fin,Data&data,string&descripcio,int&codi)
//Pre:cert//Post:S'emplenen les dades necessàries per omplir un esdeveniment de l'agenda
{
    cout<<"ESDEVENIMENT PER INSERIR: "<<endl;
    cout<<"CODI:"<<endl;cin>>codi;

    cout<<"DESCRIPCIO:"<<endl;cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,descripcio);

    cout<<"DIA:"<<endl;int format;cin>>format;
    int dia,mes,any;
    dia=format%100;format/=100;
    mes=format%100;format/=100;
    any=format;data=Data(dia,mes,any);

    cout<<"HORA INICI:"<<endl;cin>>format;
    inici=Hora(format/100,format%100);

    cout<<"HORA FINAL:"<<endl;cin>>format;
    fin=Hora(format/100,format%100);
}

void mostrar_comandes()
//pre:cert//post:es mostren les comandes disponibles
{
    cout<<"OPCIONS:"<<endl;
    cout<<"1: INSERIR ESDEVENIMENT"<<endl;
    cout<<"2: ELIMINAR ESDEVENIMENT"<<endl;
    cout<<"3: MOSTRAR AGENDA"<<endl;
    cout<<"9: MOSTRAR EL MENU D'OPCIONS"<<endl;
    cout<<"0: SORTIR DEL PROGRAMA"<<endl;
}
void inserir_esdeveniment(AgendaDinamica&llista)
{
    Hora inici,fin;Data dia;
    string descripcio;int codi;

    emplenar_informacio(inici,fin,dia,descripcio,codi);
    Esdeveniment esdv(inici,fin,dia,descripcio,codi);
    llista.inserir(esdv);
}
void eliminar_esdeveniment(AgendaDinamica&llista)
{
    llista.treure();
}
void mostrar_agenda(const AgendaDinamica&llista)
{
    llista.mostrar_agenda();
}
int main()
{
    int comanda=9; AgendaDinamica llista;
    while(comanda!=0)
    {
        if(comanda==1)inserir_esdeveniment(llista);
        else if(comanda==2)eliminar_esdeveniment(llista);
        else if(comanda==3)mostrar_agenda(llista);
        else if(comanda==9)mostrar_comandes();
        cout<<endl;
        cout<<"OPCIO:"<<endl;
        cin>>comanda;
    }
    cout<<"FINAL DEL PROGRAMA";
    return 0;
}
