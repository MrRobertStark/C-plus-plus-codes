#ifndef DURADA_H
#define DURADA_H


class Durada
{
    public:
        //CONSTRUCTOR
        Durada();
        //pre:cert//post:s'inicialitza la variable amb valors per defecte
        Durada(int segons,int minuts,int hores,int dies);
        //pre:segons>=0 natural>=0 hores>=0 dies>=0

        //CONSULTORS
        void mostrar_durada()const;
        //pre:cert//post:es mostra l'objecte en format convencional
        int solicitar_durada()const;
        //pre:cert//post:es retorna la durada en format segons

        //MODIFICADORS
        void backup(ofstream&fitxer)const;
        //pre:cert//post:es desa el fitxer la durada en format convencional

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int MAX_HORES=24;
        static const int MAX_MINUTS=60;
        static const int MAX_SEGONS=60;

        //ATRIBUTS
        int a_duracio;

        //METODES DE CLASSE
        static void conversio_convencional(int&segons,int&minuts,int&hores,int&dies);
        //pre:segons>=0//post:es converteix l'objecte en format convencional
};

#endif // DURADA_H
