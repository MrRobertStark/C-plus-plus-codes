#ifndef AGENDA_H
#define AGENDA_H

#include "Esdeveniment.h"

class Agenda
{
    public:
        //CONSTRUCTORS
        Agenda();
        //pre: cert
        //Post: s'inicialitzen els valors de l'objecte Agenda
        //CONSULTORS
        void buscar_data_i_estudiar_durada();
        //pre: cert
        //Post: es busca una data entrat per teclat  i retorna la duració de les activitats de la mateixa data
        //MODIFICADORS
        void afegir_esdeveniment();
        //pre: cert
        //Post: es llegeix un Esdeveniment i es desa a la taula de l'agenda segons el criteri data-hora-descripció
        //METODES PUBLICS

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int MAX_ELEMENTS=100;
        static const int NO_TROBAT=-1;
        //ATRIBUTS
        int a_n_elements;
        Esdeveniment a_taula[MAX_ELEMENTS];
        //METODES PRIVATS
        int buscar_pos_existencia(const Esdeveniment&e);
        //Pre:
        //Post:
        void inserir_ordenat(const Esdeveniment&e);
        //Pre:
        //Post:
        void intercanviar_elements(Esdeveniment&e1,Esdeveniment&e2);
        //Pre:
        //Post:
        int comptador_duracio_esdeveniments(int pos);
        //Pre:
        //Post:
        int buscar_pos_data(const Data&d);
        //Pre:
        //Post:
};
#endif // AGENDA_H
