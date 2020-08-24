#include "Punt2D.h"
#include<iostream>
using namespace std;

Punt2D::Punt2D()
{
    a_x=0;
    a_y=0;
}
Punt2D::Punt2D(double x,double y)
{
    a_x=x;
    a_y=y;
}
void Punt2D::llegir()
{
    double x,y;
    cin>>x>>y;
    a_x=x;a_y=y;
}
void Punt2D::mostrar()const
{
    cout<<"("<<a_x<<", "<<a_y<<")"<<endl;
}
Punt2D Punt2D::calcul_punt_mig(const Punt2D&p)
{
    double x=(p.a_x-a_x)/2;
    double y=(p.a_y-a_y)/2;
    x+=a_x;y+=a_y;
    Punt2D aux(x,y);
    return aux;
}
void Punt2D::actualitzar_origen(Punt2D& punt_mig,double base,double altura)
{
    double x=punt_mig.a_x,y=punt_mig.a_y;
    base/=2;altura/=2;
    x-=base;y-=altura;
    a_x=x;a_y=y;
}
void Punt2D::desplasar(const Punt2D&p)
{
    double x=a_x,y=a_y;
    x+=p.a_x;y+=p.a_y;
    a_x=x;a_y=y;
}
Punt2D Punt2D::suma(double a,double b)
{
    double x=a_x,y=a_y;
    x+=a;y+=b;
    Punt2D p(x,y);
    return p;
}
Punt2D Punt2D::calcul_centre(const Punt2D&p)
{
    double x=a_x+p.a_x/2;
    double y=a_y+p.a_y/2;
    Punt2D aux(x,y);
    return aux;
}
