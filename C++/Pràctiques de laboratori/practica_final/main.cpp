//Original
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//Entrada: fitxers_llegits/I els pacients que no tenen donants associats? Necessito fer un recorregut seq�encial per forca...
//Sugerencia: implementar un "mostrar_taula_fila"
//Sortida:
const int MAX=1000;
const string sang_neutre="O";//M'han dit que hauria de crear una taula nova ordenada per compatibles d'un donant a partir de sang/data. Mneh...
const string sang_AB="AB";
const string EOP= "SORTIR";
struct tempo{
    int dia;
    int mes;
    int any;
};
struct info_pacient{
    string codi;
    tempo data_entrada_pool;
    string grup_sanguini;
    string hospital;
    string ciutat;
    string codi_donant_associat;
};
struct info_donant{
    string codi;
    string grup_sanguini;
    string codi_pacient_associat;
};
struct Taula_Pacients{
    info_pacient vec[MAX];
    int n;
};
struct Taula_Donants{
    info_donant vec[MAX];
    int n;
};
struct Taula_Pacients_Auxiliar{
    info_pacient vec[MAX];
    int n;
};
int calcul_mig(int esq,int dret)
//Pre:
//Post:
{
    int resultat=(esq+dret)/2;
    return resultat;
}
void verificar_existencia_codi_pacient_o_donant_associat_amb_pos(const Taula_Pacients&pacients,const Taula_Donants&donants,string codi,bool&trobat,int&pos,int element)
//Pre:
//Post:
{
    int esq=0,dret,mig;
    if(element=='P'){//Busquem l'element a la taula dels pacients
        dret=pacients.n;
        mig=calcul_mig(esq,dret);
        while(esq!=dret-1 && pacients.vec[mig].codi!=codi)
        {
            if (pacients.vec[mig].codi>codi)dret=mig;
            else esq=mig;
            mig=calcul_mig(esq,dret);
        }
        if(pacients.vec[mig].codi==codi){
            trobat=true;
            pos=mig;
        }
        else if(pacients.vec[dret].codi==codi){
            trobat=true;
            pos=dret;
        }
    }
    else{//Busquem el codi per la taula dels donants
            dret=donants.n;
            mig=calcul_mig(esq,dret);
            while(esq!=dret-1&&donants.vec[mig].codi!=codi)
        {
            if (donants.vec[mig].codi>codi)dret=mig;
            else esq=mig;
        }
        if(donants.vec[mig].codi==codi){
            trobat=true;
            pos=mig;
        }
        else if(donants.vec[dret].codi==codi){
            trobat=true;
            pos=dret;
        }
    }
}
void inserir_ordenant(Taula_Pacients& pacients,Taula_Donants& donants,char element)
//Pre: la quantitat d'elements a la taula dels pacients i dels donants han de ser >=0 i <=MAX. L'element ha de prendre valor D(donants) o P(pacients)
//Post: s'insereix ordenadament per codi ascendent la dada del pacient o donant a la taula adequada.
{
    int i;
    if(donants.n<MAX&&element=='D')
    {
        info_donant aux;
        i=donants.n-1;
        while(i>0 && donants.vec[i].codi<donants.vec[i-1].codi)
        {
            aux=donants.vec[i];
            donants.vec[i]=donants.vec[i-1];
            donants.vec[i-1]=aux;
            i--;
        }
        donants.n++;
    }
    else if(pacients.n<MAX&&element=='P')
    {
        i=pacients.n-1;
        info_pacient aux;
        while(i>0&&pacients.vec[i].codi<pacients.vec[i-1].codi){
            aux=pacients.vec[i];
            pacients.vec[i]=pacients.vec[i-1];
            pacients.vec[i-1]=aux;
            i--;
        }
        pacients.n++;
    }
}
void eliminar_fitxa(Taula_Pacients&pacients,Taula_Donants&donants,int pos,int element)
//Pre:
//Post:
{
    if(pacients.n>0&&element=='P'){
        for(int i=pos;i<pacients.n-1;i++)
        {
            pacients.vec[i]=pacients.vec[i+1];
        }
        pacients.n--;
    }
    else if(donants.n>0)
    {
        for(int i=pos;i<donants.n-1;i++)
        {
            donants.vec[i]=donants.vec[i+1];
        }
        donants.n--;
    }
}
void llegir_fitxers_ordenant_taules(ifstream&fitxer_pacients,ifstream&fitxer_donants,Taula_Pacients&pacients,Taula_Donants&donants)
//Pre:
//Post:
{
    info_donant aux;bool trobat=false;
    int pos;
    char element='P';
    pacients.n=0;
    while(pacients.n<MAX && not fitxer_pacients.eof())
    {
        pacients.vec[pacients.n].codi_donant_associat="0";
        fitxer_pacients>>pacients.vec[pacients.n].codi>>pacients.vec[pacients.n].data_entrada_pool.dia>>pacients.vec[pacients.n].data_entrada_pool.mes>>pacients.vec[pacients.n].data_entrada_pool.any>>pacients.vec[pacients.n].grup_sanguini>>pacients.vec[pacients.n].hospital>>pacients.vec[pacients.n].ciutat;
        element='P';
        inserir_ordenant(pacients,donants,element);
    }
    donants.n=0;
    while(donants.n<MAX && not fitxer_donants.eof())
    {
        fitxer_donants>>aux.codi>>aux.grup_sanguini>>aux.codi_pacient_associat;
        element='P';
        verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,aux.codi,trobat,pos,element);
        if(donants.n<MAX&&not trobat)
        {
            donants.vec[donants.n]=aux;
            inserir_ordenant(pacients,donants,element);
        }
    }
    pos=0;
    while(pos<pacients.n)
    {
        if(pacients.vec[pos].codi_donant_associat=="0")eliminar_fitxa(pacients,donants,pos,'P');
        else pos++;
    }
}
bool es_compatible(string sang1,string sang2)
//Pre:
//Post:
{
    bool compatible=(sang1==sang2 or sang1==sang_neutre or sang2==sang_AB);
    return compatible;
}
void conversio_de_sang_a_num(string&sang)
//Pre:
//Post:
{
    if(sang=="O")sang=1;
    else if(sang=="A")sang=2;
    else if(sang=="B")sang=3;
    else sang=4;
}
bool es_menor_data(tempo data1,tempo data2)
//Pre:
//Post:
{
    bool minim=false;
    if(data2.any<data1.any)minim=true;
    else if(data2.any==data1.any)
    {
        if(data2.mes<data1.mes)minim=true;
        else if(data2.mes==data1.mes)
        {
            if(data2.dia<data1.dia)minim=true; //I si es la mateixa data?
        }
    }
    return minim;
}
bool es_menor(info_pacient pacient1,info_pacient pacient2)
//Pre:
//Post:
{
    bool mini=false;
    conversio_de_sang_a_num(pacient2.grup_sanguini);
    conversio_de_sang_a_num(pacient1.grup_sanguini);
    if(pacient2.grup_sanguini<pacient1.grup_sanguini)mini=true;
    else if(pacient2.grup_sanguini==pacient1.grup_sanguini)
    {
        if(es_menor_data(pacient1.data_entrada_pool,pacient2.data_entrada_pool))mini=true;
    }
    return mini;
}
void inserir_a_taula_aux_ordenant_per_grup_sanguini(Taula_Pacients_Auxiliar&taula_aux,const info_pacient pacient)
//Pre:
//Post:
{
    if(taula_aux.n<MAX){
        int j=taula_aux.n-1;
        taula_aux.n++;
        while(j>=0&&es_menor(taula_aux.vec[j],pacient))
        {
            taula_aux.vec[j+1]=taula_aux.vec[j];
            j--;
        }
        taula_aux.vec[j+1]=pacient;
    }
}
void execucio_del_programa(Taula_Pacients&pacients,Taula_Donants&donants)
//Pre:
//Post:
{
    int pos;bool trobat;
    info_donant aux_d;
    info_pacient aux_p;
    string missatge;
    cout<< "Estic preparat, que voldries que fes? ";
    cin>>missatge;
    while(missatge!=EOP){
        if(missatge=="ALTA")
        {
            cin>>aux_p.codi>>aux_p.data_entrada_pool.dia>>aux_p.data_entrada_pool.mes>>aux_p.data_entrada_pool.any>>aux_p.grup_sanguini>>aux_p.hospital>>aux_p.codi_donant_associat>>aux_d.grup_sanguini;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,aux_p.codi,trobat,pos,'P');
            if(pacients.n<MAX && donants.n<MAX&&not trobat)
            {
                pacients.vec[pacients.n]=aux_p;
                inserir_ordenant(pacients,donants,'P');
                donants.vec[donants.n].codi=aux_p.codi_donant_associat;
                donants.vec[donants.n].grup_sanguini=aux_d.grup_sanguini;donants.vec[donants.n].codi_pacient_associat=aux_p.codi;//Un donant t� associat un pacient �nic i viceversa?
                inserir_ordenant(pacients,donants,'D');
            }
            else cout<< "Aquest codi ja existia. ";
        }
        else if(missatge=="BAIXA")
        {
            cin>>aux_p.codi;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,aux_p.codi,trobat,pos,'P');
            if(trobat)
            {
                aux_d.codi=pacients.vec[pos].codi_donant_associat;
                eliminar_fitxa(pacients,donants,pos,'P');
                verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,aux_d.codi,trobat,pos,'D');
                eliminar_fitxa(pacients,donants,pos,'D');
            }
            else cout<< "Aquest codi no existeix ";
        }
        else if(missatge=="PACIENT")
        {
            cin>>aux_p.codi;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,aux_p.codi,trobat,pos,'P');
            if(trobat)
            {
                cout<<pacients.vec[pos].codi<<" "<<pacients.vec[pos].data_entrada_pool.dia<<" "<<pacients.vec[pos].data_entrada_pool.mes<<" "<<pacients.vec[pos].data_entrada_pool.any<<" "<<pacients.vec[pos].grup_sanguini<<" "<<pacients.vec[pos].hospital<<" ";
                cout<<pacients.vec[pos].hospital<<" "<<pacients.vec[pos].ciutat<<" "<<pacients.vec[pos].codi_donant_associat;
                verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,pacients.vec[pos].codi_donant_associat,trobat,pos,'D');
                cout<<donants.vec[pos].grup_sanguini;
                cout<<endl;
            }
            else cout<< "El codi no existeix. ";
        }
        else if(missatge=="DONANT")
        {
            cin>>aux_d.codi;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,aux_d.codi,trobat,pos,'D');
            if(trobat)
            {
                cout<<donants.vec[pos].codi<<" "<<donants.vec[pos].grup_sanguini<<donants.vec[pos].codi_pacient_associat<<" ";
                verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,donants.vec[pos].codi_pacient_associat,trobat,pos,'P');
                cout<<pacients.vec[pos].codi<<" "<<pacients.vec[pos].data_entrada_pool.dia<<" "<<pacients.vec[pos].data_entrada_pool.mes<<" "<<pacients.vec[pos].data_entrada_pool.any<<" "<<pacients.vec[pos].grup_sanguini<<" "<<pacients.vec[pos].hospital<<" "<<pacients.vec[pos].ciutat;
                cout<<endl;
            }
            else cout<< "No s'ha trobat el codi. ";
        }
        else if(missatge=="POSSIBLES_DONANTS")
        {
            cin>>aux_p.codi;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,aux_p.codi,trobat,pos,'P');
            for(int i=0;i<donants.n;i++){
                if(es_compatible(donants.vec[i].grup_sanguini,pacients.vec[pos].grup_sanguini)){
                    cout<<donants.vec[i].codi<<" "<<donants.vec[i].grup_sanguini<<endl;
                }
            }
        }
        else if(missatge=="POSSIBLES_RECEPTORS")
        {
            cin>>aux_d.codi;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,aux_d.codi,trobat,pos,'D');
            if(trobat)
            {
                Taula_Pacients_Auxiliar taula_aux;
                taula_aux.n=0;
                for(int i=0;i<pacients.n;i++)
                {
                    if(es_compatible(donants.vec[pos].grup_sanguini,pacients.vec[i].grup_sanguini))
                    {
                        inserir_a_taula_aux_ordenant_per_grup_sanguini(taula_aux,pacients.vec[i]);
                    }
                }
                for(int i=0;i<taula_aux.n;i++)
                {
                    cout<<taula_aux.vec[i].codi<<" "<<taula_aux.vec[i].data_entrada_pool.dia<<" "<<taula_aux.vec[i].data_entrada_pool.mes<<" "<<taula_aux.vec[i].data_entrada_pool.any<<" "<<taula_aux.vec[i].grup_sanguini<<" "<<taula_aux.vec[i].hospital<<" ";
                    cout<<taula_aux.vec[i].hospital<<" "<<taula_aux.vec[i].ciutat<<" "<<taula_aux.vec[i].codi_donant_associat<<" "<<donants.vec[pos].grup_sanguini<<endl;
                }
            }
            else cout<< "El codi que has entrat no existeix a la llista. ";
        }
        else if(missatge=="INTERCANVI_VIABLE")
        {
            cin>>aux_p.codi>>aux_d.codi;//Per no haver de declarar m�s variables auxiliars reaprofito els que tinc
            int pos_aux,pos_aux2;
            verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,aux_p.codi,trobat,pos,'P');
            if(trobat){
                pos_aux=pos;
                verificar_existencia_codi_pacient_o_donant_associat_amb_pos(pacients,donants,aux_d.codi,trobat,pos,'D');
                if(trobat){
                    pos_aux2=pos;
                    if(es_compatible(pacients.vec[pos_aux].grup_sanguini,pacients.vec[pos_aux2].grup_sanguini)&&es_compatible(pacients.vec[pos_aux2].grup_sanguini,pacients.vec[pos_aux].grup_sanguini))cout<<"SI ";
                    else cout<<"NO ";
                }
                else cout<<"No s'ha pogut troba el codi del segon pacient. ";
            }
            else cout<<"No s'ha pogut trobar el codi del primer pacient a analitzar. ";
        }
        else if(missatge=="LLISTAR_INTERCANVIS_POSSIBLES")//Ens podem estalviar el if?
        {
            for(int i=0;i<pacients.n-1;i++)
            {
                if(es_compatible(pacients.vec[i].grup_sanguini,pacients.vec[i+1].grup_sanguini)&&es_compatible(pacients.vec[i+1].grup_sanguini,pacients.vec[i].grup_sanguini)){
                    cout<<pacients.vec[i].codi<<" "<<pacients.vec[i].grup_sanguini<<" "<<pacients.vec[i+1].codi<<" "<<pacients.vec[i+1].grup_sanguini;
                }
                cout<<endl;
            }
        }
        cout<<"Ara qu� voldries fer? ";
        cin>>missatge;
    }
}
int main()
{
    cout<< "Hola!, necessito que em diguis el nom del fitxer on hi ha la informacio dels pacients per poder ajudar-te: ";
    Taula_Pacients pacients;Taula_Donants donants;
    string nom_fitxer_p,nom_fitxer_d;
    cin>>nom_fitxer_p;
    ifstream fitxer_pacients(nom_fitxer_p.c_str());
    if(not fitxer_pacients.fail())
    {
        cout<< "Ja gairebe estem! Ara necessito el nom del fitxer on hi ha la informacio dels donants ";
        cin>>nom_fitxer_d;
        ifstream fitxer_donants(nom_fitxer_d.c_str());
        if(not fitxer_donants.fail())
        {
            llegir_fitxers_ordenant_taules(fitxer_pacients,fitxer_donants,pacients,donants);
            execucio_del_programa(pacients,donants);
        }
        else cout<< "No s'ha pogut obrir l'arxiu dels donants...";
    }
    else cout<< "No s'ha pogut obrir l'arxiu dels pacients.";
    return 0;
}
