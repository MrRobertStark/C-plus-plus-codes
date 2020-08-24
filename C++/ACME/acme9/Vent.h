#ifndef VENT_H
#define VENT_H

#include "Hora.h"
#include "Data.h"

class Vent
{
    public:
        //CONSTRUCTORSR
        Vent();
        //Pre:cert
        //Post:inicialització de les variables als valors per defecte
        //CONSULTORS
        int consultar_velocitat()const;
        //Pre:cert
        //Post:es retorna la velocitat registrada del vent
        void mostrar_dades_vent()const;
        //Pre:cert
        //Post:es mostren els valors desats a la variable vent
        bool operator<(const Vent&v)const;
        //Pre:les dades del vent han de ser correctes
        //Post: resposta de si la velocitat de l'objecte actual es inferior a l'entrada
        bool operator==(const Vent&v)const;
        //Pre:cert
        //Post: resposta de si la velocitat de dos objectes tipus-vent són iguals
        //MODIFICADORS
        void llegir_dades_vent();
        //Pre:cert
        //Post:les dades de l'objecte són plens

    protected:

    private:
        //CONSTANTS DE CLASSE
        //ATRIBUTS
        int a_velocitat;
        Data a_data_vent;
        Hora a_hora_vent;
        //METODES PRIVATS
        //METODES DE CLASSE
};

#endif // VENT_H
