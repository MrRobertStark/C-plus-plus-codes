#ifndef VECTOR_PARAULES_H
#define VECTOR_PARAULES_H

#include "Paraula.h"

class Vector_Paraules
{
    public:
        //CONSTRUCTORS
        Vector_Paraules();
        //Pre:
        //Post:
        //CONSULTORS
        int consultar_n_paraules_diferents()const;
        //Pre:
        //Post:
        void consultar_paraules_amb_minim_aparicions(int llindar)const;
        //Pre:
        //Post:
        //Modificadors
        void analitzar_existencia_paraula(const Paraula&p);
        //Pre:
        //Post:

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int NO_TROBAT=-1;
        static const int MAX_ELEMENTS=100;
        //ATRIBUTS
        Paraula vector_paraules[MAX_ELEMENTS];
        int an_paraules_diferents;
        //METODES DE INSTANCIA
        int buscar_pos_preexistencia_paraula(const Paraula&p)const;
        //Pre:
        //Post:
        void inserir_ordenat(const Paraula&p);
        //Pre:
        //post:
        void incrementar_n_aparicions_paraula(int pos);
        //Pre:
        //Post:
        //METODES DE CLASSE
        static void intercanviar(Paraula&p1,Paraula&p2);
        //Pre:
        //Post:
};

#endif // VECTOR_PARAULES_H
