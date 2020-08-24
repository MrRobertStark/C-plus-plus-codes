#include "Data.h"

const int Data::DIES_MES[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Data::Data()
//Pre: cert
//Post: s'inicialitzen les variables amb els valors per defecte
{
    a_dia=1;
    a_mes=1;
    a_any=2001;
}
void Data::llegir_data()
//Pre: cert
//Post: es llegeix la data introduida en format DD/MM/AAAA
{
    int dia,mes,any;
    char format;
    do{
        dia=mes=any=0; cin>>format;

        while(es_numero(format)){dia=dia*10+conversio_a_num(format);cin>>format;}
        cin>>format;

        while(es_numero(format)){mes=mes*10+conversio_a_num(format);cin>>format;}

        for(int i=0;i<4;i++){cin>>format;any=any*10+conversio_a_num(format);}

    }while(not es_data_valida(dia,mes,any));

    a_dia=dia;a_mes=mes;a_any=any;

}
bool Data::es_data_valida(int dia,int mes,int any)
//Pre:cert
//Post:es desa la primera data llegida correcte
{
    bool correcte=true;
    bool es_de_trespas=(any%400==0) and (any%100!=0 or any%400==0);
    if(any>3999 or any<1600 or mes>MAX_MESOS or mes<1 or dia<1)correcte=false;
    else
    {
        int dies_mes;
        if(es_de_trespas&&mes==2)dies_mes=29;
        else dies_mes=DIES_MES[mes];

        if(dia>dies_mes)correcte=false;
    }
    return correcte;
}
bool Data::es_numero(char nombre)
//Pre: cert
//Post: retorna cert si nombre representa un dígit entre 0 i 9 inclosos.
{
    return (nombre>='0'&&nombre<='9');
}
void Data::mostrar_data()const
//Pre: cert
//Post: es mostra la data de l'objecte actual
{
    cout<<a_dia<<"/"<<a_mes<<"/"<<a_any<<" - ";
}
int Data::conversio_a_num(char c)
//Pre: c ha de ser un char
//Post: es retorna el dígit que representa c
{
    return (c-'0');
}
