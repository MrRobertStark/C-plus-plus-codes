#ifndef HORA_H
#define HORA_H

#include <iostream>

using namespace std;

class Hora
{
    public:
        //CONSTRUCTORS
        Hora();
        //Pre:cert
        //Post:minut=hora=0
        //CONSULTORS
        void mostrar_hora()const;
        //Pre:cert
        //Post:es mostra la hora desada a l'objecte actual
        //MODIFICADORS
        void llegir_hora();
        //Pre:cert
        //Post:es llegeix la hora introduida en format HH::MM

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int MAX_HORES=24;
        static const int MAX_MINUTS=60;
        //ATRIBUTS
        int a_hora;
        int a_minut;
        //METODES PRIVATS
        //METODES DE CLASSE
        static bool es_hora_valida(int hora,int minut);
        //Pre:cert
        //Post: hora>=0 i hora<MAX_HORES i minut>=0 i minut<MAX_MINUTS
        static bool es_num(char c);
        //Pre: cert
        //Post: retorna cert en cas que c representi un nombre enter entre el 0 i el 9
        static int conversio_num(char c);
        //Pre: c ha de ser un char
        //Post: es converteix el nombre que representa c en un int
};

#endif // HORA_H
