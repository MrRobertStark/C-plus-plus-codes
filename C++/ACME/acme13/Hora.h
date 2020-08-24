#ifndef HORA_H
#define HORA_H

#include <iostream>
using namespace std;

class Hora
{
    public:
        Hora();
        Hora(int hora,int minut);
        void mostrar_hora()const;
        void mostrar_marge_temps(const Hora&h)const;

        bool operator==(const Hora&e)const;
        bool operator!=(const Hora&e)const;
        bool operator<(const Hora&e)const;
        bool operator>(const Hora&e)const;

    protected:

    private:
        int a_hora;
        int a_minut;
};

#endif // HORA_H
