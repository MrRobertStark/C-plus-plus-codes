#ifndef INFORME_H
#define INFORME_H

#include <limits>
#include <iostream>
#include "Vent.h"
#include <string>

using namespace std;

class Informe
{
    public:
        //CONSTRUCTORS
        Informe();
        //Pre:cert
        //Post:inicialitzacio de les variables amb els valors per defecte
        //CONSULTORS
        string consultar_poblacio()const;
        //Pre:cert
        //Post:es retorna el nom de la població de l'objecte actual
        void mostrar_informe()const;
        //Pre:cert
        //Post:es mostren totes les dades desades a l'objecte actual
        int consultar_n_incidencies()const;
        //Pre:cert
        //Post:es retorna el nombre d'incidencies de l'objecte actual
        int consultar_litres_pluja()const;
        //Pre:cert
        //Post:es retorna els litres desats a l'objecte actual
        int consultar_cm_neu()const;
        //Pre:cert
        //Post:es consulta el valor dels cm de l'objecte actual
        int consultar_velocitat_vent()const;
        //Pre:cert
        //Post:es consulta la velocitat del vent de l'objecte actual
        bool es_menor(const Informe&i,char criteri)const;
        //Pre: cert
        //Post: es retorna si l'objecte entrat és inferior a l'actual segons el criteri entrat
        bool operator<(const Informe&i)const;
        //Pre:cert
        //Post:es retorna si l'objecte actual és inferior a l'entrat segons comarca-població
        bool operator==(const Informe&i)const;
        //Pre:cert
        //Post:es retorna si l'objecte actual és igual a l'entrat segons comarca-població
        bool operator!=(const Informe&i)const;
        //Pre:cert
        //Post:es retorna si l'objecte actual és diferet a l'entrat segons comarca-població
        //MODIFICADORS
        Informe emplenar_informacio();
        //Pre:cert
        //Post:es retorna un informe nou amb les dades emplenades
        void incrementar_litres_pluja(const Informe&i);
        //Pre:els litres de pluja han de ser enters positius
        //Post:es sumen els litres de pluja i es desa a l'objecte actual
        void incrementar_cm_neu(const Informe&i);
        //Pre:els cms dels objectes han de ser enters positius
        //Post: es sumens els cms dels objectes i es desa a l'objecte actual
        void actualitzar_dades_vent(const Informe&i);
        //Pre:les dades vent dels objectes han de ser correctes
        //Post: es desa a l'objecte actual la informació vent més gran en quant a velocitat del vent
        void actualitzar_incidencies(const Informe&i);
        //Pre:cert
        //Post: es registra a l'objecte actual totes les incidències del informe i

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int MAX_INCIDENTS=50;
        //ATRIBUTS
        string a_comarca;
        string a_poblacio;
        int a_litres_pluja;
        int a_cm_neu;
        Vent a_vent;
        string a_incidents[MAX_INCIDENTS];
        int a_n_incidents;
        //METODES PRIVATS
        //METODES DE CLASSE
};

#endif // INFORME_H
