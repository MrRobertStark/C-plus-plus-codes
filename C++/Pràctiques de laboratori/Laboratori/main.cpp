#include <iostream>
using namespace std;
const int EOS=0;
//Entrada: sequencia de nombres disposats verticalment
//Sortida: veure si la sequencia compleix una progressi� aritm�tica

int main(){
    cout<<"SEQ��NCIA DE NATURALS [EOS=0]:"<<endl;
    int n,increment,previ,actual;
    previ=actual=0;
    while(n!=EOS){
        cin>>n;
        previ=actual;
        actual=n;
        increment=diferencia(previ,actual);


    }
    return 0;
}
