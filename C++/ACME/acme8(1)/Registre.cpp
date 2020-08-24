#include "Registre.h"

Registre::Registre()
{
    a_n_lletres=25;
}
void Registre::afegir_paraula_al_registre(const Paraula&p)
//Pre:
//Post:
{
    int classificacio=conversor_lletra_num(p.consultar_inicial());
    a_taula[classificacio].analitzar_existencia_paraula(p);
}
void Registre::buscar_paraules_amb_minim_aparicions()const
//Pre:
//Post:
{
    cout<< "ENTRA UN LIMIT: "<<endl;
    int limit;cin>>limit;
    for(int i=0;i<N_LLETRES_DIFERENTS;i++)a_taula[i].consultar_paraules_amb_minim_aparicions(limit);
}
int Registre::conversor_lletra_num(char inicial)
//Pre:
//Post:
{
    return (inicial-'a');
}
int Registre::recompte_paraules_diferents()const
//Pre:
//post:
{
    int recompte=0;
    for(int i=0;i<N_LLETRES_DIFERENTS;i++)recompte+=a_taula[i].consultar_n_paraules_diferents();
    return recompte;
}
