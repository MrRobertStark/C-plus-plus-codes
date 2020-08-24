#include <iostream>
#include <string>

using namespace std;

bool es_lletra(char c)
{
    bool lletra=((c>='a'&&c<'z')or(c>='A'&&c<='Z'));
    return lletra;
}

int main()
{
    cout << "ENTRA UNA PARAULA QUALSEVOL:" << endl;
    string paraula="";char c;int comptador=0;

    cin>>c;
    while(es_lletra(c))
    {
        comptador++;
        paraula+=c;
        cin>>c;
    }
    cout<< "EL NOMBRE DE LLETRES EN LA PARAULA SON: "<<comptador<<" LLETRES"<<endl;
    cout<< "FINS AVIAT";
    return 0;
}
