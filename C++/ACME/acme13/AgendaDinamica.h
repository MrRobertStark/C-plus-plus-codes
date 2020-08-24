#ifndef AGENDADINAMICA_H
#define AGENDADINAMICA_H

#include "Esdeveniment.h"
#include "Data.h"
#include "Hora.h"
#include <iostream>

using namespace std;

class AgendaDinamica
{
    public:
        AgendaDinamica();
        ~AgendaDinamica();
        AgendaDinamica(const AgendaDinamica&o);
        AgendaDinamica&operator=(const AgendaDinamica&o);

        void mostrar_agenda()const;
        void inserir(const Esdeveniment&e);
        void treure();

    protected:

    private:
        struct Node
        {
            Esdeveniment esdv;
            Node*next;
        };
        Node*a_primer;

        void copia(const AgendaDinamica&o);
        void allibera();
        bool buida()const;
};

#endif // AGENDADINAMICA_H
