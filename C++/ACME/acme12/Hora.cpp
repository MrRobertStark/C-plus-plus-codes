#include "Hora.h"

Hora::Hora()
//Pre:cert//Post:s'inicialitzen les variables a l'hora 00:00
{
    a_hora=0;
    a_minut=0;
}
int Hora::duracio(const Hora&h)const
//Pre:les dades de les hores han de ser correctes//Post:es retorna la duració total entre dues hores
{
    int hores=abs(h.a_hora-a_hora);hores*=MAX_MINUTS;
    int minuts=(h.a_minut-a_minut);
    return (hores+minuts);
}
void Hora::mostrar_hora()const
//Pre:les dades de l'hora han de ser correctes//Post:es mostra la hora desada a l'objecte actual
{
    if(a_hora<10)cout<<0;cout<<a_hora<<":";
    if(a_minut<10)cout<<0;cout<<a_minut<<endl;
}
void Hora::llegir_hora()
//Pre:cert//Post:es llegeix una hora correcte entrada per teclat
{
    int hora=0,minut=0;
    char format; cin>>format;

    do{
        while(es_nombre(format)){hora=hora*10+conversio_num(format);cin>>format;}
        for(int i=0;i<2;i++){cin>>format;minut=minut*10+conversio_num(format);}
    }while(not es_hora_valida(hora,minut));

    a_hora=hora;
    a_minut=minut;
}
bool Hora::es_hora_valida(int hora,int minut)
//Pre:cert//Post:retorna cert/fals en funció de si l'hora entrada per teclat és correcte
{
    return(hora>=0&&hora<MAX_HORES && minut>=0&&minut<MAX_MINUTS);
}
bool Hora::es_nombre(char c)
//Pre:c és un char//Post:retorna cert/fals si c representa un nombre entre 0 i 9
{
    return (c>='0' && c<='9');
}
int Hora::conversio_num(char c)
//Pre:c>='0' && c<='9'//Post:es retorna el nombre decimal que representa c
{
    return (c-'0');
}
