#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX=100;
const int EOS=0;
//Entrada:
//Sortida:
struct botiga{
    int edat;
    int districte;
    double compra;
    int hores;
    int minuts;
};
typedef botiga Taula_botiga[MAX];

botiga llegir_info(ifstream&fitxer)
//Pre:
//Post:
{
    botiga b;
    fitxer>>b.edat;
    if(b.edat!=0){
        fitxer>>b.districte>>b.compra>>b.hores>>b.minuts;
    }
    return b;
}
void elimina_copia(Taula_botiga taula,int&n)
//Pre:
//Post:
{
    for(int i=0;i<n-1;i++)
    {
        if(taula[i].edat==taula[n-1].edat){
            taula[i].compra+=taula[n-1].compra;
            taula[i].hores+=taula[n-1].hores;
            taula[i].minuts+=taula[n-1].minuts;
            n--;
        }
    }
}
void mostrar_cella(botiga b)
//Pre:
//Post:
{
    cout<<b.edat<<" "<<b.compra<<" "<<(b.hores*60)+b.minuts<<endl;
}
void mostrar_taula(Taula_botiga taula,int n)
//Pre:
//Post:
{
    for(int i=0;i<n;i++)
    {
        mostrar_cella(taula[i]);
    }
}
void llegir_taula_del_fitxer_eliminant_copies_i_mostrar(Taula_botiga taula,int&n,ifstream&fitxer)
//Pre:
//Post:
{
    n=0;
    botiga info_compra=llegir_info(fitxer);
    while(info_compra.edat!=0&&n<MAX)
    {
        taula[n]=info_compra;
        elimina_copia(taula,n,info_compra);
        n++;
        info_compra=llegir_info(fitxer);
    }
    mostrar_taula(taula,n);
}

int buscar_minim(Taula_botiga taula,int n,int inici)
//Pre:
//Post:
{
    int minim=inici;
    for(int i=inici;i<n;i++)if(taula[i]<taula[inici])minim=i;
    return minim;
}
void intercanvi(botiga a,botiga b)
//Pre:
//Post:
{
    botiga aux=a;
    a=b;
    b=aux;
}

void ordenar_taula_i_mostrar(Taula_botiga taula,int n)
//Pre:
//Post:
{
    int pos_minim=0;
    for(int i=0;i<n-1;i++){
        pos_minim=buscar_minim(taula,n,i);
        intercanvi(taula[i],taula[pos_minim]);
    }
    mostrar_taula(taula,n);
}
double despesa_per_minut(Taula_botiga taula,int n)
//Pre:
//Post:
{
    double total_diners,total_temps;
    total_diners=total_temps=0;
    for(int i=0;i<n;i++){
        total_diners+=taula[i].compra;
        total_temps+= taula[i].hores*60 + taula[i].minuts;
    }
    double resultat=(total_diners/total_temps);
    if(total_temps==0)resultat=0;
    return (resultat);
}
int calcul_mig(int esq,int dret)
//Pre:
//Post:
{
    int resultat=(esq+dret)/2;
    return resultat;
}
bool existeix(Taula_botiga taula,int n,int edat)
//Pre:
//Post:
{
    int esq=0;
    int dret=n-1;
    int mig=calcul_mig(esq,dret);
    while(esq!=dret-1 && taula[mig].edat!=edat)
    {
        if(taula[mig].edat>edat)dret=mig;
        else esq=mig;
        mig=calcul_mig(esq,dret);
    }
    bool trobat=((taula[mig].edat==edat) or (taula[mig+1].edat==edat));
    return trobat;
}
int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    Taula_botiga taula;
    int n;
    cout<< "NOM DEL FITXER DE TEXT:"<<endl;
    string nom_fitxer;
    cin>>nom_fitxer;
    ifstream fitxer (nom_fitxer.c_str());
    if(not fitxer.fail()){
        cout<< "RESUM DE LES COMPRES REALITZADES (SEGONS ORDRE D'ENTRADA DE LES EDATS):"<<endl;
        llegir_taula_del_fitxer_eliminant_copies_i_mostrar(taula,n,fitxer);
        cout<< "RESUM DE LES COMPRES REALITZADES (ORDENAT PER EDAT, ASCENDENT):"<<endl;
        ordenar_taula_i_mostrar(taula,n);
        cout<< "DESPESA PER MINUT: "<<despesa_per_minut(taula,n)<< " EUROS/MINUT"<<endl;
        cout<<endl;
        cout<<"ENTRAR UNA EDAT:"<<endl;
        int edat;
        cin>>edat;
        if(existeix(taula,n,edat))cout<< "HI HA ALGU DE "<<edat<<" ANYS QUE HA COMPRAT"<<endl;
        else cout<< "NO HI HA NINGU DE "<<edat<<" ANYS QUE HAGI COMPRAT"<<endl;
    }
    else cout<< "NO S'HA TROBAT EL FITXER";
    return 0;
}
//me falta corregir el temps (hora-entrada i hora-sortida).
