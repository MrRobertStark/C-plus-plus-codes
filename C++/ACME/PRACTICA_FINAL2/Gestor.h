#ifndef GESTOR_H
#define GESTOR_H

#include "Llista_Reproduccions.h"
#include "Historial.h"
#include "TaulaCancons.h"
#include <iostream>
#include <fstream>
#include <limits>


using namespace std;

class Gestor
{
    public:
        //CONSTRUCTORS
        Gestor();
        //pre:cert//post:s'inicialitza l'objecte actual al valor per defecte

        //CONSULTORS
        void mostrar_cataleg(string criteri)const;
        //pre:criteri existent//post:cataleg mostrat per criteri

        //MODIFICADORS
        void autoreproduccio(int durada);
        //pre:durada>=0//post:llista de reproducció reproduida sencera segons la durada entrada
        void eliminar_canco(string criteri);
        //pre:cert//post:una canco treta
        void afegir_canco_al_cataleg();
        //pre:cert//post:s'insereix una canco al cataleg
        void reproduccio_per_durada(const Durada&d);
        //pre:cert//post:nova llista de reproducció i historial buida
        void select(string criteri);
        //pre:criteri existent//post:es selecciona una canco a partir del criteri entrat
        void canvi_mode_adrecament();
        //pre:cert//post:mode text a youtube o viceversa
        void reproduir();
        //pre:cert//post:última reproducció reproduïda
        void buida(string opcio);
        //pre:opcio valida//post:historial o reproducció buides

        void backup(ofstream&fitxer)const;
        //pre:fitxer obert//post:cataleg desat al fitxer
        void lectura_fitxer(ifstream&fitxer);
        //pre:fitxer obert//post:cancons llegides del fitxer



    protected:

    private:

        //ATRIBUTS
        Llista_Reproduccions a_llista;
        Historial a_historial;
        TaulaCancons a_cataleg;
        bool a_mode;

        string a_comentari_final;

        //METODES PRIVATS
        void actualitzar_informacio(const Canco&c);
        //pre:cert//post:s'actualiza la informació de la canco a totes les llistes/taula
        bool preexistencia(const Canco&c)const;
        //pre:cert//post:preexistencia de c confirmada
        void obrir_enllac(string link)const;
        //pre:cert//post:link obert a youtube

        Canco seleccio_final(const TaulaCancons&aux)const;
        //pre:cert//post:una canco seleccionada de t
        void emplenar_taula_per_criteri(TaulaCancons&t,string criteri,string format="a")const;
        //pre:criteri vàlid//post:cancons inserides a t del catàleg per el criteri entrat
};

#endif // GESTOR_H
