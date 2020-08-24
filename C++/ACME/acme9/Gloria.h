#ifndef GLORIA_H
#define GLORIA_H

#include <iostream>
#include "Informe.h"
#include <string>

using namespace std;

class Gloria
{
    public:
        //CONSTRUCTORS
        Gloria();
        //Pre: cert
        //Post: s'inicialitza els valors per defecte
        //CONSULTORS
        void mostrar_tots_els_informes()const;
        //Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS
        //Post: es mostren tots els informes de la taula
        void mostrar_poblacio_amb_mes_incidencies()const;
        //Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
        //Post: es mostra la població amb més incidències
        void mostrar_informes_per_llindar()const;
        //Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
        //Post: es mostren tots els informes que superen un llindar de caràcter entrat per teclat
        //Modificadors
        void actualitzar();
        //Pre: cert
        //Post: s'actualitzen i implementen els informes existents/nous al registre.
        void actualitzar_max_incidencies(int n);
        //Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
        //Post: s'actualitza el nombre maxim d'incidències.

    protected:

    private:
        //CONSTANTS DE CLASSE
        static const int NO_TROBAT=-1;
        static const int MAX_ELEMENTS=200;
        //ATRIBUTS
        Informe a_registre[MAX_ELEMENTS];
        int a_n_elements;
        int a_maxim_incidencies;
        //METODES PRIVATS
        void ordenar_informes_llindar_pluja(int llindar,Gloria&taula)const;
        //Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
        //Post: una taula d'informes ordenat per llindar litres de pluja decreixent. En cas d'empat per comarca-població
        void ordenar_informes_llindar_neu(int llindar,Gloria&taula)const;
        //Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
        //Post: una taula d'informes ordenat per llindar cm de neu decreixent. En cas d'empat per comarca-població
        void ordenar_informes_llindar_vent(int llindar,Gloria&taula)const;
        //Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
        //Post: una taula d'informes ordenat per llindar velocitat de vent decreixent. En cas d'empat per comarca-població
        void inserir_ordenat(const Informe&i,char criteri='c');
        //Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
        //Post: s'insereix un informe a la taula actual en funció del criteri entrat.
        void intercanviar(Informe&i1,Informe&i2);
        //Pre: A=a B=b
        //Post: A=b B=a
        int buscar_existencia_previa(const Informe&aux)const;
        //Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
        //Post: es retorna la posició de l'informe entrat. Si no existia pos=-1
        void implementar_dades_noves(int pos,const Informe&aux);
        //Pre: a_n_elements>=0 && a_n_elements<=MAX_ELEMENTS i a_n_incidencies>=0 && a_n_incidencies<=MAX
        //Post:s'actualitzen els valors de l'informe existent amb l'entrat
        //METODES DE CLASSE
};

#endif // GLORIA_H
