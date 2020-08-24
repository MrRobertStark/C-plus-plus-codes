#ifndef ESDEVENIMENT_H
#define ESDEVENIMENT_H

#include <iostream>
#include "Data.h"
#include "Hora.h"
#include <string>

using namespace std;

class Esdeveniment
{
    public:
        //CONSTRUCTORS
        Esdeveniment();
        //Pre: cert
        //Post: s'inicialitzen els valors de l'objecte Esdeveniment
        //CONSULTORS
        int duracio_esdeveniment()const;
        //Pre:
        //Post:
        bool es_igual_data_esdeveniments(const Esdeveniment&e1)const;
        //Pre:
        //Post:
        bool son_dates_equivalents(const Data&d)const;
        //Pre:
        //Post:
        bool es_data_inferior(const Data&d)const;
        //Pre:
        //Post:
        //MODIFICADORS
        void llegir_esdeveniment();
        //Pre: cert
        //Post: es llegeixen dades intrínsiques d'un esdeveniment i es desen en un objecte Esdeveniment
        //METODES D'INSTANCIES
        //OPRS
        bool operator ==(const Esdeveniment&e)const;
        //Pre: A i B
        //Post: A==B
        bool operator <(const Esdeveniment&e)const;
        //Pre: A i B
        //Post: A<B
        bool operator !=(const Esdeveniment&e)const;
        //Pre: A i B
        //Post: A!=B

    protected:

    private:
        //ATRIBUTS
        string a_esdeveniment;
        Data a_data;
        Hora a_h_inici;
        Hora a_h_final;
        //CONSTANTS DE CLASSE
        //METODES DE CLASSE

};

#endif // ESDEVENIMENT_H
