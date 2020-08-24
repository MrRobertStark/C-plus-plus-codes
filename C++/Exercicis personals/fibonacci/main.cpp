#include <iostream>

using namespace std;
int main()
{
    cout<< "Aquest programa realitza la serie fibonacci fins al nove terme, ok?"<<endl;
    cout<<endl;
    int n_anterior,n_posterior,n_aux,comptador;
    n_anterior=comptador=n_aux=0;
    n_posterior=1;
    while(comptador<9)
    {
        n_aux=n_anterior+n_posterior;
        n_anterior=n_posterior;
        n_posterior=n_aux;
        comptador++;
    }
    cout<< "El resultat obtingut a partir de l'operacio es el seguent: "<<n_posterior<<endl;
}
