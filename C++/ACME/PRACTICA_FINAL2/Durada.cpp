#include "Durada.h"

Durada::Durada()
{
    a_duracio=0;
}
Durada::Durada(int segons,int minuts,int hores,int dies)
{
    a_duracio=(segons+minuts*MAX_SEGONS+hores*MAX_SEGONS*MAX_MINUTS+dies*MAX_SEGONS*MAX_MINUTS*MAX_HORES);
}
int Durada::solicitar_duracio()const
{
    return a_duracio;
}
void Durada::mostrar_durada()const
{
    int segons=a_duracio,minuts=0,hores=0,dies=0;
    char signe_segons='"';
    canvi_convencional(segons,minuts,hores,dies);

    if(dies!=0)cout<<dies<<"d ";
    if(hores!=0)cout<<hores<<"h ";
    if(minuts!=0)cout<<minuts<<"' ";
    cout<<segons<<signe_segons;
}
void Durada::backup(ofstream&fitxer)const
{
    int segons=a_duracio,minuts=0,hores=0,dies=0;
    char signe_segons='"';
    canvi_convencional(segons,minuts,hores,dies);

    if(dies!=0)fitxer<<dies<<"d ";
    if(hores!=0)fitxer<<hores<<"h ";
    if(minuts!=0)fitxer<<minuts<<"' ";
    fitxer<<segons<<signe_segons;
}
Durada Durada::operator+(const Durada&d)const
{
    return Durada(d.a_duracio+a_duracio);
}
bool Durada::operator==(const Durada&d)const
{
    return (a_duracio==d.a_duracio);
}
bool Durada::operator!=(const Durada&d)const
{
    return !(*this==d);
}
bool Durada::operator<(const Durada&d)const
{
    return a_duracio<d.a_duracio;
}
bool Durada::operator>(const Durada&d)const
{
    return !(*this<d);
}
void Durada::canvi_convencional(int&segons,int&minuts,int&hores,int&dies)
{
    while(segons>=MAX_SEGONS){segons-=MAX_SEGONS;minuts++;}
    while(minuts>=MAX_MINUTS){minuts-=MAX_MINUTS;hores++;}
    while(hores>=MAX_HORES){hores-=MAX_HORES;dies++;}
}
