#include "Fraccions.h"
#include <iostream>
#include <cmath>
using namespace std;

Fraccions::Fraccions()
{
    a_num=1;
    a_denum=1;
}
Fraccions::Fraccions(int num,int denum)
{
    if(denum==0){a_num=1;a_denum=1;}
    else{a_num=num;a_denum=denum;}
}
void Fraccions::mostrar()const
{
    cout<<a_num<<"/"<<a_denum<<endl;
}
int Fraccions::maxim_comu_divisor(int a,int b)
{
    int residu = a % b;
    while (residu != 0) {
        int a = b;
        b = residu;
        residu = a % b;
    }
    return b;
}
int Fraccions::minim_comu_multiple(int a,int b)
{
    int mcd=maxim_comu_divisor(a,b);
    return (a*b/mcd);
}
void Fraccions::dividir(const Fraccions&p,const Fraccions&p1)
{
    int a,b,c,d;
    a=p.a_num;b=p.a_denum;c=p1.a_num;d=p1.a_denum;
    a_num=a*d;
    a_denum=b*c;
}
void Fraccions::multiplicar(const Fraccions&p,const Fraccions&p1)
{
    int a,b,c,d;
    a=p.a_num;b=p.a_denum;c=p1.a_num;d=p1.a_denum;
    a_num=a*c;
    a_denum=b*d;
}
void Fraccions::restar(const Fraccions&p,const Fraccions&p1)
{
    int a,b,c,d,mcm;
    a=p.a_num;b=p.a_denum;c=p1.a_num;d=p1.a_denum;
    mcm=minim_comu_multiple(b,d);
    a*=(mcm/b);c*=(mcm/d);
    a-=c;
    a_num=a;
    a_denum=mcm;
}
void Fraccions::sumar(const Fraccions&p,const Fraccions&p1)
{
    int a,b,c,d,mcm;
    a=p.a_num;b=p.a_denum;c=p1.a_num;d=p1.a_denum;
    mcm=minim_comu_multiple(b,d);
    a*=(mcm/b);c*=(mcm/d);
    a+=c;
    a_num=a;
    a_denum=mcm;
}
void Fraccions::simplificar()
{
    int a,b,mcd;
    a=a_num;b=a_denum;
    mcd=maxim_comu_divisor(abs(a),abs(b));
    if(a*b<0)
    {
        a=abs(a);b=abs(b);a*=-1;
    }
    a_num=a/mcd;a_denum=b/mcd;
}
void Fraccions::llegir()
{
    int a,b;
    do{
        cin>>a>>b;
    }while(b==0);
    a_num=a;a_denum=b;
}
