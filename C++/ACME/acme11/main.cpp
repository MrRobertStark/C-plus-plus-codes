#include <iostream>

using namespace std;
//Entrada: n_elements>0 a llegir (strings) i els strings mateixos
//Sortida: es mostra llista de strings entrats ordenats creixentment i decreixenent

void intercanviar(string &p,string &q)
//Pre: p i q són strings. P=p Q=q
//Post: P=q Q=p
{
    string aux=p;
    p=q; q=aux;
}
void emplenar_taula_ordenant(string *t,int n)
//Pre: n>0. La taula ha de tenir espai per tots els n elements
//Post: s'emplena la taula de manera ordenada
{
    for(int i=0;i<n;i++)
    {
        int m=i;
        cin>>*(t+i);
        while(m>0&&*(t+m)<*(t+m-1))
        {
            intercanviar(*(t+m),*(t+m-1));
            m--;
        }
    }
}

void mostrar_taula_per_criteri(string *t,int n,int criteri=1)
//Pre: n>0 i la taula ha de contenir espai per a tots els n elements. El criteri ha de ser 1 0 -1
//Post: en funció del criteri es mostra la taula ascendentment o descendentment
{
    if(criteri==1)
    {
        cout<<*t;
        for(int i=1;i<n;i++)cout<<", "<<*(t+i);
    }
    else if(criteri==-1)
    {
        cout<<*(t+n-1);
        for(int i=n-2;i>=0;i--)cout<<", "<<*(t+i);
    }
    cout<<endl;
}

int main()
{
    int n;
    do{
        cout << "QUANTES CADENES TENS (>0):" << endl;
        cin>>n;
    }while(n<=0);

    string t[n];
    cout<<"ENTRA LES CADENES:"<<endl;
    emplenar_taula_ordenant(t,n);

    cout<< "ORDRE CREIXENT:"<<endl;
    mostrar_taula_per_criteri(t,n);

    cout<< "ORDRE DECREIXENT:"<<endl;
    mostrar_taula_per_criteri(t,n,-1);

    return 0;
}
