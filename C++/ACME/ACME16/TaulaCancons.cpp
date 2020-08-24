#include "TaulaCancons.h"

TaulaCancons::TaulaCancons()
{
    a_maxim_uid=0;
    a_maxim_elements=5;
    a_n_elements=0;
    a_t=new Canco[a_maxim_elements];
}
TaulaCancons::TaulaCancons(const TaulaCancons&taula)
{
    copiar(taula);
}
TaulaCancons&TaulaCancons::operator=(const TaulaCancons&taula)
{
    if(&taula!=this)
    {
        alliberar();copiar(taula);
    }
    return (*this);
}
TaulaCancons::~TaulaCancons()
{
    alliberar();
}
void TaulaCancons::mostrar_cancons_limit_temps(const Durada&d)const
//pre:temps>0//post:es mostren les cancons pel limit entrat per teclat
{
    int limit=d.solicitar_durada(),sumador=0,pos=0;
    while(sumador+a_t[pos].consultar_duracio()<=limit)
    {
        sumador+=a_t[pos].consultar_duracio();a_t[pos].mostrar_canco();
        pos++;
    }
    cout<< "TEMPS TOTAL: ";Durada d1=Durada(sumador);d1.mostrar_durada();cout<<endl;
}
Canco TaulaCancons::solicitar_canco(int pos)const
{
    return a_t[pos];
}
int TaulaCancons::solicitar_maxim_uid()const
{
    return a_maxim_uid;
}
int TaulaCancons::solicitar_n_elements()const
{
    return a_n_elements;
}
void TaulaCancons::mostrar_taula()const
{
    for(int i=0;i<a_n_elements;i++)a_t[i].mostrar_canco();
}
void TaulaCancons::inserir_per_criteri(const Canco&c,string criteri)
{
    if(criteri=="break")insercio_per_durada(c);
    else if(criteri=="songs")insercio_general(c);
    else if(criteri=="genre")insercio_per_genere(c);
}
bool TaulaCancons::buscar_preexistencia(const Canco&c)const
{
    int esq=0,dret=a_n_elements-1,mig=(esq+dret)/2;bool trobat=false;
    if(esq==dret)trobat=(a_t[esq]==c);
    else
    {
        while(esq!=dret-1&&a_t[mig]!=c)
        {
            if(a_t[mig]<c)esq=mig;
            else dret=mig;
            mig=(esq+dret)/2;
        }
        trobat=(a_t[mig]==c or a_t[dret]==c);
    }
    return trobat;
}
void TaulaCancons::backup()const
{
    ofstream fitxer("a.dat");
    for(int i=0;i<a_n_elements;i++)a_t[i].backup(fitxer);
}
void TaulaCancons::actualitzar_maxim_uid(int k)
//pre:k>=0//post:a_maxim_uid=k
{
    a_maxim_uid=k;
}
void TaulaCancons::insercio_general(const Canco&c)
{
    if(a_n_elements==a_maxim_elements)ampliar();

    int pos=a_n_elements;a_t[pos]=c;
    while(pos>0&&a_t[pos]<a_t[pos-1])
    {
        intercanviar(a_t[pos],a_t[pos-1]);pos--;
    }
    a_n_elements++;
}
void TaulaCancons::insercio_per_genere(const Canco&c)
{
    if(a_n_elements==a_maxim_elements)ampliar();

    int pos=a_n_elements;a_t[pos]=c;
    while(pos>0&&a_t[pos].es_menor(a_t[pos-1],"genre"))
    {
        intercanviar(a_t[pos],a_t[pos-1]);pos--;
    }
    a_n_elements++;
}
void TaulaCancons::insercio_per_durada(const Canco&c)
{
    if(a_n_elements==a_maxim_elements)ampliar();

    int pos=a_n_elements;a_t[pos]=c;
    while(pos>0&&a_t[pos].es_menor(a_t[pos-1],"break"))
    {
        intercanviar(a_t[pos],a_t[pos-1]);pos--;
    }
    a_n_elements++;
}
void TaulaCancons::alliberar()
{
    a_maxim_elements=a_maxim_uid=a_n_elements=0;
    delete[] a_t;
}
void TaulaCancons::reservar()
{
    a_t=new Canco[a_maxim_elements];
}
void TaulaCancons::copiar(const TaulaCancons&taula)
{
    a_maxim_uid=taula.a_maxim_uid;
    a_maxim_elements=taula.a_maxim_elements;
    a_n_elements=taula.a_n_elements;

    reservar();
    for(int i=0;i<a_n_elements;i++)a_t[i]=taula.a_t[i];
}
void TaulaCancons::ampliar()
{
    Canco*aux=a_t; a_maxim_elements*=2;
    reservar();

    for(int i=0;i<a_n_elements;i++)a_t[i]=aux[i];
    delete[]aux;
}
void TaulaCancons::intercanviar(Canco&c1,Canco&c2)
{
    Canco aux=c1;c1=c2;c2=aux;
}
