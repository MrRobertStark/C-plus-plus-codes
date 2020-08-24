#include "AgendaDinamica.h"

AgendaDinamica::AgendaDinamica()
{
    a_primer=NULL;
}
AgendaDinamica::~AgendaDinamica()
//pre:cert//post:s'inicialitza la llista dinamica a zero
{
    allibera();
}
AgendaDinamica::AgendaDinamica(const AgendaDinamica&o)
//pre:cert//post:s'inicialitza una memòria dinàmica a "o"
{
    a_primer=NULL;
    copia(o);
}
AgendaDinamica&AgendaDinamica::operator=(const AgendaDinamica&o)
//pre:cert//post:es copia la memòria dinàmica "o" a l'objecte actual
{
    if(this!=&o)
    {
        allibera();
        copia(o);
    }
    return (*this);
}
void AgendaDinamica::mostrar_agenda()const
//pre:cert//post:es mostra la llista sencera
{
    if(not buida())
    {
        cout<<"LLISTA D'ESDEVENIMENTS:"<<endl;

        Node*aux=a_primer;
        while(aux!=NULL){aux->esdv.mostrar();aux=aux->next;}
    }
    else cout<< "AGENDA BUIDA"<<endl;
}
void AgendaDinamica::inserir(const Esdeveniment&e)
{
// Pre: --; Post: si e no existeix s'ha inserit en el lloc que li toca per mantenir l'ordre; en cas contrari no es fa cap inserció
    Node *anterior=NULL,*posterior=a_primer,*nou;
    bool FiCerca=false; bool trobat=false;
    while(posterior!=NULL&&!FiCerca)
    {
        if(posterior->esdv>e or posterior->esdv==e)
        {
            FiCerca=true;
            trobat=posterior->esdv==e;
        }
        else{anterior=posterior;posterior=posterior->next;}
    }
    if(!trobat)
    {
        nou=new Node; nou->esdv=e;nou->next=posterior;
        if(anterior==NULL)a_primer=nou;
        else anterior->next=nou;
    }
    else cout<<"AQUEST ESDEVENIMENT JA EXISTEIX"<<endl;
}

void AgendaDinamica::treure()
//pre:cert//post:es treu l'esdeveniment que tingui com a identificador el codi entrat
{
    if(not buida())
    {
        cout<<"CODI DE L'ESDEVENIMENT PER ESBORRAR:"<<endl;
        int codi;cin>>codi;

        Node*anterior=NULL,*posterior=a_primer;
        bool trobat=false;
        while(posterior!=NULL&&!trobat)
        {
            if(posterior->esdv.consultar_codi()==codi)trobat=true;
            else{anterior=posterior;posterior=posterior->next;}
        }
        if(trobat)
        {
            cout<<"ESDEVENIMENT ESBORRAT:"<<endl;posterior->esdv.mostrar();
            if(anterior==NULL)a_primer=posterior->next;
            else{anterior->next=posterior->next;}
            delete posterior;
        }
        else cout<< "AQUEST ESDEVENIMENT NO EXISTEIX"<<endl;
    }
    else cout<<"AGENDA BUIDA"<<endl;
}
bool AgendaDinamica::buida()const
//pre:cert//post:a_primer==NULL
{
    return (a_primer==NULL);
}
void AgendaDinamica::copia(const AgendaDinamica&o)
//pre:cert//post:es copia la llista "o" a la llista actual.
{
    if(!o.buida())
    {
        Node *desti,*origen;//Copiem els continguts dels inicis
        origen=o.a_primer;
        a_primer=new Node;a_primer->esdv=origen->esdv;a_primer->next=NULL;
        desti=a_primer;

        origen=origen->next;desti=desti->next;//Ara pasem al segon element de la cua

        while(origen!=NULL)
        {
           desti=new Node; desti->esdv=origen->esdv;//Copiem els continguts del punter origen al destí
           desti->next=NULL;

           desti=desti->next;origen=origen->next;//Pasem al següent terme
        }
    }
}
void AgendaDinamica::allibera()
//pre:cert//post:memoria dinàmica alliberada
{
    while(not buida())
    {
        Node*present;present=a_primer;
        a_primer=a_primer->next;
        delete present;
    }
}

