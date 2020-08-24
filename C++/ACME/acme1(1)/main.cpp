#include<string>
#include<iostream>
using namespace std;
//Entrada: Una sèrie de comandes/info donades per l'usuari
//Sortida: resultats de les comandes introduïdes
const string EOS = "FI";
const int MAXIM_INCIDENTS=30;
const int MAXIM_POBLACIONS=200;
struct dada_vent{
    double velocitat;
    string dia;
    string hora;
};
struct tipus_dada{
    double litres;
    double neu;
    dada_vent vent;
    string Taula_Incidents[MAXIM_INCIDENTS];
    int n_incidents;
};
struct fitxa_poblacio{
    string nom_poblacio;
    string nom_comarca;
    tipus_dada fenomen_natural;
};
struct Gloria{
    int n_poblacions;
    fitxa_poblacio vec[MAXIM_POBLACIONS];
};
void inicialitzacio(fitxa_poblacio&dada)
//Pre: cert
//post: inicialitza les variables importants de "dada"
{
    dada.fenomen_natural.litres=0;
    dada.fenomen_natural.neu=0;
    dada.fenomen_natural.n_incidents=0;
    dada.fenomen_natural.vent.velocitat=0;
}
void mostrar_taula_incidents(tipus_dada dada)
//pre: dada.n_incidents>0 i dada.n_incidents<MAX_INCIDENTS
//post:mostra la taula d'incidents continguda a dada
{
    cout<<"-- ";
    int m=dada.n_incidents;
    for(int i=0;i<m;i++)cout<<dada.Taula_Incidents[i]<<" ";
}
void ensenyar_cella(fitxa_poblacio fitxa)
//Pre:cert
//Post:es mostra la informació continguda als elements de "fitxa" si n'hi ha
{
    cout<<fitxa.nom_comarca<<" "<<fitxa.nom_poblacio<<": ";
    if(fitxa.fenomen_natural.litres!=0)cout<<fitxa.fenomen_natural.litres<<" l/m2 ";
    if(fitxa.fenomen_natural.neu!=0)cout<<fitxa.fenomen_natural.neu<<" cm ";
    if(fitxa.fenomen_natural.vent.velocitat!=0)cout<<fitxa.fenomen_natural.vent.velocitat<<" km/h "<<fitxa.fenomen_natural.vent.dia<<" - "<<fitxa.fenomen_natural.vent.hora;
    if(fitxa.fenomen_natural.n_incidents!=0)mostrar_taula_incidents(fitxa.fenomen_natural);
    cout<<endl;
}
void mostra_taula(const Gloria& taula)
//Pre: taula.n_poblacions>0 i taula.n_poblacions<MAX_POBLACIONS
//Post:es mostra la informació de la taula "taula"
{
    if(taula.n_poblacions>0){
        for(int i=0;i<taula.n_poblacions;i++){
        ensenyar_cella(taula.vec[i]);
        }
    }
    else cout<< "No tenim dades"<<endl;
}
bool es_menor_poblacio(fitxa_poblacio dada1,fitxa_poblacio dada2)
//Pre: cert
//Post: dada1>dada2 o dada1<dada2
{
    return (dada1.nom_poblacio<dada2.nom_poblacio);
}
bool es_menor(fitxa_poblacio dada1,fitxa_poblacio dada2)
//Pre: cert
//Post: dada1>dada2 o dada1<dada2
{
    bool menor=false;
    if(dada1.nom_comarca<dada2.nom_comarca)menor=true;
    else if(dada1.nom_comarca==dada2.nom_comarca)menor=es_menor_poblacio(dada1,dada2);
    return menor;
}
void intercanvi(fitxa_poblacio& dada1,fitxa_poblacio& dada2)
//pre: a=A i b=B
//post: a=B i b=A
{
    fitxa_poblacio aux=dada1;
    dada1=dada2;
    dada2=aux;
}
void emplenar_info_pluja(fitxa_poblacio&aux)
//Pre:cert
//Post:s'emplena la informació buida de aux.pluja
{
    cin>>aux.fenomen_natural.litres;
}
void emplenar_info_neu(fitxa_poblacio&aux)
//Pre:cert
//post:s'emplena la informació buida de aux.neu
{
    cin>>aux.fenomen_natural.neu;
}
void emplenar_info_vent(fitxa_poblacio&vent)
//pre:cert
//post:s'emplena la informació buida de aux.vent.velocitat
{
    cin>>vent.fenomen_natural.vent.velocitat;
    cout<< "Dia i hora:"<<endl;
    cin>>vent.fenomen_natural.vent.dia;
    cin>>vent.fenomen_natural.vent.hora;
}
void emplenar_info_incidents(fitxa_poblacio&aux)
//pre:cert
//post:s'emplena la taula dels incidents d'aux.
{
    aux.fenomen_natural.n_incidents=0;
    string desastre;
    cin>>desastre;
    aux.fenomen_natural.Taula_Incidents[0]=desastre;
    aux.fenomen_natural.n_incidents++;
}
fitxa_poblacio llegir_dada()
//Pre:cert
//post: es llegeix i desa la informació que l'usuari vol emmagatzemar
{
    fitxa_poblacio aux;
    inicialitzacio(aux);
    cout<<"Poblacio:"<<endl;
    cin>>aux.nom_poblacio;
    if(aux.nom_poblacio!=EOS){
        cout<<"Comarca:"<<endl;
        cin>>aux.nom_comarca;
        cout<< "[p/n/v/i]:"<<endl;
        char tipus;
        cin>>tipus;
        cout<<"Dada:"<<endl;
        if(tipus=='p')emplenar_info_pluja(aux);
        else if(tipus=='n')emplenar_info_neu(aux);
        else if(tipus=='v')emplenar_info_vent(aux);
        else if(tipus=='i')emplenar_info_incidents(aux);
    }
    return aux;
}
void verificar_existencia_amb_pos_poblacio(const Gloria&taula,fitxa_poblacio aux,bool&trobat,int&pos)
//Pre:taula.n_poblacions>=0 i taula.n_poblacions<MAX_POBLACIONS
//Post: busca l'existència de taula.poblacio i la seva posicio
{
    int comptador;
    string comarca=taula.vec[pos].nom_comarca;
    if(taula.vec[pos].nom_poblacio>aux.nom_poblacio)comptador=-1;
    else if(taula.vec[pos].nom_poblacio<aux.nom_poblacio)comptador=1;
    while(pos>=0&&pos<taula.n_poblacions&&taula.vec[pos].nom_comarca==comarca&&taula.vec[pos].nom_poblacio!=aux.nom_poblacio)pos+=comptador;
    if(pos>=0&&pos<taula.n_poblacions&&taula.vec[pos].nom_comarca==comarca&&taula.vec[pos].nom_poblacio==aux.nom_poblacio)trobat=true;
}
void verificar_existencia_amb_pos(const Gloria&taula,fitxa_poblacio aux,bool&trobat,int&pos)
//Pre:taula.n_poblacions>=0 i taula.n_poblacions<MAX_POBLACIONS
//Post:busca l'existencia i pos a la taula la informació continguda a "aux"
{
    trobat=false;
    if(taula.n_poblacions>0)
    {
        int esq=0,dret=taula.n_poblacions-1,mig=(esq+dret)/2;
        while(esq!=dret-1&&taula.vec[mig].nom_comarca!=aux.nom_comarca){
            if(taula.vec[mig].nom_comarca>aux.nom_comarca)dret=mig;
            else esq=mig;
            mig=(esq+dret)/2;
        }
        if(taula.vec[mig].nom_comarca==aux.nom_comarca or taula.vec[dret].nom_comarca==aux.nom_comarca){
            pos=mig;
            verificar_existencia_amb_pos_poblacio(taula,aux,trobat,pos);
        }
    }
}
void actualitzar_valors(Gloria&taula,fitxa_poblacio aux,int pos)
//Pre: taula.n_poblacions>=0 i taula.n_poblacions<MAX_POBLACIONS
//Post:s'afegeix la informació de "aux" a la taula.vec[pos]
{
    taula.vec[pos].fenomen_natural.litres+=aux.fenomen_natural.litres;
    taula.vec[pos].fenomen_natural.neu+=aux.fenomen_natural.neu;
    if(taula.vec[pos].fenomen_natural.vent.velocitat<aux.fenomen_natural.vent.velocitat)taula.vec[pos].fenomen_natural.vent=aux.fenomen_natural.vent;
    if(aux.fenomen_natural.n_incidents>0){
        taula.vec[pos].fenomen_natural.Taula_Incidents[taula.vec[pos].fenomen_natural.n_incidents]=aux.fenomen_natural.Taula_Incidents[aux.fenomen_natural.n_incidents-1];
        taula.vec[pos].fenomen_natural.n_incidents++;
    }
}
void inserir_ordenar_limit1(Gloria&taula,fitxa_poblacio info)
//pre:taula.n_poblacions>=0 i taula.n_poblacions<MAX_POBLACIONS
//post:s'insereix per ordre de llindar decreixent "info"
{
    int i=taula.n_poblacions;
    taula.vec[taula.n_poblacions]=info;
    while(i>0&&taula.vec[i].fenomen_natural.litres>=taula.vec[i-1].fenomen_natural.litres){
        if(taula.vec[i].fenomen_natural.litres>taula.vec[i-1].fenomen_natural.litres)intercanvi(taula.vec[i],taula.vec[i-1]);
        else if(taula.vec[i].fenomen_natural.litres==taula.vec[i-1].fenomen_natural.litres&&es_menor(taula.vec[i],taula.vec[i-1]))intercanvi(taula.vec[i],taula.vec[i-1]);
        i--;
    }
    taula.n_poblacions++;
}
void inserir_ordenar_limit2(Gloria&taula,fitxa_poblacio info)
//pre:taula.n_poblacions>=0 i taula.n_poblacions<MAX_POBLACIONS
//post:s'insereix per ordre de llindar decreixent "info"
{
    int i=taula.n_poblacions;
    taula.vec[taula.n_poblacions]=info;
    while(i>0&&taula.vec[i].fenomen_natural.neu>=taula.vec[i-1].fenomen_natural.neu){
        if(taula.vec[i].fenomen_natural.neu>taula.vec[i-1].fenomen_natural.neu)intercanvi(taula.vec[i],taula.vec[i-1]);
        else if(taula.vec[i].fenomen_natural.neu==taula.vec[i-1].fenomen_natural.neu&&es_menor(taula.vec[i],taula.vec[i-1]))intercanvi(taula.vec[i],taula.vec[i-1]);
        i--;
    }
    taula.n_poblacions++;
}
void inserir_ordenar_limit3(Gloria&taula,fitxa_poblacio info)
//pre:taula.n_poblacions>=0 i taula.n_poblacions<MAX_POBLACIONS
//post:s'insereix per ordre de llindar decreixent "info"
{
    int i=taula.n_poblacions;
    taula.vec[taula.n_poblacions]=info;
    while(i>0&&taula.vec[i].fenomen_natural.vent.velocitat>=taula.vec[i-1].fenomen_natural.vent.velocitat){
        if(taula.vec[i].fenomen_natural.vent.velocitat>taula.vec[i-1].fenomen_natural.vent.velocitat)intercanvi(taula.vec[i],taula.vec[i-1]);
        else if(taula.vec[i].fenomen_natural.vent.velocitat==taula.vec[i-1].fenomen_natural.vent.velocitat&&es_menor(taula.vec[i],taula.vec[i-1]))intercanvi(taula.vec[i],taula.vec[i-1]);
        i--;
    }
    taula.n_poblacions++;
}
void mostra_poblacions_llindar(Gloria&taula)
//pre:taula.n_poblacions>=0 i taula.n_poblacions<MAX_POBLACIONS
//post:es mostra les poblacions que superen un llindar
{
    Gloria taula_aux;taula_aux.n_poblacions=0;
    cout<<"[p/v/n]:"<<endl;
    char classifica;cin>>classifica;
    cout<<"Llindar:"<<endl;
    int limit;cin>>limit;
    if(classifica=='p')
    {
        for(int i=0;i<taula.n_poblacions;i++){
            if(taula.vec[i].fenomen_natural.litres>limit){
                inserir_ordenar_limit1(taula_aux,taula.vec[i]);
            }
        }
    }
    else if(classifica=='n')
    {
        for(int i=0;i<taula.n_poblacions;i++){
            if(taula.vec[i].fenomen_natural.neu>limit){
                inserir_ordenar_limit2(taula_aux,taula.vec[i]);
            }
        }
    }
    else if(classifica=='v')
    {
        for(int i=0;i<taula.n_poblacions;i++){
            if(taula.vec[i].fenomen_natural.vent.velocitat>limit){
                inserir_ordenar_limit3(taula_aux,taula.vec[i]);
            }
        }
    }
    if(taula_aux.n_poblacions!=0)mostra_taula(taula_aux);
    else cout<< "Llindar no superat"<<endl;
}
void inserir_ordenat_comarca_poblacio(Gloria&taula,fitxa_poblacio pob)
//pre:taula.n_poblacions>=0 i taula.n_poblacions<MAX_POBLACIONS
//Post:s'insereix la informació de "pob" a la taula per ordre comarca-poblacio
{
    int i=taula.n_poblacions;
    taula.vec[i]=pob;
    while(i>0&&es_menor(taula.vec[i],taula.vec[i-1])){
        intercanvi(taula.vec[i],taula.vec[i-1]);
        i--;
    }
    taula.n_poblacions++;
}
void mostra_poblacio_desgraciat(const Gloria& taula)
//pre:taula.n_poblacions>=0 i taula.n_poblacions<MAX_POBLACIONS
//post:mostra la població amb més incidents
{
    int MAX=0;
    if(taula.n_poblacions>0){
        for(int i=0;i<taula.n_poblacions;i++){
            if(taula.vec[i].fenomen_natural.n_incidents>taula.vec[MAX].fenomen_natural.n_incidents)MAX=i;
        }
        ensenyar_cella(taula.vec[MAX]);
    }
    else cout<< "No hi ha incidents registrats"<<endl;
}
void actualitzar(Gloria&taula)
//pre:taula.n_poblacions>=0 i taula.n_poblacions<MAX_POBLACIONS
//Post:s'actualitzen els valors donats per l'usuari
{
    cout<<"Entra registres:"<<endl;
    fitxa_poblacio aux;
    aux=llegir_dada();
    int pos;bool trobat=false;
    while(taula.n_poblacions<MAXIM_POBLACIONS&&aux.nom_poblacio!=EOS){
        verificar_existencia_amb_pos(taula,aux,trobat,pos);
        if(not trobat)inserir_ordenat_comarca_poblacio(taula,aux);
        else actualitzar_valors(taula,aux,pos);
        aux=llegir_dada();
    }
}
void execucio_del_programa()
//Pre:cert
//Post:s'executa el programa principal seguint una sèrie de comandes
{
    string ordre;
    Gloria taula;taula.n_poblacions=0;
    cout<< "Opcio [a/m/c/r/s]:"<<endl;
    cin>>ordre;
    while(ordre!="s"){
        if(ordre=="a")actualitzar(taula);
        else if(ordre=="m")mostra_taula(taula);
        else if(ordre=="c")mostra_poblacio_desgraciat(taula);
        else mostra_poblacions_llindar(taula);
        cout<<endl;
        cout<< "Opcio [a/m/c/r/s]:"<<endl;
        cin>>ordre;
    }
}
int main()
{
    cout<< "REGISTRES TEMPORAL GLORIA"<<endl;cout<<endl;
    execucio_del_programa();
    return 0;
}
