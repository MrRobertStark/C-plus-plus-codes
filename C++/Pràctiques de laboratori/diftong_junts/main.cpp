#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//Entrada:Nom de <fitxer>
//Sortida:La posició dins del text de la primera vocal del diftong, o bé 0 en cas contrari.

bool es_vocal(char a){
    bool resultat=false;
    if((a=='a')or(a=='e')or(a=='i')or(a=='o')or(a=='u')or(a=='A')or(a=='E')or(a=='I')or(a=='O')or(a=='U'))resultat=true;
    return resultat;
}

bool es_diftong(char a,char b){
    bool resultat=false;
    if(es_vocal(a) && es_vocal(b))resultat=true;
    return resultat;
}

int analisi_text(ifstream& fitxer){
    int posicio=0;
    char c_anterior,c_actual;
    c_anterior='_';
    c_actual=fitxer.get();
    if(not fitxer.eof()){
        while(not fitxer.eof() && not es_diftong(c_anterior,c_actual)){
            c_anterior=c_actual;
            c_actual=fitxer.get();
            posicio++;
            cout<<"Tenim que: "<<c_anterior<<" "<<c_actual<<endl;
        }
        posicio-=1;
    }
    return posicio;
}

int main(){
    cout<< "Nom del fitxer de text:"<<endl;
    string nom_fitxer;
    cin>>nom_fitxer;
    ifstream fitxer(nom_fitxer.c_str());
    cout<<"Posició diftong: "<<analisi_text(fitxer)<<endl;
    return 0;
}
