#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX=100;
const int EOS=0;
const int MINUTS_REALS=60;
//Entrada:sequencia amb informació d'una serie de compres realitzades en una botiga a partir d'un fitxer
//Sortida:escriure la informacio tractant els copiats desordenadament i ordenadament, el preu/minut i si existeix algun usuari amb una característica

struct botiga{
    int edat;
    int districte;
    double compra;
    int h_entrada;
    int h_sortida;
};
typedef botiga Taula_Botiga[MAX];
int calcul_mig(int esq,int dret)
//Pre:0<=esq<dret i esq<dret<n
//Post: retorna el terme mig entre tots dos valors
{
    int mig=(esq+dret)/2;
    return mig;
}
bool ja_existia(const Taula_Botiga taula,int n,int edat)
//Pre: Taula[0..n-1] i 0<=n<=MAX. edat>0
//Post:retorna cert si existeix el terme edat a la taula
{
    bool trobat=false;
    if(n>=2){
        int esq=0;
        int dret=n-1;
        int mig=calcul_mig(esq,dret);
        while(taula[mig].edat!=edat && esq!=dret-1)
        {
            if(taula[mig].edat<edat)esq=mig;
            else dret=mig;
            mig=calcul_mig(esq,dret);
        }
        if(taula[mig].edat==edat or taula[dret].edat==edat)trobat=true;
    }
    if(taula[0].edat==edat or taula[1].edat==edat)trobat=true;
    return trobat;
}
int arreglar_temps(int&temps)
//Pre: temps>0
//Post:arregla el temps entrada en cas que hi hagi una suma de minuts impossible
{
    int hores=temps/100;
    int minuts=temps%100;
    while(minuts>=MINUTS_REALS)
    {
        minuts-=MINUTS_REALS;
        hores++;
    }
    return (temps=hores*100+minuts);
}
void sumar_temps_i_preu(Taula_Botiga taula,int n,int pos,botiga b)
//Pre: Taula[0..n-1] i 0<=n<=MAX. b.edat!=0 i b.h_entrada<=b.h_sortida
//Post: suma el temos i el preu de les dades noves les quals edats ja existien previament a la taula
{
    taula[pos].h_sortida+=(b.h_sortida-b.h_entrada);
    taula[pos].h_sortida=arreglar_temps(taula[pos].h_sortida);
    taula[pos].compra+=b.compra;
}
botiga llegir_dada_compra(ifstream&fitxer)
//Pre: QUE EL FITXER EXISTEIXI
//Post: recull informació del fitxer
{
    botiga b;
    fitxer>>b.edat;
    if(b.edat>0)fitxer>>b.districte>>b.compra>>b.h_entrada>>b.h_sortida;
    return b;
}
void llegir_dada(ifstream&fitxer,botiga& b)
//Pre: Fitxer existeixi
//Post;retorna una b amb la informació adient del fitxer
{
    b=llegir_dada_compra(fitxer);
    while(b.edat!=0 && b.h_entrada>b.h_sortida){
        b=llegir_dada_compra(fitxer);
    }
}
void mostrar_cella(botiga b)
//Pre: b.edat!=0
//Post:ensenya la informacio continguda a la variable b
{
    int temps_total=(b.h_sortida/100*60+b.h_sortida%100)-(b.h_entrada/100*60+b.h_entrada%100);
    cout<<b.edat<<" "<<b.compra<<" "<<temps_total<<endl;
}
void mostrar_taula(const Taula_Botiga taula,int n)
//Pre: Taula[0..n-1] i 0<=n<=MAX
//Post: ensenya la taula
{
    for(int i=0;i<n;i++)mostrar_cella(taula[i]);
    cout<<endl;
}
bool existeix(const Taula_Botiga taula,int n,int edat,int& pos)
//Pre:Taula[0..n-1] i 0<=n<=MAX
//Post: retorna cert si l'edat existia previament a la taula i guarda la seva posicio
{
    bool trobat=false;
    int i=0;
    while(i<n-1 && taula[i].edat!=edat)
    {
        i++;
    }
    pos=i;
    if(taula[i].edat==edat)trobat=true;
    return trobat;
}
void llegir_fitxer_eliminant_mateixes_edats_i_sumant_dades_i_mostrar(ifstream&fitxer,Taula_Botiga taula,int&n)
//Pre:Que el fitxer existeixi.Taula[0..n-1] i 0<=n<=MAX
//Post: llegeix el fitxer entrat afegint la informacio interessada en cas que l'edat ja existís previament i sinó afegir a la taula. Finalment,mostrar-la
{
    n=0;
    botiga b;
    llegir_dada(fitxer,b);
    int pos;
    while(n<MAX && b.edat!=0)
    {
        if(existeix(taula,n,b.edat,pos))
        {
            sumar_temps_i_preu(taula,n,pos,b);
        }
        else {
            taula[n]=b;
            n++;
        }
        llegir_dada(fitxer,b);
    }
    mostrar_taula(taula,n);
}
void intercanviar(botiga& a,botiga& b)
//Pre: a.edat!=0 i b.edat!=0
//Post: intercanvia valors de a i b
{
    botiga aux=a;
    a=b;
    b=aux;
}
void ordenar_taula_ascendentment_i_mostrar(Taula_Botiga taula,int n)
//Pre: Taula[0..n-1] i 0<=n<=MAX
//Post: ordena la taula ascendentment
{
    int j;
    for(int i=0;i<n-1;i++)
    {
        j=i+1;
        while(j>0 && taula[j].edat<taula[j-1].edat){
            intercanviar(taula[j],taula[j-1]);
            j--;
        }
    }
    mostrar_taula(taula,n);
}
double calcul_despesa_per_minut(const Taula_Botiga taula,int n)
//Pre:Taula[0..n-1] i 0<=n<=MAX
//Post: retorna la divisió entre el total de diners de la taula i el total de temps.
{
    double total_preu;
    int total_temps,aux_temps;
    total_preu=total_temps=aux_temps=0;
    for(int i=0;i<n;i++)
    {
        total_preu+=taula[i].compra;
        aux_temps=(taula[i].h_sortida-taula[i].h_entrada);
        total_temps+=(aux_temps/100*60)+aux_temps%100;
    }

    return(total_preu/total_temps);
}
int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<< "NOM DEL FITXER DE TEXT:"<<endl;
    string nom_fitxer;
    cin>>nom_fitxer;
    cout<<endl;
    ifstream fitxer(nom_fitxer.c_str());
    Taula_Botiga taula;
    int n;
    if(not fitxer.fail())
    {
        cout<< "RESUM DE LES COMPRES REALITZADES (SEGONS ORDRE D'ENTRADA DE LES EDATS):"<<endl;
        llegir_fitxer_eliminant_mateixes_edats_i_sumant_dades_i_mostrar(fitxer,taula,n);
        cout<< "RESUM DE LES COMPRES REALITZADES (ORDENAT PER EDAT, ASCENDENT):"<<endl;
        ordenar_taula_ascendentment_i_mostrar(taula,n);
        cout<< "DESPESA PER MINUT: "<<calcul_despesa_per_minut(taula,n)<<" EUROS/MINUT"<<endl;
        cout<<endl;
        cout<< "ENTRAR UNA EDAT:"<<endl;
        int edat_nou;
        cin>>edat_nou;
        if(ja_existia(taula,n,edat_nou))cout<< "HI HA ALGU DE "<<edat_nou<<" ANYS QUE HA COMPRAT";
        else cout<< "NO HI HA NINGU DE "<<edat_nou<<" ANYS QUE HAGI COMPRAT";
    }
    else cout<< "NO S'HA TROBAT EL FITXER";
    return 0;
}
