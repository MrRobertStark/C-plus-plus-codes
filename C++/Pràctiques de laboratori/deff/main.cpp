#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//Entrada:
//Sortida:
const int MAX=1000;
const string EOP="SORTIR";
struct tempo{
    int dia,mes,any;
};
struct info_tractament
{
    string codi;
    tempo data_entrada_pool;
    string grup_sanguini;
    string hospital;
    string ciutat;
    string codi_associat;
    string grup_sanguini_associat;
};
struct Taula_informacio
{
    info_tractament vec[MAX];
    int n;
};
void buscar_existencia_amb_pos(const Taula_informacio&taula,string codi,bool&trobat,int&pos)
//Pre:
//Post:
{
    int esq=0,dret=taula.n-1,mig=(esq+dret)/2;
    trobat=false;
        while(esq!=dret-1 && taula.vec[mig].codi!=codi){
            if(taula.vec[mig].codi>codi)dret=mig;
            else esq=mig;
            mig=(esq+dret)/2;
        }
        if(taula.vec[mig].codi==codi){
            trobat=true;
            pos=mig;
        }
        else if(taula.vec[dret].codi==codi){
            trobat=true;
            pos=dret;
        }
}
void ordenacio(Taula_informacio&taula)
//Pre:
//Post:
{
    info_tractament aux;int i=taula.n;
    while(i>0 && taula.vec[i].codi<taula.vec[i-1].codi){
            aux=taula.vec[i];
            taula.vec[i]=taula.vec[i-1];
            taula.vec[i-1]=aux;
            i--;
    }
}
void eliminar_dada( Taula_informacio&taula,int pos)
//Pre:
//Post:
{
    for(int i=pos;i<taula.n;i++)taula.vec[i]=taula.vec[i+1];
    taula.n--;
}
void llegir_fitxers_ordenant_taules(ifstream&fitxer_pacients,ifstream&fitxer_donants, Taula_informacio&pacients, Taula_informacio&donants)
//Pre:
//Post:
{
    info_tractament aux;
    bool trobat;
    int pos;
    pacients.n=donants.n=pos=0;
    while(pacients.n<MAX&&not fitxer_pacients.eof()){
        pacients.vec[pacients.n].codi_associat="0";
        fitxer_pacients>>pacients.vec[pacients.n].codi;
        fitxer_pacients>>pacients.vec[pacients.n].data_entrada_pool.dia;
        fitxer_pacients>>pacients.vec[pacients.n].data_entrada_pool.mes;
        fitxer_pacients>>pacients.vec[pacients.n].data_entrada_pool.any;
        fitxer_pacients>>pacients.vec[pacients.n].grup_sanguini;
        fitxer_pacients>>pacients.vec[pacients.n].hospital;
        fitxer_pacients>>pacients.vec[pacients.n].ciutat;
        pacients.n++;
        ordenacio(pacients);
    }
    while(donants.n<pacients.n && not fitxer_donants.eof()){
        fitxer_donants>>aux.codi;
        fitxer_donants>>aux.grup_sanguini;
        fitxer_donants>>aux.codi_associat;
        buscar_existencia_amb_pos(pacients,aux.codi_associat,trobat,pos);
        if(trobat){
            donants.vec[donants.n].codi=aux.codi;
            donants.vec[donants.n].grup_sanguini=aux.grup_sanguini;
            donants.vec[donants.n].codi_associat=pacients.vec[pos].codi;
            donants.vec[donants.n].grup_sanguini_associat=pacients.vec[pos].grup_sanguini;
            donants.vec[donants.n].ciutat=pacients.vec[pos].ciutat;
            donants.vec[donants.n].hospital=pacients.vec[pos].hospital;
            donants.vec[donants.n].data_entrada_pool=pacients.vec[pos].data_entrada_pool;
            donants.n++;
            ordenacio(donants);
        }
        pos=0;
        while(pos<pacients.n){
            if(pacients.vec[pos].codi_associat=="0")eliminar_dada(pacients,pos);
            else pos++;
        }
    }
    for(int i=0;i<pacients.n;i++)cout<<pacients.vec[i].codi<<endl;
    cout<<endl;
    for(int j=0;j<donants.n;j++)cout<<donants.vec[j].codi<<endl;
}
int main()
{
    cout<<"INTRODUEIX NOM FITXER DE PACIENTS:"<<endl;
    Taula_informacio pacients;
    Taula_informacio donants;
    string nom_fitxer_p,nom_fitxer_d;
    cin>>nom_fitxer_p;
    ifstream fitxer_pacients(nom_fitxer_p.c_str());
    if(not fitxer_pacients.fail()){
        cout<< "INTRODUEIX NOM FITXER DE DONANTS:"<<endl;
        cin>>nom_fitxer_d;
        ifstream fitxer_donants(nom_fitxer_d.c_str());
        if(not fitxer_donants.fail()){
            llegir_fitxers_ordenant_taules(fitxer_pacients,fitxer_donants,pacients,donants);
            //execucio_del_programa(pacients,donants);
        }
        else cout<< "ERROR OBERTURA FITXER";
    }
    else cout<< "ERROR OBERTURA FITXER";
    return 0;
}

