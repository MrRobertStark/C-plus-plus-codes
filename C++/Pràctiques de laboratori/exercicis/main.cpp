#include<iostream>
using namespace std;
const int EOS=0;
//Entrada: Una sequencia num�rica natural
//Sortida: comptar els capicues totals a la sequencia

bool es_mtp(){
    int llavor,resultat;
    cin>>llavor;
    resultat=llavor;
    while(resultat!=1 && resultat!=EOS){
        if(resultat%2!=0)resultat=resultat*3+1;
        else resultat/=2;
        cout<<resultat<<" ";
    }
    cout<<endl;
    bool resposta=(resultat==1);
    return resposta;

}

int main(){
    cout<<"Seq��ncia de naturals [EOS = 0]."<<endl;
    int resultat=es_mtp();
    if(resultat)cout<<"Seq��ncia-MTP-1: Cert"<<endl;
    else cout<<"Seq��ncia-MTP-1: Fals"<<endl;
    return 0;
}
