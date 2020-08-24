#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

class Data
{
    public:
        //CONSTRUCTORS
        Data();
        //Pre:cert
        //Post: s'inicialitzen les variables amb els valors per defecte
        //CONSULTORS
        void mostrar_data()const;
        //Pre:cert
        //Post:es mostra la data desada a l'objecte actual
        //MODIFICADORS
        void llegir_data();
        //Pre:cert
        //Post:es desa la primera data correcte llegida

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int MAX_MESOS=12;
        static const int DIES_MES[];
        //ATRIBUTS
        int a_dia;
        int a_mes;
        int a_any;
        //METODES PRIVATS
        //METODES DE CLASSE
        static bool es_data_valida(int dia,int mes,int any);
        //Pre:cert
        //Post:es verifica que la data introduida és correcte
        static bool es_numero(char nombre);
        //Pre:cert
        //Post:retorna cert si nombre representa un dígit entre 0 i 9 inclosos.
        static int conversio_a_num(char c);
        //Pre:c ha de ser un char
        //Post: es retorna el nombre que representa c
};

#endif // DATA_H
