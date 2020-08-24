#include "Hora.h"

Hora::Hora()
//Pre:
//Post:
{
    a_hora=0;
    a_minut=0;
}
Hora::Hora(int hora,int minut)
//Pre:
//Post:
{
    if(es_hora_valida(hora,minut))
    {
        a_hora=hora;a_minut=minut;
    }
    else
    {
        a_hora=0;
        a_minut=0;
    }
}
Hora Hora::consultar_hora()const
{
    return Hora(a_hora,a_minut);
}
int Hora::durada(const Hora&h2)const
//Pre:
//Post:
{
    int hores=abs(h2.a_hora-a_hora);hores*=MAX_MINUTS;
    int minuts=(h2.a_minut-a_minut);
    return (hores+minuts);
}
void Hora::llegir()
//Pre:
//Post:
{
    int hora,minut,format;
    do{
        cin>>format;
        hora=format/100;
        minut=format%100;
    }while(not es_hora_valida(hora,minut));

    a_hora=hora;
    a_minut=minut;
}
bool Hora::operator==(const Hora&h)const
//Pre:
//Post:
{
    return (a_hora==h.a_hora&&a_minut==h.a_minut);
}
bool Hora::operator<(const Hora&h)const
//Pre:
//Post:
{
    return (a_hora<h.a_hora or (a_hora==h.a_hora&&a_minut<h.a_minut));
}
bool Hora::operator>(const Hora&h)const
//Pre:
//Post:
{
    return !(a_hora<h.a_hora or (a_hora==h.a_hora&&a_minut<h.a_minut));
}
bool Hora::es_hora_valida(int hora,int minut)
{
    return (hora<MAX_HORES && minut<MAX_MINUTS);
}
