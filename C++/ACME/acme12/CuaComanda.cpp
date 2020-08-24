#include "CuaComanda.h"

CuaComanda::CuaComanda()
//Pre:cert//Post:s'inicialitzn els valors de l'objecte pels valors per defecte
{
    a_primer=NULL;
    a_ultim=NULL;
    a_duracio_total=0;
}
void CuaComanda::inserir_comanda(int& c_pendents)
//Pre:cert//Post:s'insereix una nova comanda i s'enllaça al reste de la cua
{
    Node*aux=new Node;
    aux->anterior=aux->posterior=NULL;
    aux->a_comanda.llegir_comanda();

    if(buida())a_primer=a_ultim=aux;
    else {a_primer->anterior=aux;a_primer=aux;}
    c_pendents++;
}
void CuaComanda::treure_comanda(int pendents)
//Pre://Post:s'el·limina el primer element entrat de la cua
{

    Node*aux=a_ultim;
    if(a_primer==a_ultim)a_primer=a_ultim=NULL;
    else {a_ultim=a_ultim->anterior;a_ultim->posterior=NULL;}
    delete	aux;
}
bool CuaComanda::buida()const
//Pre://Post:
{
    return a_primer==NULL;
}
void CuaComanda::resum_comandes_servides(int c_servides)const
//Pre:c_servides>=0//Post:es mostren n_comandes servides i la mitjana de duració
{
    cout<< "NOMBRE DE COMANDES SERVIDES:"<<endl;
    cout<<c_servides<<endl;
    if(c_servides!=0)
    {
        cout<< "TEMPS MIG D'ESPERA:"<<endl;
        cout<<double(a_duracio_total)/c_servides<<endl;
    }
}
void CuaComanda::servir_comanda(int&c_servides,int&c_pendents)
//Pre:c_pendents>=0//Post:es treu de la cua la primera comanda i s'actualizen els valors de les comandes pendents i servides
{
    if(c_pendents>0)
    {
        c_servides++;c_pendents--;
        int duracio=a_ultim->a_comanda.consultar_duracio_comanda();
        a_duracio_total+=duracio;

        cout<<"ES SERVEIX COMANDA:"<<endl;
        a_ultim->a_comanda.mostrar_comanda();

        cout<< "TEMPS D'ESPERA: "<<duracio<<" MINUTS"<<endl;
        treure_comanda(c_pendents);
    }
    else cout<< "NO HI HA COMANDES PENDENTS"<<endl;
}
void CuaComanda::mostrar_comandes()const
//pre:cert//Post:es mostren totes les comandes de la cua per l'ordre que han entrat
{
    Node*aux=a_ultim;
    cout<<"LLISTAT DE COMANDES PENDENTS"<<endl;
    cout<< "-------------------------"<<endl;
    while(aux!=NULL)
    {
        aux->a_comanda.mostrar_comanda();
        aux=aux->anterior;
        cout<< "-------------------------"<<endl;
    }
}
