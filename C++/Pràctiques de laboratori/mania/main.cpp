#include<iostream>
using namespace std;
//Entrada:Sequencia de productes definits per un codi enter i un preu real
//Sortida: mostrar els productes entrats després d'haver llegir el producte de codi 0
struct producte{
    int codi;
    double preu;
};
const int EOS=0;
const int MAX=100;
typedef producte Taula_mercancia[MAX];

producte llegir_mercancia(){
//Pre:
//post:
    producte p;
    cin>>p.codi;
    if(p.codi!=EOS){
        cin>>p.preu;
    }
    return p;
}

void mostrar_producte (producte p){
    cout<<p.codi<<" "<<p.preu<<endl;
}

void mostrar_taula(const Taula_mercancia taula,int n){
//Pre:
//Post:
    for(int i=0;i<n;i++){
        mostrar_producte(taula[i]);
    }
}


void llegir_taula(Taula_mercancia taula, int&n){
//Pre:
//Post:
    n=0;
    producte llegit = llegir_mercancia();
    while(llegit.codi!=EOS && n<MAX){
        taula[n]=llegit;
        n++;
        llegit=llegir_mercancia();
    }
}

void intercanvi(producte p,producte q){
//Pre:
//Post:
    producte aux=p;
    p=q;
    q=aux;
}

int buscar_el_minim(const Taula_mercancia taula,int inici,int n){
//Pre:
//Post:
    int pos=inici;
    for(int i=inici;i<n-1;i++){
        if(taula[pos].codi>taula[i].codi)pos=i;
    }
    return pos;
}

void moure_taula(Taula_mercancia taula,int n,int pos){
//Pre:
//Post:
    for(int i=(n-1);i>pos;i--){
        intercanvi(taula[i],taula[i-1]);
    }
}


void inserir_productes_ordenats(Taula_mercancia taula,int& n,int falten){
//Pre:
//Post:
    producte mercancia;
    int pos;
    for(int i=0;i<falten;i++){
        pos=0;
        mercancia=llegir_mercancia();
        while(taula[pos].codi < mercancia.codi && pos<n){
            pos++;
        }
        n++;
        moure_taula(taula,n,pos);
        taula[pos]=mercancia;
    }
}


void ordenar_taula_creixentment(Taula_mercancia taula,int n){
//Pre:
//Post:
    int pos_minim;
    for(int i=0;i<n-1;i++){
        pos_minim= buscar_el_minim(taula,i,n);
        intercanvi(taula[i],taula[pos_minim]);
    }
}

int main(){
    cout<< "Entra una sequencia de productes amb un codi enter i un preu real"<<endl;
    Taula_mercancia taula;
    int n;
    llegir_taula(taula,n);
    cout<< "Te'l mostrare:"<<endl;
    mostrar_taula(taula,n);
    cout<<"Be, ara te'l ordeno"<<endl;
    ordenar_taula_creixentment(taula,n);
    mostrar_taula(taula,n);
    cout<<"Queden més productes sense comptar? Quants?"<<endl;
    int falten;
    cin>>falten;
    inserir_productes_ordenats(taula,n,falten);
    cout<<"Te'l ensenyo"<<endl;
    mostrar_taula(taula,n);
    return 0;
}
