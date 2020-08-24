#include "Esdeveniment.h"

Esdeveniment::Esdeveniment()
//Pre: cert
//Post: s'inicialitzen els valors de l'objecte Esdeveniment
{
    a_esdeveniment="";
}
void Esdeveniment::llegir_esdeveniment()
//Pre: cert
//Post: es llegeixen dades intrínsiques d'un esdeveniment i es desen en un objecte Esdeveniment
{
    cout<< "DESCRIPCIO:"<<endl;
    cin>>a_esdeveniment;
    cout<< "DIA:"<<endl;
    a_data.llegir_data();
    cout<< "HORA INICI:"<<endl;
    a_h_inici.llegir();
    cout<< "HORA FINAL:"<<endl;
    do{
        a_h_final.llegir();
    }while(a_h_final<a_h_inici);
}

bool Esdeveniment::operator==(const Esdeveniment&e)const
//Pre: A i B
//Post: A==B
{
    return (a_esdeveniment==e.a_esdeveniment&&
            a_data==e.a_data&&
            a_h_final==e.a_h_final&&
            a_h_inici==e.a_h_inici);
}
bool Esdeveniment::operator<(const Esdeveniment&e)const
//Pre: A i B
//Post: A<B
{
    bool menor=false;
    if (a_data<e.a_data)menor=true;
    else if(a_data==e.a_data &&a_h_inici<e.a_h_inici)menor=true;
    else if(a_data==e.a_data &&a_h_inici==e.a_h_inici&&a_h_final<e.a_h_final)menor=true;
    else if(a_data==e.a_data &&a_h_inici==e.a_h_inici&&a_h_final==e.a_h_final&&a_esdeveniment<e.a_esdeveniment)menor=true;
    return menor;
}
bool Esdeveniment::operator!=(const Esdeveniment&e)const
//Pre: A i B
//Post: A!=B
{
    return !(a_esdeveniment==e.a_esdeveniment&&
            a_data==e.a_data&&
            a_h_final==e.a_h_final&&
            a_h_inici==e.a_h_inici);
}
int Esdeveniment::duracio_esdeveniment()const
//Pre:
//Post:
{
    return a_h_inici.durada(a_h_final);
}
bool Esdeveniment::es_igual_data_esdeveniments(const Esdeveniment&e1)const
//Pre:
//Post:
{
    return (e1.a_data==a_data);
}
bool Esdeveniment::son_dates_equivalents(const Data&d)const
//Pre:
//Post:
{
    return (a_data==d);
}
bool Esdeveniment::es_data_inferior(const Data&d)const
//Pre:
//Post:
{
    return (a_data<d);
}
