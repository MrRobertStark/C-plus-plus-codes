#include <iostream>
#include "Punt2D.h"
#include "Rectangle.h"
using namespace std;

int main()
{
    Rectangle r1,r2,r3;
    r1.llegir();r2.llegir();cout<<endl;
    r1.mostrar();cout<<endl;
    r2.mostrar();cout<<endl;
    r3=r1.rectangle_mig(r2);
    r3.mostrar();cout<<endl;
    r3.producte_amb_escalar('o');
    r3.mostrar();cout<<endl;
    r3.producte_amb_escalar('c');
    r3.mostrar();cout<<endl;
    r3.desplasament();
    r3.mostrar();cout<<endl;
    double perimetre=r3.calcul_perimtre();
    cout<< "Perímetre: "<<perimetre<<endl;
    return 0;
}
