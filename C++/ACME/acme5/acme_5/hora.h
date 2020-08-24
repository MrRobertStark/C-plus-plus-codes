#include <iostream>
#ifndef HORA_H
#define HORA_H
using namespace std;

class Hora
{
    public:
        //ATRIBUTS
        Hora();
        //CONSULTORS
        void mostrar()const;
        int duracio(const Hora&h)const;
        bool es_menor(const Hora&h)const;
        //MODIFICADORS
        void llegir();
        //METODES PUBLICS

    protected:

    private:
        //ATRIBUTS
        int a_hora;
        int a_minut;
        //CONSTANTS
        const int MAX_HORA=24;
        const int MAX_MINUT=60;
        //METODES PRIVATS
        static bool es_hora_valida(int hora,int minut);
};

#endif // HORA_H
