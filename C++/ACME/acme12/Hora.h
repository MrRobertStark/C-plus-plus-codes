#ifndef HORA_H
#define HORA_H

#include <iostream>

using namespace std;

class Hora
{
    public:
        //CONSTRUCTORS
        Hora();
        //Pre:cert//Post:s'inicialitzen les variables a l'hora 00:00
        //CONSULTORS
        int duracio(const Hora&h)const;
        //Pre:les dades de les hores han de ser correctes//Post:es retorna la duració total entre dues hores
        void mostrar_hora()const;
        //Pre:les dades de l'hora han de ser correctes//Post:es mostra la hora desada a l'objecte actual
        //MODIFICADORS
        void llegir_hora();
        //Pre:cert//Post:es llegeix una hora correcte entrada per teclat

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
        //Pre:cert//Post:retorna cert/fals en funció de si l'hora entrada per teclat és correcte
        static bool es_nombre(char c);
        //Pre:c és un char//Post:retorna cert/fals si c representa un nombre entre 0 i 9
        static int conversio_num(char c);
        //Pre:c>='0' && c<='9'//Post:es retorna el nombre decimal que representa c

};

#endif // HORA_H
