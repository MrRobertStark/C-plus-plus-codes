#include<iostream>
using namespace std;
const int EOS=0;
const int MAX=1000;
//Entrada: Una sequencia de un nombre de telefon, la durada de la trucada feta amb el telefon i els costos resultants de cadascuna
//Sortida:Determinació del preu mig d'un minut de trucada, els euros gastats en total i quants euros s'han gastat en cada nombre i el percentatge que representa de l'import final
struct telefon{
    int num;
    double temps;
    double diners;
};
typedef telefon Taula_mobile[MAX];

telefon llegir_data()
//Pre:cert
//Post:Retorna el nombre de telefon, la durada de la trucada i els costos
{
    telefon t;
    cin>>t.num;
    if(t.num!=EOS)cin>>t.temps>>t.diners;
    return t;
}

void eliminar_copies_sumant_costos(Taula_mobile taula,int&n)
//Pre: la taula ha de ser [0..n-1] i 0<=n<=MAX
//Post:retorna la taula emplenada eliminant les copies però sumant-les a les originals
{
    for(int i=0;i<=n-2;i++){
        if(taula[i].num==taula[n-1].num){
            taula[i].temps+=taula[n-1].temps;
            taula[i].diners+=taula[n-1].diners;
            n--;
        }
    }
}

void calcul_temps_i_diners_totals(const Taula_mobile taula,int n,double&total_temps,double&total_diners)
//Pre: La taula ha de ser mida [0..n-1] i 0<=n<=MAX.
//Post: calcula els diners totals i el temps total de la sequencia
{
    for(int i=0;i<n;i++){
        total_diners+=taula[i].diners;
        total_temps+=taula[i].temps;
    }
}
void llegir_telefons_i_dades(Taula_mobile taula,int&n,double&total_temps,double&total_diners)
//Pre: taula ha de tenir mida [0..n-1] i 0<=n<=MAX
//Post: llegeix totes les dades de la sequencia(nombre de telefon,durada de la trucada i costos)
{
    total_diners=total_temps=n=0;
    telefon data=llegir_data();
    while(data.num!=EOS&&n<MAX)
    {
        taula[n]=data;
        n++;
        eliminar_copies_sumant_costos(taula,n);
        data=llegir_data();
    }
    calcul_temps_i_diners_totals(taula,n,total_temps,total_diners);
}

void euros_x_numero_amb_percentatge(const Taula_mobile taula,int n,double total_diners)
//Pre:
//Post:
{
    for(int i=0;i<n;i++){
        cout<<"TEL "<<taula[i].num<<": "<<taula[i].diners<<" EUROS, "<<taula[i].diners/total_diners*100<<"%"<<endl;
    }
}
int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<< "INTRODUEIX LA SEQUENCIA:"<<endl;
    Taula_mobile taula;
    int n;
    double total_temps,total_diners;
    llegir_telefons_i_dades(taula,n,total_temps,total_diners);
    if(total_temps==0)total_temps=1;
    cout<< "PREU MIG MINUT: "<<total_diners/total_temps<<" EUROS"<<endl;
    cout<< "TOTAL EUROS GASTATS: "<<total_diners<<" EUROS  "<<endl;
    euros_x_numero_amb_percentatge(taula,n,total_diners);
    return 0;
}
