#ifndef REGISTRE_H
#define REGISTRE_H

#include "Paraula.h"
#include "Vector_Paraules.h"

class Registre
{
    public:
        //CONSTRUCTORS
        Registre();
        //Pre:
        //Post:
        //CONSULTORS
        void buscar_paraules_amb_minim_aparicions()const;
        //Pre:
        //post:
        int recompte_paraules_diferents()const;
        //Pre:
        //Post:
        //MODIFICADORS
        void afegir_paraula_al_registre(const Paraula&p);
        //pre:
        //Post:

    protected:

    private:
        //CONSTANTS DE CLASSSE
        static const int N_LLETRES_DIFERENTS=25;
        //ATRIBUTS
        int a_n_lletres;
        Vector_Paraules a_taula[N_LLETRES_DIFERENTS];
        //METODES PRIVATS
        //METODES DE CLASSE
        static int conversor_lletra_num(char inicial);
        //Pre:
        //post:
};

#endif // REGISTRE_H
