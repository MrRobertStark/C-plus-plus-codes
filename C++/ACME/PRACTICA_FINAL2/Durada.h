#ifndef DURADA_H
#define DURADA_H

#include<fstream>
#include <iostream>

using namespace std;

class Durada
{
    public:
        //CONSTRUCTORS
        Durada();
        //Pre:cert//post:S'inicialitza l'atribut pel valor per defecte
        Durada(int segons,int minuts=0,int hores=0,int dies=0);
        //pre:el temps han de ser nombres naturals//post:s'inicialitza l'atribut pels valors entrats

        //CONSULTORS
        int solicitar_duracio()const;
        //pre:cert//post:es retorna la duracio en segons

        void mostrar_durada()const;
        //Pre:cert//post:es mostra de manera convencional la durada

        //MODIFICADORS
        void backup(ofstream&fitxer)const;
        //Pre:fitxer obert//post:es desa la durada de manera convencional al fitxer entrat

        //OPERADORS
        Durada operator+(const Durada&d)const;
        //Pre:A i B//post:A+B
        bool operator<(const Durada&d)const;
        //Pre:A=a B=b//Post:A<B
        bool operator>(const Durada&d)const;
        //Pre:A=a B=b//Post:A>B
        bool operator==(const Durada&d)const;
        //Pre:A=a B=b//Post:A==B
        bool operator!=(const Durada&d)const;
        //Pre:A=a B=b//Post:A!=B

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int MAX_HORES=24;
        static const int MAX_MINUTS=60;
        static const int MAX_SEGONS=60;

        //ATRIBUTS
        int a_duracio;

        //METODES DE CLASSE
        static void canvi_convencional(int&segons,int&minuts,int&hores,int&dies);
        //Pre:segons>=0//post:es retorna el temps entrat a mode convencional
};

#endif // DURADA_H
