#ifndef PUNT2D_H
#define PUNT2D_H
using namespace std;

class Punt2D
{
    public:
        //CONSTRUCTORS
        Punt2D();
        //CONSULTORS
        void mostrar()const;
        //MODIFICADORS
        void llegir();
        //FUNCIONS PUBLIQUES
        void sumar(Punt2D p_anterior,double& trajecte);
        //ACCIONS PUBLIQUES

    protected:

    private:
        //ATRIBUTS
        int a_x;
        int a_y;
};

#endif // PUNT2D_H
