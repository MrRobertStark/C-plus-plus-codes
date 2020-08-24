#ifndef LLISTA_REPRODUCCIONS_H
#define LLISTA_REPRODUCCIONS_H

#include <iostream>
#include "Canco.h"

using namespace std;

class Llista_Reproduccions
{
    public:
        //CONSTRUCTORS
        Llista_Reproduccions();
        //pre:cert//post:s'inicialitza l'objecte als valors per defecte
        Llista_Reproduccions(const Llista_Reproduccions&llista);
        //pre:cert//post:s'inicialitza l'objecte per la llista entrada
        Llista_Reproduccions&operator=(const Llista_Reproduccions&llista);
        //pre:cert//post:es copien les dades de la llista a l'objecte actual

        //DESTRUCTORS
        ~Llista_Reproduccions();
        //pre:cert//post:s'allibera la informació emmagatzemada a l'objecte actual

        //CONSULTORS
        Canco seguent_canco()const;
        //pre:cert//post:es retorna la seguent canco a reproduir

        void mostrar_llista()const;
        //pre:cert//post:llista mostrada
        bool es_buida()const;
        //pre:cert//post:a_primer==NULL

        //MODIFICADORS
        void eliminar_canco(const Canco&c);
        //pre:cert//post:canco eliminada de la llista
        void actualitzar_info_canco(const Canco&c);
        //pre:cert//post:la n_reproduccions de la canco de la llista s'incrementa a 1
        void backup(ofstream&fitxer)const;
        //pre:fixer obert//post:es desa la llista de reproducció al fixer
        void empila(const Canco&c);
        //pre:cert//post:s'empila la canco a la llista al final
        void desencua();
        //pre:cert//post:s'elimina el primer element
        void alliberar();
        //pre:cert//post:cua buida

    protected:

    private:
        struct Node{
            Canco c;
            Node*seguent;
        };
        //ATRIBUTS
        Node* a_ultim;
        Node* a_primer;
        int a_n_elements;

        void copiar(const Llista_Reproduccions&llista);
        //pre:A=a B=b//post:A=B
};

#endif // LLISTA_REPRODUCCIONS_H
