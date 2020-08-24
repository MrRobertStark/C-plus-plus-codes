#include<iostream>
using namespace std;
//Entrada: Temperatura, altitud i unitats de l'estat de l'aigua
//Sortida: Estat de l'aigua
int main(){
cout<< "Entra la temperatura en graus: ";
double temperatura;
cin>>temperatura;
cout<< "Entra C per Celsius o F per Fahrenheit: ";
char unitat_temperatura;
cin>>unitat_temperatura;
cout<< "Entra l'altitud sobre el nivell del mar: ";
double altitud;
cin>>altitud;
cout<< "Entra M per metres o P per peus: ";
char unitat_distancia;
cin>> unitat_distancia;

string estat1= "Solid";
string estat2= "Liquid";
string estat3= "Gas";
string estat;
double altura_definitiva=100-altitud/300.0;

if(unitat_temperatura= 'F')temperatura=(temperatura-32)/1.8;//De celsius a farenheit
if(unitat_distancia='P')altitud/3.2808; //De metres a peus
if(temperatura<=0)estat=estat1;
if(temperatura>0 && temperatura<altura_definitiva)estat=estat2;
else estat=estat3;
cout<<"Estat de l'aigua: "<<estat<<endl;
return 0;
}
