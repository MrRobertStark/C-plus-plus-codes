#include <iostream>
#include <cmath>
using namespace std;

//Entrada: tres varibales
//Sortida: resolució ecuació de segon grau

int main(){

double a,b,c;
cin>>a>>b>>c;
cout<< "ok"<<endl;
double resultat1;
double resultat2;
    if(a==0){
        resultat1= -c/b;
    }
    if(a!=0){
        resultat1=-b/(-2*a)+sqrt(b*b-4*a*c)/(-2*a);
        resultat2=-b/(-2*a)-sqrt(b*b-4*a*c)/(-2*a);
    }
    cout<<resultat1<<endl;
    cout<<resultat2<<endl;



}

