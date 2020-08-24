#include<iostream>
#include<string>
using namespace std;
//Entrada: dia,mes i any
//Sortida: el dia de la semana que correspon en l'entrada

int correcio_mes(int mes){
    if((mes==1) | (mes==2))mes+=12;
    return mes;
}
int correcio_any(int mes,int any){
    if((mes==13) | (mes==14))any-=1;
    return any;
}
void resultat(int w){
    if(w==0)cout<<"Dilluns";
    else if(w==1)cout<<"Dimarts";
    else if(w==2)cout<<"Dimecres";
    else if(w==3)cout<<"Dijous";
    else if(w==4)cout<<"Divendres";
    else if(w==5)cout<<"Dissabte";
    else cout<<"Diumenge";
}

void calcul_dia_setmana(int dia,int mes,int any){
    mes = correcio_mes(mes);
    any = correcio_any(mes,any);
    int w=(dia+5+(26*(mes+1))/10+(5*(any%100))/4+(21*(any/100))/4)%7;
    resultat(w);
}

int main(){
    int dia,mes, any;
    cout<<"Entre el dia (1-31): ";
    cin>>dia;
    cout<<"Entre el mes (Gen=1, Feb=2, Mar=3, ...): ";
    cin>>mes;
    cout<<"Entre l'any (4 xifres): ";
    cin>>any;
    calcul_dia_setmana(dia,mes,any);
    return 0;
}
