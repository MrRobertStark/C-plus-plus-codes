#include "Esdeveniment.h"

Esdeveniment::Esdeveniment()
//pre:cert//post:s'inicialitzen les variables de l'esdeveniment pels valors per defecte
{
    a_descripcio="";
    a_codi=0;
}
Esdeveniment::Esdeveniment(const Hora&inici,const Hora&fin,const Data&data,string descripcio,int codi)
//Pre:les dades entrades han de ser correctes//Post:s'introdueixen i desen els valors entrats per teclat a l'Esdeveniment
{
    a_hora_inici=inici;
    a_hora_final=fin;
    a_data=data;
    a_descripcio=descripcio;
    a_codi=codi;
}
void Esdeveniment::mostrar()const
//pre:cert//post:es mostra l'Esdeveniment
{
    cout<<"[";a_data.mostrar_data();
    a_hora_inici.mostrar_marge_temps(a_hora_final);cout<<"] ";
    cout<<a_descripcio<<" ("<<a_codi<<")"<<endl;
}
bool Esdeveniment::operator==(const Esdeveniment&e)const
//Pre:les dades de l'esdeveniment han de ser correctes//post:retorna cert si els dos esdeveniments són iguals
{
    return(a_hora_inici==e.a_hora_inici&&a_hora_final==e.a_hora_final&&
           a_data==e.a_data&&a_descripcio==e.a_descripcio&&a_codi==e.a_codi);
}
bool Esdeveniment::operator!=(const Esdeveniment&e)const
//Pre:les dades de l'esdeveniment han de ser correctes//post:retorna cert si els dos esdeveniments són diferents
{
    return!(a_hora_inici==e.a_hora_inici&&a_hora_final==e.a_hora_final&&
           a_data==e.a_data&&a_descripcio==e.a_descripcio&&a_codi==e.a_codi);
}
bool Esdeveniment::operator>(const Esdeveniment&e)const
//pre:les dades de l'esdeveniment han de ser correctes//post:retorna cert si l'esdeveniment actual és superior a l'entrat
{
    return ((a_data>e.a_data)or
            (a_data==e.a_data&&a_hora_inici>e.a_hora_inici)or
            (a_data==e.a_data&&a_hora_inici==e.a_hora_inici&&a_hora_final>e.a_hora_final)or
            (a_data==e.a_data&&a_hora_inici==e.a_hora_inici&&a_hora_final==e.a_hora_final&&a_descripcio>e.a_descripcio));
}
bool Esdeveniment::operator<(const Esdeveniment&e)const
//pre:les dades de l'esdeveniment han de ser correctes//post:retorna cert si l'esdeveniment actual és inferior a l'entrat
{
    return !((a_data>e.a_data)or
            (a_data==e.a_data&&a_hora_inici>e.a_hora_inici)or
            (a_data==e.a_data&&a_hora_inici==e.a_hora_inici&&a_hora_final>e.a_hora_final)or
            (a_data==e.a_data&&a_hora_inici==e.a_hora_inici&&a_hora_final==e.a_hora_final&&a_descripcio>e.a_descripcio));
}
bool Esdeveniment::operator<=(const Esdeveniment&e)const
//Pre://post:
{
    return (*this)<e or (*this)==e;
}
int Esdeveniment::consultar_codi()const
//pre:cert//post:s'envia el codi de l'esdeveniment
{
    return a_codi;
}

