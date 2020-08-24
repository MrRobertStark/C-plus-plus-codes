#include <iostream>

using namespace std;
const int MAX=100;
typedef int Taula_Enter[MAX];
const int EOS=0;

void taula_invertida(const Taula_Enter taula, Taula_Enter taula1,int n){
    int comptador=n-1;
    for(int i=0;i<n;i++){
        taula1[i]=taula[comptador];
        comptador--;
    }
    cout<<"La taula invertida queda: ";
    for(int i=0;i<n;i++){
        cout<<taula1[i];
    }
    cout<<endl;
}

void calcul_valor_minim(const Taula_Enter taula,int n){
    int minim=taula[0];
    int pos=0;
    for(int i=1;i<n;i++){
        if(minim>taula[i]){
            minim=taula[i];
            pos=i;
        }
    }
    cout<<"El minim es: "<<minim<<" a la posicio "<<pos<<endl;
}

void suma_vectors(const Taula_Enter taula,int n){
    int suma=0;
    for(int i=0;i<n;i++){
        suma+=taula[i];
    }
    cout<<"La suma dels termes del vector son: "<<suma<<endl;
}

void escriure_taula(const Taula_Enter taula,int n){
    for(int i=0;i<n;i++){
        cout<<taula[i]<<" ";
    }
    cout<<endl;
}

void llegir_taula(Taula_Enter taula,int&n){
    int comptador=0;
    cin>>n;
    while(n!=EOS && comptador<MAX){
        taula[comptador]=n;
        comptador++;
        cin>>n;
    }
    n=comptador;
}

int main()
{
    cout << "Entra un vector" << endl;
    int n;
    Taula_Enter taula;
    Taula_Enter taula1;
    llegir_taula(taula,n);
    escriure_taula(taula,n);
    suma_vectors(taula,n);
    calcul_valor_minim(taula,n);
    taula_invertida(taula,taula1,n);
    return 0;
}
