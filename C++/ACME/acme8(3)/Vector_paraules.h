#ifndef VECTOR_PARAULES_H
#define VECTOR_PARAULES_H

#include <iostream>
#include "Paraula.h"
#include "Vector_abecedari.h"

using namespace std;

class Vector_paraules
{
    public:
        //CONSTRUCTORS
        Vector_paraules();
        //Pre:
        //Post:
        //CONSULTORS
        int consultar_paraules_totals()const;
        //Pre:
        //Post:
        void mostrar_paraula_per_llindar()const;
        //Pre:
        //Post:
        //MODIFICADORS
        void implementar_paraula_dins_registre(const Paraula&p);
        //Pre:
        //Post:
        //METODES PUBLICS

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int NO_TROBAT=-1;
        static const int MAX_ELEMENTS=25000;
        //ATRIBUTS
        Paraula vector_p[MAX_ELEMENTS];
        Vector_abecedari abecedari;

        int a_n_elements;
        //METODES PRIVATS
        int buscar_preexistencia_paraula_al_registre(int inici,int final,const Paraula&p);
        //Pre:
        //Post:
        void inserir_ordenat(const Paraula&p);
        //Pre:
        //Post:
        void incrementar_aparicions_paraules(int pos);
        //Pre:
        //post:
        void intercanviar(Paraula&p1,Paraula&p2);
        //Pre:
        //Post:
        //METODES DE CLASSE
};

#endif // VECTOR_PARAULES_H
