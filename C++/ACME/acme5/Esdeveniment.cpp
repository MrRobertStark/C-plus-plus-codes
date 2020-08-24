#include "Esdeveniment.h"

Esdeveniment::Esdeveniment()
{
    a_succes="";
}
void Esdeveniment::llegir()
{
    string succes;
    Data dia;
    Hora h_inici,h_final;
    cout<< "DESCRIPCIO:"<<endl;
    cin>>succes;
    cout<<"DIA:"<<endl;
    dia.llegir();
    cout<<"HORA INICI:"<<endl;
    h_inici.llegir();
    cout<< "HORA FINAL:"<<endl;
    do{
        h_final.llegir();
    }while(not h_inici.es_menor(h_final));

    a_succes=succes;
    a_h_inici=h_inici;
    a_h_final=h_final;
    a_dia=dia;
}
void Esdeveniment::mostrar_esdeveniment()const
{
    cout<< "DESCRIPCIO: "<<a_succes<<endl;
    cout<< "DATA: "; a_dia.mostrar();cout<<endl;
    cout<< "HORA: "; a_h_inici.mostrar();
    cout<<" - ";a_h_final.mostrar();
}
bool Esdeveniment::es_mes_llarg(const Esdeveniment& e)
{
    return(a_h_inici.duracio(a_h_final)<e.a_h_inici.duracio(e.a_h_final));
}
