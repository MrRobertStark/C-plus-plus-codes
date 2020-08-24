#ifndef CLASSIFICACIO_H
#define CLASSIFICACIO_H

#include "Paraula.h"
#include <iostream>
#include <fstream>

using namespace std;

class Classificacio
{
    public:
        Classificacio();
        //CONSULTORS
        void mostrar_paraules_amb_minim_aparicions()const;
        //Pre:
        //Post:
        int buscar_preexistencia_paraula(const Paraula&p)const;
        //Pre:
        //Post:
        int consultar_n_paraules_diferents()const;
        //Pre:
        //Post:
        //MODIFICADORS
        void inserir_ordenat(const Paraula&p);
        //Pre:
        //Post:
        void incrementar_aparicions(int pos);
        //Pre:
        //Post:
        //MÈTODES D'INSTÀNCIES

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int MAX_ELEMENTS=25000;
        static const int NO_TROBAT=-1;
        //ATRIBUTS
        Paraula a_llistat_Paraules[MAX_ELEMENTS];
        int a_n_elements;
        //METODES D'INSTÀNCIES
        //MÈTODES DE CLASSE
        void intercanviar(Paraula&p1,Paraula&p2);
        //Pre:
        //Post:
};

#endif // CLASSIFICACIO_H
