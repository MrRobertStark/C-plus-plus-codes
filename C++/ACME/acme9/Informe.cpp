#include "Informe.h"

Informe::Informe()
//Pre: cert
//Post: incialització de les variables amb els valors per defecte
{
    a_comarca="";
    a_poblacio="";
    a_litres_pluja=0;
    a_cm_neu=0;
    a_n_incidents=0;
}
void Informe::mostrar_informe()const
//pre:cert
//post:es mostren totes les dades desats a l'objecte actual
{
    cout<<a_comarca<<", "<<a_poblacio<<": ";
    if(a_litres_pluja!=0)cout<<a_litres_pluja<<" l/m2 ";
    if(a_cm_neu!=0)cout<<a_cm_neu<<" cm ";
    if(a_vent.consultar_velocitat()!=0)a_vent.mostrar_dades_vent();
    if(a_n_incidents!=0)
    {
        cout<< "-- "<<a_incidents[0];
        for(int i=1;i<a_n_incidents;i++)cout<<", "<<a_incidents[i];
    }
    cout<<endl;
}
int Informe::consultar_n_incidencies()const
//Pre:cert
//Post:es retorna el nombre d'incidencies de l'objecte actual
{
    return a_n_incidents;
}
int Informe::consultar_litres_pluja()const
//Pre: litres>=0
//Post: es retornen els litres de l'objecte actual
{
    return a_litres_pluja;
}
int Informe::consultar_cm_neu()const
//pre: cm_neu>=0
//post: es retornen els cm de l'objecte actual
{
    return a_cm_neu;
}
int Informe::consultar_velocitat_vent()const
//Pre: velocitat>=0
//Post: es retorna la velocitat del vent de l'objecte actual
{
    return a_vent.consultar_velocitat();
}
bool Informe::es_menor(const Informe&i,char criteri)const
//Pre: les dades de i han de ser correctes
//Post: es comprova si l'objecte actual es menor que l'entrat segons el criteri entrat
{
    bool menor=false;

    if(criteri=='p')
        menor=(a_litres_pluja<i.a_litres_pluja or
               (a_litres_pluja==i.a_litres_pluja&&a_comarca<i.a_comarca)or
               (a_litres_pluja==i.a_litres_pluja&&a_comarca==i.a_comarca&&a_poblacio<i.a_poblacio));

    else if(criteri=='n')
        menor=(a_cm_neu<i.a_cm_neu or
               (a_cm_neu==i.a_cm_neu&&a_comarca<i.a_comarca)or
               (a_cm_neu==i.a_cm_neu&&a_comarca==i.a_comarca&&a_poblacio<i.a_poblacio));

    else if(criteri=='v')
        menor=(a_vent.consultar_velocitat()<i.a_vent.consultar_velocitat() or
               (a_vent.consultar_velocitat()==i.a_vent.consultar_velocitat()&&a_comarca<i.a_comarca)or
               (a_vent.consultar_velocitat()==i.a_vent.consultar_velocitat()&&a_comarca==i.a_comarca&&a_poblacio<i.a_poblacio));

    return menor;
}
bool Informe::operator<(const Informe&i)const
//Pre: cert
//Post: es comprova si l'objecte actual es menor que l'entrat segons la comarca-població
{
    return (a_comarca<i.a_comarca or
            (a_comarca==i.a_comarca&&a_poblacio<i.a_poblacio));
}
bool Informe::operator==(const Informe&i)const
//Pre: cert
//Post: es comprova si l'objecte actual es igual que l'entrat segons comarca-població
{
    return (a_comarca==i.a_comarca&&a_poblacio==i.a_poblacio);
}
bool Informe::operator!=(const Informe&i)const
//Pre:cert
//Post:es comprova si l'objecte actual és diferent que l'entrat segons la comarca-població
{
    return !(a_comarca==i.a_comarca&&a_poblacio==i.a_poblacio);
}
Informe Informe::emplenar_informacio()
//Pre: cert
//Post: es retorna un informe nou amb les dades plenes
{
    char tipus_dada; Informe aux;

    cout<<"Poblacio:"<<endl;
    while(aux.a_poblacio=="")getline(cin,aux.a_poblacio);
    if(aux.a_poblacio!="FI")
    {
        cout<<"Comarca:"<<endl;
        getline(cin,aux.a_comarca);

        cout<< "[p/n/v/i]:"<<endl;
        cin>>tipus_dada;

        cout<< "Dada:"<<endl;
        if(tipus_dada=='p')cin>>aux.a_litres_pluja;
        else if(tipus_dada=='n')cin>>aux.a_cm_neu;
        else if(tipus_dada=='v')aux.a_vent.llegir_dades_vent();
        else if(tipus_dada=='i')
        {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            getline(cin,aux.a_incidents[aux.a_n_incidents]);
            aux.a_n_incidents++;
        }
    }
    return aux;
}
void Informe::incrementar_litres_pluja(const Informe&i)
//Pre: els litres han de ser enters positius
//Post: es sumen els litres dels dos objectes i es desa a l'actual
{
    a_litres_pluja+=i.a_litres_pluja;
}
void Informe::incrementar_cm_neu(const Informe&i)
//Pre: els cms dels objectes han de ser enters positius
//Post: es sumen els cms dels dos objectes i es desa a l'actual
{
    a_cm_neu+=i.a_cm_neu;
}
void Informe::actualitzar_dades_vent(const Informe&i)
//Pre: les dades del vent han de ser les correctes
//Post: s'ecriu a l'objecte actual la informació vent més gran (qui tingui major velocitat)
{
    if(a_vent.consultar_velocitat()<i.a_vent.consultar_velocitat())a_vent=i.a_vent;
}
void Informe::actualitzar_incidencies(const Informe&i)
//Pre: les dades dels informes han de ser les correctes
//Post: es registra a la taula de les incidencies de l'objecte actual les incidències de l'informe actual.
{
    if(a_n_incidents<MAX_INCIDENTS){a_incidents[a_n_incidents]=i.a_incidents[0];a_n_incidents++;}
}
string Informe::consultar_poblacio()const
//Pre: cert
//Post:es consulta el nom de la població de l'objecte actual
{
    return a_poblacio;
}
