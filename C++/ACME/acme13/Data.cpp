#include "Data.h"

Data::Data()
//Pre:s'inicialitzen les variables a la data 1/1/2001
{
    a_dia=1;
    a_mes=1;
    a_any=2001;
}
Data::Data(int dia,int mes,int any)
//Pre:la data ha de ser correcte//Post:s'inicialitza l'objecte actual segons les dades entrades per teclat
{
    a_dia=dia;
    a_mes=mes;
    a_any=any;
}
void Data::mostrar_data()const
//Pre:les dades de la data han de ser vàlides//Post:es mostra la data desada a l'objecte actual
{
    cout<<a_dia<<"/"<<a_mes<<"/"<<a_any<<", ";
}

bool Data::operator==(const Data&d)const
//pre:les dades de la data han de ser correctes//post:retorna cert si les dates són iguals
{
    return (a_dia==d.a_dia&&a_mes==d.a_mes&&a_any==d.a_any);
}
bool Data::operator!=(const Data&d)const
//pre:les dades de la data han de ser correctes//post:retorna cert si les dates són diferents
{
    return !(a_dia==d.a_dia&&a_mes==d.a_mes&&a_any==d.a_any);
}
bool Data::operator>(const Data&d)const
//pre:les dades de la data han de ser correctes//post:retorna cert si la data actual és superior a l'entrat
{
    return ((a_any>d.a_any) or
            (a_any==d.a_any&&a_mes>d.a_mes) or
            (a_any==d.a_any&&a_mes==d.a_mes&&a_dia>d.a_dia));
}
bool Data::operator<(const Data&d)const
//pre:les dades de la data han de ser correctes//post:retorna cert si la data actual és inferior a l'entrat
{
    return !((a_any>d.a_any) or
            (a_any==d.a_any&&a_mes>d.a_mes) or
            (a_any==d.a_any&&a_mes==d.a_mes&&a_dia>d.a_dia));
}





