#include "Durada.h"

Durada::Durada()
{
    a_duracio=0;
}
Durada::Durada(int segons,int minuts,int hores,int dies)
{
    a_duracio=(segons+minuts*MAX_SEGONS+hores*MAX_MINUTS*MAX_SEGONS+dies*MAX_HORES*MAX_MINUTS*MAX_SEGONS);
}
int Durada::consultar_duracio()const
{
    return a_duracio;
}
void Durada::mostrar_duracio()const
{
    int segons=a_duracio,minuts=0,hores=0,dies=0;
    conversio_convencional(segons,minuts,hores,dies);
    char signe_segons='"';

    if(dies!=0)cout<<dies<<"d ";
    if(hores!=0)cout<<hores<<"h ";
    if(minuts!=0)cout<<minuts<<"' ";
    cout<<segons<<signe_segons;
}
void Durada::llegir_duracio()
{
    cin>>a_duracio;
}
void Durada::conversio_convencional(int&segons,int&minuts,int&hores,int&dies)const
{
    while(segons>=MAX_SEGONS){segons-=MAX_SEGONS;minuts++;}
    while(minuts>=MAX_MINUTS){minuts-=MAX_MINUTS;hores++;}
    while(hores>=MAX_HORES){hores-=MAX_HORES;dies++;}
}
Durada Durada::operator+(const Durada&d)const
{
    return Durada(a_duracio+d.a_duracio);
}
Durada Durada::operator-(const Durada&d)const
{
    return Durada(a_duracio-d.a_duracio);
}
bool Durada::operator<(const Durada&d)const
{
    return (a_duracio<d.a_duracio);
}
bool Durada::operator>(const Durada&d)const
{
    return !(a_duracio<d.a_duracio);
}
bool Durada::operator==(const Durada&d)const
{
    return (a_duracio==d.a_duracio);
}
bool Durada::operator!=(const Durada&d)const
{
    return !(a_duracio==d.a_duracio);
}
bool Durada::operator>=(const Durada&d)const
{
    return (a_duracio>=d.a_duracio);
}
bool Durada::operator<=(const Durada&d)const
{
    return (a_duracio<=d.a_duracio);
}
