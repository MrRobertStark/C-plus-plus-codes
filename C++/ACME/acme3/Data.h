#ifndef DATA_H
#define DATA_H
#include<string>
using namespace std;

class Data
{
    public:
        //CONSTRUCTORS
        Data();
        //pre
        //post
        //CONSULTORS
        void mostrar(int format)const;
        //pre
        //post
        bool es_igual(const Data&d)const;
        //pre
        //post
        //MODIFICADORS
        void llegir(int format);
        //FUNCIONS PUBLIQUES
        bool es_menor(const Data&d);
        //pre
        //post
        //ACCIONS PUBLIQUES

    protected:

    private:
        //ATRIBUTS
        int a_dia;
        int a_mes;
        int a_any;
        //CONSTANTS DE CLASSE
        static const int MESOS_ANY=12;
        static const int DIES_MES[];
        static const string NOM_MES[];
        //FUNCIONS PRIVADES
        static bool es_data_valida(int dia,int mes,int any);
        //pre
        //post
        static bool esDeTraspas(int any);
        //pre
        //post
        //ACCIONS PRIVADES
};

#endif // DATA_H
