#include "Historial.h"

Historial::Historial()
{
    a_cim=NULL;
    a_base=NULL;
    a_n_elements=0;
}
Historial::Historial(const Historial&h)
{
    copiar(h);
}
Historial&Historial::operator=(const Historial&h)
{
    if(this!=&h)
    {
        alliberar();copiar(h);
    }
    return *this;
}
Historial::~Historial()
{
    alliberar();
}
void Historial::mostrar_historial()const
{
    Node*aux=a_cim;

    if(not buida())
        while(aux!=NULL)
        {
            aux->c.mostrar_canco();
            aux=aux->seguent;
        }
    else cout<<"NO HI HA RES PER MOSTRAR"<<endl;
}
bool Historial::buida()const
{
    return a_cim==NULL;
}
void Historial::eliminar_canco(const Canco&c)
{
    if(not buida())
    {
        Node*anterior=NULL,*actual=a_cim,*aux=NULL;
        while(actual!=NULL)
        {
            if(actual->c==c)
            {
                aux=actual;

                if(anterior==NULL)
                    a_cim=actual=actual->seguent;
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
        if(anterior==NULL && actual==NULL)a_cim=a_base=NULL;
        else a_base=anterior;
    }
}
void Historial::actualitzar_info_canco(const Canco&c)
{
    Node*aux=a_cim;
    while(aux!=NULL)
    {
        if(aux->c==c)aux->c=c;
        aux=aux->seguent;
    }
}
void Historial::backup(ofstream&fitxer)const
{
    fitxer<< "MTP[STACK] "<<a_n_elements<<endl;
    if(not buida())
    {
        Node*aux=a_cim;
        while(aux!=NULL)
        {
            fitxer<<aux->c.solicitar_uid()<<" ";
            aux=aux->seguent;
        }
        fitxer<<endl;
    }
}
void Historial::empilar(const Canco&c,string criteri)
{
    Node*aux=new Node; aux->c=c;
    aux->seguent=NULL;

    if(buida()) a_cim=a_base=aux;
    else
    {
        if(criteri=="cim")
        { aux->seguent=a_cim; a_cim=aux; }

        else if(criteri=="MTP[STACK]")
        { a_base->seguent=aux; a_base=aux; }
    }

    a_n_elements++;
}
void Historial::desempila()
{
    if(not buida())
    {
        if(a_cim==a_base)
            {delete a_cim; a_cim=a_base=NULL;}

        else
        {
            Node*aux=a_cim;
            a_cim=a_cim->seguent;
            delete aux;
        }

        a_n_elements--;
    }
}
void Historial::alliberar()
{
    while(not buida())desempila();
}
void Historial::copiar(const Historial&h)
{
    if(not h.buida())
    {
        Node*origen,*desti;
        origen=h.a_cim;

        a_cim=new Node;desti=a_cim;

        while(origen->seguent!=NULL)
        {
            desti->c=origen->c;
            Node*aux=new Node; desti->seguent = aux;

            desti=desti->seguent;
            origen=origen->seguent;
        }
        desti->c=origen->c; desti->seguent=NULL; a_base=desti;
        a_n_elements=h.a_n_elements;
    }
}

