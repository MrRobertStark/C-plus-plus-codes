#include <iostream>
#include "Fraccions.h"
using namespace std;

void operacions(Fraccions f1,Fraccions f2, Fraccions&resultat)
{
    char operacio;
    cout << "Introdueix operaci� [+-*/] o fi [#]: " << endl;
    cin >> operacio;
    while(operacio!='#')
    {
        if(operacio=='+')resultat.sumar(f1,f2);
        else if(operacio=='-')resultat.restar(f1,f2);
        else if(operacio=='*')resultat.multiplicar(f1,f2);
        else if(operacio=='/')resultat.dividir(f1,f2);
        resultat.simplificar();
        cout<<"El resultat �s el seg�ent: ";
        resultat.mostrar();
        cout << "Introdueix operaci� [+-*/] o fi [#]: " << endl;
        cin >> operacio;
    }
}

int main()
{
    Fraccions f1,f2,resultat;
    cout << "Primera fracci�: " << endl;
    f1.llegir();
    cout << "Segona fracci�: " << endl;
    f2.llegir();
    operacions(f1,f2,resultat);
    return 0;
}
