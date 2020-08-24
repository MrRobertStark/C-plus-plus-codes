#include <iostream>
using namespace std;
const int EOS= -1;
//Entrada: una sequencia numèrica
//Sortida: Veure si hi ha algun nombre multiple de 7

bool multiple_7(){
    int n;
    cin>>n;
    while(n!=EOS && n%7!=0){
        cin>>n;
    }
    bool resultat=(n%7==0);
    return resultat;
}

int main(){
    cout<<"Entra la sequencia i acaba-la amb -1: ";
    if(multiple_7())cout<<"Hi ha un múltiple de 7";
    else cout<< "No hi ha multiple de 7 a la llista.";
    return 0;
}
