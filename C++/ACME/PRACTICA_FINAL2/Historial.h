#ifndef HISTORIAL_H
#define HISTORIAL_H

#include "Canco.h"

class Historial
{
    public:
        //CONSTRUCTORS
        Historial();
        //pre:cert//post:s'inicialitzarà l'objecte actual pels valors predeterminats
        Historial(const Historial&h);
        //pre:cert//post:s'inicialitzarà l'objecte actual per l'historial entrat
        Historial&operator=(const Historial&h);
        //pre:cert//post:es copia "h" a l'objecte actual

        //DESTRUCTORS
        ~Historial();
        //pre:cert//post:s'elimina tota inforamció emmagatzemat a la pila

        //CONSULTORS
        void mostrar_historial()const;
        //pre:cert//post:historial mostrada
        bool buida()const;
        //pre:cert//post:llista buida

        //MODIFICADORS
        void eliminar_canco(const Canco&c);
        //pre:cert//post:canco eliminada de la llista
        void actualitzar_info_canco(const Canco&c);
        //pre:cert//post:la n_reproduccions de la canco c de l'historial incrementat a 1
        void backup(ofstream&fitxer)const;
        //pre:fixer obert//post:es desa l'historial al fitxer
        void empilar(const Canco&c,string criteri="cim");
        //pre:criteri valid//post:canco empilada a la pila
        void desempila();
        //pre:cert//post:es desempila l'última canco afegida
        void alliberar();
        //pre:cert//post:s'allibera l'historial

    protected:

    private:
        struct Node{
            Canco c;
            Node*seguent;
        };
        //ATRIBUTS
        Node* a_cim;
        Node* a_base;
        int a_n_elements;

        //METODES PRIVATS
        void copiar(const Historial&h);
        //pre:cert//post:es copia "h" a l'objecte actual
};

#endif // HISTORIAL_H
