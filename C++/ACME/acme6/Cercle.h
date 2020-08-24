#include <iostream>
#ifndef CERCLE_H
#define CERCLE_H
#include <cmath>
#include "Punt2D.h"
using namespace std;

class Cercle
{
    public:
        //CONSTRUCTORS
        Cercle();
        //pre: cert
        //post: es construeix un cercle amb els valors per defecte
        //CONSULTORS
        void mostrar_cercle()const;
        //pre: cert
        //post: es mostren les dades de l'objecte cercle
        bool punt_dins_cercle(double x,double y);
        //pre: cert
        //post: es consulta si el punt entrat per teclat es troba dins del cercle creat
        //MODIFICADORS
        void llegir_dades();
        //pre: cert
        //post: s'omplen les dades de l'objecte CERCLE entrats per teclat
        //ACCIONS I FUNCIONS PUBLICS
        void moure_cercle();
        //pre: cert
        //post: es mouen les coordenades de l'origen del cercle
        void escalar_cercle();
        //pre: cert
        //post: es reescala la mida del cercle segons la raó entrat per teclat

    protected:

    private:
        //ATRIBUTS
        Punt2D a_origen;
        double a_radi;
};

#endif // CERCLE_H
