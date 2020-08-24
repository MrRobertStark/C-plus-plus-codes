#include <iostream>
using namespace std;
const int MAX_FIL=3;
const int MAX_COL=4;
typedef int Matriu_Enter[MAX_FIL][MAX_COL];
//Entrada:
//Sortida:

bool es_primer(int m)
//pre:
//post:
{
    int divisor=2;
    while(m%divisor!=0 && divisor*divisor<m)
    {
        divisor++;
    }
    bool resultat=(m%divisor!=0);
    if(m==2)resultat=true;
    return resultat;
}

int comptador_de_primers(const Matriu_Enter matriu,int col)
//pre:
//post:
{
    int comptador=0;
    for(int i=0;i<MAX_FIL;i++)
    {
        if(es_primer(matriu[i][col-1]))comptador++;
    }
    return comptador;
}

void llegir_matriu(Matriu_Enter matriu){
//pre:
//post:
    for(int i=0;i<MAX_FIL;i++)
    {
        for(int j=0;j<MAX_COL;j++)cin>>matriu[i][j];
    }
}

int main()
{
    cout<< "INTRODUEIX ELS VALORS DE LA MATRIU:"<<endl;
    Matriu_Enter matriu;
    llegir_matriu(matriu);
    cout<< "INTRODUEIX UNA COLUMNA (1..4):"<<endl;
    int col;
    cin>>col;
    int n_primers = comptador_de_primers(matriu,col);
    cout<< "A LA COLUMNA "<<col<<" HI HA "<<n_primers<<" NOMBRES PRIMERS"<<endl;
    return 0;
}
