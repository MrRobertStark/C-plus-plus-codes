#include<iostream>
using namespace std;
const int MAX_FIL=3;
const int MAX_COL=4;
typedef int Matriu_Enter[MAX_FIL][MAX_COL];
//Entrada: una matriu amb 3 files i 4 columnes amb termes enters superiors a 1 i la columna a analitzar
//Sortida:a la columna donada recompta la quantitat de nº primers

bool es_primer(int m){
//Pre: un terme m>1 enter
//Post: mira si el nombre és primer o no
    int divisor=2;
    while(m%divisor!=0 && divisor<=m/2){
        divisor++;
    }
    return (m%divisor!=0);
}

int n_primers(const Matriu_Enter matriu,int col){
//Pre: Una matriu 3x4 amb termes >1 enters
//Post: recopmte de n_primers a la columna demanada
    int comptador=0;
    for(int i=0;i<MAX_FIL;i++){
        if(es_primer(matriu[i][col]))comptador++;
    }
    return comptador;
}
void llegir_matriu(Matriu_Enter matriu){
    for(int j=0;j<MAX_COL;j++){
        for(int i=0;i<MAX_FIL;i++){
            cin>>matriu[i][j];
        }
    }
}
void escriure_matriu(Matriu_Enter matriu){
    for(int i=0;i<MAX_FIL;i++){
        for(int j=0;j<MAX_COL;j++){
            cout<<matriu[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cout<< "INTRODUEIX ELS VALORS DE LA MATRIU:"<<endl;
    Matriu_Enter matriu;
    llegir_matriu(matriu);
    escriure_matriu(matriu);
    cout<<"INTRODUEIX UNA COLUMNA (1..4):"<<endl;
    int col;
    cin>>col;
    int recompte_primers= n_primers(matriu,col);
    cout<<"A LA COLUMNA "<<col<<" HI HA "<<recompte_primers<< " NOMBRES PRIMERS"<<endl;
    return 0;
}
