#include<iostream>
using namespace std;
const int MAX_FIL=100;
const int MAX_COL=100;
typedef int Matriu_Enter[MAX_FIL][MAX_COL];
//Entrada:
//Sortida:

bool fora_de_rang(int a,int n){
//Pre
//post
    bool resultat=false;
    if(a<0 && a>=n)resultat=true;
    return resultat;
}

void mostrar_matriu(Matriu_Enter matriu,int n)
//Pre:
//Post:
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matriu[i][j]<<" ";
        }
        cout<<endl;
    }
}

void filtratge(int&a,int&b,int n){
//Pre:
//post:

        if(a<0)a+=n;
        else if(a>=n)a-=n;


        if(b<0)b+=n;
        else if(b>=n)b-=n;
}

void seguent_casella(int& fila,int& columna){
//Pre:
//Post:
    fila--;
    columna++;
}

void construccio_matriu(Matriu_Enter matriu,int n){
//Pre:
//Post:
    int comptador=1;
    int fila,columna;
    fila=0;
    columna=n/2;
    while(comptador<=n*n){
        if(matriu[fila][columna]==0){
            matriu[fila][columna]=comptador;
            seguent_casella(fila,columna);
            filtratge(fila,columna,n);
        }
        else{
            fila+=2;
            columna--;
            filtratge(fila,columna,n);
            matriu[fila][columna]=comptador;
            seguent_casella(fila,columna);
            filtratge(fila,columna,n);
        }
        comptador++;
    }
}

int main(){
    cout<< "MIDA QUADRAT:"<<endl;
    int n;
    cin>>n;
    cout<< "EL RESULTAT ES:"<<endl;
    Matriu_Enter matriu = {0};
    construccio_matriu(matriu,n);
    mostrar_matriu(matriu,n);
    return 0;
}

