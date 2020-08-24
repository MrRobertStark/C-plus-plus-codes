#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Punt2D.h"

class Rectangle
{
    public:
        //CONSTRUCTORS
        Rectangle();
        //CONSULTORS
        void mostrar()const;
        double calcul_perimtre()const;
        //MODIFICADORS
        void llegir();
        void producte_amb_escalar(char format);
        void desplasament();
        Rectangle rectangle_mig(const Rectangle&r2);
        //CONSTANTS
        //ACCIONS
        //FUNCIONS

    protected:

    private:
        //ATRIBUTS
        Punt2D a_origen;
        double a_base;
        double a_altura;
        //CONSTANTS
        //ACCIONS
        //FUNCIONS
};

#endif // RECTANGLE_H
