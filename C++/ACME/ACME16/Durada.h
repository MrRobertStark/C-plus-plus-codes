#ifndef DURADA_H
#define DURADA_H

#include <iostream>
#include<fstream>
#include<string>

using namespace std;

class Durada
{
    public:
        //CONSTRUCTORS
        Durada();
        //pre:cert//post:s'inicialitza l'objecte pels valors per defecte
        Durada(int segons,int minuts=0,int hores=0,int dies=0);
        //pre:segons>=0 minuts>=0 hores>=0 dies>=0//post:s'inicialitzen l'objecte pels valors entrats

        //CONSULTORS
        void mostrar_durada()const;
        //pre:cert//post:es mostra la durada pel format convencional
        int solicitar_durada()const;
        //pre:cert//post:es retorna la durada en format segons

        //MODIFICADORS
        void backup(ofstream&fitxer)const;
        //pre:fitxer obert//post:es desa la durada en format convencional al fitxer

    protected:

    private:
        //CONSTANS DE CLASSE
        static const int MAX_HORES=24;
        static const int MAX_MINUTS=60;
        static const int MAX_SEGONS=60;

        //ATRIBUTS
        int a_duracio;

        //METODES DE CLASSE
        static void canvi_convencional(int&segons,int&minuts,int&hores,int&dies);
        //pre:segons>=0//post:es tranforma la duració en format convencional
};

#endif // DURADA_H
