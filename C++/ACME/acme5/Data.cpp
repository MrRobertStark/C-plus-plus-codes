#include "Data.h"
using namespace std;

const int Data::DIES_MES[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Data::Data()
{
    a_dia=1;
    a_mes=1;
    a_any=2001;
}
void Data::llegir()
{
    int dia,mes,any,nombre;
    do{
        cin>>nombre;
        dia=nombre%100;nombre/=100;
        mes=nombre%100;nombre/=100;
        any=nombre;
    }while(not es_data_valida(dia,mes,any));
    a_dia=dia;
    a_mes=mes;
    a_any=any;
}
bool Data::es_data_valida(int dia,int mes,int any)
{
    bool correcte=true;
    bool es_de_traspas = (any % 4 == 0) and (any % 100 != 0 or any % 400 == 0);
    if(any>3999 or any<1600 or mes>MESOS_ANY or mes<1 or dia<1)correcte=false;
    else
    {
        int dies_mes;
        if(es_de_traspas and mes==2)dies_mes=29;
        else dies_mes=DIES_MES[mes];
        if(dies_mes<dia)correcte=false;
    }
    return correcte;
}
void Data::mostrar()const
{
    int dia,mes,any;
    dia=mostrar_dia();mes=mostrar_mes();any=mostrar_any();
    cout<<dia<<"/"<<mes<<"/"<<any;
}
int Data::mostrar_dia()const
{
    return a_dia;
}
int Data::mostrar_mes()const
{
    return a_mes;
}
int Data::mostrar_any()const
{
    return a_any;
}
bool Data::es_menor(const Data&d)const
{
   return (a_any < d.a_any) or
    (a_any == d.a_any and a_mes < d.a_mes) or
    (a_any == d.a_any and a_mes == d.a_mes and a_dia < d.a_dia);
}
