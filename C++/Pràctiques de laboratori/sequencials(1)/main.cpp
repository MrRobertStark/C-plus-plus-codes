#include <iostream>

using namespace std;
const int EOS= '-1';
//Entrada: una seqüència alfanumèrica
//Sortida: identificar si hi ha un nombre primer a la llista

bool no_primer(int n){
    int divisor=2;
    while(n%divisor!=0&&divisor*divisor<n){
        divisor++;
    }
    bool resultat=(n&divisor==0);
    return resultat;
}

bool primerdetected(){
    int n;
    cin>>n;
    while(n=no_primer(n)&&n!=EOS){
        cin>>n;
    }
    bool resultat=(n!=EOS);
    return resultat;
}

int main()
{
    cout << "Entra la sequencia però acaba-la amb -1: ";
    if(primer_detected())cout<<"^Prime number detected";
    else cout<<"No prime number detected";
    return 0;
}
