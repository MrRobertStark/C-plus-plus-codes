#include "Gestor.h"

#ifdef _WIN32
    #include <windows.h>
    #include <shellapi.h>
#endif // _WIN32

Gestor::Gestor()
{
    a_mode=false;
    a_comentari_final="No comments";
}
void Gestor::mostrar_cataleg(string criteri)const
{
    if(a_cataleg.solicitar_a_n_elements()!=0)
    {
        if(criteri=="f" or criteri=="queue")a_llista.mostrar_llista();
        else if(criteri=="g" or criteri=="history")a_historial.mostrar_historial();
        else
        {
            TaulaCancons aux;
            for(int i=0;i<a_cataleg.solicitar_a_n_elements();i++)
                aux.inserir_per_criteri(a_cataleg.solicitar_canco(i),criteri);

            aux.mostrar_cancons(criteri);
        }
    }
    else cout<< "NO HI HA RES PER MOSTRAR"<<endl;
}
void Gestor::autoreproduccio(int segons)
{
    int espera;

    if(!a_llista.es_buida())
        while(not a_llista.es_buida())
        {
            if(segons==0)espera=a_llista.seguent_canco().solicitar_durada().solicitar_duracio();
            else espera=segons;
            reproduir();
            #ifdef _WIN32
                Sleep(espera*1000);
            #endif // _WIN32
        }
    else cout<< "[ATENCIO] NO HI HA CANCONS PER REPRODUIR"<<endl;
}
void Gestor::afegir_canco_al_cataleg()
{
    string titol,artista;char signe_segons='"';
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"TITOL:"<<endl;getline(cin,titol);
    cout<< "ARTISTA:"<<endl;getline(cin,artista);
    Canco c=Canco(Durada(0),0,2001,0,titol,artista);

    if(a_cataleg.preexistencia(c)==-1)
    {
        cout<< "ANY:"<<endl;int any;cin>>any;
        cout<< "DURADA [' "<<signe_segons<<"]:"<<endl;int minuts,segons;cin>>minuts>>segons;
        cout<< "GENERE:"<<endl;string genere;cin>>genere;
        cout<< "ESTAT D'ANIM:"<<endl;string anim;cin>>anim;
        cout<< "YOUTUBE:"<<endl;string codi;cin>>codi;

        c=Canco(Durada(segons,minuts),a_cataleg.solicitar_maxim_uid()+1,any,0,titol,artista,genere,anim,codi);
        a_cataleg.incrementar_maxim_uid(c.solicitar_uid());
        a_cataleg.inserir_per_criteri(c);
    }
    else cout<< "[ATENCIO] AQUESTA CANCO JA HI ES"<<endl;
}
void Gestor::reproduccio_per_durada(const Durada&d)
{
    if(a_cataleg.solicitar_a_n_elements()!=0)
    {
        TaulaCancons aux; a_llista.alliberar();

        for(int i=0;i<a_cataleg.solicitar_a_n_elements();i++)
            aux.inserir_per_criteri(a_cataleg.solicitar_canco(i),"break");

        int pos=0; Durada sumador,aux_duracio=aux.solicitar_canco(pos).solicitar_durada();
        while(pos<aux.solicitar_a_n_elements() && (sumador+aux_duracio<d or sumador+aux_duracio==d))
        {
            sumador=sumador+aux_duracio;
            a_llista.empila(aux.solicitar_canco(pos));
            pos++;
            aux_duracio=aux.solicitar_canco(pos).solicitar_durada();
        }
        a_llista.mostrar_llista();
        cout<< "TEMPS TOTAL: "; sumador.mostrar_durada();cout<<endl;
    }
    else cout<< "NO HI HA RES PER MOSTRAR"<<endl;
}
void Gestor::select(string criteri)
{
    if(a_cataleg.solicitar_a_n_elements()==0)cout<< "NO HI HA RES PER MOSTRAR"<<endl;
    else
    {
        TaulaCancons aux; emplenar_taula_per_criteri(aux,criteri);

        if(aux.solicitar_a_n_elements()==0)cout<< "NO HI HA CANCONS PER SELECCIONAR..."<<endl;
        else
        {
            Canco c=seleccio_final(aux);
            c.mostrar_canco(); a_llista.empila(c);
        }
    }
}
void Gestor::eliminar_canco(string criteri)
{
    if(a_cataleg.solicitar_a_n_elements()==0)cout<< "NO HI HA RES PER MOSTRAR"<<endl;
    else
    {
        TaulaCancons aux; emplenar_taula_per_criteri(aux,criteri);

        if(aux.solicitar_a_n_elements()==0)cout<< "NO HI HA CANCONS PER SELECCIONAR..."<<endl;
        else
        {
            Canco c=seleccio_final(aux);
            c.mostrar_canco(2);
            cout<< "VOLS ESBORRAR-LA (s/n)?"<<endl;
            char opcio;cin>>opcio;
            if(opcio=='s')
            {
                a_cataleg.eliminar_canco(a_cataleg.preexistencia(c,"uid"));
                a_llista.eliminar_canco(c);
                a_historial.eliminar_canco(c);
            }
        }
    }
}
void Gestor::emplenar_taula_per_criteri(TaulaCancons&t,string criteri,string format)const
{
   if(criteri!= "a"&&criteri!="all") //INICIALITZEM LA TAULA AUX AMB EL FILTRE ENTRAT
    {
        string filtre;cin>>filtre;
        for(int i=0;i<a_cataleg.solicitar_a_n_elements();i++)
        {
            if(a_cataleg.solicitar_canco(i).solicitar_camp_string(criteri).find(filtre)!=string::npos)//Tingui espai o no el string a analitzar, faig servir string.finde(cadena) per reduir nombre d'instruccions
                t.inserir_per_criteri(a_cataleg.solicitar_canco(i),format);
        }
    }
    else
    {
        for(int i=0;i<a_cataleg.solicitar_a_n_elements();i++)
            t.inserir_per_criteri(a_cataleg.solicitar_canco(i),format);
    }
}
Canco Gestor::seleccio_final(const TaulaCancons&aux)const
{
    int opcio=0; //ARA ESCOLLIM LA CANCO QUE VULGUEM DE LA TAULA RESULTANT

    if(aux.solicitar_a_n_elements()>1)
    {
        for(int i=0;i<aux.solicitar_a_n_elements();i++)
            {cout<< "[ #"<<i+1<<" ] ";aux.solicitar_canco(i).mostrar_canco();}

        cout<< "SELECCIONA [1.."<<aux.solicitar_a_n_elements()<<"]"<<endl;
        do
        {
            cin>>opcio;
        }while(opcio<0 or opcio>aux.solicitar_a_n_elements());
        opcio--;
    }
    else cout<< "SELECCIO AUTOMATICA (NOMES UNA)"<<endl;

    cout<< "S'HA SELECCIONAT"<<endl;

    return (aux.solicitar_canco(opcio));
}

void Gestor::canvi_mode_adrecament()
{
    a_mode=!a_mode;
    if(a_mode)cout<< "MODE YOUTUBE ACTIVAT"<<endl;
    else cout<< "MODE TEXT ACTIVAT"<<endl;
}
void Gestor::reproduir()
{
    if(not a_llista.es_buida())
    {
        string missatge="REPRODUINT";
        if(a_mode)missatge+="...";
        else missatge+= " PER TEXT...";
        cout<<missatge<<endl;

        Canco c=a_llista.seguent_canco();c.mostrar_canco();
        c.incrementar_n_reproduccions();
        actualitzar_informacio(c);

        a_historial.empilar(c);a_llista.desencua();

        if(a_mode)obrir_enllac(c.solicitar_camp_string());//PER DEFECTE ES DEMANARA EL CODI DE LA CANCO (EL LINK)
    }
    else cout<< "[ATENCIO] NO HI HA CANCONS PER REPRODUIR"<<endl;
}
void Gestor::buida(string opcio)
{
    if(opcio=="a" or opcio=="queue")a_llista.alliberar();
    else if(opcio=="b" or opcio=="history")a_historial.alliberar();
}
void Gestor::backup(ofstream&fitxer)const
{
    fitxer<< "MTP[CATALOGUE] 1 ";
    if(a_mode)fitxer<<"true"<<endl;
    else fitxer<<"false"<<endl;
    fitxer<< "MTP[SONGS] "<<a_cataleg.solicitar_a_n_elements()<<endl;

    a_cataleg.backup(fitxer);//ES DESA EL CATALEG AL FITXER
    a_historial.backup(fitxer);//ES DESA L'HISTORIAL
    a_llista.backup(fitxer);//ES DESA LA LLISTA DE REPRODUCCIÓ

    fitxer<<endl<<a_comentari_final;//ES DESA EL COMENTARI
}
void Gestor::lectura_fitxer(ifstream&fitxer)
{
    string missatge,mode;int n_cancons,uid;
    fitxer>>missatge>>missatge>>mode>>missatge>>n_cancons;

    a_cataleg.incrementar_maxim_uid(n_cancons);
    a_mode=(mode=="true");

    for(int i=0;i<n_cancons;i++)//LECTURA DE LES CANCONS
    {
        Canco c; c.lectura_fitxer(fitxer);
        a_cataleg.inserir_per_criteri(c); //Per defecte s'insereix la canco per uid
    }

    fitxer>>missatge>>n_cancons;
    for(int i=0;i<n_cancons;i++)//LECTURA DE L'HISTORIAL
    {
        fitxer>>uid; Canco c=Canco(Durada(0),uid);
        a_historial.empilar(a_cataleg.solicitar_canco(a_cataleg.preexistencia(c,"uid")),missatge);
    }

    fitxer>>missatge>>n_cancons;
    for(int i=0;i<n_cancons;i++)//LECTURA DE LA LLISTA DE REPRODUCCIÓ
    {
        fitxer>>uid;Canco c=Canco(Durada(0),uid);
        a_llista.empila(a_cataleg.solicitar_canco(a_cataleg.preexistencia(c,"uid")));
    }

    fitxer.ignore(numeric_limits<streamsize>::max(),'\n');//LECTURA DELS COMENTARI
    getline(fitxer,a_comentari_final);
}
void Gestor::obrir_enllac(string link)const
{
    #ifdef _WIN32
        string url= "https://youtu.be/";url+=link;
        ShellExecute(0,0,url.c_str(),0,0, SW_SHOW);
    #endif // _WIN32
}
void Gestor::actualitzar_informacio(const Canco&c)
{
    int pos_taula=a_cataleg.preexistencia(c,"uid");
    a_cataleg.actualizar_info_canco(pos_taula,c);
    a_llista.actualitzar_info_canco(c);
    a_historial.actualitzar_info_canco(c);
}
