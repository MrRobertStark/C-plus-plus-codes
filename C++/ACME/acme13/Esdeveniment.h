#ifndef ESDEVENIMENT_H
#define ESDEVENIMENT_H

#include<iostream>
#include "Hora.h"
#include "Data.h"

using namespace std;

class Esdeveniment
{
    public:
        Esdeveniment();
        Esdeveniment(const Hora&inici,const Hora&fin,const Data&data,string descripcio,int codi);
        void mostrar()const;
        int consultar_codi()const;

        bool operator==(const Esdeveniment&e)const;
        bool operator!=(const Esdeveniment&e)const;
        bool operator<(const Esdeveniment&e)const;
        bool operator>(const Esdeveniment&e)const;
        bool operator<=(const Esdeveniment&e)const;

    protected:

    private:
        Hora a_hora_inici;
        Hora a_hora_final;
        Data a_data;
        string a_descripcio;
        int a_codi;
};

#endif // ESDEVENIMENT_H
