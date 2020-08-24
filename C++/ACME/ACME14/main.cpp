#include <iostream>
#include "Durada.h"

using namespace std;

void intercanviar(Durada&d1,Durada&d2)
//Pre:A=a B=b//post:A=b B=a
{
    Durada aux=d1;
    d1=d2;d2=aux;
}

void entrar_durades(Durada t[],int n)
//pre:n>0//post:s'emplena la taula amb durades
{
    cout<<"ENTRA LES DURADES:"<<endl;
    for(int i=0;i<n;i++)t[i].llegir_duracio();
}
void ordenar_taula(Durada t[],int n)
//pre:n>0//post:s'ordena la taula per duració creixent
{
    int pos;
    for(int i=1;i<n;i++)
    {
        pos=i;
        while(pos>0&&t[pos]<t[pos-1]){intercanviar(t[pos],t[pos-1]);pos--;};
    }
}
void mostrar_elements(Durada t[],int n,Durada total)
//pre:n>0//post:Es mostra quants elements de la taula es podrien afegir a una llista sense que el seu total superi total
{
    Durada sumador;int pos=0;
    while(pos<n&&(sumador+t[pos])<=total){sumador=sumador+t[pos];pos++;}

    if(pos>0)
    {
        cout<< "CALEN "<<pos<<" ELEMENTS: ";
        t[0].mostrar_duracio();for(int i=1;i<pos;i++){cout<<", ";t[i].mostrar_duracio();}
        cout<<endl<<"DURADA TOTAL: ";sumador.mostrar_duracio();cout<<endl;
    }
}

int main()
{
    int n,m;
    do{
        cout<<"QUANTS VALORS TENS (>0):"<<endl;
        cin>>n;
    }while(n<=0);
    Durada t[n],total;

    entrar_durades(t,n);
    ordenar_taula(t,n);

    cout<<endl<<"DURADA MAXIMA (min, 0 per acabar):"<<endl;
    cin>>m;
    while(m!=0)
    {
        total=Durada(0,m);
        mostrar_elements(t,n,total);
        cout<<endl<<"DURADA MAXIMA (min, 0 per acabar):"<<endl;
        cin>>m;
    }
    return 0;
}
