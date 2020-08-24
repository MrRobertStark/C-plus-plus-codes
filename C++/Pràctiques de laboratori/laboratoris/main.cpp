#include <iostream>
using namespace std;
const int MAX_FIL=100;
const int MAX_COL=100;
typedef int Matriu_Enter[MAX_FIL][MAX_COL];
//Entrada: una matriu amb un ordre [0..n-1][0..m-1] i un nombre k
//Sortida: les coordenades del primer multiple de k

void mostrar_matriu(const Matriu_Enter matriu,int n,int m)
//pre://pre: 0<=n<=MAX_FIL-1 i 0<=m<=MAX_COL-1 i k>0
//post: mostra les components de la matriu
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matriu[i][j]<<" ";
        }
        cout<<endl;
    }
}

void filtratge (int& a,int& b,int c)
{
    if(a<0)a+=c;
    else if(a>c)a-=c;
    if(b<0)b+=c;
    else if(b>c)b-=c;
}

void construccio_matriu(Matriu_Enter matriu,int n,int m)
//pre: 0<=n<=MAX_FIL-1 i 0<=m<=MAX_COL-1 i k>0
//post: construeix la matriu màgica
{
    int comptador=0;
    int i,j;
    i=0;
    j=1;
    while(comptador<9)
    {
        comptador++;
        if(matriu[i][j]==0){
            matriu[i][j]=comptador;
            i-=1;
            j+=1;
            filtratge(i,j,n);
        }
        else {
            i+=2;
            j-=1;
            filtratge(i,j,n);
            matriu[i][j]=comptador;
        }
    }
}

int main()
{
    cout << "MIDA QUADRAT:" << endl;
    int ordre;
    cin>>ordre;
    Matriu_Enter matriu = {0};
    construccio_matriu(matriu,ordre,ordre);
    cout<<"EL RESULTAT ES:"<<endl;
    mostrar_matriu(matriu,ordre,ordre);
    return 0;
}
