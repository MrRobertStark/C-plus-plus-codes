#include <iostream>
#include "Punt3D.h"

using namespace std;
//Entrada
//sortida
const int MAX_OPERACIONS=5;
const char FI_OPERACIO='f';

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    int comptador_z=0,comptador_op=0;
    Punt3D p1;
    p1.llegir();
    char ordre='c';
    while(comptador_op<MAX_OPERACIONS && ordre!=FI_OPERACIO)
    {
        cout<<"ENTRAR OPERACIO (s, r, m, v, f):"<<endl;
        cin>>ordre;
        if(ordre!=FI_OPERACIO)
        {
            if(ordre=='s')p1.sumar();
            else if(ordre=='r')p1.restar();
            else if(ordre=='m')p1.multiplicacio_real();
            else if(ordre=='v')p1.producte_vectorial();
            p1.mostrar(comptador_z);
            comptador_op++;
        }

    }
    cout<<"NOMBRE D'OPERACIONS: "<<comptador_op<<endl;
    cout<< "RESULTATS A L'HEMISFERI NORD: "<<comptador_z;
    return 0;
}
