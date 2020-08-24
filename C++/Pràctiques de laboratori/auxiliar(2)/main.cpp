#include<iostream>
#include<string>
using namespace std;
//Entrada:Un nombre enter
//sortida:verificacio de si n es un nombre sociable

int suma_divisors(int m){
    int sumador=0;
    for(int i=1;i <= m/2 ;i++){
        if(m%i==0){
            sumador+=i;
    }
    }
    m=sumador;
    return m;
}

void comprovacio_sociabilitat(int m, int n){
    m=suma_divisors(m);
    if(m==n){
        cout<<m<<","<<endl;
        cout<<"ES PERFECTE";
    }
    else if(m!=n){
        cout<<m<<",";
        while(m!=n && m!=0){
            m=suma_divisors(m);
            cout<<m<<",";
        }
        cout<<endl;
        if(m==n){
            cout<<"NUMEROS SOCIABLES";
        }
        if(m==0){
            cout<< "NUMEROS NO SOCIABLES";
        }
    }
}


int main(){
    int n;
    int m;
    string resultat= "---";
    cout<< "INTRODUEIX UN NUMERO:"<<endl;
    cin>>n;
    m=n;
    cout<< "SERIE:"<<endl;
    comprovacio_sociabilitat(m,n);
    return 0;
}
