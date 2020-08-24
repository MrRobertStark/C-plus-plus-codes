#include "Comanda.h"

Comanda::Comanda()
//Pre:cert//Post:s'inicialitzen les variables de la comanda pels seus valors per defecte
{
    a_codi=0;
    a_duracio_espera=0;
    a_client="";
}
void Comanda::mostrar_comanda()const
//Pre:les dades de les comandes han de ser correctes//Post:es mostren les dades de les comandes
{
    cout<< "CODI: "<<a_codi<<endl;
    cout<< "NOM: "<<a_client<<endl;
    cout<< "HORA ENTRADA: "; a_h_inici.mostrar_hora();
}
void Comanda::llegir_comanda()
//Pre:cert//Post:les dades de la comanda s'emplenen per valors entrades per teclat
{
    cout<< "ENTRA LA COMANDA:"<<endl;
    cout<< "CODI: "<<endl;
    cin>>a_codi;
    cout<<"NOM:"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,a_client);
    cout<< "HORA ENTRADA:"<<endl;
    a_h_inici.llegir_hora();
}
int Comanda::consultar_duracio_comanda()const
//Pre:
//Post:
{
    cout<< "HORA ACTUAL:"<<endl;
    Hora h;h.llegir_hora();

    return (a_h_inici.duracio(h));
}
