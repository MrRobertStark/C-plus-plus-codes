#include <iostream>
#include <string>

using namespace std;

void enviar_missatge(string text="[MISSATGE PER DEFECTE]")
//Pre:
//Post:
{
    cout<<text<<endl;
}

int main()
{
    cout<<endl;
    cout << "Prova de fer execucions per defecte:" << endl;
    string missatge1,missatge2,missatge3;
    char condicio;

    getline(cin,missatge1);
    enviar_missatge(missatge1);

    cin>>condicio;
    cout<<condicio<<endl;

    getline(cin,missatge2);
    enviar_missatge(missatge2);

    getline(cin,missatge3);
    enviar_missatge(missatge3);

    return 0;
}
