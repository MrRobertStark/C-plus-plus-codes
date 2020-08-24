#ifndef PUNT2D_H
#define PUNT2D_H


class Punt2D
{
    public:
        //CONSTRUCTORS
        Punt2D();
        Punt2D(double x,double y);
        //CONSULTORS
        void mostrar()const;
        //MODIFICADORS
        void llegir();
        //FUNCIONS
        Punt2D calcul_punt_mig(const Punt2D&p);
        Punt2D suma(double a,double b);
        //ACCIONS
        void actualitzar_origen(Punt2D& punt_mig,double base,double altura);
        void desplasar(const Punt2D&p);
        Punt2D calcul_centre(const Punt2D&p);
        //CONSTANTS

    protected:

    private:
        //ATRIBUTS
        double a_x;
        double a_y;
        //FUNCIONS
        //ACCIONS
        //CONSTANTS
};

#endif // PUNT2D_H
