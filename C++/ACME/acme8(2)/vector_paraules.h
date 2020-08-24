#ifndef VECTOR_PARAULES_H
#define VECTOR_PARAULES_H

#include <iostream>
#include "Paraula.h"

using namespace std;

class vector_paraules
{
    public:
        //CONSTRUCTORS
        vector_paraules();
        //Pre:
        //Post:
        //CONSULTORS
        void consultar_paraules_per_llindar(int llindar)const;
        //Pre:
        //post:
        int consultar_n_elements()const;
        //Pre:
        //Post:
        //MODIFICADORS
        void implementar_paraula_al_llistat(const Paraula&p,int&total);
        //Pre:
        //Post:

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int TOTAL_ELEMENTS=25000;
        static const int NO_TROBAT=-1;
        //ATRIBUTS
        int a_n_elements;
        Paraula a_taula[TOTAL_ELEMENTS];
        //METODES PRIVATS
        int buscar_preexistencia_al_llistat(const Paraula&p)const;
        //Pre:
        //Post:
        void inserir_ordenat(const Paraula&p);
        //pre:
        //post:
        void incrementar_n_aparicions(int pos);
        //Pre:
        //Post:
        //METODES DE CLASSE
        static void intercanviar(Paraula&p1,Paraula&p2);
        //pre:
        //post:
};

#endif // VECTOR_PARAULES_H
