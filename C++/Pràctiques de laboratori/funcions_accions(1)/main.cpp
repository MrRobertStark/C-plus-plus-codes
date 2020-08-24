#include <iostream>
#include <cmath>
using namespace std;
//Entrada: un natural n
//Sortida: sumatori dels nombres<n

int calcul_retro (int n){
    int suma=0;
    for (int i=1;i<=n;i++){
        suma+=i;
    }
     return suma;
}

int main(){
    cout<< "Entra un nombre natural: ";
    int n;
    cin>>n;
    int suma=calcul_retro(n);
    cout<< "El sumatori dels nombres <n es: "<<suma;
    return 0;
}
