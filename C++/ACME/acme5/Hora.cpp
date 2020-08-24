#include "Hora.h"

Hora::Hora()
{
    a_hora=0;
    a_minut=0;
}
void Hora::llegir()
{
    int hora,minut,lectura;
    do{
        cin>>lectura;
        minut=lectura%100;
        hora=lectura/100;
    }while(not es_hora_valida(hora,minut));
    a_hora=hora;
    a_minut=minut;
}
bool Hora::es_hora_valida(int hora,int minut)
{
    return(hora>=0&&hora<=MAX_HORA&&minut>=0&&minut<MAX_MINUT);
}
bool Hora::es_menor(const Hora&h)const
{
    return (a_hora < h.a_hora) or (a_hora == h.a_hora and a_minut < h.a_minut);
}
int Hora::duracio(const Hora&h)const
{
    return (h.a_hora*60+h.a_minut)-(a_hora*60+a_minut);
}
int Hora::mostrar_hora()const
{
    return a_hora;
}
int Hora::mostrar_minut()const
{
    return a_minut;
}
void Hora::mostrar()const
{
    if(a_hora<10)cout<<"0";
    cout<<a_hora<<":";
    if(a_minut<10)cout<<"0";
    cout<<a_minut;
}
