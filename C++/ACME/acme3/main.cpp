#include <iostream>
#include "Data.h"

using namespace std;

const int EOP=0;
const int MAX=100;

struct TaulaDates{
    Data vec[MAX];
    int n;
};
void mostrar_comandes()
//pre
//post
{
    cout<< "OPCIONS:"<<endl;
    cout<< "1: ENTRAR UNA DATA EN FORMAT AAAAMMDD"<<endl;
    cout<< "2: ENTRAR UNA DATA EN FORMAT D M A"<<endl;
    cout<< "3: MOSTRAR LES DATES ORDENADES EN FORMAT CURT"<<endl;
    cout<< "4: MOSTRAR LES DATES ORDENADES EN FORMAT LLARG"<<endl;
    cout<< "9: MOSTRAR EL MENU D'OPCIONS"<<endl;
    cout<< "0: SORTIR DEL PROGRAMA"<<endl;
}
int main()
{
    TaulaDates taula;taula.n=0;
    int comanda=9;
    while(comanda!=EOP)
    {
        if(comanda==1 or comanda==2)
        {
            if(comanda==1)cout<<"ENTRA UNA DATA (AAAAMMDD):";
            else cout<<"ENTRA UNA DATA (D M A):";
            cout<<endl;
            taula.vec[taula.n].llegir(comanda);
            bool trobat=false;
            int i=0;
            while(i<taula.n&&not trobat)
            {
                if(taula.vec[taula.n].es_igual(taula.vec[i]))trobat=true;
                i++;
            }
            if(not trobat)
            {
                int i=taula.n;
                while(i>0&&taula.vec[i].es_menor(taula.vec[i-1])){
                    Data d1=taula.vec[i];
                    taula.vec[i]=taula.vec[i-1];
                    taula.vec[i-1]=d1;
                    i--;
                }
                taula.n++;
            }
        }
        else if(comanda==3 or comanda==4){
            cout<<"LLISTAT DE LES DATES:"<<endl;
            if(taula.n>0)for(int i=0;i<taula.n;i++)taula.vec[i].mostrar(comanda);
        }
        else mostrar_comandes();
        cout<<"OPCIO:"<<endl;cin>>comanda;
    }
    cout<< "FINAL DEL PROGRAMA";
    return 0;
}
