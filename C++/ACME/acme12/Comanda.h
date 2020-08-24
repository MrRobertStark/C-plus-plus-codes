#ifndef COMANDA_H
#define COMANDA_H

#include<iostream>
#include "Hora.h"
#include <limits>

using namespace std;

class Comanda
{
    public:
        //CONSTRUCTORS
        Comanda();
        //Pre:cert//Post:s'inicialitzen les variables de la comanda pels seus valors per defecte
        //CONSULTORS
        void mostrar_comanda()const;
        //Pre:les dades de les comandes han de ser correctes//Post:es mostren les dades de les comandes
        int consultar_duracio_comanda()const;

        //MODIFICADORS
        void llegir_comanda();
        //Pre:cert//Post:les dades de la comanda s'emplenen per valors entrades per teclat

    protected:

    private:
        //CONSTANTS DE CLASSE
        //ATRIBUTS
        int a_codi;
        int a_duracio_espera;
        string a_client;
        Hora a_h_inici;
        //METODES PRIVATS
        //METODES DE CLASSE
};

#endif // COMANDA_H
