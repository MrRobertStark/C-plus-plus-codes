#include<iostream>
using namespace std;
const int EOS=-1;
const int MAX=100;
typedef int Taula_Enter[MAX];
//Entrada: Una sequencia acabada en -1
//Sortida: Dir en quina meitat de la sequencia hi ha més nombres perfectes
bool es_perfecte(int n){
    int suma=0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0)suma++;
    }
    bool perfecte=(suma==n);
    return perfecte;
}
void llegir_taula(Taula_Enter taula,int& pos_taula){
    int n;
    pos_taula=0;
    cin>>n;
    while(n!=EOS){
        taula[pos_taula]=n;
        pos_taula++;
        cin>>n;
    }
}

int recompte_perfectes(const Taula_Enter taula,int pos_taula){
    int suma_perfectes1,suma_perfectes2,resultat;
    for(int i=0;i<pos_taula/2;i++){
        if(es_perfecte(taula[i]))suma_perfectes1++;
    }
    for(int i=pos_taula-1;i>pos_taula/2;i--){
        if(es_perfecte(taula[i]))suma_perfectes2++;
    }
    if(suma_perfectes1>suma_perfectes2)resultat=1;
    else if(suma_perfectes1<suma_perfectes2)resultat=2;
    else resultat=0;
    return resultat;
}

int main(){
    int pos_taula;
    Taula_Enter taula;
    cout<<"ENTRA UNA SEQUENCIA DE NOMBRES ENTERS POSITIUS ACABADA AMB -1:"<<endl;
    llegir_taula(taula,pos_taula);
    int meitat=recompte_perfectes(taula,pos_taula);
    if(meitat==1)cout<<"HI HA MES NOMBRES PERFECTES A LA PRIMERA MEITAT"<<endl;
    else if(meitat==2)cout<<"HI HA MES NOMBRES PERFECTES A LA SEGONA MEITAT"<<endl;
    else cout<<"HI HA ELS MATEIXOS A LES DUES MEITATS"<<endl;
}
