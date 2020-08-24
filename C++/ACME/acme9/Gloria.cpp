#include "Gloria.h"

Gloria::Gloria()
//Pre: cert
//Post: s'inicialitza els valors per defecte
{
    a_n_elements=0;
    a_maxim_incidencies=0;
}

void Gloria::mostrar_tots_els_informes()const
//Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS
//Post: es mostren tots els informes de la taula
{
    if(a_n_elements!=0)for(int i=0;i<a_n_elements;i++)a_registre[i].mostrar_informe();
    else cout<< "No tenim dades"<<endl;
}
void Gloria::mostrar_poblacio_amb_mes_incidencies()const
//Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
//Post: es mostra la població amb més incidències
{
    if(a_maxim_incidencies!=0)
    {
        int i=0;
        while(i<a_n_elements&&a_registre[i].consultar_n_incidencies()!=a_maxim_incidencies)i++;
        a_registre[i].mostrar_informe();
    }
    else cout<< "No hi ha incidents registrats"<<endl;
}
void Gloria::mostrar_informes_per_llindar()const
//Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
//Post: es mostren tots els informes que superen un llindar de caràcter entrat per teclat
{
    cout<< "[p/v/n]:"<<endl;
    char criteri; int llindar;
    cin>>criteri;
    cout<< "Llindar:"<<endl;
    cin>>llindar;

    Gloria taula;
    if(criteri=='p')ordenar_informes_llindar_pluja(llindar,taula);
    else if(criteri=='n')ordenar_informes_llindar_neu(llindar,taula);
    else if(criteri=='v')ordenar_informes_llindar_vent(llindar,taula);

    if(taula.a_n_elements!=0)taula.mostrar_tots_els_informes();
    else cout<< "Llindar no superat"<<endl;
}
void Gloria::ordenar_informes_llindar_pluja(int llindar, Gloria&taula)const
//Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
//Post: una taula d'informes ordenat per llindar litres de pluja decreixent. En cas d'empat per comarca-població
{
    for(int i=0;i<a_n_elements;i++)if(a_registre[i].consultar_litres_pluja()>llindar)taula.inserir_ordenat(a_registre[i],'p');
}
void Gloria::ordenar_informes_llindar_neu(int llindar, Gloria&taula)const
//Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
//Post: una taula d'informes ordenat per llindar cm de neu decreixent. En cas d'empat per comarca-població
{
    for(int i=0;i<a_n_elements;i++)if(a_registre[i].consultar_cm_neu()>llindar)taula.inserir_ordenat(a_registre[i],'n');
}
void Gloria::ordenar_informes_llindar_vent(int llindar, Gloria&taula)const
//Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
//Post: una taula d'informes ordenat per llindar velocitat de vent decreixent. En cas d'empat per comarca-població
{
    for(int i=0;i<a_n_elements;i++)if(a_registre[i].consultar_velocitat_vent()>llindar)taula.inserir_ordenat(a_registre[i],'v');
}
void Gloria::inserir_ordenat(const Informe&inf,char criteri)
//Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
//Post: s'insereix un informe a la taula actual en funció del criteri entrat.
{
    int i=a_n_elements;
    a_registre[i]=inf;

    if(criteri=='c')while(i>0&&a_registre[i]<a_registre[i-1]){intercanviar(a_registre[i],a_registre[i-1]);i--;}
    else while(i>0&&!a_registre[i].es_menor(a_registre[i-1],criteri)){intercanviar(a_registre[i],a_registre[i-1]);i--;}

    a_n_elements++;

}
void Gloria::intercanviar(Informe&i1,Informe&i2)
//Pre: A=a B=b
//Post: A=b B=a
{
    Informe aux=i1;
    i1=i2; i2=aux;
}
void Gloria::actualitzar()
//Pre: cert
//Post: s'actualitzen i implementen els informes existents/nous al registre.
{
    cout<< "Entra registres:"<<endl;
    Informe aux= aux.emplenar_informacio();

    while(aux.consultar_poblacio()!="FI")
    {
        int pos=buscar_existencia_previa(aux);
        if(pos==NO_TROBAT&&a_n_elements<MAX_ELEMENTS){
            inserir_ordenat(aux);
            actualitzar_max_incidencies(aux.consultar_n_incidencies());
        }
        else {
            implementar_dades_noves(pos,aux);
            actualitzar_max_incidencies(a_registre[pos].consultar_n_incidencies());
        }
        aux= aux.emplenar_informacio();
    }
}
int Gloria::buscar_existencia_previa(const Informe&aux)const
//Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
//Post: es retorna la posició de l'informe entrat. Si no existia pos=-1
{
    int esq=0,dret=a_n_elements-1,mig=(esq+dret)/2,pos=NO_TROBAT;
    if(esq<dret)
    {
        while(esq!=dret-1&&a_registre[mig]!=aux)
        {
            if(a_registre[mig]<aux)esq=mig;
            else dret=mig;
            mig=(esq+dret)/2;
        }
        if(a_registre[mig]==aux)pos=mig;
        else if(a_registre[dret]==aux)pos=dret;
    }
    else if(esq==dret&&a_registre[esq]==aux)pos=esq;

    return pos;
}
void Gloria::implementar_dades_noves(int pos,const Informe&aux)
//Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
//Post:s'actualitzen els valors de l'informe existent amb l'entrat
{
    if(aux.consultar_litres_pluja()!=0)a_registre[pos].incrementar_litres_pluja(aux);
    else if(aux.consultar_cm_neu()!=0)a_registre[pos].incrementar_cm_neu(aux);
    else if(aux.consultar_velocitat_vent()!=0)a_registre[pos].actualitzar_dades_vent(aux);
    else if(aux.consultar_n_incidencies()!=0)a_registre[pos].actualitzar_incidencies(aux);
}
void Gloria::actualitzar_max_incidencies(int n)
//Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
//Post: s'actualitza el nombre maxim d'incidències.
{
    if(n>a_maxim_incidencies)a_maxim_incidencies=n;
}




