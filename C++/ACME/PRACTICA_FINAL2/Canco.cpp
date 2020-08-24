#include "Canco.h"

Canco::Canco()
{
    a_any=2001;
    a_reproduccions=a_uid=0;
    a_titol=a_artista=a_genere=a_anim=a_link="";
}
Canco::Canco(const Durada&d,int uid,int any,int repro,string titol,string artista,string genere,string anim,string codi)
{
    a_duracio=d;
    a_uid=uid;
    a_any=any;
    a_reproduccions=repro;
    a_titol=titol;
    a_artista=artista;
    a_genere=genere;
    a_anim=anim;
    a_link=codi;
}
Durada Canco::solicitar_durada()const
{
    return a_duracio;
}
void Canco::mostrar_canco(int format)const
{
    if(format==1)
    {
        string espai= " | ",inici="[ ",finali=" ]";

        cout<<inici<<a_titol<<espai<<a_artista<<espai<<a_any<<espai;
        a_duracio.mostrar_durada();
        cout<<espai<<a_genere<<espai<<a_anim<<espai<<a_reproduccions<<finali<<endl;
    }
    else if(format==2)
    {
        cout<<"[CANCO"<<endl;
        cout<<"TITOL:          "<<a_titol<<endl;
        cout<< "ARTISTA:        "<<a_artista<<endl;
        cout<< "ANY:            "<<a_any<<endl;
        cout<< "DURADA:          ";a_duracio.mostrar_durada();cout<<endl;
        cout<< "GENERE:         "<<a_genere<<endl;
        cout<< "ESTAT D'ANIM:   "<<a_anim<<endl;
        cout<< "YOUTUBE:        "<<a_link<<endl;
        cout<< "REPRODUCCIONS:  "<<a_reproduccions<<endl;
        cout<< "FI]             "<<endl;
    }
}
string Canco::solicitar_camp_string(string camp)const
{
    string resultat;
    if(camp=="b" or camp=="artist")resultat=a_artista;
    else if(camp=="c"  or camp =="title")resultat=a_titol;
    else if(camp=="d" or camp== "genre")resultat=a_genere;
    else if (camp=="e" or camp=="mood")resultat=a_anim;
    else if(camp=="link")resultat= a_link;
    return resultat;
}
int Canco::solicitar_uid()const
{
    return a_uid;
}
bool Canco::es_menor(const Canco&c,string criteri)const
{
    bool menor;
    if(criteri=="a" or criteri=="songs")
        menor=(*this)<c;

    else if(criteri=="b" or criteri=="genre")
        menor=(*this).a_genere<c.a_genere or ((*this).a_genere==c.a_genere&&(*this)<c);

    else if(criteri=="c" or criteri=="mood")
        menor=(*this).a_anim<c.a_anim or ((*this).a_anim==c.a_anim&&(*this)<c);

    else if(criteri=="d" or criteri=="topten")
        menor=(*this).a_reproduccions>c.a_reproduccions or ((*this).a_reproduccions==c.a_reproduccions&&(*this)<c);

    else if(criteri=="e" or criteri=="year")
        menor=(*this).a_any<c.a_any or ((*this).a_any==c.a_any&&(*this)<c);

    else if(criteri=="break")
        menor=(*this).solicitar_durada()<c.solicitar_durada() or ((*this).solicitar_durada()==c.solicitar_durada()&&(*this)<c);

    else if(criteri=="uid")
        menor=(*this).a_uid<c.a_uid or ((*this).a_uid==c.a_uid&&(*this)<c);

    return menor;
}
void Canco::incrementar_n_reproduccions()
{
    a_reproduccions++;
}
void Canco::backup(ofstream&fitxer)const
{
    char espai=' ';
    fitxer<<a_uid<<endl<<a_titol<<endl<<a_artista<<endl;
    fitxer<<a_any<<espai<<a_duracio.solicitar_duracio()<<espai<<a_genere<<espai;
    fitxer<<a_anim<<espai<<a_link<<espai<<a_reproduccions<<endl;
}
void Canco::lectura_fitxer(ifstream&fitxer)
{
    fitxer>>a_uid;fitxer.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(fitxer,a_titol);getline(fitxer,a_artista);

    int duracio;
    fitxer>>a_any>>duracio>>a_genere>>a_anim>>a_link>>a_reproduccions;
    a_duracio=Durada(duracio);
}
bool Canco::operator<(const Canco&c)const
{
    return (a_titol<c.a_titol)or(a_titol==c.a_titol&&a_artista<c.a_artista);
}
bool Canco::operator>(const Canco&c)const
{
    return !((*this)<c);
}
bool Canco::operator==(const Canco&c)const
{
    return a_titol==c.a_titol && a_artista==c.a_artista;
}
bool Canco::operator!=(const Canco&c)const
{
    return !((*this)==c);
}
