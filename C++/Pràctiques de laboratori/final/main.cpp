#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;
//Entrada:
//Sortida:
const int MAX=100;
struct Info_Cripto{
    int codi;
    int n_aparicions=0;
};
typedef Info_Cripto Taula_Info[MAX];
void ensenyar_posicio(Info_Cripto m)
//Pre:
//Post:
{
    cout<<m.codi<<" "<<m.n_aparicions<<endl;
}
void mostrar_taula(Taula_Info taula,int n)
//Pre:
//Post:
{
    for(int i=0;i<n;i++)ensenyar_posicio(taula[i]);
}
void intercanviar(Info_Cripto&a,Info_Cripto&b)
//Pre:
//Post:
{
    Info_Cripto aux=a;
    a=b;
    b=aux;
}
Info_Cripto llegir_dada(ifstream&fitxer)
//Pre:
//Post:
{
    Info_Cripto aux;
    if(not fitxer.eof())fitxer>>aux.codi;
    if(aux.codi<0)aux.codi*=-1;
    return (aux);
}
void verificar_existencia_per_sumar_n_aparicions(Taula_Info taula,int n,Info_Cripto aux,bool&trobat)
//Pre:
//Post:
{
    trobat=false;
    for(int i=0;i<n;i++)
    {
        if(taula[i].codi==aux.codi)
        {
            trobat=true;
            taula[i].n_aparicions++;
        }
    }
}
void si_no_existia_afegir_taula(Taula_Info taula,int&n,Info_Cripto aux,bool trobat)
//Pre:
//Post:
{
    if(not trobat)
    {
        taula[n]=aux;
        n++;
    }
}
void llegir_fitxer_sumant_aparicions(Taula_Info taula,int& n,ifstream&fitxer)
//Pre:
//Post:
{
    bool trobat=false;
    Info_Cripto aux=llegir_dada(fitxer);
    while(n<MAX && not fitxer.eof())//He posat la condicio?
    {
        verificar_existencia_per_sumar_n_aparicions(taula,n,aux,trobat);
        si_no_existia_afegir_taula(taula,n,aux,trobat);
        aux=llegir_dada(fitxer);
    }
}
int buscar_pos_minim(Taula_Info taula,int n,int inici,int&pos_minim)
//Pre:
//Post:
{
    pos_minim=inici;
    for(int i=inici;i<n;i++)if(taula[pos_minim].codi>taula[i].codi)pos_minim=i;
    return pos_minim;
}
void ordenar_taula(Taula_Info taula,int n)
//Pre:
//Post:
{
    int pos_minim=0;
    for(int i=0;i<n;i++)
    {
        pos_minim=buscar_pos_minim(taula,n,i,pos_minim);//Error? he posat un paràmetre innecesari?(pos_minim)
        intercanviar(taula[i],taula[pos_minim]);
    }
}
int main()
{
    ifstream fitxer("b.dat");
    Taula_Info taula;
    int n=0;
    llegir_fitxer_sumant_aparicions(taula,n,fitxer);cout<<"La taula resultant seria aquesta:"<<endl;
    mostrar_taula(taula,n);
    ordenar_taula(taula,n);cout<<"Ordenada quedaria així: "<<endl;
    mostrar_taula(taula,n);
    return 0;
}
