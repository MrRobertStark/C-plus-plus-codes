#include<iostream>
using namespace std;
const char EOS= '.';
const int MAX=140;
typedef char Taula_char[MAX];
//Entrada: un text i un pas
//Sortida: a cada lletra sumar-li el pas i al resultat invertir-lo

void intercanvi(char&a,char&b){
    char aux=a;
    a=b;
    b=aux;
}

bool es_lletra(char lletra){
    bool resultat=(lletra>='A'&& lletra<='Z');
    return resultat;
}

void codificacio(Taula_char taula,int pos,int pas){
    int posicio_abecedari;
    for(int i=0;i<pos;i++){
        if(es_lletra(taula[i])){
            posicio_abecedari=taula[i]-'A';
            posicio_abecedari+=pas;
            if(posicio_abecedari<0 or posicio_abecedari>25){
                if(posicio_abecedari>25)posicio_abecedari-=26;
                else posicio_abecedari+=26;
            }
            taula[i]='A'+ posicio_abecedari;
        }
    }
    for(int i=0;i<pos;i++){
        cout<<taula[i];
    }
    cout<<endl;
    for(int i=0;i<=(pos-1)/2;i++){
        intercanvi(taula[i],taula[(pos-1-i)]);
    }
}

void llegir_taula(Taula_char taula,int& pos){
    pos=0;
    char frase;
    cin>>frase;
    while(frase!=EOS && pos<MAX){
        taula[pos]=frase;
        pos++;
        cin.get(frase);
    }
}

int main(){
    cout<<"INTRODUEIX EL PAS:"<<endl;
    int pas,pos;
    cin>>pas;
    cout<<"INTRODUEIX EL TEXT:"<<endl;
    Taula_char taula;
    llegir_taula(taula,pos);
    cout<<"TEXT CODIFICAT:"<<endl;
    codificacio(taula,pos,pas);
    for(int i=0;i<pos;i++){
        cout<<taula[i];
    }
    return 0;
}
