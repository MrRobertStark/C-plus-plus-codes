#include "Data.h"
#include<iostream>
using namespace std;

//CONSTANTS DE CLASSE
const int Data::DIES_MES[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string Data::NOM_MES[]= {"CAP", "GENER", "FEBRER", "MARC", "ABRIL", "MAIG", "JUNY", "JULIOL", "AGOST", "SETEMBRE", "OCTUBRE", "NOVEMBRE", "DESEMBRE"};
//CONSTRUCTORS
Data::Data()
//pre
//post
{
    a_dia=1;
    a_mes=1;
    a_any=2001;
}
//CONSTRUCTORS AMB PARAMETRES
Data::Data(int d,int m,int a)
//pre
//post
{
    if(es_data_valida(d,m,a)){
        a_dia=d;
        a_mes=m;
        a_any=a;
    }
    else{
        a_dia=1;
        a_mes=1;
        a_any=2001;
    }
}
//CONSULTORS
void Data::mostrar()const{
//pre
//post
    cout<<a_dia<<"/"<<a_mes<<"/"<<a_any<<endl;
}
bool Data::es_menor(const Data&d)const{
//pre
//post
    bool veritat;
    veritat=(a_any<d.a_any);
    veritat=(a_any<d.a_any&&a_mes<d.a_mes);
    veritat=(a_any<d.a_any&&a_mes<d.a_mes&&a_dia<d.a_dia);
    return veritat;
}
//MODIFICADOR
void Data::llegir()
//pre
//post
{
    int nombre;
    int d,m,a;
    cin>>nombre;
    d=nombre%100;nombre/=100;
    m=nombre%100;nombre/=100;
    a=nombre;
    while(not es_data_valida(d,m,a)){
        cin>>nombre;
        d=nombre%100;nombre/=100;
        m=nombre%100;nombre/=100;
        a=nombre;
    }
    a_dia=d;a_mes=m;a_any=a;
}
bool Data::es_data_valida(int d,int m,int a)
//pre
//post
{
    bool correcte=true;
    bool es_de_trespas=(a%4==0)and((a%100!=0)or(a%400==0));
    if(a>3999 or a<1600 or m>MESOS_ANY or m<1 or d<1)correcte=false;
    else {
        int dies_mes;
        if(es_de_trespas and m==2)dies_mes=29;
        else dies_mes=DIES_MES[m];
        if(d>dies_mes)correcte=false;
    }
    return correcte;
}
bool Data::es_aniversari(Data data_actual)
//pre
//post
{
    return (a_dia==data_actual.a_dia&&a_mes==data_actual.a_mes);
}
bool Data::anys_complerts(const Data&data_actual)
//pre
//post
{
    return (a_mes>=data_actual.a_mes&&a_any>=data_actual.a_any);
}
int Data::calcul_edat(const Data&data_actual)
//pre
//post
{
    return a_any-data_actual.a_any;
}
