#include <iostream>
#include "TaulaCancons.h"
#include "Canco.h"
#include "Durada.h"
#include <fstream>
#include <limits>

using namespace std;

void lectura_fitxer(ifstream&fitxer,TaulaCancons&t)
//Pre:fitxer obert//post:es llegeixen les cancons trobades al fitxer
{
    string missatge;int nombre;Canco c;
    getline(fitxer,missatge);fitxer>>missatge;fitxer>>nombre;
    t.actualitzar_maxim_uid(nombre);

    for(int i=0;i<nombre;i++)
    {
        c.lectura_fitxer(fitxer);
        t.inserir_per_criteri(c);
    }
}
void mostrar_comandes()
//pre:cert//post:es mostren les comandes programmades
{
    cout<< "a/add: AFEGIR CANCO"<<endl;
    cout<< "b/break: MAXIM CANCONS DISPONIBLES EN UN TEMPS DETERMINAT"<<endl;
    cout<< "c a/show songs: ES MOSTREN LES CANCONS PER TITOL-ARTISTA"<<endl;
    cout<< "c b/show genre: ES MOSTREN LES CANCONS PER GENERE"<<endl;
    cout<< "x/save: ES DESEN LES CANCONS EN UN FITXER"<<endl;
    cout<< "y/help: ES MOSTREN LES COMANDES PROGRAMADES"<<endl;
    cout<< "z/quit: S'ACABA EL PROGRAMA"<<endl;
}
void afegir_canco(TaulaCancons&t)
//pre:cert//post:s'afegeix una canco
{
    string titol,artista;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout<< "TITOL:"<<endl;getline(cin,titol);
    cout<< "ARTISTA:"<<endl;getline(cin,artista);

    Canco c=Canco(Durada(0),0,0,0,titol,artista);
    if(not t.buscar_preexistencia(c))
    {
        char signe_segons='"';int any,segons,minuts,uid;
        string genere,anim,codi;

        cout<< "ANY:"<<endl;cin>>any;
        cout<< "DURADA [' "<<signe_segons<<"]:"<<endl;cin>>minuts>>segons;
        cout<< "GENERE:"<<endl;cin>>genere;
        cout<< "ESTAT D'ANIM:"<<endl;cin>>anim;
        cout<< "YOUTUBE:"<<endl;cin>>codi;
        uid=t.solicitar_maxim_uid()+1;t.actualitzar_maxim_uid(uid);

        c=Canco(Durada(segons,minuts),uid,any,0,titol,artista,genere,anim,codi);
        t.inserir_per_criteri(c);
    }
    else cout<< "[ATENCIO] LA CANCO JA HI ES"<<endl;
}
void taula_duracio(const TaulaCancons&t)
//pre:cert//post:es mostren les cancons disponibles en un temps indicat
{
    int duracio;cin>>duracio; Durada d=Durada(0,duracio);
    TaulaCancons aux;

    for(int i=0;i<t.solicitar_n_elements();i++)aux.inserir_per_criteri(t.solicitar_canco(i),"break");
    aux.mostrar_cancons_limit_temps(d);
}
void mostrar_taula(const TaulaCancons&t)
//pre:cert//post:es mostren les cancons desades a la taula
{
    string criteri;cin>>criteri;

    if(criteri=="songs" or criteri=="a")t.mostrar_taula();
    else if(criteri=="genre" or criteri=="b")
    {
        TaulaCancons aux;
        for(int i=0;i<t.solicitar_n_elements();i++)aux.inserir_per_criteri(t.solicitar_canco(i),"genre");
        aux.mostrar_taula();
    }
}
void desar_taula(const TaulaCancons&t)
//Pre:cert//post:es desa la taula al fitxer indicat
{
    t.backup();
}
void execucio_comandes(TaulaCancons&t)
//pre:cert//post:s'executen una serie de comandes entrades per teclat
{
    string comanda;cout<<"OPCIO:"<<endl;cin>>comanda;

    while(comanda!="z"&&comanda!="quit")
    {
        if(comanda=="a" or comanda== "add")afegir_canco(t);
        else if(comanda=="b" or comanda== "break")taula_duracio(t);
        else if(comanda=="c" or comanda== "show")mostrar_taula(t);
        else if(comanda=="x" or comanda== "save")desar_taula(t);
        else if(comanda=="y" or comanda== "help")mostrar_comandes();
        cout<<endl<<"OPCIO:"<<endl;cin>>comanda;
    }
}

int main()
{
    cout<< "FITXER:"<<endl;string nom_fitxer;TaulaCancons t;
    cin>>nom_fitxer;ifstream fitxer(nom_fitxer.c_str());

    if(not fitxer.fail())
    {
        lectura_fitxer(fitxer,t);
        execucio_comandes(t);
    }
    else cout<< "NO S'HA POGUT OBRIR L'ARXIU"<<endl;
    cout<<"A REVEURE...!"<<endl;
    return 0;
}
