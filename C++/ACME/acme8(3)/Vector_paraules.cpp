#include "Vector_paraules.h"

Vector_paraules::Vector_paraules()
{
    a_n_elements=0;
}
void Vector_paraules::implementar_paraula_dins_registre(const Paraula&p)
//Pre:
//Post:
{
    if(p.consultar_paraula()!=""){
        int inici= abecedari.recompte_n_elements_per_lletra(p.consultar_inicial())-1;
        int fin= inici+ abecedari.consulta_n_posicions_lletra(p.consultar_inicial())+1;
        int pos=buscar_preexistencia_paraula_al_registre(inici,fin,p);

        if(pos==NO_TROBAT&&a_n_elements<MAX_ELEMENTS)inserir_ordenat(p);
        else incrementar_aparicions_paraules(pos);
    }
}
int Vector_paraules::buscar_preexistencia_paraula_al_registre(int inici,int fin,const Paraula&p)
//Pre:
//Post:
{
    int esq=inici,dret=fin,mig=(esq+dret)/2,pos=NO_TROBAT;
    if(esq<dret)
    {
        while(esq!=dret-1&&vector_p[mig]!=p)
        {
            if(vector_p[mig]<p)esq=mig;
            else dret=mig;
            mig=(esq+dret)/2;
        }
        if(vector_p[mig]==p)pos=mig;
        else if(vector_p[dret]==p)pos=dret;
    }
    else if(esq==dret&&vector_p[esq]==p)pos=esq;
    return pos;
}
void Vector_paraules::incrementar_aparicions_paraules(int pos)
//Pre:
//Post:
{
    vector_p[pos].incrementar_n_aparicions();
}
void Vector_paraules::inserir_ordenat(const Paraula&p)
//Pre:
//Post:
{
    int i=a_n_elements; vector_p[i]=p;
    while(i>0&&vector_p[i]<vector_p[i-1])
    {
        intercanviar(vector_p[i],vector_p[i-1]);
        i--;
    }
    abecedari.increment_quantificador(p.consultar_inicial());
    a_n_elements++;
}
void Vector_paraules::intercanviar(Paraula&p1,Paraula&p2)
//Pre:
//Post:
{
    Paraula aux=p1;
    p1=p2; p2=aux;
}
void Vector_paraules::mostrar_paraula_per_llindar()const
//Pre:
//Post:
{
    int llindar;cin>>llindar;
    for(int i=0;i<a_n_elements;i++)if(vector_p[i].consultar_n_aparicions()>=llindar)vector_p[i].mostrar_paraula();
}
int Vector_paraules::consultar_paraules_totals()const
//Pre:
//Post:
{
    return a_n_elements;
}
