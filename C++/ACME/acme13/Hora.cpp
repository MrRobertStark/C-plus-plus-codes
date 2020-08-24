#include "Hora.h"

Hora::Hora()
//Pre:cert//Post:S'inicialitzen les variables a l'hora 00:00
{
    a_hora=0;
    a_minut=0;
}
Hora::Hora(int hora,int minut)
//Pre:hora>=0 && hora<24 && minut>=0 && minut<60
{
    a_hora=hora;
    a_minut=minut;
}
void Hora::mostrar_hora()const
//Pre:l'hora ha de ser correcte//Post:Es mostra l'hora desada a l'objecte actual
{
    if(a_hora<10)cout<<0;
    cout<<a_hora<<":";
    if(a_minut<10)cout<<0;
    cout<<a_minut;
}
void Hora::mostrar_marge_temps(const Hora&h)const
//Pre:les hores han de ser correctes.//Post:es mostren les dues hores per ordre
{
    (*this).mostrar_hora();cout<<" - ";
    h.mostrar_hora();
}
bool Hora::operator==(const Hora&h)const
//pre:les hores han de ser correctes//post:indica si les dues hores són iguals
{
    return (a_hora==h.a_hora&&a_minut==h.a_minut);
}
bool Hora::operator!=(const Hora&h)const
//pre:les hores han de ser correctes//post:indica si les dues hores són diferents
{
    return !(a_hora==h.a_hora&&a_minut==h.a_minut);
}
bool Hora::operator>(const Hora&h)const
//pre:les hores han de ser correctes//post:indica si l'hora actual és superior a l'entrat
{
    return ((a_hora>h.a_hora)or(a_hora==h.a_hora&&a_minut>h.a_minut));
}
bool Hora::operator<(const Hora&h)const
//pre:les hores han de ser correctes//post:indica si l'hora actual és inferior a l'entrat
{
    return !((a_hora>h.a_hora)or(a_hora==h.a_hora&&a_minut>h.a_minut));
}
