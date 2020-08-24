#include "Punt2D.h"

Punt2D::Punt2D()
//Pre: cert
//Post: Es construeix un punt a l'origen
{
    a_x=0;
    a_y=0;
}
Punt2D::Punt2D(double x,double y)
//Pre:cert
//Post:Es construeix un punt segons les coordenades entrades
{
    a_x=x;
    a_y=y;
}
void Punt2D::mostrar()const
//Pre: cert
//Post: es mostren les dades de l'objecte punt
{
    cout<<"("<<a_x<<","<<a_y<<")";
}
void Punt2D::llegir()
//Pre: cet
//Post: es llegeixen i es desen les dades entrades per teclat a l'objecte punt
{
    double x,y;
    cin>>x>>y;
    a_x=x;a_y=y;
}
double Punt2D::dist(const Punt2D& p)
//Pre: cert
//Post: es calcula la distància entre dos punts
{
    Punt2D p1=resta_punt(p);
    return sqrt(p1.a_x*p1.a_x+p1.a_y*p1.a_y);
}
void Punt2D::desplacar(double x,double y)
//Pre: cert
//Post: es desplacen les coordenades de l'objecte les unitats entrades per teclat
{
    a_x+=x;
    a_y+=y;
}
Punt2D Punt2D::resta_punt(const Punt2D&p)
//Pre: cert
//Post: es retorna la resta entre dos punts (com a resultant, un vector)
{
    double x=(p.a_x-a_x);
    double y=(p.a_y-a_y);
    return Punt2D(x,y);
}
