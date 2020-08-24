#ifndef FRACCIONS_H
#define FRACCIONS_H


class Fraccions
{
    public:
        //CONSTRUCTORS
        Fraccions();
        Fraccions(int num,int denum);
        //CONSULTORS
        void mostrar()const;
        //MODIFICADORS
        void llegir();
        void sumar(const Fraccions&p,const Fraccions&p1);
        void restar(const Fraccions&p,const Fraccions&p1);
        void multiplicar(const Fraccions&p,const Fraccions&p1);
        void dividir(const Fraccions&p,const Fraccions&p1);
        void simplificar();
        //FUNCIONS
        //ACCIONS

    protected:

    private:
        //ATRIBUTS
        int a_num;
        int a_denum;
        //FUNCIONS
        //ACCIONS
        static int maxim_comu_divisor(int a,int b);
        static int minim_comu_multiple(int a,int b);
};

#endif // FRACCIONS_H
