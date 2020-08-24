#include "Canco.h"
#include "TaulaCancons.h"
#include<iostream>
#include<limits>
#include<fstream>
#include "Durada.h"

using namespace std;

const string ERROR_OBERTURA="NO S'HA POGUT OBRIR L'ARXIU";
const string ACOMIAT= "A REVEURE...!";
const int NO_TROBAT=-1;

Canco llegir_canco(ifstream&fitxer)
{
    int any,reproduccions,segons,uid;
    string titol,artista,genere,anim,codi;

    fitxer>>uid;
    fitxer.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(fitxer,titol);getline(fitxer,artista);
    fitxer>>any>>segons>>genere>>anim>>codi>>reproduccions;
    Canco c=Canco(Durada(segons),uid,any,reproduccions,titol,artista,genere,anim,codi);
    uid++;
    return c;
}

void llegir_fitxer(TaulaCancons&taula,ifstream&fitxer)
//pre:fitxer obert//post:es llegeix el fitxer i es desa la seva informació a la taula
{
    string missatge;int enter;
    getline(fitxer,missatge);fitxer>>missatge;fitxer>>enter;

    for(int i=0;i<enter;i++){Canco c=llegir_canco(fitxer);taula.afegir_canco(c);}
}
void afegir_canco(TaulaCancons&taula)
//Pre:cert//post:s'afegeix una nova canco a la taula si no hi era abans
{
    char signe_minuts= '"';
    string titol,artista;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<< "TITOL:"<<endl;getline(cin,titol);
    cout<< "ARTISTA:"<<endl;getline(cin,artista);

    int pos=taula.buscar_pos_preexistencia(Canco(Durada(0),0,0,0,titol,artista));
    if(pos==NO_TROBAT)
    {
        int any,minuts,segons;
        Durada duracio;Canco c;
        string genere,anim,codi;

        cout<< "ANY:"<<endl;cin>>any;
        cout<< "DURADA [' "<<signe_minuts<<"]:"<<endl;cin>>minuts>>segons;duracio=Durada(segons,minuts);
        cout<< "GENERE:"<<endl;cin>>genere;
        cout<< "ESTAT D'ANIM:"<<endl;cin>>anim;
        cout<< "YOUTUBE:"<<endl;cin>>codi;

        c=Canco(duracio,0,any,0,titol,artista,genere,anim,codi);taula.inserir_i_incrementar_uid(c);
        taula.afegir_canco(c);
    }
    else cout<< "[ATENCIO] LA CANCO JA HI ES"<<endl;
}
void mostrar_taula(const TaulaCancons&taula)
//pre:taula.a_n_elements>0//post:es mostren tots els elements de la taula
{
    taula.mostrar_cancons();
}
void desar_taula(const TaulaCancons&taula)
//pre:cert//post:es desa la taula a un fitxer extern
{
    ofstream checkpoint("b.dat");
    taula.desar(checkpoint);
}
void mostrar_comandes()
//pre:cert//post:es mostren les comandes programmades
{
    cout<< "a/add AFEGIR_ELEMENT"<<endl;
    cout<< "b/mostrar MOSTRAR TAULA"<<endl;
    cout<< "x/save DESAR LA TAULA"<<endl;
    cout<< "y/help MOSTRAR LES COMANDES"<<endl;
    cout<< "z/quit SORTIR DEL PROGRAMA"<<endl;
}
void execucio_programa(TaulaCancons&taula)
//pre:taula.a_n_elements>0//post:s'executen una serie de comandes entrades per teclat
{
    string comanda;
    cout<< "OPCIO:"<<endl;
    cin>>comanda;

    while(comanda!="quit" && comanda!="z")
    {
        if(comanda=="a" or comanda== "add")afegir_canco(taula);
        else if(comanda== "b" or comanda== "mostrar")mostrar_taula(taula);
        else if(comanda== "x" or comanda== "save")desar_taula(taula);
        else if(comanda== "y" or comanda== "help")mostrar_comandes();

        cout<<endl<<"OPCIO:"<<endl;
        cin>>comanda;
    }
}

int main()
{
    TaulaCancons taula;
    Canco c;

    string nom_fitxer_entrada;
    cout<<"FITXER:"<<endl;
    cin>>nom_fitxer_entrada;
    ifstream fitxer_entrada(nom_fitxer_entrada.c_str());

    if(not fitxer_entrada.fail())
    {
        llegir_fitxer(taula,fitxer_entrada);
        execucio_programa(taula);
    }
    else cout<<ERROR_OBERTURA<<endl;
    cout<<ACOMIAT<<endl;
    return 0;
}
