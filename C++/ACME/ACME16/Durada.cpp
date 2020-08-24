#include "Durada.h"

Durada::Durada()
{
    a_duracio=0;
}

Durada::Durada(int segons,int minuts,int hores,int dies)
{
    a_duracio=(segons+minuts*MAX_SEGONS+hores*MAX_SEGONS*MAX_MINUTS+dies*MAX_HORES*MAX_SEGONS*MAX_MINUTS);
}
void Durada::mostrar_durada()const
{
    char signe_segons= '"';
    int segons=a_duracio,minuts=0,hores=0,dies=0;
    canvi_convencional(segons,minuts,hores,dies);

    if(dies!=0)cout<<dies<<"d ";
    if(hores!=0)cout<<hores<<"h ";
    if(minuts!=0)cout<<minuts<<"' ";
    cout<<segons<<signe_segons;
}
int Durada::solicitar_durada()const
{
    return a_duracio;
}
void Durada::backup(ofstream&fitxer)const
{
    char signe_segons= '"';
    int segons=a_duracio,minuts=0,hores=0,dies=0;
    canvi_convencional(segons,minuts,hores,dies);

    if(dies!=0)fitxer<<dies<<"d ";
    if(hores!=0)fitxer<<hores<<"h ";
    if(minuts!=0)fitxer<<"' ";
    fitxer<<segons<<signe_segons;
}
void Durada::canvi_convencional(int&segons,int&minuts,int&hores,int&dies)
{
    while(segons>=MAX_SEGONS){minuts++;segons-=MAX_SEGONS;}
    while(minuts>=MAX_MINUTS){hores++;minuts-=MAX_MINUTS;}
    while(hores>=MAX_HORES){dies++;hores-=MAX_HORES;}
}
