#include <iostream>
#include <cmath>
using namespace std;
//Entrada:
//Sortida:

struct punt{
    int x;
    int y;
};
struct cercle{
    punt origen;
    int radi;
};

punt llegir_punt(){
    punt p;
    cin>>p.x>>p.y;
    return p;
}

cercle llegir_cercle(){
    cercle cer;
    cer.origen =llegir_punt();
    cout<<"I el radi? "<<endl;
    cin>>cer.radi;
    return cer;
}

double distancia_entre_punts(punt p,punt q){
    double distancia= abs((p.x-q.x)*(p.x-q.x)-(p.y)*(q.y));
    return sqrt(distancia);
}

bool pertany(cercle cer,punt q){
    double distancia = distancia_entre_punts (cer.origen,q);
    return (distancia<=cer.radi);
}

int main(){
    cout<<" Entra l'origen de la circumferència i a més a més el seu radi: "<<endl;
    cercle cer= llegir_cercle();
    cout<< "Entra el punt a analitzar"<<endl;
    punt p = llegir_punt();
    if(pertany(cer,p))cout<< "Si";
    else cout<< "No";
    return 0;
}
