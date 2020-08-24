#include <iostream>

using namespace std;

void valors_amb_separadors_de_milers(long long nombre)
//pre:nombre>0//post:s'escriu nombre amb separados de milers
{
    if(nombre<1000)
        cout<<nombre;

    else
    {
        valors_amb_separadors_de_milers(nombre/1000);
        long long aux=nombre%1000;
        cout<<'.'<<(aux/100)<<(aux%100)/10<<aux%10;
    }
}
void representacio_xifres(long long nombre,int comptador)
//pre:nombre>0//post:n_xifres>0
{
    if(comptador==0)
    {
        valors_amb_separadors_de_milers(nombre);
        cout<<" ";
    }

    else
    {
        representacio_xifres(nombre,comptador-1);
        cout<<" ";
        valors_amb_separadors_de_milers(nombre+comptador);
    }
}

int main()
{

    long long nombre;
    do{
        cout<< "ENTRA UN ENTER POSITIU:"<<endl;
        cin>>nombre;
    }while(nombre<0);

    int n_xifres;
    do{
        cout<< "QUANTS VALORS VOLS MOSTRAR (N>0)?"<<endl;
        cin>>n_xifres;
    }while(n_xifres<=0);

    representacio_xifres(nombre,n_xifres-1);

    return 0;
}
