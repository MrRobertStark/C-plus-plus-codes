#include "Vent.h"

Vent::Vent()
//Pre: cert
//Post: s'inicialitza la variable velocitat a 0
{
    a_velocitat=0;
}
int Vent::consultar_velocitat()const
//Pre: la velocitat del vent ha de ser un nombre enter positiu
//Post: es retorna la velocitat registrada del vent
{
    return a_velocitat;
}
bool Vent::operator<(const Vent&v)const
//Pre: les dades dels vents han de ser correctes
//Post: resposta de si la velocitat de l'objecte actual es inferior a l'entrada
{
    return (a_velocitat<v.consultar_velocitat());
}
bool Vent::operator==(const Vent&v)const
//Pre: cert
//Post: resposta de si la velocitat de dos objectes tipus-vent són iguals
{
    return a_velocitat==v.consultar_velocitat();
}
void Vent::llegir_dades_vent()
//Pre:cert
//Post:les dades de l'objecte són plens
{
    cin>>a_velocitat;
    cout<< "Dia i hora:"<<endl;
    a_data_vent.llegir_data(); a_hora_vent.llegir_hora();
}
void Vent::mostrar_dades_vent()const
//Pre:cert
//Post:es mostraran els valors desats a la variable vent
{
    cout<<a_velocitat<<" km/h ";
    a_data_vent.mostrar_data();
    a_hora_vent.mostrar_hora();
}
