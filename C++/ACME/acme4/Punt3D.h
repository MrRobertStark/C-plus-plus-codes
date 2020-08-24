#ifndef PUNT3D_H
#define PUNT3D_H
using namespace std;

class Punt3D
{
    public:
        //CONSTRUCTORS
        Punt3D();
        //pre:
        //post:
        //CONSULTORS
        void mostrar(int&comptador)const;
        //pre
        //post
        //MODIFICADORS
        void llegir();
        //FUNCIONS PUBLIQUES
        //ACCIONS PRIVADES
        void sumar();
        //pre
        //post
        void restar();
        //pre
        //post
        void multiplicacio_real();
        //pre
        //post
        void producte_vectorial();
        //pre
        //post

    protected:

    private:
        //ATRIBUTS
        double a_x;
        double a_y;
        double a_z;
        //FUNCIONS PRIVADES
        //ACCIONS PRIVADES
};

#endif // PUNT3D_H
