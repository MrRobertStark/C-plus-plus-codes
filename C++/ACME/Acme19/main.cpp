#include <iostream>

using namespace std;

bool i_suma_vector_idem(const int t[],int n,int&comptador,int&sumador)
//pre:n>0//post:es retorna cert si un element del vector equival a la suma dels elements anteriors
{
    bool correcte=false;

    if(comptador<n)
    {
        if(t[comptador]==sumador)correcte=true;
        else
        {
            sumador+=t[comptador]; comptador++;
            correcte=i_suma_vector_idem(t,n,comptador,sumador);
        }
    }
    else correcte=false;

    return correcte;
}

void suma_vector_idem(const int t[],int n)
//pre:n>=0//post:es mostra si un element del vector coincideix amb la suma dels elements anteriors
{
    int comptador=0,sumador=0;
    bool resultat= i_suma_vector_idem(t,n,comptador,sumador);

    if(resultat)
    {
        cout<< "S'HA TROBAT UNA CASELLA:"<<endl;

        cout<<t[0];
        for(int i=1;i<comptador;i++)
        {
            if(t[i]>0)cout<<" + "<<t[i];
            else cout<<" - "<<t[i]*-1;
        }
        cout<<" = "<<sumador;
    }
    else cout<< "NO S'HA TROBAT CAP CASELLA";

}

int main()
{
    cout << "ENTRA EL NOMBRE DE CASELLES: " << endl;
    int n; cin>>n;
    int taula[n];

    cout<< "ENTRA ELS VALORS:"<<endl;
    for(int i=0;i<n;i++)cin>>taula[i];

    suma_vector_idem(taula,n);

    return 0;
}
