#include "Classificacio.h"

Classificacio::Classificacio()
{
    a_n_elements=0;
}
void Classificacio::mostrar_paraules_amb_minim_aparicions()const
//Pre:
//Post:
{
    cout<< "ENTRA EL MINIM D'APARICIONS:"<<endl;
    int limit;cin>>limit;
    for(int i=0;i<a_n_elements;i++)if(a_llistat_Paraules[i].consultar_n_aparicions()>limit)
        a_llistat_Paraules[i].mostrar_paraula();
}
void Classificacio::inserir_ordenat(const Paraula& p)
//Pre:
//Post:
{
    int i=a_n_elements;
    if(a_n_elements<MAX_ELEMENTS)
    {
        a_llistat_Paraules[i]=p;
        while(i>0&&a_llistat_Paraules[i]<a_llistat_Paraules[i-1])
        {
            intercanviar(a_llistat_Paraules[i],a_llistat_Paraules[i-1]);
            i--;
        }
        a_n_elements++;
    }
}
int Classificacio::buscar_preexistencia_paraula(const Paraula&p)const
//Pre:
//Post:
{
    int esq=0,dret=a_n_elements-1,mig=(esq+dret)/2,pos=NO_TROBAT;
    if(esq<dret)
    {
        while(esq!=dret-1&&a_llistat_Paraules[mig]!=p)
        {
            if(a_llistat_Paraules[mig]<p)esq=mig;
            else dret=mig;
            mig=(esq+dret)/2;
        }
        if(a_llistat_Paraules[mig]==p)pos=mig;
        else if(a_llistat_Paraules[dret]==p)pos=dret;
    }
    else if(esq==dret && a_llistat_Paraules[mig]==p)pos=mig;
    return pos;
}
void Classificacio::intercanviar(Paraula&p1,Paraula&p2)
//Pre:
//Post:
{
    Paraula aux=p1;
    p1=p2;p2=aux;
}
void Classificacio::incrementar_aparicions(int pos)
//Pre:
//Post:
{
    a_llistat_Paraules[pos].incrementar_n_aparicions();
}
int Classificacio::consultar_n_paraules_diferents()const
//Pre:
//post:
{
    return a_n_elements;
}
