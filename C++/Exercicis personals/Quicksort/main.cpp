#include <iostream>

using namespace std;

void intercanvi(int &a,int &b)
//pre:A=a B=b//post: A=b B=a
{
    int aux=b;
    b=a; a=aux;
}

void particio(int vec[],int n,int esq,int dret,int& pos_pivot)
//pre:n>=0 && esq<=dret//post:s'aplica una particio al vector posant el pivot a la posició correcte
{
    int pivot= vec[dret];
    pos_pivot=esq;

    for(int i=esq;i<=dret-1;i++)
    {
        if(vec[i]<pivot){
            intercanvi(vec[i],vec[pos_pivot]);
            pos_pivot++;
        }
    }
    intercanvi(vec[pos_pivot],vec[dret]);
}

void i_quicksort(int vec[],int n,int esq,int dret)
//pre:esq<=dret//post:s'aplica quicksort al vector vec
{
    if(esq<dret){
        int k;
        particio(vec,n,esq,dret,k); //vec[k] serà la pos del pivot
        i_quicksort(vec,n,esq,k-1);
        i_quicksort(vec,n,k+1,dret);
    }
}

void quicksort(int vec[],int n)
//pre:n>=0//post:s'aplica quicksort al vector entrat
{
    i_quicksort(vec,n,0,n-1);
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
    cout<<endl<< "Ara vaig a ordenar els elements de la taula amb el quicksort."<<endl<<endl<<"Aquest es el resultat:"<<endl;

    quicksort(vec,n);
    for(int i=0;i<n;i++)cout<<vec[i]<<" ";
    cout<<endl<<"A REVEURE!...";
    return 0;
}
