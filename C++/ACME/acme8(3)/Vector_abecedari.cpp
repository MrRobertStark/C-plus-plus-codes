#include "Vector_abecedari.h"

Vector_abecedari::Vector_abecedari()
{
    for(int i=0;i<MAX_ABECEDARI;i++)Taula_Enter[i]=0;
}
int Vector_abecedari::recompte_n_elements_per_lletra(char lletra)const
//Pre:
//Post:
{
    int n=transformar_lletra_a_num(lletra);
    int comptador=0;
    for(int i=0;i<n;i++)comptador+=Taula_Enter[i];
    return comptador;
}
int Vector_abecedari::transformar_lletra_a_num(char lletra)
//Pre:
//Post:
{
    return (lletra-'a');
}
int Vector_abecedari::consulta_n_posicions_lletra(char lletra)const
//Pre:
//Post:
{
    return(Taula_Enter[transformar_lletra_a_num(lletra)]);
}
void Vector_abecedari::increment_quantificador(char lletra)
//Pre:
//Post:
{
    Taula_Enter[transformar_lletra_a_num(lletra)]++;
}
