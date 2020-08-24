#include "Llista_Reproduccions.h"

Llista_Reproduccions::Llista_Reproduccions()
{
    a_ultim=NULL;
    a_primer=NULL;
    a_n_elements=0;
}
Llista_Reproduccions::Llista_Reproduccions(const Llista_Reproduccions&llista)
{
    copiar(llista);
}
Llista_Reproduccions&Llista_Reproduccions::operator=(const Llista_Reproduccions&llista)
{
    if(this!=&llista)
    {
        alliberar();copiar(llista);
    }
    return *this;
}
Llista_Reproduccions::~Llista_Reproduccions()
{
    alliberar();
}
void Llista_Reproduccions::mostrar_llista()const
{
    if(not es_buida())
    {
        Node*aux=a_primer;
        while(aux!=NULL)
        {
            aux->c.mostrar_canco();
            aux=aux->seguent;
        }
    }
    else cout<<"NO HI HA RES PER MOSTRAR"<<endl;
}
bool Llista_Reproduccions::es_buida()const
{
    return a_ultim==NULL;
}
void Llista_Reproduccions::eliminar_canco(const Canco&c)
{
    if(not es_buida())
    {
        Node *anterior=NULL,*actual=a_primer,*aux;
        while(actual!=NULL)
        {
            aux=actual;
            if(actual->c==c)
            {
                if(anterior==NULL)
                    a_primer=actual=actual->seguent;

                else
                {
                    actual=actual->seguent;
                    anterior->seguent=actual;
                }
                delete aux;
            }
            else
            {
                anterior=actual;
                actual=actual->seguent;
            }
        }
        if(anterior==NULL && actual==NULL)a_primer=a_ultim=NULL;
        else a_ultim=anterior;
    }
}
Canco Llista_Reproduccions::seguent_canco()const
{
    return a_primer->c;
}
void Llista_Reproduccions::actualitzar_info_canco(const Canco&c)
{
    Node*aux=a_primer;
    while(aux!=NULL)
    {
        if(aux->c==c)aux->c=c;
        aux=aux->seguent;
    }
}
void Llista_Reproduccions::backup(ofstream&fitxer)const
{
    fitxer<< "MTP[QUEUE] "<<a_n_elements<<endl;
    if(a_n_elements!=0)
    {
        Node*aux=a_primer;
        while(aux!=NULL)
        {
            fitxer<<aux->c.solicitar_uid()<<" ";
            aux=aux->seguent;
        }
    }
}
void Llista_Reproduccions::empila(const Canco&c)
{
    Node*aux=new Node; aux->c=c; aux->seguent=NULL;

    if(es_buida())
        a_primer=a_ultim=aux;

    else
    {
        a_ultim->seguent=aux;
        a_ultim=a_ultim->seguent;
    }
    a_n_elements++;
}
void Llista_Reproduccions::desencua()
{
    if(not es_buida())
    {
        Node*aux=a_primer;

        if(a_primer==a_ultim)
            a_primer=a_ultim=NULL;

        else
            a_primer=a_primer->seguent;

        delete aux; a_n_elements--;
    }
}
void Llista_Reproduccions::alliberar()
{
    while(not es_buida())desencua();
}
void Llista_Reproduccions::copiar(const Llista_Reproduccions&llista)
{
    if(not llista.es_buida())
    {
        Node*origen=llista.a_primer,*desti=new Node;
        a_primer=desti;

        while(origen!=llista.a_ultim)
        {
            desti->c=origen->c;
            desti->seguent=new Node;

            desti=desti->seguent;
            origen=origen->seguent;
        }
        desti->c=origen->c; desti->seguent=NULL;
        a_ultim=desti;
    }
}
