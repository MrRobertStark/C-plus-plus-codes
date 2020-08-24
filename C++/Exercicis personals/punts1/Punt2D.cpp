#include "Punt2D.h"
#include <iostream>
#include <cmath>
using namespace std;

Punt2D::Punt2D()
{
    a_x=0;
    a_y=0;
}
void Punt2D::llegir()
//pre
//post
{
    cin>>a_x>>a_y;
}
void Punt2D::sumar(Punt2D p_anterior,double& trajecte)
//pre
//post
{
    a_x+=p_anterior.a_x;
    a_y+=p_anterior.a_y;
    trajecte+=sqrt((a_x-p_anterior.a_x)*(a_x-p_anterior.a_x)+(a_y-p_anterior.a_y)*(a_y-p_anterior.a_y));
}
void Punt2D::mostrar()const
//pre
//post
{
    cout<<"("<<a_x<<","<<a_y<<")"<<endl;
}
