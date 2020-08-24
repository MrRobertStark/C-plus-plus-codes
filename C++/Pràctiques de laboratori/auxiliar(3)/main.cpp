#include <iostream>
using namespace std;

//Entrada: dos enters a i b
//Sortida: llistat de nombres capicua i si són primers
int potencia (int exponent){
    int potencia=1;
    for(int i=exponent;i>=1;i--){
        potencia*=10;
    }
    return potencia;
}
int recompte_digits(int candidat){
    //pre: candidat>0
    //post: compta el nombre de digits que té candidat
    int nombre=candidat;
    int comptador=1;
    while(nombre>=10){
        nombre/=10;
        comptador++;
    }
    return comptador;
}

bool es_primer(int candidat){
    //Pre: candidat>0
    //Post: verificació de si candidat és un nombre primer
    int comptador=0;
    for(int i=1;i<=candidat;i++){
        if(candidat%i==0)comptador++;
    }
    bool resultat=(comptador==2);
    return resultat;
}
bool es_capicua(int candidat){
    //Pre: candidat>0
    //Post:comprovació de si candidat és un nombre capicua
    int sumador=0;
    int entrada =candidat;
    int residu;
    int exponent;
    for(int i=recompte_digits(candidat);i>=1;i--){
        exponent=i-1;
        residu= entrada%10;
        residu= residu*potencia(exponent); //No dejan usar pow. Falta multiplicar por el exponente
        sumador+=residu;
        entrada/=10;
    }
    bool resultat= (sumador==candidat);
    return resultat;
}

void analisi_nombre(int a,int b){
    int candidat;
    for(int i=a;i<=b;i++){
        candidat=i;
        if(es_capicua(candidat)){
            cout<<candidat<<" ";
            if(es_primer(candidat))cout<<"primer"<<endl;
            else cout<<endl;
        }
    }
}
int main(){
    int a,b;
    cout<<"ENTRAR NUMERO 1:"<<endl;
    cin>>a;
    cout<<"ENTRAR NUMERO 2:"<<endl;
    cin>>b;
    cout<<"CAPICUES ENTRE "<<a<<" I "<<b<<":"<<endl;
    analisi_nombre(a,b);
    return 0;
}
