#include <iostream>
#include<fstream>

using namespace std;

int main()
{
    cout<<endl<<"Digue'm alguna cosa que jo te la retornare"<<endl;
    string missatge;getline(cin,missatge);

    ofstream fitxer("a.dat");
    if(not fitxer.fail())fitxer<<missatge<<endl;
    else cout<< "No s'ha pogut obrir l'arxiu"<<endl;
    return 0;
}
