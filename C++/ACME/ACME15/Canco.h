#ifndef CANCO_H
#define CANCO_H


class Canco
{
    public:
        //CONSTRUCTORS
        Canco();
        //pre:cert//post:s'inicialitza l'objecte pels valors per defecte
        Canco(const Durada&d,int uid,int any,int n_reproduccions,string titol,string artista,string genere,string anim,string codi);
        //pre:cert//post:s'inicialitza l'objecte pels valors entrats

        //CONSULTORS
        void mostrar_canco()const;
        //pre:cert//post:es mostra la canco

        //MODIFICADORS
        void lectura_fitxer(ifstream&fitxer);
        //pre:fitxer obert//post:es llegeix una canco del fitxer
        void backup(ofstream&fitxer)const;
        //pre:fitxer obert//post:es desa la canco al fitxer

        //OPERADORS
        bool operator<(const Canco&c)const;
        //pre:A=a B=b//post:A<B
        bool operator>(const Canco&c)const;
        //pre:A=a B=b//post:A>B
        bool operator==(const Canco&c)const;
        //pre: A=a B=b//post:A==B
        bool operator!=(const Canco&c)const;
        //pre: A=a B=b//post:A!=B

    protected:

    private:
        //ATRIBUTS
        int a_uid;
        int a_any;
        int a_n_reproduccions;
        Durada a_duracio;
        string a_titol;
        string a_artista;
        string a_genere;
        string a_anim;
        string a_codi_ytb;
};

#endif // CANCO_H
