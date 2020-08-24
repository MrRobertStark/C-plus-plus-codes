#include "TaulaCancons.h"

TaulaCancons::TaulaCancons()
{
    a_maxim_elements=5;
    a_n_elements=a_maxim_uid=0;
    reservar();
}
TaulaCancons::TaulaCancons(const TaulaCancons&taula)
{
    copiar(taula);
}
TaulaCancons&TaulaCancons::operator=(const TaulaCancons&taula)
{
    if(this!=&taula)
        copiar(taula);

    return *this;
}

TaulaCancons::~TaulaCancons()
{
    alliberar();
}
void TaulaCancons::mostrar_cancons(string criteri)const
{
    if(criteri!="d"&&criteri!="topten")
        for(int i=0;i<a_n_elements;i++)a_t[i].mostrar_canco();

    else
    {
        int pos=0;
        while(pos<10&&pos<a_n_elements) { a_t[pos].mostrar_canco(); pos++; }
    }
}
int TaulaCancons::solicitar_a_n_elements()const
{
    return a_n_elements;
}
Canco TaulaCancons::solicitar_canco(int pos)const
{
    return a_t[pos];
}
int TaulaCancons::solicitar_maxim_uid()const
{
    return a_maxim_uid;
}
int TaulaCancons::preexistencia(const Canco&c,string criteri)const
{
    int trobat=-1;
    if(criteri=="uid")
    {
        int esq=0,dret=a_n_elements-1,mig=(esq+dret)/2;
        if(esq<dret)
        {
            while(esq<dret&&a_t[mig].solicitar_uid()!=c.solicitar_uid())
            {
                if(a_t[mig].solicitar_uid()<c.solicitar_uid())esq=mig+1;
                else dret=mig-1;
                mig=(esq+dret)/2;
            }
        }
        if(a_t[mig].solicitar_uid()==c.solicitar_uid())trobat=mig;
    }
    else if(criteri=="songs")
    {
        int pos=0;
        while(pos<a_n_elements&&a_t[pos]!=c)pos++;
        if(pos<a_n_elements)trobat=pos;
    }
    return trobat;
}
void TaulaCancons::eliminar_canco(int pos)
{
    for(int i=pos;i<a_n_elements-1;i++) a_t[i]=a_t[i+1];
    a_n_elements--;
}
void TaulaCancons::backup(ofstream&fitxer)const
{
    for(int i=0;i<a_n_elements;i++)a_t[i].backup(fitxer);
}
void TaulaCancons::inserir_per_criteri(const Canco&c,string criteri)
{
    if(a_n_elements==a_maxim_elements)ampliar();
    incrementar_maxim_uid(c.solicitar_uid());
    int i=a_n_elements;

    while(i>0&&c.es_menor(a_t[i-1],criteri))
    {
        a_t[i]=a_t[i-1];
        i--;
    }
    a_t[i]=c;
    a_n_elements++;
}
void TaulaCancons::incrementar_maxim_uid(int k)
{
    if(k>a_maxim_uid)a_maxim_uid=k;
}
void TaulaCancons::actualizar_info_canco(int pos,const Canco&c)
{
    a_t[pos]=c;
}
void TaulaCancons::alliberar()
{
    a_maxim_elements=5; a_maxim_uid=a_n_elements=0;
    delete[]a_t;
}
void TaulaCancons::reservar()
{
    a_t=new Canco[a_maxim_elements];
}
void TaulaCancons::copiar(const TaulaCancons&taula)
{
    alliberar();

    a_n_elements=taula.a_n_elements;
    a_maxim_elements=taula.a_maxim_elements;
    a_maxim_uid=taula.a_maxim_uid;

    reservar();
    for(int i=0;i<taula.a_n_elements;i++)a_t[i]=taula.a_t[i];
}
void TaulaCancons::ampliar()
{
    Canco*aux=a_t;a_maxim_elements*=2;
    reservar();
    for(int i=0;i<a_n_elements;i++)a_t[i]=aux[i];
    delete []aux;
}
