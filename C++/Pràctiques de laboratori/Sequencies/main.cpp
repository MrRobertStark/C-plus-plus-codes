#include <iostream>
using namespace std;
//Entrada:n sequencial
//sortida: trobar el primer nombre no-primer

void next_candidat(int& a,int& b){
    b*=2;
    a+=b;
}

bool es_primer(int n){
    int divisor=2;
    while(n%divisor!=0 && divisor*divisor<n){
        divisor++;
    }
    bool resultat=(n%divisor!=0);
    return resultat;
}

int main(){
    cout<<"Entra n: ";
    int n;
    int comptador=1;
    cin>>n;
    while(n=es_primer(n)){
        next_candidat(n,comptador);
    }
    cout<<"El primer no-primer es: "<<n<<endl;
    return 0;
}
