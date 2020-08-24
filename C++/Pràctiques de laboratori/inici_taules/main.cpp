#include <iostream>
using namespace std;
//Entrada: 5 dades
//Sortida: les 5 dades entrades per l'usuari
const int MAX=100;
typedef int Taula_Enter[MAX];

void llegir_dades(const Taula_Enter taula,int& n){
    for(int i=0;i<5;i++){
        cin>>taula[i];
    }
}
void escriure_dades(const Taula_enter){
    for(int i=0;i<5;i++){
        cout<<t[i]<<' ';
    }
}

int main(){
    cout<< "Entra 5 dades, mozo: "<<endl;
    int n;
    cin>>n;
    Taula_Enter pepito_grillo;
    llegir_dades(pepito_grillo);
    cout<<"Les dades obtingudes son: ";
    escriure_dades(pepito_grillo);
    return 0;
}
