#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data
{
    public:
        Data();
        Data(int dia,int mes,int any);
        void mostrar_data()const;

        bool operator==(const Data&e)const;
        bool operator!=(const Data&e)const;
        bool operator<(const Data&e)const;
        bool operator>(const Data&e)const;

    protected:

    private:
        int a_dia;
        int a_mes;
        int a_any;
};

#endif // DATA_H
