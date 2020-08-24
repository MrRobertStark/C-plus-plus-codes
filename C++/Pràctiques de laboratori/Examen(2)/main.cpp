#include<iostream>
using namespace std;
//Entrada: un natural n
//Sortida: el primer nombre primer n>=n

void seguent_candidat(int& n, int comptador){
    n+=comptador;
    comptador*=2;
}

bool es_primer(int candidat){
    int divisor=2;
    while(candidat%divisor!=0 && divisor*divisor<candidat){
        divisor++;
    }
    bool es_primer=(candidat%divisor==0);
    return es_primer;
}

int main(){
    int n,repeticions,comptador;
    comptador=2;
    cout<< "Entra un enter";
    cin>>n;
    while(n=es_primer(n)){
        seguent_candidat(n,comptador);
    }
    cout<<"El nombre "<<n<<" és primer"<<endl;
    return 0;
}
