#include "Vector_Paraules.h"

Vector_Paraules::Vector_Paraules()
{
    an_paraules_diferents=0;
}
int Vector_Paraules::consultar_n_paraules_diferents()const
//Pre:
//Post:
{
    return an_paraules_diferents;
}
void Vector_Paraules::analitzar_existencia_paraula(const Paraula&p)
//Pre:
//Post:
{
    int pos=buscar_pos_preexistencia_paraula(p);
    if(pos==NO_TROBAT)inserir_ordenat(p);
    else incrementar_n_aparicions_paraula(pos);
}
int Vector_Paraules::buscar_pos_preexistencia_paraula(const Paraula&p)const
//Pre:
//post:
{
    int esq=0,dret=an_paraules_diferents-1,mig=(esq+dret)/2,pos=NO_TROBAT;
    if(esq<dret)
    {
        while(esq!=dret-1&&vector_paraules[mig]!=p)
        {
            if(vector_paraules[mig]<p)esq=mig;
            else dret=mig;
            mig=(esq+dret)/2;
        }
        if(vector_paraules[mig]==p)pos=mig;
        else if(vector_paraules[dret]==p)pos=dret;
    }
    else if(esq==dret&&vector_paraules[esq]==p)pos=esq;
    return pos;
}
void Vector_Paraules::intercanviar(Paraula&p1,Paraula&p2)
//Pre:
//Post:
{
    Paraula aux=p1;
    p1=p2; p2=aux;
}
void Vector_Paraules::inserir_ordenat(const Paraula&p)
//Pre:
//Post:
{
    int i=an_paraules_diferents;
    if(an_paraules_diferents<MAX_ELEMENTS)
    {
        vector_paraules[i]=p;
        while(i>0&&vector_paraules[i]<vector_paraules[i-1])
        {
            intercanviar(vector_paraules[i],vector_paraules[i-1]);
            i--;
        }
        an_paraules_diferents++;
    }
}
void Vector_Paraules::incrementar_n_aparicions_paraula(int pos)
//Pre:
//Post:
{
    vector_paraules[pos].incrementar_n_aparicions();
}
void Vector_Paraules::consultar_paraules_amb_minim_aparicions(int llindar)const
//Pre:
//Post:
{
    for(int i=0;i<an_paraules_diferents;i++)if(vector_paraules[i].consultar_n_aparicions()>llindar)vector_paraules[i].mostrar_paraula();
}
