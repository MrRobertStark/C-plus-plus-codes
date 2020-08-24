#include<iostream>
using namespace std;
const int MAX_FIL=100;
const int MAX_COL=100;
typedef int Matriu_Enter[MAX_FIL][MAX_COL];
//Entrada:Una matriu d'ordre n i m on 0<=n<=MAX_FIL i 0<=m<=MAX_COL
//Sortida:La matriu enetrada transposada

void llegir_matriu(Matriu_Enter mat,int n,int m)
//Pre:
//Post:
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
}

void transposar_matriu(const Matriu_Enter mat,Matriu_Enter transp,int n,int m)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            transp[j][i]=mat[i][j];
        }
    }
}

void exposar_matriu(const Matriu_Enter mat,int n,int m)
//pre:
//post:
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"Entra l'ordre de la matriu (n i m)"<<endl;
    int n,m;
    cin>>n>>m;
    cout<<"D'acord, ara introdueix-me els elements de la matriu"<<endl;
    Matriu_Enter mat,transposat;
    llegir_matriu(mat,n,m);
    cout<<"D'acord, un cop llegit te'l transposaré"<<endl;
    transposar_matriu(mat,transposat,m,n);
    exposar_matriu(transposat,n,m);
    return 0;
}

