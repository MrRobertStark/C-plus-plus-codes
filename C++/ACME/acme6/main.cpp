#include <iostream>
#include "Punt2D.h"
#include "Cercle.h"

using namespace std;
const char EOS='s';
//Entrada: Un cercle
//Sortida: S'executen una sèrie de comandes entrades per teclat

void mostrar_menu_comandes()
//Pre: cert
//Post: es mostren les comandes del programa
{
    cout<<"m: MOSTRAR EL CERCLE"<<endl;
    cout<<"d: MOURE EL CERCLE"<<endl;
    cout<<"e: ESCALAR EL CERCLE RESPECTE EL CENTRE"<<endl;
    cout<<"i: CONSULTAR SI UN PUNT ES INTERIOR"<<endl;
    cout<<"s: SORTIR"<<endl;
    cout<< "ENTRA UNA OPCIO:"<<endl;
}
void punt_dins_cercle(Cercle c)
//Pre: cert
//Post: es mira si un punt entrat pertany a l'àrea del cercle
{
    double x,y;
    cout<< "ENTRA UN PUNT:"<<endl;
    cin>>x>>y;
    if(c.punt_dins_cercle(x,y))cout<< "EL PUNT ES INTERIOR"<<endl;
    else cout<< "EL PUNT NO ES INTERIOR "<<endl;
}
int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    Cercle c;
    Punt2D p;
    char ordre;
    cout<< "ENTRA EL CERCLE INICIAL: "<<endl;
    c.llegir_dades();
    mostrar_menu_comandes();
    cin>>ordre;
    while(ordre!=EOS)
    {
        if(ordre=='m')c.mostrar_cercle();
        else if(ordre=='d')c.moure_cercle();
        else if(ordre=='e')c.escalar_cercle();
        else if(ordre=='i')punt_dins_cercle(c);
        mostrar_menu_comandes();
        cin>>ordre;
    }
    return 0;
}
