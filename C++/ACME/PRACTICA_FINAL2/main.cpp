#include <iostream>
#include <fstream>
#include "Gestor.h"

using namespace std;

void mostrar_comandes()
//pre:cert//post:es mostren les comandes programmades
{
    cout << "MENU" << endl;
    cout << "a. AFEGIR CANCO (add)" << endl;
    cout << "b. ESPERA (break)" << endl;
    cout << "c. MOSTRAR... (show)" << endl;
    cout << "...   a. LES CANCONS (songs)" << endl;
    cout << "...   b. PER GENERE (genre)" << endl;
    cout << "...   c. PER ESTAT D'ANIM (mood)" << endl;
    cout << "...   d. LES 10 MES ESCOLTADES (topten)" << endl;
    cout << "...   e. PER ANY (year)" << endl;
    cout << "...   f. CUA DE REPRODUCCIO (queue)" << endl;
    cout << "...   g. HISTORIAL (history)" << endl;
    cout << "d. SELECCIONAR... (select)" << endl;
    cout << "...   a. TOTES (all)" << endl;
    cout << "...   b. PER ARTISTA (artist)" << endl;
    cout << "...   c. PER TITOL (title)" << endl;
    cout << "...   d. PER GENERE (genre)" << endl;
    cout << "...   e. PER ESTAT D'ANIM (mood)" << endl;
    cout << "e. ESBORRAR... (empty)" << endl;
    cout << "...   a. CUA DE REPRODUCCIO (queue)" << endl;
    cout << "...   b. HISTORIAL (history)" << endl;
    cout << "f. MODE (youtube)" << endl;
    cout << "g. REPRODUIR (play)" << endl;
    cout << "x. GUARDAR (save)" << endl;
    cout << "y. MENU (help)" << endl;
    cout << "z. SORTIR (quit)" << endl;
}

void inserir_canco(Gestor&g)
//pre:cert//post:canco afegida al cataleg
{
    g.afegir_canco_al_cataleg();
}
void llista_reproduccio_per_durada(Gestor&g)
//pre:cert//post:nova llista de reproducció en funció de una durada entrada i historial nou
{
    int temps; cin>>temps;
    g.reproduccio_per_durada(Durada(0,temps));
}
void mostrar(const Gestor&g)
//pre:cert//post:cataleg mostrat segons un criteri
{
    string criteri; cin>>criteri;
    g.mostrar_cataleg(criteri);
}
void seleccionar_canco_del_cataleg(Gestor&g)
//pre:cert//post:s'insereix una canco a la llista de reproducció
{
    string criteri; cin>>criteri;
    g.select(criteri);
}
void canvi_de_mode(Gestor&g)
//pre:cert//post:mode de reproducció canviat
{
    g.canvi_mode_adrecament();
}
void reproduir_canco(Gestor&g)
//pre:cert//post:pròxima canco de la llista de reproducció reproduïda i afegida a l'historia
{
    g.reproduir();
}
void desar_cataleg(const Gestor&g)
//pre:cert//post:dades del gestor desat al fitxer indicat
{
    string nom_fitxer;
    cout<< "NOM DEL FTIXER A DESAR:"<<endl;
    cin>>nom_fitxer;
    ofstream fitxer(nom_fitxer.c_str());
    g.backup(fitxer);
    cout<< "DADES DESADES"<<endl;
}
void desar_cataleg(const Gestor&g,string nom_fitxer)
//pre:fitxer obert//post:es desa el cataleg al fitxer
{
    string inicials= "out_"; inicials+=nom_fitxer;
    ofstream fitxer(inicials.c_str());
    g.backup(fitxer);
}
void lectura_fitxer(Gestor&g,ifstream&fitxer)
//pre:fitxer obert//post:cancons del fitxer desat al cataleg del gestor
{
    g.lectura_fitxer(fitxer);
}
void esborrar_cues(Gestor&g)
//pre:cert//post: historial o llista de reprdoucció buides
{
    string opcio; cin>>opcio;
    g.buida(opcio);
}
void remoure_canco(Gestor&g)
//pre:cert//post:una canco remoguda de la llista si existia
{
    string criteri; cin>>criteri;
    g.eliminar_canco(criteri);
}
void reproduccio_total(Gestor&g)
{
    int valor;
    do{
        cin>>valor;
    }while(valor<0);

    g.autoreproduccio(valor);
}
void execucio_programa(Gestor&g)
//pre:cert//post:s'executen una serie de comandes entrades per teclat
{
    string comanda ;cout<< "OPCIO:"<<endl; cin>>comanda;

    while(comanda!="z" && comanda!="quit")
    {
        if(comanda=="add" or comanda== "a")inserir_canco(g);
        else if(comanda=="break" or comanda== "b")llista_reproduccio_per_durada(g);
        else if(comanda=="show" or comanda=="c")mostrar(g);
        else if(comanda=="select" or comanda=="d")seleccionar_canco_del_cataleg(g);
        else if(comanda=="youtube" or comanda=="f")canvi_de_mode(g);
        else if(comanda=="play" or comanda=="g")reproduir_canco(g);
        else if(comanda=="save" or comanda=="x")desar_cataleg(g);
        else if(comanda=="help" or comanda=="y")mostrar_comandes();
        else if(comanda=="empty" or comanda== "e")esborrar_cues(g);
        else if(comanda=="remove" or comanda=="i")remoure_canco(g);
        else if(comanda=="qplay" or comanda=="h")reproduccio_total(g);
        cout<<endl<<"OPCIO:"<<endl; cin>>comanda;
    }
}

int main()
{
    string nom_fitxer; Gestor g;
    cout<< "FITXER:"<<endl;
    cin>>nom_fitxer;

    ifstream fitxer(nom_fitxer.c_str());
    if(not fitxer.fail())
    {
        lectura_fitxer(g,fitxer);
        execucio_programa(g);
        desar_cataleg(g,nom_fitxer);
    }
    else cout<< "NO S'HA POGUT OBRIR L'ARXIU"<<endl;
    cout<<"A REVEURE...!";
    return 0;
}
