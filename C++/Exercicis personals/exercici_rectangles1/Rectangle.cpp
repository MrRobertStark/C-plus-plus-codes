#include "Rectangle.h"
#include "Punt2D.h"
#include<iostream>
using namespace std;

Rectangle::Rectangle()
{
    a_base=1;
    a_altura=1;
}
void Rectangle::llegir()
{
    cout<<"Entra components (x,y) del vèrtex inferior esquerre, separades per un espai: ";
    Punt2D aux_origen;
    double base,altura;
    aux_origen.llegir();
    cout<<"Entra base i altura, separades per un espai: ";
    do{
        cin>>base;
        cin>>altura;
    }while(base*altura<0);
    a_origen=aux_origen;
    a_base=base;
    a_altura=altura;
}
void Rectangle::producte_amb_escalar(char format)
{
    double base=a_base,altura=a_altura,relacio,x=base,y=altura;
    if(format=='c')
    {
        relacio=0.5;
        base*=relacio;altura*=relacio;
        Punt2D p(x,y);
        Punt2D punt_mig=a_origen.calcul_centre(p);
        a_origen.actualitzar_origen(punt_mig,base,altura);
    }
    else
    {
        relacio=2;
        base*=relacio;altura*=relacio;
    }
    a_base=base;a_altura=altura;
}
void Rectangle::desplasament()
{
    Punt2D p(1,1);
    a_origen.desplasar(p);
}
double Rectangle::calcul_perimtre()const
{
    return(a_base*2+a_altura*2);
}
void Rectangle::mostrar()const
{
    Punt2D v1,v2,v3,v4;
    v1=a_origen;
    v2=v1.suma(a_base,0);
    v3=v1.suma(a_base,a_altura);
    v4=v1.suma(0,a_altura);
    cout<< "Origen: ";v1.mostrar();
    cout<<"Base: "<<a_base<<", Altura: "<<a_altura<<endl;
    cout<<"Vèrtexs:"<<endl;
    v1.mostrar();
    v4.mostrar();
    v3.mostrar();
    v2.mostrar();
    cout<<endl;
}
Rectangle Rectangle::rectangle_mig(const Rectangle&r2)
{
    Rectangle r3;
    Punt2D punt_mig=a_origen.calcul_punt_mig(r2.a_origen);
    r3.a_origen=punt_mig;
    if(a_base*a_altura<r2.a_base*r2.a_altura)
    {
        r3.a_base=a_base;
        r3.a_altura=a_altura;
    }
    else
    {
        r3.a_base=r2.a_base;
        r3.a_altura=r2.a_altura;
    }
    return r3;
}
