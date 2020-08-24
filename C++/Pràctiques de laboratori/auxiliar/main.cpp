#include<iostream>
using namespace std;
//Entrada: un nombre natural
//sortida: resultat del teorema de Euler
int euclides(int m,int n){
    //pre: cert
    //post: calcula el maxim comu dividor entre m i n
    int num1,num2,residu;
    num1=n;
    num2=m;
    while(num1%num2!=0){
        residu=num1%num2;
        num1=num2;
        num2=residu;
    }
    return num2;
}

int laboratori(int n){
    //Pre:n>2
    //Post:aplicació formula d'Euler
    int m,comptador;
    comptador = 0;
    for(int i=1;i<=n;i++){
        m=i;
        if(euclides(m,n)==1)comptador++;
    }
    return comptador;
}

int main(){
    int n;
    cout<< "ENTRA UN ENTER MAJOR O IGUAL A 2:"<<endl;
    cin>>n;
    cout<< "LA FUNCIO D'EULER DE "<<n<<" ES "<<laboratori(n);
    return 0;
}
