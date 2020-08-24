#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int EOS=0;
const int MAX=100;
const int MINUTS_REALS=60;
//Entrada:
//Sortida:
struct temps{
    int hores;
    int minuts;
};
struct botiga{
    int edat;
    int districte;
    double preu;
    temps h_entrada;
    temps h_sortida;
    int temps_total;
};
typedef botiga Taula_Botiga[MAX];
botiga llegir_dada(fitxer)
//Pre:
//Post:
{
    botiga b;
    int temps;
    fitxer>>b.edat;
    if(b.edat!=0){
        b.districte>>b.preu>>temps;
        b.h_entrada.hores=temps/100;
        b.h_entrada.minuts=temps%100;
        fitxer>>temps;
        b.h_sortida.hores=temps/100;
        b.h_sortida.minuts=temps%100;
    }
    return b;
}
botiga llegir_dades_eliminant_cronologia_impossible(ifstream&fitxer)
//Pre:
//Post:
{
    botiga b=llegir_dada(fitxer);
    while(b.h_entrada.hores<=b.h_sortida.hores && b.h_sortida.minuts>b.h_entrada.minuts)
    {
        b=llegir_dada(fitxer);
    }
    return b;
}
void arreglar_el_temps(int& hores,int& minuts)
//Pre:
//Post:
{
    while(minuts>=MINUTS_REALS)
    {
        minuts-=MINUTS_REALS;
        hores++;
    }
}
void eliminacio_mateixes_edats_sumant_dades(Taula_Botiga taula,int&n,b)
//Pre:
//Post:
{
    for(int i=0;i<n-1;i++)
    {
        if(taula[i].edat==taula[n-1].edat)
        {
            taula[i].preu+=taula[n-1].preu;
            taula[i].h_sortida.minuts+=abs(taula[n-1].h_sortida.minuts-taula[n-1].h_entrada.minuts);
            taula[i].h_sortida.minuts+=((abs(taula[n-1].h_sortida.hores-taula[n-1].h_entrada.hores))*60);//Si hi ha una copia suma els diners i afegeix temps a la hora final en minuts a taula[i]
            arreglar_el_temps(taula[i].h_entrada.hores,taula[i].h_entrada.minuts);//Fes els canvis més adients perquè els minuts no siguin superiors a 60
        }
    }
}
void llegir_fitxer_eliminant_mateixes_edats_i_cronologia_impossible(Taula_Botiga taula,int&n,ifstream&fitxer)
//Pre:
//Post:
{
    n=0;
    botiga b=llegir_dades_eliminant_cronologia_impossible(fitxer);
    while(b.edat>0&&n<MAX)
        {
        taula[n]=b;
        eliminacio_mateixes_edats_sumant_dades(taula,n,b);
        n++;
        b=llegir_dades_eliminant_cronologia_impossible(fitxer);
        }
}
int calcul_temps_total(int h_entrada,int h_sortida,int m_entrada,int m_sortida)
//Pre:
//Post:
{
    int total=abs(h_entrada-h_sortida)*60+(m_entrada+m_sortida);
    return total;
}
void ensenyar_cella(botiga b)
//Pre:
//Post:
{
    cout<<b.edat<<" "<<b.preu<<" ";
    b.temps_total=calcul_temps_total(b.h_entrada.hores,b.h_sortida.hores,b.h_entrada.minuts,b.h_sortida.minuts);
    cout<<b.temps_total<<endl;
}
void mostrar_taula(Taula_botiga taula,int n)
//Pre:
//Post:
{
    for(int i=0;i<n;i++)
        ensenyar_cella(taula[i]);
}
int buscar_minim(Taula_botiga taula,int n,int inici)
//Pre:
//Post:
{
    int minim=inici;
    for(int i=inici;i<n;i++)
    {
        if(taula[minim].edat>taula[i].edat)minim=i;
    }
    return minim;
}
void intercanviar(botiga&a,botiga&b)
//Pre:
//Post:
{
    botiga aux=a;
    a=b;
    b=aux;
}
void ordenar_taula_ascendentment_i_mostrar(Taula_Botiga taula,int n)
//Pre:
//Post:
{
    int pos_minim=0;
    for(int i=0;i<n-1;i++)
    {
        pos_minim=buscar_minim(taula,n,i);
        intercanviar(taula[i],taula[pos_minim]);
    }
    mostrar_taula(taula,n);
}
int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    Taula_Botiga taula;
    int n;
    cout<< "NOM DEL FITXER DE TEXT:"<<endl;
    string nom_fitxer;
    cin>>nom_fitxer;
    ifstream fitxer(nom_fitxer.c_str());
    if(not fitxer.fail()){
        llegir_fitxer_eliminant_mateixes_edats_i_cronologia_impossible(taula,n,nom_fitxer);
        cout<< "RESUM DE LES COMPRES REALITZADES (SEGONS ORDRE D'ENTRADA DE LES EDATS):"<<endl;
        mostrar_taula(taula,n);
        cout<< "RESUM DE LES COMPRES REALITZADES (ORDENAT PER EDAT, ASCENDENT):"<<endl;
        ordenar_taula_ascendentment_i_mostrar(taula,n);
        cout<< "DESPESA PER MINUT: "//CONTINUAR A PARTIR DE AQUI,PLIS//
    }
    else cout<< "NO S'HA TROBAT EL FITXER";
}
