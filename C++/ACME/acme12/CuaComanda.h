#ifndef CUACOMANDA_H
#define CUACOMANDA_H

#include "Comanda.h"

class CuaComanda
{
    public:
        //CONSTRUCTORS
        CuaComanda();
        //Pre:cert//Post:s'inicialitzn els valors de l'objecte pels valors per defecte
        //CONSULTORS
        void mostrar_comandes()const;
        //pre:cert//Post:es mostren totes les comandes de la cua per l'ordre que han entrat
        void resum_comandes_servides(int c_servides)const;
        //Pre:c_servides>=0//Post:es mostren n_comandes servides i la mitjana de duració
        //MODIFICADORS
        void inserir_comanda(int& c_pendents);
        //Pre:cert//Post:s'insereix una nova comanda i s'enllaça al reste de la cua
        void servir_comanda(int&c_servides,int&c_pendents);
        //Pre:c_pendents>=0//Post:es treu de la cua la primera comanda i s'actualizen els valors de les comandes pendents i servides

    protected:

    private:
        struct Node{
            Comanda a_comanda;
            Node* anterior;
            Node* posterior;
        };
        //CONSTANTS DE CLASSE
        //ATRIBUTS
        Node* a_primer;
        Node* a_ultim;
        int a_duracio_total;
        //METODES PRIVATS
        void treure_comanda(int pendents);
        //Pre://Post:s'el·limina el primer element entrat de la cua
        bool buida()const;
        //Pre://Post:
        //METODES DE CLASSE
};

#endif // CUACOMANDA_H
