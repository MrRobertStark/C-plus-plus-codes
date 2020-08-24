#ifndef TAULACANCONS_H
#define TAULACANCONS_H

#include "Durada.h"
#include "Canco.h"
#include <iostream>
#include <string>

using namespace std;

class TaulaCancons
{
    public:
        //CONSTRUCTORS
        TaulaCancons();
        //pre:cert//post:s'inicialitza l'objecte pel valor per defecte
        TaulaCancons(const TaulaCancons&taula);
        //pre:cert//post:s'inicialitza l'objecte pel valor per defecte
        TaulaCancons&operator=(const TaulaCancons&taula);
        //pre:cert//post:s'inicialitza l'objecte per l'objecte entrat

        //DESTRUCTOR
        ~TaulaCancons();
        //pre:cert//post:es destrueix l'element i es posa pel valor per defecte

        //CONSULTORS
        void mostrar_cancons_limit_temps(const Durada&d)const;
        //pre:cert//post:es mostren les cancons segons el limit entrat
        Canco solicitar_canco(int pos)const;
        //pre:cert//post:es retorna la canco indicada
        int solicitar_maxim_uid()const;
        //pre:cert//post:es retorna a_maxim_uid
        int solicitar_n_elements()const;
        //pre:cert//post:es retorna a_n_elements
        void mostrar_taula()const;
        //pre:cert//post:es mostren tots els elements de la taula
        void inserir_per_criteri(const Canco&c,string criteri="songs");
        //pre:cert//post:s'insereix a la TaulaCancons la canco entrada segons el criteri
        bool buscar_preexistencia(const Canco&c)const;
        //pre:a_n_elements>=0//post:es retorna cert si un element ja existeix o no

        //MODIFICADORS
        void backup()const;
        //pre:cert//post:es desa a un fitxer la informació continguda a l'objecte actual
        void actualitzar_maxim_uid(int k);
        //pre:cert//post:a_maxim_uid=k

    protected:

    private:
        //ATRIBUTS
        int a_maxim_uid;
        int a_maxim_elements;
        int a_n_elements;
        Canco *a_t;

        //METODES PRIVATS
        void insercio_general(const Canco&c);
        //pre:cert//post:s'insereix a la taula segons titol-artista
        void insercio_per_durada(const Canco&c);
        //pre:cert//post:canco inserida segons la seva durada. En cas d'empat per titol-artista
        void insercio_per_genere(const Canco&c);
        //pre:cert//post:canco inserida segons el seu genere. En cas d'empat per titol-artista

        void alliberar();
        //pre:cert//post:memoria dinamica alliberada
        void reservar();
        //pre:cert//post:es reserven a_n_maxim posicions de memòria noves
        void copiar(const TaulaCancons&taula);
        //pre:A=A B=B//post: A=B
        void ampliar();
        //pre:cert//post:s'amplia l'espai de memòria de la taula
        //METODES DE CLASSE
        static void intercanviar(Canco&c1,Canco&c2);
        //pre:A=a B=b//post:A=B B=A
};

#endif // TAULACANCONS_H
