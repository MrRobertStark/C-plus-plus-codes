#ifndef CANCO_H
#define CANCO_H

#include "Durada.h"
#include <limits>
#include <fstream>
#include <string>

using namespace std;

class Canco
{
    public:
        //CONSRUCTORS
        Canco();
        //pre:cert//post:s'inicialitza l'objecte pels valors per defecte
        Canco(const Durada&d,int uid=0,int any=0,int repro=0,string titol="",string artista="",string genere="",string anim="",string codi="");
        //Pre:ints>=0//post:s'inicialitza l'objecte per les variables entrades

        //CONSULTORS
        Durada solicitar_durada()const;
        //pre:cert//post:es retorna la duració de la canco
        string solicitar_camp_string(string camp="link")const;
        //pre:camp existent//post:es retorna l'artista/titol/genere/mood o codi de la canco
        int solicitar_uid()const;
        //pre:cert//post:es retorna la uid de la canco

        void mostrar_canco(int format=1)const;
        //pre:cert//post:es mostra la canco
        bool es_menor(const Canco&c,string criteri)const;
        //pre:cert//post:l'objecte actual és comparat per l'entrat segons un criteri entrat

        //MODIFICADORS
        void incrementar_n_reproduccions();
        //pre:cert//post:a_n_reproduccions++
        void backup(ofstream&fitxer)const;
        //Pre:fitxer obert//post:es desa la canco al fitxer entrat
        void lectura_fitxer(ifstream&fitxer);
        //pre:fitxer obert//post:es llegeix una canco del fitxer entrat

        //OPERADORS
        bool operator<(const Canco&c)const;
        //Pre:A i B//post:A<B
        bool operator>(const Canco&c)const;
        //Pre:A i B//Post:A>B
        bool operator==(const Canco&c)const;
        //Pre:A i B//post:A==B
        bool operator!=(const Canco&c)const;
        //Pre:A i B//post:A!=B

    protected:

    private:

        //ATRIBUTS
        Durada a_duracio;
        int    a_uid;
        int    a_any;
        int    a_reproduccions;
        string a_titol;
        string a_artista;
        string a_genere;
        string a_anim;
        string a_link;
};

#endif // CANCO_H
