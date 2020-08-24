#include "Hora.h"

Hora::Hora()
//Pre: cert
//Post: minut=hora=0
{
    a_minut=0;
    a_hora=0;
}
void Hora::mostrar_hora()const
//Pre: cert
//Post: es mostra la hora desada a l'objecte actual
{
    if(a_hora<10)cout<<0; cout<<a_hora<<":";
    if(a_minut<10)cout<<0; cout<<a_minut<<" ";
}
void Hora::llegir_hora()
//Pre: cert
//Post: es llegeix la hora introduida en format HH:MM
{
    int hora,minut; char format;
    do{
        hora=minut=0;
        cin>>format;
        while(es_num(format)){hora=hora*10+conversio_num(format);cin>>format;}
        for(int i=0;i<2;i++){cin>>format;minut=minut*10+conversio_num(format);}

    }while(not es_hora_valida(hora,minut));

    a_hora=hora; a_minut=minut;

}
bool Hora::es_hora_valida(int hora,int minut)
//Pre: cert
//Post: hora>=0 i hora<MAX_HORES i minut>=0 i minut<MAX_MINUTS
{
    return (hora>=0&&hora<MAX_HORES&&minut>=0&&minut<MAX_MINUTS);
}
bool Hora::es_num(char c)
//Pre: cert
//Post: retorna cert en cas que c representi un nombre enter
{
    return (c<='9'&&c>='0');
}
int Hora::conversio_num(char c)
//Pre: c ha de ser un char
//Post: es converteix el nombre que representa c en un int
{
    return (c-'0');
}
