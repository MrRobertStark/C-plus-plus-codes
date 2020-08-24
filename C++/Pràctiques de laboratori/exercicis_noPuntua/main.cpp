#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const double PI = 3.14159;
//Entrada: un radi d'un cercle > 0
//Sortida: área del cerce i del quadrat circumscrit
void calcul_area(double radi,double & a_cercle,double & a_quadrat){
    //Pre: radi>0
    //Post:area del quadrat i del cercle
    a_cercle = PI*pow(radi,2);
    a_quadrat= 2*pow(radi,2);
}

int main(){
    cout<< "Entra un radi: ";
    double radi,a_cercle,a_quadrat;
    cin>>radi;
    calcul_area(radi,a_cercle,a_quadrat);
    cout<< "L'area del cercle és "<< a_cercle<<", la del quadrat és "<< a_quadrat<< "amb un radi "<<radi;
    return 0;
}
