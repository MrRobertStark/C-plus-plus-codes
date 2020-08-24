#include<iostream>
#include<string>
#include<fstream>
using namespace std;
const double NOTA_MINIMA=8.50;
//ENTRADA: Nom de <fitxer>.
//SORTIDA: Codi de l'alumne si existeix, o 0 altrament (per exemple un fitxer buit).


double mitjana(double a,double b,double c){
    double resultat= (a+b+c)/3;
    return resultat;
}

int primer_alumne_excellent(ifstream& fitxer){
    int codi,punts,comptador,candidat;
    double nota1,nota2,nota3;
    while(punts!=3 && not fitxer.eof()){
        comptador=candidat=punts=0;
        fitxer>>codi;
        while(comptador!=1){
            fitxer>>nota1;
            if(nota1>=NOTA_MINIMA)punts++;
            fitxer>>nota2;
            if(nota2>=NOTA_MINIMA)punts++;
            fitxer>>nota3;
            if(nota3>=NOTA_MINIMA)punts++;
            comptador++;
        }
    }
    if(punts==3 && mitjana(nota1,nota2,nota3)>=9)candidat=codi;
    return candidat;
}


int main(){
    cout<< "Introduir nom del fitxer de notes:"<<endl;
    string nom;
    cin>>nom;
    ifstream fitxer(nom.c_str());
    cout<< "Codi alumne: " <<primer_alumne_excellent(fitxer)<<endl;
    return 0;
}
