#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout<< "Entra una lletra:"<<endl;
    char lletra;cin>>lletra;
    int pos_abecedari = lletra-'a';
    cout<< "La lletra es troba a la pos "<<pos_abecedari<< " de l'abecedari"<<endl;
    return 0;
}
