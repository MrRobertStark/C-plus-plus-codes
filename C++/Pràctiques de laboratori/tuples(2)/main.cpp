#include<iostream>
using namespace std;
const int EOS=0;
struct Data_any{
    int dia;
    int mes;
    int any;
};

Data_any llegir_data(){
    //pre:
    //post:
    Data_any data;
    cin>>data.dia;
    if(data.dia!=EOS){
        cin>>data.mes>>data.any;
    }
    return data;<
}

int main(){
    cout<< "Entra una sequencia de dates per veure si n'hi ha algun 29 de febrer:"<<endl;
    Data_any data;
    bool trobat = false;
    cin>>data.dia;
    if(data.dia!=EOS){
        cin>>data.mes>>data.any;
        while(data.dia!=EOS && not trobat){
            if(data.dia==29 && data.mes==2)trobat=true;
            else data=llegir_data();
        }
    }
    if(trobat)cout<<"Trobat"<<endl;
    else cout<<"No trobat"<<endl;
    return 0;
}
