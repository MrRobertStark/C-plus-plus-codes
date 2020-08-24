#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data
{
    public:
        //CONSTRCUTORS
        Data();
        //Pre:cert
        //Post:Es crea i inicialitza un objecte tipus Data
        Data(int dia,int mes,int any);
        //Pre:cert
        //Post:Es crea i inicialitza un objecte tipus Data
        //CONSULTORS
        void mostrar_data()const;
        //Pre:les dates han de ser correctes segons el dia-mes-any corresponents
        //Post:Es mostra la data desada a l'objecte principal.
        Data consultar_data()const;
        //Pre:
        //Post:
        //MODIFICADORS
        void llegir_data();
        //Pre:cert
        //Post:Es llegeix i inicialitza una Data
        //METODES D'INSTANCIA
        //OPERADORS
        bool operator==(const Data&d)const;
        //Pre:les dates han de correctes segons el dia-mes-any adientes
        //Post: retorna si Data_objecte_principal==data entrat
        bool operator<(const Data&d)const;
        //Pre:les dates han de correctes segons el dia-mes-any adientes
        //Post: retorna si Data_objecte_principal<data entrat
        bool operator!=(const Data&d)const;
        //Pre:les dates han de correctes segons el dia-mes-any adientes
        //Post: retorna si Data_objecte_principal!=data entrat

    protected:

    private:
        //ATRIBUTS
        int a_dia;
        int a_mes;
        int a_any;
        //CONSTANTS DE CLASSE
        static const int MAX_MESOS=12;
        static const int DIES_MES[];
        //METODES DE CLASSE
        static bool es_data_valida(int dia,int mes,int any);
        //pre: dia>0 mes>0 any>1666 any<3999
        //post: es comprova si la data entrada és vàlida segons uns criteris
};

#endif // DATA_H
