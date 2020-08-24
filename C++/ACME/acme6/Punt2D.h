#include <iostream>

#ifndef PUNT2D_H
#define PUNT2D_H
#include <cmath>

using namespace std;

class Punt2D
{
    public:
        //CONSTRUCTORS
        Punt2D();
        //Pre: cert
        //Post: Es construeix un punt a l'origen
        Punt2D(double x,double y);
        //Pre:cert
        //Post:Es construeix un punt segons les coordenades entrades
        //CONSULTORS
        double dist(const Punt2D& p);
        //Pre: cert
        //Post: Es retorna la distància entre dos punts
        void mostrar()const;
        //Pre: cert
        //Post: es mostren les dades de l'objecte punt
        //MODIFICADORS
        void llegir();
        //Pre: cert
        //Post: es llegeixen les dades per teclat i s'insereixen a l'objecte punt
        //Metodes publics
        void desplacar(double x,double y);
        //Pre: cert
        //Post: es desplaça el punt principal segons les coordenades entrades per teclat

    protected:

    private:
        //ATRIBUTS
        double a_x;
        double a_y;
        //ACCIONS I FUNCIONS PRIVATS
        Punt2D resta_punt(const Punt2D&p);
        //Pre: cert
        //Post: Es retorna el resultat de la resta entre dos punts
};

#endif // PUNT2D_H
