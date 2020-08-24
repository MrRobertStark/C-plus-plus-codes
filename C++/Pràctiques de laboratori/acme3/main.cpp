#include <iostream>
using namespace std;
//Entrada: Una data en format de 3 naturals consecutius indicant dia, mes i any
//Sortida: Si el dia funciona o no
int main(){
    cout<< "Data format <dia> <mes> <any>: "<<endl;
        unsigned dia,mes,any;
        cin>>dia>>mes>>any;
        string resultat;

        if (any>1583){ //Comprovació any
            if (mes<=12 && mes>=1){ //Comprovació mes
                if (mes==1){
                    if (dia<=30 && dia>=1)resultat="Valida";
                    else resultat= "Incorrecta";
                }
                else if(mes==3){
                    if (dia<=31 && dia>=1)resultat="Valida";
                    else resultat= "Incorrecta";
                }
                else if(mes==4){
                    if (dia<=30 && dia>=1)resultat="Valida";
                    else resultat= "Incorrecta";
                }
                else if(mes==5){
                    if (dia<=31 && dia>=1)resultat="Valida";
                    else resultat= "Incorrecta";
                }
                else if(mes==6){
                    if (dia<=30 && dia>=1)resultat="Valida";
                    else resultat= "Incorrecta";
                }
                else if(mes==7){
                    if (dia<=31 && dia>=1)resultat="Valida";
                    else resultat= "Incorrecta";
                }
                else if(mes==8){
                    if (dia<=31 && dia>=1)resultat="Valida";
                    else resultat= "Incorrecta";
                }
                else if(mes==9){
                    if (dia<=30 && dia>=1)resultat="Valida";
                    else resultat= "Incorrecta";
                }
                else if(mes==10){
                    if (dia<=31 && dia>=1)resultat="Valida";
                    else resultat= "Incorrecta";
                }
                else if(mes==11){
                    if (dia<=30 && dia>=1)resultat="Valida";
                    else resultat= "Incorrecta";
                }
                else if(mes==12){
                    if (dia<=31 && dia>=1)resultat="Valida";
                    else resultat= "Incorrecta";
                }
                else{
                    if(mes==2){
                        bool trespas(any%4==0 && any%100!=0 | any%400==0);
                            if (trespas) {
                                    if(dia<=29 && dia>=1)resultat="Valida";
                        }
                        else resultat= "Incorrecta";
                        }
                        else if (dia<=28 && dia>=1)resultat="Valida";
                        else resultat= "Incorrecta";

                }
            }
            else resultat= "Incorrecta";
        }
        else resultat= "Incorrecta";
    cout<<resultat;
    return 0;
}

