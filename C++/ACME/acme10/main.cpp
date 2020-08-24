#include <iostream>
#include <string>

using namespace std;
//Entrada: el nombre de caràcters a llegir i els caràcters (strings)
//Sortida: es mostren els caràcters en sentit invers a l'entrat

void insercio_caracters(string *t,int n)
//Pre: n>=0. La taula ha de ser d'ordre t[n]
//Post:totes les posicions de la taula han quedad emplenades per strings
{
    for(int i=0;i<n;i++)cin>>*(t+i);
}
void mostrar_caracters_al_reves(string *t,int n)
//Pre: n>=0. Totes les posicions de la taula han de ser plenes
//Post: s'han mostrar per ordre invers a l'entrat els strings llegits
{
    cout<<*(t+(n-1));
    for(int i=n-2;i>=0;i--)cout<<", "<<*(t+i);
}

int main()
{
    int n;
    do{
        cout<< "QUANTES CADENES TENS (>0):"<<endl;
        cin>>n;
    }while(n<=0);

    string t[n];

    cout<< "ENTRA LES CADENES:"<<endl;
    insercio_caracters(t,n);

    cout<< "ORDRE INVERS:"<<endl;
    mostrar_caracters_al_reves(t,n);
    return 0;
}
