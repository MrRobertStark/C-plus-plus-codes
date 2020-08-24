#include <iostream>
#include <cmath>
#include <string>
using namespace std;
//Entrada: dos naturals a i b
//Sortida: el màxim entre a i b

void calcul_maxim(int & a, int & b, int & maxim){
    if(a>b)maxim=a;
    else maxim=b;
}

int main(){
    cout<< "Entra dos naturals a i b: ";
    int a,b,maxim;
    cin>>a>>b;
    calcul_maxim(a,b,maxim);
    cout<< "El maxim entre a i b es: "<<maxim;
    return 0;
}
