#include <iostream>
#ifndef DATA_H
#define DATA_H

using namespace std;

class Data
{
    public:
        //CONSTRUCTORS
        Data();
        //CONSULTORS
        void mostrar()const;
        int mostrar_dia()const;
        int mostrar_mes()const;
        int mostrar_any()const;
        //MODIFICADORS
        void llegir();
        //METODES INSTÀNCIES
        bool es_menor(const Data&d)const;

    protected:

    private:
        //ATRIBUTS
        int a_dia;
        int a_mes;
        int a_any;
        //CONSTANTS
        static const int MESOS_ANY=12;
        static const int DIES_MES[];
        //MÈTODES PRIVATS
        static bool es_data_valida(int dia,int mes,int any);
};

#endif // DATA_H
