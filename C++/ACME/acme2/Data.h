#ifndef DATA_H
#define DATA_H
#include<string>
using namespace std;

class Data
{
    public:
        //CONSTRUCTORS
        Data();
        //Pre:
        //Post:
        Data(int d,int m,int a);
        //Pre:
        //Post:
        //CONSULTORS
        void mostrar()const;
        //pre
        //post
        bool es_menor(const Data& d)const;
        //pre
        //post
        //MODIFICADORS
        void llegir();
        //pre:
        //post:
        bool es_aniversari(Data data_actual);
        //pre
        //post
        int calcul_edat(const Data&data_actual);
        //pre
        //post
        bool anys_complerts(const Data&data_actual);
        //pre
        //post
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
        //FUNCIONS DE CLASSE
        static bool es_data_valida(int dia,int mes,int any);
        //pre
        //post
};

#endif // DATA_H
