#include<iostream>
using namespace std;
//Entrada:
//Sortida:
const int EOS=0;
const int MAX=100;
struct producte{
    int codi;
    double preu;
};
typedef producte Taula_productes[MAX];

producte llegir_producte()
//Pre:
//Post:
{
    producte p;
    cin>>p.codi;
    if(p.codi!=EOS)cin>>p.preu;
    return p;
}

void llegir_productes(Taula_productes taula,int&n)
//Pre:
//Post:
{
    producte p;
    p=llegir_producte();
    while(p.codi!=EOS && n<MAX){
        taula[n]=p;
        p=llegir_producte();
        n++;
    }
}

void ensenyar_cella(const Taula_productes taula,int n)
//Pre:
//Post:
{
    cout<<taula[n].codi<<" "<<taula[n].preu<<" "<<endl;
}

void ensenyar_productes(const Taula_productes taula,int n)
//Pre:
//Post:
{
    for(int i=0;i<n;i++)ensenyar_cella(taula,i);
}

int buscar_pos_minim(const Taula_productes taula,int n,int inici)
//Pre:
//Post:
{
    int pos_minim=inici;
    for(int i=inici;i<n;i++)if(taula[i].codi<taula[pos_minim].codi)pos_minim=i;
    return pos_minim;
}

void intercanviar (producte& mercancia1,producte& mercancia2){
//Pre:
//Post:
    producte aux=mercancia2;
    mercancia2=mercancia1;
    mercancia1=aux;
}

void ensenyar_productes_ordenats(Taula_productes taula,int n)
//Pre:
//Post:
{
    int pos_minim;
    for(int i=0;i<n;i++){
        pos_minim=buscar_pos_minim(taula,n,i);
        intercanviar(taula[i],taula[pos_minim]);
    }
    ensenyar_productes(taula,n);
}

int calcul_mig(int esq,int dret)
//pre:
//post:
{
    int resultat=(esq+dret)/2;
    return resultat;
}

int buscar_minim_rapidament(const Taula_productes taula,int n,int codi)
//Pre:
//Post:
{
    int esq=0;
    int dret=n-1;
    int mig=calcul_mig(esq,dret);
    while(esq!=dret-1)
    {
        if(taula[mig].codi<codi)esq=mig;
        else dret=mig;
        mig=calcul_mig(esq,dret);
    }
    return esq;
}

void afegir_producte_be(Taula_productes taula,int&n,int pos_minim,producte p)
//pre:
//Post:
{
    if(n+1<MAX){
        for(int i=n;i>=pos_minim+2;i--)taula[i]=taula[i-1];
        taula[pos_minim+1]=p;
    }
    n++;
}

void llegir_productes_ordenant(Taula_productes taula,int& n,int falten)
//Pre:
//Post:
{
    int minim;
    for(int i=0;i<falten;i++)
    {
        producte p=llegir_producte();
        minim=buscar_minim_rapidament(taula,n,p.codi);
        if(minim==0)minim-=1;
        else if(minim==n-2)minim++;
        afegir_producte_be(taula,n,minim,p);
    }
}

void busca_si_existeix_amb_pos(const Taula_productes taula,int n,int codi,bool& existencia,int& pos)
//Pre:
//Post:
{
    existencia=false;
    pos=buscar_minim_rapidament(taula,n,codi);
    if((taula[pos].codi==codi)or (taula[pos+1].codi==codi))existencia=true;
}

void llegir_codi_eliminant(Taula_productes taula,int& n)
//Pre:
//Post:
{
    int codi,pos;
    cin>>codi;
    bool existencia=false;
    busca_si_existeix_amb_pos(taula,n,codi,existencia,pos);
    if(existencia){
        for(int i=pos+1;i<n;i++)taula[i]=taula[i+1];
        n--;
    }
    else cout<<"No existeix"<<endl;

}
int main()
{
    cout<< "Entra una sequencia dels codis dels productes amb els seus preus acabades en 0"<<endl;
    Taula_productes taula;
    int n=0;
    llegir_productes(taula,n);
    cout<< "Te'ls mostro: "<<endl;
    ensenyar_productes(taula,n);
    cout<< "Tel's ordenaré creixentment i te'ls mostraré. Mira:"<<endl;
    ensenyar_productes_ordenats(taula,n);
    cout<< "Et queden productes  per posar? Quants?"<<endl;
    int falten;
    cin>>falten;
    cout<< "I quins productes son?:"<<endl;
    llegir_productes_ordenant(taula,n,falten);
    cout<<"Quedaria així:"<<endl;
    ensenyar_productes(taula,n);
    cout<<"Anem a esborrar el codi que m'entris."<<endl;
    llegir_codi_eliminant(taula,n);
    ensenyar_productes(taula,n);
    return 0;
}
