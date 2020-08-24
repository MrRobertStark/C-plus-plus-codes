#ifndef VECTOR_ABECEDARI_H
#define VECTOR_ABECEDARI_H


class Vector_abecedari
{
    public:
        //CONSTRUCTORS
        Vector_abecedari();
        //Pre:
        //Post:
        //CONSULTORS
        int recompte_n_elements_per_lletra(char lletra)const;
        //Pre:
        //Post:
        int consulta_n_posicions_lletra(char lletra)const;
        //Pre:
        //Post:
        //MODIFICADORS
        void increment_quantificador(char lletra);
        //Pre:
        //Post:
        //METODES PUBLICS

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int MAX_ABECEDARI=25;
        //ATRIBUTS
        int Taula_Enter[MAX_ABECEDARI];
        //METODES PRIVATS
        //METODES DE CLASSE
        static int transformar_lletra_a_num(char lletra);
        //Pre:
        //Post:
};

#endif // VECTOR_ABECEDARI_H
