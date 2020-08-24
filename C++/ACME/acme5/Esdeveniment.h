#ifndef ESDEVENIMENT_H
#define ESDEVENIMENT_H

#include<iostream>
#include "Data.h"
#include "Hora.h"

using namespace std;

class Esdeveniment
{
    public:
        //constructors
        Esdeveniment();
        //consultors
        void mostrar_esdeveniment()const;
        //modificadors
        void llegir();
        //funcions publics
        bool es_mes_llarg(const Esdeveniment&e);
        //acions publics


    protected:

    private:
        //atributs
        string a_succes;
        Data a_dia;
        Hora a_h_inici;
        Hora a_h_final;
        //constants
        //metodes privats
};

#endif // ESDEVENIMENT_H
