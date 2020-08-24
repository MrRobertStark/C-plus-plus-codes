#include "Agenda.h"

Agenda::Agenda()
{
    a_n_elements=0;
}
void Agenda::afegir_esdeveniment()
//Pre:
//Post:
{
    Esdeveniment aux; aux.llegir_esdeveniment();
    int pos=buscar_pos_existencia(aux);
    if(pos==NO_TROBAT)inserir_ordenat(aux);
}
int Agenda::buscar_pos_existencia(const Esdeveniment&e)
//Pre:
//Post:
{
    int esq=0,dret=a_n_elements-1,mig=(esq+dret)/2,pos=NO_TROBAT;
    if(esq<dret)
    {
        while(esq!=dret-1&&a_taula[mig]!=e)
        {
            if(a_taula[mig]<e)esq=mig;
            else dret=mig;
            mig=(esq+dret)/2;
        }
        if(a_taula[mig]==e)pos=mig;
        else if(a_taula[dret]==e)pos=dret;
    }
    else if(esq==dret&&a_taula[mig]==e)pos=mig;
    return pos;
}
void Agenda::inserir_ordenat(const Esdeveniment&e)
//Pre:
//Post:
{
    if(a_n_elements<MAX_ELEMENTS)
    {
        int i=a_n_elements;
        a_taula[i]=e;
        while(i>0&&a_taula[i]<a_taula[i-1])
        {
            intercanviar_elements(a_taula[i],a_taula[i-1]);
            i--;
        }
        a_n_elements++;
    }
}
void Agenda::intercanviar_elements(Esdeveniment&e1,Esdeveniment&e2)
//Pre:
//Post:
{
    Esdeveniment aux=e1;
    e1=e2;
    e2=aux;
}
void Agenda::buscar_data_i_estudiar_durada()
//Pre:
//Post:
{
    cout<< "ENTRA UNA DATA:"<<endl;
    Data d; d.llegir_data();
    int pos=buscar_pos_data(d); int duracio=0;
    if(pos==NO_TROBAT)
    {
        cout<<"EL TEMPS OCUPAT DEL DIA ";d.mostrar_data();cout<<" ES DE "<<duracio<< " MINUTS"<<endl;
    }
    else
    {
        duracio+=comptador_duracio_esdeveniments(pos);
        cout<<"EL TEMPS OCUPAT DEL DIA ";d.mostrar_data();cout<<" ES DE "<<duracio<< " MINUTS"<<endl;
    }
}
int Agenda::comptador_duracio_esdeveniments(int pos)
//Pre:
//Post:
{
    int pos_aux=pos-1,pos_aux2=pos,duracio=0;
    while(pos_aux>=0&&a_taula[pos_aux].es_igual_data_esdeveniments(a_taula[pos_aux+1]))
    {
        duracio+=a_taula[pos_aux].duracio_esdeveniment();
        pos_aux--;
    }
    while(pos_aux2<a_n_elements&&a_taula[pos_aux2].es_igual_data_esdeveniments(a_taula[pos]))
    {
        duracio+=a_taula[pos_aux2].duracio_esdeveniment();
        pos_aux2++;
    }
    return duracio;
}
int Agenda::buscar_pos_data(const Data&d)
//Pre:
//Post:
{
    int esq=0,dret=a_n_elements-1,mig=(esq+dret)/2,pos=NO_TROBAT;
    if(esq<dret)
    {
        while(esq!=dret-1&& not a_taula[mig].son_dates_equivalents(d))
        {
            if(a_taula[mig].es_data_inferior(d))esq=mig;
            else dret=mig;
            mig=(esq+dret)/2;
        }
        if(a_taula[mig].son_dates_equivalents(d))pos=mig;
        else if(a_taula[dret].son_dates_equivalents(d))pos=dret;
    }
    else if(esq==dret&&a_taula[esq].son_dates_equivalents(d))pos=esq;
    return pos;
}
