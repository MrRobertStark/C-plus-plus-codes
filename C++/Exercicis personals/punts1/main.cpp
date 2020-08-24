#include <iostream>
#include "Punt2D.h"
using namespace std;

const char EOS='n';

int main()
{
    Punt2D p_origen,p_final,p_seguent,p_anterior;
    char ordre;
    double trajecte=0;
    cout << "Entra les coordenades x i y del punt inicial: ";
    p_origen.llegir();
    p_anterior=p_origen;
    cout<< "Vols entrar un nou punt? ";cin>>ordre;
    while(ordre!=EOS){
        cout<< "Entra el vector (x,y): "; p_seguent.llegir();
        p_seguent.sumar(p_anterior,trajecte);
        cout<<"Punt seguent: ";p_seguent.mostrar();
        p_anterior=p_seguent;
        cout<< "Trajecte:"<<trajecte<<endl;
        cout<< "Vols entrar un nou punt? ";cin>>ordre;
    }
    cout<< "Punt final: ";p_origen.mostrar();
    p_seguent.sumar(p_origen,trajecte);
    cout<< "Distancia trajecte= "<<trajecte<<endl;
    return 0;
}
