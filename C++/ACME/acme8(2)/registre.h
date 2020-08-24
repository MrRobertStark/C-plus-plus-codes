#ifndef REGISTRE_H
#define REGISTRE_H

#include<fstream>
#include<string>
#include<iostream>

#include "vector_paraules.h"
#include "Paraula.h"

using namespace std;

class registre
{
    public:
        //CONSTRUCTORS
        registre();
        //pre:
        //post:
        //CONSULTORS
        int consultar_paraules_totals()const;
        //Pre:
        //Post:
        void buscar_paraules_amb_llindar()const;
        //Pre:
        //Post:
        //MODIFICADORS
        void implementar_paraula_al_registre(ifstream&fitxer);
        //Pre:
        //Post:

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int MAX_ELEMENTS=25;
        static const int NO_TROBAT=-1;
        //ATRIBUTS
        vector_paraules a_registre[MAX_ELEMENTS];
        int a_n_totals;
        //METODES PRIVATS
        //METODES DE CLASSE
        static int conversio_char_a_num(char m);
};

#endif // REGISTRE_H
