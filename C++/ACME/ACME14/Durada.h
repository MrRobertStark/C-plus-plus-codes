#ifndef DURADA_H
#define DURADA_H

#include<iostream>
using namespace std;

class Durada
{
    public:
        Durada();
        Durada(int segons,int minuts=0,int hores=0,int dies=0);

        int consultar_duracio()const;
        //pre:a_duracio>0//post:es retorna a_duracio
        void mostrar_duracio()const;
        //pre:a_duracio>0//post:es mostra de manera convencional  la duracio

        bool operator<(const Durada&d)const;
        //pre:cert//post:A<B
        bool operator>(const Durada&d)const;
        //pre:cert//post:A>B
        bool operator==(const Durada&d)const;
        //pre:cert//post:A==B
        bool operator!=(const Durada&d)const;
        //pre:cert//post:A!=B
        bool operator>=(const Durada&d)const;
        //pre:cert//post:A>=B
        bool operator<=(const Durada&d)const;
        //pre:cert//post:A<=B

        void llegir_duracio();
        //pre:cert//post:es llegeix una duracio
        Durada operator+(const Durada&d)const;
        //pre:A=A B=B C=C//post: C=A+B
        Durada operator-(const Durada&d)const;
        //pre:A=A B=B C=C//post:C=A-B

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int MAX_HORES=24;
        static const int MAX_MINUTS=60;
        static const int MAX_SEGONS=60;
        //ATRIBUTS
        int a_duracio;
        //METODES PRIVATS
        void conversio_convencional(int&segons,int&minuts,int&hores,int&dies)const;
        //Pre:cert//post:s'actualizen els valors per tal de representar a_duracio de manera convencional
        //METODES DE CLASSE

};

#endif // DURADA_H
