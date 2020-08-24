#include <iostream>
using namespace std;
const int EOS=-1;
//Entrada:una sequencia acabada en -1
//Sortida: ens diu si la sequencia és creixent o no

bool es_creixent(){
    //Pre: cert
    //Post: analitza si la sequencia es creixent o no
    int a,b;
    cin>>a;
    b=a;
    while(b!=EOS && b>=a){
        a=b;
        cin>>b;
    }
    bool resultat=(b==EOS);
    return resultat;
}

int main()
{
    cout << "Introdueix una seqquencia: " << endl;
    if(es_creixent())cout<<"La sequencia es creixent";
    else cout<<"No es creixent";
    return 0;
}
