#include <iostream>

using namespace std;

void fusio(int vec[],int n,int esq,int ini2,int dret)
{
    int aux[dret-esq+1],comptador=0;
    for(int i=esq;i<ini2;i++){
        aux[comptador]=vec[i]; comptador++;
    }
    for(int j=dret;j>=ini2;j--){
        aux[comptador]=vec[j];comptador++;
    }

    int limitdret=comptador-1,limitesq=0,pos=esq;
    while(limitesq<=limitdret){
        if(aux[limitesq]<aux[limitdret]){
            vec[pos]=aux[limitesq];
            limitesq++;
        }
        else{
            vec[pos]=aux[limitdret];
            limitdret--;
        }
        pos++;
    }
}

void i_mergesort(int vec[],int n,int esq,int dret)
//pre:esq>=0 esq<dret//post:s'ordena el vector per mergesort
{
    if(esq<dret)
    {
        int mig=(esq+dret)/2;
        i_mergesort(vec,n,esq,mig);
        i_mergesort(vec,n,mig+1,dret);
        fusio(vec,n,esq,mig+1,dret);
    }
}

void mergesort(int vec[],int n)
//pre:n>0//post:s'ordena el vector per mergesort
{
    i_mergesort(vec,n,0,n-1);
}

int main()
{
    cout << "Hello world!" << endl<<"Quants elements vols ordenar (n>0)? ";
    int n,m=0; cin>>n;
    int vec[n];

    while(m!=n)
    {
        cout<< "Entra un nombre enter: ";
        cin>>vec[m]; m++;
    }
    cout<<endl<< "El vector es el seguent:"<<endl;
    for(int i=0;i<n;i++)cout<<vec[i]<<" ";
    cout<<endl<< "Ara vaig a ordenar els elements de la taula amb el mergesort."<<endl<<endl<<"Aquest es el resultat:"<<endl;

    mergesort(vec,n);
    for(int i=0;i<n;i++)cout<<vec[i]<<" ";
    cout<<endl<<"A REVEURE!...";
    return 0;
}
