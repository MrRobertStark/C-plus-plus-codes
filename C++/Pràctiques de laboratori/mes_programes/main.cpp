#include <iostream>
using namespace std;
const int EOS= '#';
//Entrada: sequencia de caràcters acabada en '#'
//Sortida: nº paraules sequencies

bool es_separador(char n){
    bool resultat=true;
    if((n>='a'&&n<='z') or (n>='A'&&n<='Z'))resultat=false;
    else if(n==EOS)resultat=false;
    return resultat;
}

void passa_separadors(char& n){
    while(n!=EOS && es_separador(n)){
        n=cin.get();
    }
}

void passa_paraula(char& n){
    while(n!=EOS && not es_separador(n)){
        n=cin.get();
    }
}

int comptador_paraules(char n){
    int comptador=0;
    passa_separadors(n);
    while(n!=EOS){
        passa_paraula(n);
        passa_separadors(n);
        comptador++;
}
    return comptador;
}

int main(){
    cout<<"Dona'm un text: "<<endl;
    char n;
    n=cin.get();
    int comptador=comptador_paraules(n);
    cout<<"Hi ha "<<comptador<<" paraula(s) en el text!"<<endl;
    return 0;
}
