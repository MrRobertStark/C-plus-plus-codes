#include <iostream>

using namespace std;

//L'aplicació calcula els dies, hores, segons dels segons totals indicat per l'usuari
int main(){

cout<< "De quant segons disposem?"<<endl;
int temps_total;
cin>>temps_total;
cout<< "El nombre representa:" <<endl;
const int SEGONS_DIES = 86400;
int dies_totals = temps_total/SEGONS_DIES;
const int SEGONS_HORES = 3600;
int hores_totals = temps_total/SEGONS_HORES;
const int SEGONS_MINUT = 60;
int minuts_totals = (temps_total/SEGONS_MINUT)%60;
int segons_totals = temps_total%60;
cout<< dies_totals<< "dies, " << hores_totals<< "hores, "<< minuts_totals<< "minuts i "<<segons_totals<< "segons."<<endl;
return 0;
}
