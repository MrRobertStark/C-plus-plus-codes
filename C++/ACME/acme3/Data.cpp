#include "Data.h"
#include <string>
#include<iostream>
using namespace std;

// CONSTANTS DE CLASSE
const int Data::DIES_MES[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string Data::NOM_MES[] = {"CAP", "GENER", "FEBRER", "MARC", "ABRIL", "MAIG", "JUNY", "JULIOL", "AGOST", "SETEMBRE", "OCTUBRE", "NOVEMBRE", "DESEMBRE"};

Data::Data()
{
    a_dia=1;
    a_mes=1;
    a_any=2001;
}
void Data::llegir(int format)
//pre
//post
{
    int dia,mes,any;
    do{
        if(format==1)
        {
            cin>>any;
            dia=any%100;
            any=any/100;
            mes=any%100;
            any/=100;
        }
        else cin>>dia>>mes>>any;
    }while(not es_data_valida(dia,mes,any));

    a_any=any;
    a_mes=mes;
    a_dia=dia;
}
bool Data::es_data_valida(int d,int m,int a)
//pre
//post
{
    bool correcte=true;
    bool es_de_traspas=esDeTraspas(a);
    if(a>3999 or a<1600 or m>MESOS_ANY or m<1 or d<1)correcte=false;
    else{
        int dies_mes;
        if(es_de_traspas && m==2)dies_mes=29;
        else dies_mes=DIES_MES[m];
        if(d>dies_mes)correcte=false;
    }
    return correcte;
}
bool Data::esDeTraspas(int any)
//pre
//post
{
    return ((any%4==0)and(any%100!=0 or any%400==0));
}
bool Data::es_menor(const Data&d)
//pre
//post
{
    bool menor=false;
    if(a_any<d.a_any)menor=true;
    else if(a_any==d.a_any&&a_mes<d.a_mes)menor=true;
    else if(a_any==d.a_any&&a_mes==d.a_mes)menor=(a_dia<d.a_dia);
    return menor;
}
void Data::mostrar(int format)const
//pre
//post
{
    if(format==3)cout<<a_dia<<"/"<<a_mes<<"/"<<a_any<<endl;
    else cout<<a_dia<<"-"<<NOM_MES[a_mes]<<"-"<<a_any<<endl;
}
bool Data::es_igual(const Data&d)const
//pre
//post
{
    return (a_dia==d.a_dia&&a_mes==d.a_mes&&a_any==d.a_any);
}
