#include<iostream>
using namespace std;
const int MAX=100;
const int EOS=-1;
typedef int Taula_Enter[MAX];

void Quins_son_els_premiats(const Taula_Enter premiats,int ordre1,const Taula_Enter jugats,int ordre2)
{
    int pos;
    for(int i=0;i<ordre2;i++)
    {
        pos=0;
        while(jugats[i]!=premiats[pos]&&pos<ordre1)
        {
            pos++;
        }
        if(jugats[i]==premiats[pos])cout<<premiats[pos]<<" ";

    }
}

void llegir_taula(Taula_Enter taula,int& ordre){
    ordre=0;
    int n;
    cin>>n;
    while(n!=EOS && ordre<MAX){
        taula[ordre]=n;
        ordre++;
        cin>>n;
    }
}

int main()
{
    Taula_Enter premiats,jugats;
    int ordre1,ordre2;
    cout<< "ENTRA LA SEQUENCIA DE NUMEROS PREMIATS ACABADA EN -1"<<endl;
    llegir_taula(premiats,ordre1);
    cout<< "ENTRA LA SEQUENCIA DE NUMEROS JUGATS ACABADA EN -1"<<endl;
    llegir_taula(jugats,ordre2);
    cout<< "HEM OBTINGUT PREMI EN ELS SEGUENTS NUMEROS"<<endl;
    Quins_son_els_premiats(premiats,ordre1,jugats,ordre2);
    return 0;
}
