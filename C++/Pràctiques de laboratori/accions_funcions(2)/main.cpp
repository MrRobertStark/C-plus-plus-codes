#include <iostream>
using namespace std;
//Entrada: un nombre natural n
//Sortida: comprovaci� si n cont� un terme parell

bool comprovacio(int n){
    while(n%2!=0 && n>0){
        n/=10;
    }
    bool parell = (n>0);
    return parell;
}

int main(){
    cout<< "Entra un natural: ";
    int n;
    cin>>n;
    bool resultat = (comprovacio(n));
    if (resultat)cout<< "Es parell";
    else cout << "Es senar";
    return 0;
}
