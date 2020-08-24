#include "Canco.h"
#include "Durada.h"

Canco::Canco()
{
    a_uid=0;
    a_any=2001;
    a_reproduccions=0;
    a_titol="";
    a_artista="";
    a_genere="";
    a_anim="";
    a_codi="";
}
Canco::Canco(const Durada&d,int uid,int any,int repro,string titol,string artista,string genere,string anim,string ytb)
{
    a_duracio=d;
    a_uid=uid;
    a_any=any;
    a_reproduccions=repro;
    a_titol=titol;
    a_artista=artista;
    a_genere=genere;
    a_anim=anim;
    a_codi=ytb;
}
int Canco::consultar_duracio()const
{
    return a_duracio.solicitar_durada();
}
void Canco::mostrar_canco()const
{
    string espai= " | ",inici="[ ",finali=" ]";

    cout<<inici<<a_titol<<espai<<a_artista<<espai<<a_any<<espai;
    a_duracio.mostrar_durada();
    cout<<espai<<a_genere<<espai<<a_anim<<espai<<a_reproduccions<<finali<<endl;
}
bool Canco::es_menor(const Canco&c,string criteri)const
{
    bool menor;
    if(criteri=="genre")menor=((*this).a_genere<c.a_genere);
    else if(criteri=="break")menor=((*this).a_duracio.solicitar_durada()<c.a_duracio.solicitar_durada());
    return menor;
}
void Canco::backup(ofstream&fitxer)const
{
    string espai= " | ",inici="[ ",finali=" ]";

    fitxer<<inici<<a_titol<<espai<<a_artista<<espai<<a_any<<espai;
    a_duracio.backup(fitxer);
    fitxer<<espai<<a_genere<<espai<<a_anim<<espai<<a_uid<<finali<<endl;
}
void Canco::lectura_fitxer(ifstream&fitxer)
{
    fitxer>>a_uid;fitxer.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(fitxer,a_titol);getline(fitxer,a_artista);

    int duracio=0;
    fitxer>>a_any>>duracio>>a_genere>>a_anim>>a_codi>>a_reproduccions;
    a_duracio=Durada(duracio);
}
bool Canco::operator==(const Canco&c)const
{
    return (a_titol==c.a_titol && a_artista==c.a_artista);
}
bool Canco::operator!=(const Canco&c)const
{
    return !(a_titol==c.a_titol && a_artista==c.a_artista);
}
bool Canco::operator<(const Canco&c)const
{
    return ((a_titol<c.a_titol) or (a_titol==c.a_titol && a_artista<c.a_artista));
}
bool Canco::operator>(const Canco&c)const
{
    return !((a_titol<c.a_titol) or (a_titol==c.a_titol && a_artista<c.a_artista));
}
