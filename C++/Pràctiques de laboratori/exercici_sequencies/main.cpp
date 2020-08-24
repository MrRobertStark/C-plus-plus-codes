#include <iostream>
#include<string>
#include<fstream>
using namespace std;
const int PRECISIO=3;
//Entrada: Nom de fitxer
//Sortida: Retorna la mitjana de la longitud dels mots (3 decimals). Altrament missatge "cap mot!" si no existiex cap mot en el fitxer. O bé "Error d'apertura fitxer." si escau.

bool es_lletra(char c){
    //Pre: C no ha de representar el final del fitxerr
    //Post: Retorna cert si c és una lletra o no
    bool resultat=false;
    if(((c>='a') && (c<='z')) or ((c>='A')&&(c<='Z')))resultat=true;
    return resultat;
}

char passa_separadors(char& c,ifstream& nom_fitxer){
    if(not es_lletra(c)){
        while(not es_lletra(c)&& not nom_fitxer.eof()){
            nom_fitxer.get(c);
        }
    }
    return c;
}

char passa_paraula(char& c, double& comptador_paraules, double& comptador_lletres,ifstream& nom_fitxer){
    if(es_lletra(c)&& not nom_fitxer.eof()){
        comptador_paraules++;
        while(es_lletra(c)&& not nom_fitxer.eof()){
            comptador_lletres++;
            c=nom_fitxer.get();
        }
    }
    return c;
}

void analisi_frase(ifstream& fitxer_principal){
    //Pre: cert
    //Post: calcula la mitjana de lletres en les paraules escrites en un fitxer
    char c;
    double comptador_paraules,comptador_lletres,mitjana;
    comptador_paraules=comptador_lletres=0;
    if(not fitxer_principal.fail()){
        c=fitxer_principal.get();
        while(not fitxer_principal.eof()){
            passa_separadors(c,fitxer_principal);
            passa_paraula(c,comptador_paraules,comptador_lletres,fitxer_principal);
        }
        mitjana=comptador_lletres/comptador_paraules;
        if(comptador_paraules==0)cout<<"Mitjana longitud mot: cap mot!"<<endl;
        else cout<<"Mitjana longitud mot: "<<mitjana<<endl;
    }
    else{
        cout<<"Error d'apertura fitxer."<<endl;
    }
}

int main(){
    cout.setf(ios::fixed);
    cout.precision(PRECISIO);
    cout<<"Fitxer:"<<endl;
    string nom;
    cin>>nom;
    ifstream fitxer_principal(nom.c_str());
    analisi_frase(fitxer_principal);
    return 0;
}
