#ifndef PARAULA_H
#define PARAULA_H

#include <iostream>
#include <fstream>

using namespace std;

class Paraula
{
    public:
        //CONSTRUCTORS
        Paraula();
        //Pre:
        //Post:
        //CONSULTORS
        void mostrar_paraula()const;
        //Pre:
        //Post:
        int consultar_n_aparicions()const;
        //Pre:
        //Post:
        char consultar_inicial()const;
        //Pre:
        //Post:
        //MODIFICADORS
        void llegir_paraula(ifstream&fitxer);
        //Pre:
        //Post:
        void incrementar_n_aparicions();
        //Pre:
        //Post:
        //MÈTODES D'INSTÀNCIES
        bool operator==(const Paraula&p)const;
        //Pre:
        //Post:
        bool operator<(const Paraula&p)const;
        //Pre:
        //Post:
        bool operator!=(const Paraula&p)const;
        //Pre:
        //post:

    protected:

    private:
        //CONSTANTS DE CLASSE
        //ATRIBUTS
        string a_paraula;
        int a_n_aparicions;
        char a_inicial;
        //METODES D'INSTÀNCIES
        //MÈTODES DE CLASSE
        static char passar_separadors(ifstream&fitxer);
        //Pre:
        //Post:
        static bool es_lletra(char c);
        //Pre:
        //Post:
        static bool es_majuscula(char c);
        //Pre:
        //Post:
        static void transformar_a_minuscula(char&c);
        //Pre:
        //Post:
};

#endif // PARAULA_H
