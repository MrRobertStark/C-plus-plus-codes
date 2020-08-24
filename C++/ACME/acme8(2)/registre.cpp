#include "registre.h"

registre::registre()
{
    a_n_totals=0;
}
void registre::implementar_paraula_al_registre(ifstream&fitxer)
//Pre:
//Post:
{
    Paraula p; p.llegir_paraula(fitxer);
    if(p.consultar_paraula()!="")
    {
        int casella=conversio_char_a_num(p.consultar_inicial());
        a_registre[casella].implementar_paraula_al_llistat(p,a_n_totals);
    }
}
int registre::conversio_char_a_num(char m)
//Pre:
//Post:
{
    return (m-'a');
}
void registre::buscar_paraules_amb_llindar()const
//Pre:
//Post:
{
    int llindar;cin>>llindar;
    for(int i=0;i<MAX_ELEMENTS;i++)
        if(a_registre[i].consultar_n_elements()>0)a_registre[i].consultar_paraules_per_llindar(llindar);
}
int registre::consultar_paraules_totals()const
//pre:
//post:
{
    return a_n_totals;
}
