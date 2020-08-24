#include "Paraula.h"

Paraula::Paraula()
//Pre:
//Post:
{
    a_paraula="";
    a_n_aparicions=0;
    a_inici='a';
}
string Paraula::consultar_paraula()const
//Pre:
//Post:
{
    return a_paraula;
}
void Paraula::mostrar_paraula()const
//Pre:
//Post:
{
    cout<<a_paraula<<": "<<a_n_aparicions<<endl;
}
void Paraula::llegir_paraula(ifstream&fitxer)
//Pre:
//Post:
{
    string paraula;
    char c=passar_separadors(fitxer);
    if(not fitxer.eof()&&es_lletra(c))
    {
        if(es_majuscula(c))transformar_a_minuscula(c);
        a_inici=c;
    }
    while(not fitxer.eof() && es_lletra(c))
    {
        if(es_majuscula(c))transformar_a_minuscula(c);
        paraula+=c;
        c=fitxer.get();
    }
    a_paraula=paraula;
    a_n_aparicions=1;
}
char Paraula::passar_separadors(ifstream&fitxer)
//Pre:
//Post:
{
    char c=fitxer.get();
    while(not fitxer.eof()&& not es_lletra(c))
    {
        c=fitxer.get();
    }
    return c;
}
bool Paraula::es_lletra(char c)
//Pre:
//Post:
{
    return (c>='a'&& c<='z') or (c>='A'&& c<='Z');
}
void Paraula::transformar_a_minuscula(char&c)
//Pre:
//Post:
{
    c = c - 'A' + 'a';
}
bool Paraula::es_majuscula(char c)
//Pre:
//Post:
{
    return (c>='A'&& c<='Z');
}
int Paraula::consultar_n_aparicions()const
//Pre:
//Post:
{
    return a_n_aparicions;
}
bool Paraula::operator==(const Paraula&p)const
//Pre:
//Post:
{
    return (a_paraula==p.a_paraula);
}
bool Paraula::operator!=(const Paraula&p)const
//Pre:
//Post:
{
    return !(a_paraula==p.a_paraula);
}
bool Paraula::operator<(const Paraula& p)const
//Pre:
//Post:
{
    return (a_paraula<p.a_paraula);
}
void Paraula::incrementar_n_aparicions()
//Pre:
//Post:
{
    a_n_aparicions++;
}
char Paraula::consultar_inicial()const
//Pre:
//Post:
{
    return a_inici;
}
