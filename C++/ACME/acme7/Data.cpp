#include "Data.h"

const int Data::DIES_MES[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Data::Data()
//Pre:
//Post:
{
    a_dia=1;
    a_mes=1;
    a_any=2001;
}
Data::Data(int dia,int mes,int any)
//Pre:
//Post:
{
    if(es_data_valida(dia,mes,any))
    {
        a_dia=dia;
        a_mes=mes;
        a_any=any;
    }
    else
    {
        a_dia=1;
        a_mes=1;
        a_any=2001;
    }
}
void Data::mostrar_data()const
{
    cout<<a_dia<<"/"<<a_mes<<"/"<<a_any;
}
void Data::llegir_data()
{
    int dia,mes,any,format;
    do{
        cin>>format;
        dia=format%100;format/=100;
        mes=format%100;format/=100;
        any=format;
    }while(not es_data_valida(dia,mes,any));

    a_dia=dia;
    a_mes=mes;
    a_any=any;
}
bool Data::operator==(const Data&d)const
{
    return (a_dia==d.a_dia&&a_mes==d.a_mes&&a_any==d.a_any);
}
bool Data::operator!=(const Data&d)const
{
    return !(a_dia==d.a_dia&&a_mes==d.a_mes&&a_any==d.a_any);
}
bool Data::operator<(const Data&d)const
{
    return (a_any<d.a_any or (a_any==d.a_any&&a_mes<d.a_mes)or(a_any==d.a_any&&a_mes==d.a_mes&&a_dia<d.a_dia));
}
bool Data::es_data_valida(int dia,int mes,int any)
{
    bool correcte=true;
    bool es_de_trespas=(any%400==0) and (any%100!=0 or any%400==0);
    if(any>3999 or any<1600 or mes>MAX_MESOS or mes<1 or dia<1)correcte=false;
    else
    {
        int dies_mes;
        if(es_de_trespas&&mes==2)dies_mes=29;
        else dies_mes=DIES_MES[mes];

        if(dia>dies_mes)correcte=false;
    }
    return correcte;
}
