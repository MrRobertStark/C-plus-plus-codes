#include <iostream>

using namespace std;

//Entrada: n>=0//Sortida:Es verifica que n és potencia de 2

void llegir_enter(long long&n)
//pre:cert//post:n>=0
{
    do{
        cout<< "ENTRA UN VALOR ENTER POSITIU (0 PER ACABAR):"<<endl;
        cin>>n;
    }while(n<0);
}
long long potencia(int base,int exponent)
//pre:base>=0 exponent>=0
{
    long long resultat;
    if(exponent==0)resultat=1;
    else if(exponent==1)resultat=base;
    else if(exponent%2==0)resultat=potencia(base*base,exponent/2);
    else if(exponent%2!=0)resultat=base*potencia(base*base,(exponent-1)/2);

    return resultat;
}

bool i_es_potencia(long long limit,int base,int exponent)
//pre: base>=0 potencia>=0
{
    long long resultat= potencia(base,exponent); bool correcte;

    if(resultat>=limit)correcte=(resultat==limit);
    else correcte=i_es_potencia(limit,base,exponent+1);

    return correcte;
}
bool es_potencia(long long nombre)
//pre:n>0 //post: n és potencia de 2 o no
{
    int base=2,exponent=0;
    return i_es_potencia(nombre,base,exponent);
}

int main()
{
    long long n; llegir_enter(n);
    while(n!=0)
    {
        if(es_potencia(n))cout<<n<<" ES POTENCIA DE 2"<<endl;
        else cout<<n<<" NO ES POTENCIA DE 2"<<endl;
        llegir_enter(n);
    }
    return 0;
}
