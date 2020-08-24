#include <iostream>
#include <cmath>
using namespace std;
//Entrada: entra un enter n>0
//Sortida: determinacio si n és capicua o no

int laboratori(int n){
    int comptador=1;
    int quocient = n;
    int residu =n;
    int suma=0;
    while (quocient>=10){ //Recompte numero digits
        quocient/=10;
        comptador++;
    }
    for(int i=1;i<=comptador;i++){ //Sumatori factorial invers
        int exponent = i-1;
        residu%=10;
        residu*= pow(10,exponent);
        suma+=residu;
        cout<<suma;
    }
    return suma;
}

int main(){
    cout<< "Hello happyflower, entra un nombre enter: ";
    int n;
    cin>>n;
    int suma= laboratori(n);
    if (suma==n)cout<< "Es capicua senyoret!";
    else cout<< "No es capicua, malament!";
    return 0;
}
