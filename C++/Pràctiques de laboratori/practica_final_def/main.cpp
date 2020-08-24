#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//Entrada: Els dos noms dels fitxers que inclouen informació de pacients i donants relacionats amb transplantaments de ronyons.
//Sortida:tota mena de consultes i modificacions via comanda entrat per teclat.
const int MAX=1000;
const string EOP="SORTIR";
struct tempo{
    int dia;
    int mes;
    int any;
};
struct info_hospital{
    string codi;
    tempo data_entrada_pool;
    string grup_sanguini;
    string hospital;
    string ciutat;
    string codi_associat;
    string grup_sanguini_associat;
};
struct Taula_Info{
    info_hospital vec[MAX];//typedef int Taula_Enter[MAX]
    int n;
};
void verificar_existencia_codi_pacient_o_donant_associat_amb_pos(const Taula_Info&taula,string codi,bool&trobat,int&pos)
//Pre: 0<=taula.n<=MAX.
//Post: verificació de si el codi a cercar es troba a la taula demanada juntament amb la seva posició.
{
    trobat=false;
    int esq,dret,mig;
    esq=0;dret=taula.n-1;mig=(esq+dret)/2;
    while(esq!=dret-1&&taula.vec[mig].codi!=codi){
        if(taula.vec[mig].codi>codi)dret=mig;
        else esq=mig;
        mig=(esq+dret)/2;
    }
    if(taula.vec[mig].codi==codi){
        pos=mig;
        trobat=true;
    }
    else if(taula.vec[dret].codi==codi){
        pos=dret;
        trobat=true;
    }
}
void inserir_ordenant(Taula_Info&taula)
//Pre: 0<=taula.n<=MAX
//Post: insereix a la posició adequada l'última informació de la taula per després ajustar taula.n
{
    info_hospital aux;int i=taula.n;
    while(i>0&&taula.vec[i].codi<taula.vec[i-1].codi)
    {
        aux=taula.vec[i];
        taula.vec[i]=taula.vec[i-1];
        taula.vec[i-1]=aux;
        i--;
    }
    taula.n++;
}
void eliminar_fitxa(Taula_Info&taula,int pos)
//Pre: 0<=taula.n<=MAX i 0<=pos<MAX
//Post: elimina la informacio trobada a la taula.vec[pos] de la taula endreçant la taula.
{
    for(int i=pos;i<taula.n-1;i++)taula.vec[i]=taula.vec[i+1];
    taula.n--;
}
void llegir_fitxers_ordenant_taules(ifstream&fitxer_pacients,ifstream&fitxer_donants, Taula_Info&pacients, Taula_Info&donants)
//Pre:fitxer_pacients i fitxer_donants han d'existir.
//Post:lectura dels dos fitxers i inserció de la seva informació a la taula corresponent amb un ordre de codi ascendent restringit per MAX elements. S'el·liminen els pacients i donants inassociats.
{
    info_hospital aux;bool trobat=false;
    int pos,pos1;
    pos=pacients.n=donants.n=0;
    while(pacients.n<MAX && not fitxer_pacients.eof())
    {
        pacients.vec[pacients.n].codi_associat="0";
        fitxer_pacients>>pacients.vec[pacients.n].codi;
        fitxer_pacients>>pacients.vec[pacients.n].data_entrada_pool.dia;
        fitxer_pacients>>pacients.vec[pacients.n].data_entrada_pool.mes;
        fitxer_pacients>>pacients.vec[pacients.n].data_entrada_pool.any;
        fitxer_pacients>>pacients.vec[pacients.n].grup_sanguini;
        fitxer_pacients>>pacients.vec[pacients.n].hospital;
        fitxer_pacients>>pacients.vec[pacients.n].ciutat;
        inserir_ordenant(pacients);
    }
    while(donants.n<pacients.n-1 && not fitxer_donants.eof()){//Es posa donants.n<pacients.n-1 ja que es veu que el programa llegeix dos cops l'última informació del fitxer dels donants. Detall no-present quan es llegeix el dels pacients.
        fitxer_donants>>aux.codi;
        fitxer_donants>>aux.grup_sanguini;
        fitxer_donants>>aux.codi_associat;
        verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,aux.codi_associat,trobat,pos1);
        if(trobat){
            donants.vec[donants.n]=aux;
            pacients.vec[pos1].codi_associat=aux.codi;
            pacients.vec[pos1].grup_sanguini_associat=aux.grup_sanguini;
            inserir_ordenant(donants);
        }
    }
    while(pos<pacients.n){
        if(pacients.vec[pos].codi_associat=="0")eliminar_fitxa(pacients,pos);
        else pos++;
    }
}
bool es_compatible(string sang1,string sang2)
//Pre: sang1 ha de correspondre al otorgant i sang2 al receptor.
//Post:comprova si l'intercanvi de ronyons és viable o no.
{
    bool resultat=false;
    if(sang1==sang2 or sang1=="O" or sang2=="AB")resultat=true;
    return resultat;
}
void conversio_de_sang_a_num(string&sang)
//Pre: sang ha de pertànyer a un grup sanguini existent.
//Post:es codifica el grup sanguini a un nombre natural.
{
    if(sang=="O")sang=1;
    else if(sang=="A")sang=2;
    else if(sang=="B")sang=3;
    else sang=4;
}
bool es_menor_data(tempo data1,tempo data2)
//Pre: data.any,data.mes i data.dia han de ser tres nombres >=0.
//Post:verifica si la data1 és major o menor que data2.
{
    bool menor=false;
    if(data2.any<data1.any)menor=true;
    else if(data2.any==data1.any){
        if(data2.mes<data1.mes)menor=true;
        else if(data2.mes==data1.mes){
            if(data2.dia<data1.dia)menor=true; //I si es va fer alhora?
        }
    }
    return menor;
}
bool es_menor(info_hospital pacient1,info_hospital pacient2)
//Pre:pacient1 i pacient2 han d'incloure la informació necessària:grups sanguinis i dates_entrada_pool
//Post:verifica si el grup_sanguini i/o les dates_entrada_pool del pacient1 són inferiors o superiors que els del pacient2.
{
    bool mini=false;
    conversio_de_sang_a_num(pacient2.grup_sanguini);
    conversio_de_sang_a_num(pacient1.grup_sanguini);
    if(pacient2.grup_sanguini<pacient1.grup_sanguini)mini=true;
    else if(pacient2.grup_sanguini==pacient1.grup_sanguini){
        if(es_menor_data(pacient1.data_entrada_pool,pacient2.data_entrada_pool))mini=true;
    }
    return mini;
}
void inserir_a_taula_aux_ordenant_per_grup_sanguini(Taula_Info&taula_aux,info_hospital pacient)
//Pre:0<=taula.aux<=MAX
//Post:s'insereix a la taula per ordre de grup_sanguini i data_entrada_pool la informació del pacient.
{
    if(taula_aux.n<MAX){
        int j=taula_aux.n-1;
        taula_aux.n++;
        while(j>=0&&es_menor(taula_aux.vec[j],pacient)){
            taula_aux.vec[j+1]=taula_aux.vec[j];
            j--;
        }
        taula_aux.vec[j+1]=pacient;
    }
}
void execucio_del_programa( Taula_Info&pacients, Taula_Info&donants)
//Pre:0<=pacients.n<=MAX.0<=donants.n<=MAX
//Post:s'executen una sèrie de comandes entrades per teclat i consultes.
{
    cout<<endl;
    int pos,pos1;bool trobat;info_hospital aux_p;string missatge;
    cout<< "ENTRA OPCIO:"<<endl;cin>>missatge;
    while(missatge!=EOP){
        if(missatge=="ALTA"){
            cin>>aux_p.codi;
            cin>>aux_p.data_entrada_pool.dia;
            cin>>aux_p.data_entrada_pool.mes;
            cin>>aux_p.data_entrada_pool.any;
            cin>>aux_p.grup_sanguini;
            cin>>aux_p.hospital;
            cin>>aux_p.ciutat;
            cin>>aux_p.codi_associat;
            cin>>aux_p.grup_sanguini_associat;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,aux_p.codi,trobat,pos);
            if(pacients.n<MAX&&not trobat){//el nºpacients sera igual a nºdonants pel que entenc. per tant només cal verificar una n
                pacients.vec[pacients.n]=aux_p;
                donants.vec[donants.n].codi=aux_p.codi_associat;
                donants.vec[donants.n].grup_sanguini=aux_p.grup_sanguini_associat;
                donants.vec[donants.n].codi_associat=aux_p.codi;
                inserir_ordenant(pacients);
                inserir_ordenant(donants);
                cout<<"ALTA REALITZADA"<<endl;
            }
            else cout<< "CODI EXISTENT"<<endl;
        }
        else if(missatge=="BAIXA"){
            cin>>aux_p.codi;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,aux_p.codi,trobat,pos);
            if(trobat){
                aux_p.codi_associat=pacients.vec[pos].codi_associat;
                eliminar_fitxa(pacients,pos);
                verificar_existencia_codi_pacient_o_donant_associat_amb_pos(donants,aux_p.codi_associat,trobat,pos);
                eliminar_fitxa(donants,pos);
                cout<<"BAIXA REALITZADA"<<endl;
            }
            else cout<< "CODI INEXISTENT"<<endl;
        }
        else if(missatge=="PACIENT"){
            cin>>aux_p.codi;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,aux_p.codi,trobat,pos);
            if(trobat){
                cout<<pacients.vec[pos].codi<<" "<<pacients.vec[pos].data_entrada_pool.dia<<" "<<pacients.vec[pos].data_entrada_pool.mes<<" "<<pacients.vec[pos].data_entrada_pool.any<<" ";
                cout<<pacients.vec[pos].grup_sanguini<<" "<<pacients.vec[pos].hospital<<" "<<pacients.vec[pos].ciutat<<" ";
                cout<<pacients.vec[pos].codi_associat<<" "<<pacients.vec[pos].grup_sanguini_associat<<" "<<endl;
            }
            else cout<< "CODI INEXISTENT"<<endl;
        }
        else if(missatge=="DONANT"){
            cin>>aux_p.codi_associat;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(donants,aux_p.codi_associat,trobat,pos);
            if(trobat){
                cout<<donants.vec[pos].codi<<" "<<donants.vec[pos].grup_sanguini<<" "<<donants.vec[pos].codi_associat<<" ";
                verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants.vec[pos].codi_associat,trobat,pos);
                cout<<pacients.vec[pos].data_entrada_pool.dia<<" "<<pacients.vec[pos].data_entrada_pool.mes<<" "<<pacients.vec[pos].data_entrada_pool.any<<" ";
                cout<<pacients.vec[pos].grup_sanguini<<" "<<pacients.vec[pos].hospital<<" "<<pacients.vec[pos].ciutat<<endl;
            }
            else cout<< "CODI INEXISTENT"<<endl;
        }
        else if(missatge=="POSSIBLES_DONANTS"){
            cin>>aux_p.codi;
            int comptador=pacients.n;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,aux_p.codi,trobat,pos1);
            if(trobat){
                for(int i=0;i<donants.n;i++){
                    if(es_compatible(donants.vec[i].grup_sanguini,pacients.vec[pos1].grup_sanguini)){
                        cout<<donants.vec[i].codi<<" "<<donants.vec[i].grup_sanguini<<" "<<donants.vec[i].codi_associat<<" ";
                        verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants.vec[i].codi_associat,trobat,pos);
                        cout<<pacients.vec[pos].data_entrada_pool.dia<<" "<<pacients.vec[pos].data_entrada_pool.mes<<" "<<pacients.vec[pos].data_entrada_pool.any<<" "<<pacients.vec[pos].grup_sanguini<<" "<<pacients.vec[pos].hospital<<" "<<pacients.vec[pos].ciutat<<endl;
                        comptador--;
                    }
                }
                if(comptador==pacients.n)cout<<"NO N'HI HA CAP"<<endl;
            }
            else cout<<"CODI INEXISTENT"<<endl;
        }
        else if(missatge=="POSSIBLES_RECEPTORS"){
            cin>>aux_p.codi_associat;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(donants,aux_p.codi_associat,trobat,pos);
            if(trobat){
                int comptador=pacients.n;
                Taula_Info taula_aux;
                taula_aux.n=0;
                for(int i=0;i<pacients.n;i++)if(es_compatible(donants.vec[pos].grup_sanguini,pacients.vec[i].grup_sanguini)){
                    inserir_a_taula_aux_ordenant_per_grup_sanguini(taula_aux,pacients.vec[i]);
                    comptador--;
                }
                if(comptador!=pacients.n){
                    for(int i=0;i<taula_aux.n;i++){
                        cout<<taula_aux.vec[i].codi<<" "<<taula_aux.vec[i].data_entrada_pool.dia<<" "<<taula_aux.vec[i].data_entrada_pool.mes<<" "<<taula_aux.vec[i].data_entrada_pool.any<<" ";
                        cout<<taula_aux.vec[i].grup_sanguini<<" "<<taula_aux.vec[i].hospital<<" "<<taula_aux.vec[i].ciutat<<" "<<taula_aux.vec[i].codi_associat<<" "<<taula_aux.vec[i].grup_sanguini_associat<<endl;
                    }
                }
                else cout<<"NO N'HI HA CAP"<<endl;
            }
            else cout<< "CODI INEXISTENT"<<endl;
        }
        else if(missatge=="INTERCANVI_VIABLE"){
            string codi1;
            cin>>aux_p.codi>>codi1;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,aux_p.codi,trobat,pos);
            if(trobat){
                verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,codi1,trobat,pos1);
                if(trobat){
                    if(es_compatible(pacients.vec[pos].grup_sanguini_associat,pacients.vec[pos1].grup_sanguini)&&es_compatible(pacients.vec[pos1].grup_sanguini_associat,pacients.vec[pos].grup_sanguini))cout<<"SI"<<endl;
                    else cout<<"NO"<<endl;
                }
                else cout<<"CODI INEXISTENT"<<endl;
            }
            else cout<<"CODI INEXISTENT"<<endl;
        }
        else if(missatge=="LLISTAR_INTERCANVIS_POSSIBLES"){
            int comptador=pacients.n;
            for(int i=0;i<pacients.n-1;i++){
                for(int j=i+1;j<pacients.n;j++){
                    if(es_compatible(pacients.vec[i].grup_sanguini_associat,pacients.vec[j].grup_sanguini)&&es_compatible(pacients.vec[j].grup_sanguini_associat,pacients.vec[i].grup_sanguini)){
                        cout<<pacients.vec[i].codi<<" "<<pacients.vec[i].grup_sanguini<<" "<<pacients.vec[j].codi<<" "<<pacients.vec[j].grup_sanguini<<endl;
                        comptador--;
                    }
                }
            }
            if(comptador==pacients.n)cout<< "NO N'HI HA CAP"<<endl;
        }
        cout<<endl;cout<<"ENTRA OPCIO:";cout<<endl;
        cin>>missatge;
    }
}
int main()
{
    cout<< "INTRODUEIX NOM FITXER DE PACIENTS:"<<endl;
    Taula_Info pacients, donants;
    string nom_fitxer_p,nom_fitxer_d;
    cin>>nom_fitxer_p;
    ifstream fitxer_pacients(nom_fitxer_p.c_str());
    if(not fitxer_pacients.fail()){
        cout<< "INTRODUEIX NOM FITXER DE DONANTS:"<<endl;
        cin>>nom_fitxer_d;
        ifstream fitxer_donants(nom_fitxer_d.c_str());
        if(not fitxer_donants.fail()){
            llegir_fitxers_ordenant_taules(fitxer_pacients,fitxer_donants,pacients,donants);
            execucio_del_programa(pacients,donants);
        }
        else cout<< "ERROR OBERTURA FITXER";
    }
    else cout<< "ERROR OBERTURA FITXER";
    return 0;
}
