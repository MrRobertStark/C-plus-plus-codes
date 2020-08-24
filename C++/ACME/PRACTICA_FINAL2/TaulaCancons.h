#ifndef TAULACANCONS_H
#define TAULACANCONS_H

#include <fstream>
#include <iostream>
#include "Canco.h"

using namespace std;

class TaulaCancons
{
    public:
        //CONSTRUCTORS
        TaulaCancons();
        //pre:cert//post:s'inicialitza l'objecte pels valors per defecte
        TaulaCancons(const TaulaCancons&taula);
        //pre:cert//post:s'inicialitza l'objecte per la taula entrat
        TaulaCancons&operator=(const TaulaCancons&taula);
        //pre:cert//post:es copien les dades de l'objecte entrat a l'actual

        //DESTRUCTOR
        ~TaulaCancons();
        //pre:cert//post:s'elimina tota informació emmagatzemada a la taula

        //CONSULTORS
        Canco solicitar_canco(int pos)const;
        //pre:pos>=0 pos<a_n_elements//post_es retorna la canco de la posició indicada
        int solicitar_maxim_uid()const;
        //Pre:cert//post:es retorna la maxima uid existent
        int solicitar_a_n_elements()const;
        //pre:cert//post:es retorna els n_elements de la taula

        void mostrar_cancons(string criteri)const;
        //pre:cert//post:totes les cancons mostrades en funcio de la quantitat de cancons que es vulguin mostrar
        int preexistencia(const Canco&c,string criteri="songs")const;
        //Pre:cert//post:posició de la canco a la taula retornada

        //MODIFICADORS
        void eliminar_canco(int pos);
        //pre:pos>=0 pos<MAX_ELEMENTS
        void backup(ofstream&fitxer)const;
        //pre:fixer_obert//post:es desa la taula al fitxer entrat
        void inserir_per_criteri(const Canco&c,string criteri="uid");
        //pre:cert//post:s'insereix a la taula la canco entrada segons el criterid demanat
        void incrementar_maxim_uid(int k);
        //pre:cert//post:s'incrementa la maxima uid a k+1
        void actualizar_info_canco(int pos,const Canco&c);
        //pre:pos>=0 && pos<MAX_ELEMENTS//post:s'actualitza la informació de la canco de la posició pos

    protected:

    private:
        //ATRIBUTS
        int a_maxim_uid;
        int a_maxim_elements;
        int a_n_elements;
        Canco*a_t;

        //METODES PRIVATS

        void copiar(const TaulaCancons&t);
        //pre:cert//post:es copia el contingut de t a l'objecte actual
        void reservar();
        //pre:cert//post:es reserven a_maxim_elements posicions
        void alliberar();
        //pre:cert//post:s'allibera la informació continguda a l'objecte actual
        void ampliar();
        //pre:cert//post:s'amplia la capacitat d'emmagatzematge de la taula
};

#endif // TAULACANCONS_H
