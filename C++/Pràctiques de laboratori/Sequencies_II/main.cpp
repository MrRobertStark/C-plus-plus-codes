#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//ENTRADA: Nom de <fitxer>.
//SORTIDA: Percentage esmentat (3 decimals) o bé 0 cas de no existir cap lletra (per exemple un fitxer buit)

bool es_vocal(char c){
    bool resultat=false;
    if((c=='a')or(c=='e')or(c=='i')or(c=='o')or(c=='u')or(c=='A')or(c=='E')or(c=='I')or(c=='O')or(c=='U'))resultat=true;
    return resultat;
}

bool es_lletra(char c){
    bool resultat=false;
    if(((c>='a') && (c<='z')) or ((c>='A')&&(c<='Z')))resultat=true;
    return resultat;
}

double percentatge_nombres(ifstream& nom_fitxer){
    char lletra= nom_fitxer.get();
    double comptador_total,comptador_vocals,resultat;
    comptador_total=comptador_vocals=0;
    while(not nom_fitxer.eof()){
        if(es_lletra(lletra)){
            comptador_total++;
            if(es_vocal(lletra))comptador_vocals++;
        }
        lletra=nom_fitxer.get();
    }
    resultat=comptador_vocals/comptador_total*100;
    if(comptador_total==0)resultat=0;
    return resultat;
}

int main(){
    cout.setf(ios::fixed);
    cout.precision(3);
    cout<<"Introduir nom del fitxer de text:"<<endl;
    string taula;
    cin>>taula;
    ifstream nom_fitxer(taula.c_str());
    double resultat = percentatge_nombres(nom_fitxer);
    cout<<"% vocals: "<<resultat<<endl;
    return 0;
}
