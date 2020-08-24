#ifndef HORA_H
#define HORA_H

#include <iostream>
#include <cmath>

using namespace std;

class Hora

{
    public:
        //CONSTRUCTORS
        Hora();
        //pre: cert
        //post: s'inicialitzen les variables de l'objecte Hora
        Hora(int hora,int minut);
        //pre: cert
        //post: s'inicialitzen les variables de l'objecte Hora
        //CONSULTORS
        Hora consultar_hora()const;
        //Pre:
        //Post:
        int durada(const Hora&h2)const;
        //pre: h_final ha de ser superior a h_inicial éssent nombres positius
        //post: es retorna l'increment de temps entre dues hores.

//MODIFICADORS
        void llegir();
        //pre:cert
        //post: es llegeixen i inicialitzen les dades de l'objecte Hora en format AAAAMMDD
        //METODES D'INSTANCIES
        //OPERADORS
        bool operator ==(const Hora&h)const;
        //pre: els components de les hores han de ser n>=0 però hora<24 i minut<60
        //post: (hora_objecte_actual==h)
        bool operator <(const Hora&h)const;
        //pre: els components de les hores han de ser n>=0 però hora<24 i minut<60
        //post: (hora_objecte_actual<h)
        bool operator >(const Hora&h)const;
        //pre: els components de les hores han de ser n>=0 però hora<24 i minut<60
        //post: (hora_objecte_actual>h)


    protected:

    private:
        //ATRIBUTS
        int a_hora;
        int a_minut;
        //CONSTANTS
        static const int MAX_MINUTS=60;
        static const int MAX_HORES=24;
        //METODES DE CLASSE
        static bool es_hora_valida(int hora,int minut);
        //pre: cert
        //post: es retorna si l'hora proposada és correcte físicament o no.

};

#endif // HORA_H
