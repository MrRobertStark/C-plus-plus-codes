#include "Punt3D.h"
#include<iostream>
using namespace std;
Punt3D::Punt3D()
{
    a_x=0;
    a_y=0;
    a_z=0;
}
void Punt3D::llegir()
//pre
//post
{
    cout<< "ENTRAR COMPONENT X:"<<endl;
    cin>>a_x;
    cout<< "ENTRAR COMPONENT Y:"<<endl;
    cin>>a_y;
    cout<< "ENTRAR COMPONENT Z:"<<endl;
    cin>>a_z;
}
void Punt3D::sumar()
//pre
//post
{
    Punt3D p;p.llegir();
    a_x+=p.a_x;
    a_y+=p.a_y;
    a_z+=p.a_z;
}
void Punt3D::restar()
//pre
//post
{
    Punt3D p;p.llegir();
    a_x-=p.a_x;
    a_y-=p.a_y;
    a_z-=p.a_z;
}
void Punt3D::multiplicacio_real()
//pre
//post
{
    cout<< "ENTRAR UN VALOR REAL:"<<endl;
    double k;cin>>k;
    a_x*=k;
    a_y*=k;
    a_z*=k;
}
void Punt3D::producte_vectorial()
//pre
//post
{
    Punt3D p;p.llegir();
    double x,y,z;
    x=a_y*p.a_z-a_z*p.a_y;
    y=a_z*p.a_x-a_x*p.a_z;
    z=a_x*p.a_y-a_y*p.a_x;
    a_x=x;a_y=y;a_z=z;
}
void Punt3D::mostrar(int&comptador)const
//pre
//post
{
    if(a_z>0)comptador++;
    cout<<"RESULTAT: "<<"("<<a_x<<", "<<a_y<<", "<<a_z<<")"<<endl;
}
