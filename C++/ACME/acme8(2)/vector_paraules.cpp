#include "vector_paraules.h"

vector_paraules::vector_paraules()
{
   a_n_elements=0;
}
void vector_paraules::implementar_paraula_al_llistat(const Paraula&p,int&total)
//Pre:
//Post:
{
    int pos=buscar_preexistencia_al_llistat(p);
    if(pos==NO_TROBAT&&total<TOTAL_ELEMENTS){inserir_ordenat(p);total++;}
    else incrementar_n_aparicions(pos);
}
int vector_paraules::buscar_preexistencia_al_llistat(const Paraula&p)const
//Pre:
//Post:
{
    int esq,dret,mig,pos;
    esq=0;dret=a_n_elements-1;mig=(esq+dret)/2;pos=NO_TROBAT;
    if(esq<dret)
    {
        while(esq!=dret-1 && a_taula[mig]!=p)
        {
            if(a_taula[mig]<p)esq=mig;
            else dret=mig;
            mig=(esq+dret)/2;
        }
        if(a_taula[mig]==p)pos=mig;
        else if(a_taula[dret]==p)pos=dret;
    }
    else if(esq==dret&&a_taula[esq]==p)pos=mig;
    return pos;
}
void vector_paraules::inserir_ordenat(const Paraula&p)
//Pre:
//post:
{
    if(a_n_elements<TOTAL_ELEMENTS)
    {
        int i=a_n_elements;
        a_taula[i]=p;
        while(i>0&&a_taula[i]<a_taula[i-1])
        {
            intercanviar(a_taula[i],a_taula[i-1]);
            i--;
        }
        a_n_elements++;
    }
}
void vector_paraules::incrementar_n_aparicions(int pos)
//Pre:
//Post:
{
    a_taula[pos].incrementar_n_aparicions();
}
void vector_paraules::intercanviar(Paraula&p1,Paraula&p2)
//Pre:
//Post:
{
    Paraula aux=p1;
    p1=p2;
    p2=aux;
}
int vector_paraules::consultar_n_elements()const
//pre:
//post:
{
    return (a_n_elements);
}
void vector_paraules::consultar_paraules_per_llindar(int llindar)const
//pre:
//post:
{
    for(int i=0;i<a_n_elements;i++)if(a_taula[i].consultar_n_aparicions()>=llindar)
        a_taula[i].mostrar_paraula();
}
