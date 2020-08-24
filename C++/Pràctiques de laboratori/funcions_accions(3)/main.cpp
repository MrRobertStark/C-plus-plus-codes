#include <iostream>
using namespace std;
//Entrada: un nombre n
//Sortida: verificació si n és primari o no

bool comprovacio_prim(int n){
    int comptador = 0;
    for (int i=1;i<=n;i++){
        if(n%i==0){
            comptador++;
        }
    }
    bool comprovacio = (comptador==2);
    return comprovacio;
}

int main() {
    cout<< "Entra n: ";
    int n;
    cin>>n;
    bool resultat=(comprovacio_prim(n));
    if (resultat) cout<< "Es primer";
    else cout<< "No es primer";
    return 0;
}
