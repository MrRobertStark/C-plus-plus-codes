#include <iostream>
using namespace std;
//Entrada:n sequencial
//sortida: trobar el primer nombre no-primer

bool es_primer(int n){
    int divisor=2;
    while(n%divisor!=0 && divisor*divisor<n){
        divisorr++
    }
    bool resultat=(n%divisor!=0);
    return resultat;
}

int main(){
    cout<<"Entra n: ";
    int n;
    cin>>n;
    while(n=es_primer){
        next_candidat(n);
    }
    cout<<"El primer no-primer es: "<<n<<endl;
    return 0;
}
