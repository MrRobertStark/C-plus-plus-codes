#ifndef CANCO_H
#define CANCO_H

#include<iostream>
#include<fstream>
#include <string>
#include "Durada.h"
#include <limits>

using namespace std;

class Canco
{
    public:
        //CONSTRUCTORS
        Canco();
        //pre:cert//post:s'inicialitza l'objecte pel valor per defecte
        Canco(const Durada&d,int uid=0,int any=0,int repro=0,string titol="",string artista="",string genere="",string anim="",string ytb="");
        //pre: int>=0//post:S'inicialitza l'objecte pels valors entrats per teclat

        //CONSULTORS
        int consultar_duracio()const;
        //pre:cert//post:es retorna la duracio de la canco
        void mostrar_canco()const;
        //pre:cert//post:es mostren la canco
        bool es_menor(const Canco&c,string criteri)const;
        //pre:cert//post:es retorna en funcio del criteri entrat

        //MODIFICADORS
        void backup(ofstream&fitxer)const;
        //pre:fitxer obert//post:es desa la canco al fitxer
        void lectura_fitxer(ifstream&fitxer);
        //pre:fixer obert//post:es llegeix una canco del fitxer

        //OPERADORS
        bool operator<(const Canco&c)const;
        //pre:A=A B=B//posta. A<B
        bool operator>(const Canco&c)const;
        //pre:A=A B=B//post:A>B
        bool operator==(const Canco&c)const;
        //pre: A=A B=B//post=A==B
        bool operator!=(const Canco&c)const;
        //pre:A=A B=B//post:A!=B


    protected:

    private:
        //ATRIBUTS
        int a_uid;
        int a_any;
        int a_reproduccions;
        Durada a_duracio;
        string a_titol;
        string a_artista;
        string a_genere;
        string a_anim;
        string a_codi;
};

#endif // CANCO_H
