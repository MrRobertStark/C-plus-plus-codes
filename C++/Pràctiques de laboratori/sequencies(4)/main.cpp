#include <iostream>
using namespace std;
const int EOS= '#';
//Entrada: Una frase
//Sortida: comptador de caràcters previs a la primera 'a'

int comptador_caracters(){
    char n;
    cin>>n;
    int comptador=0;
    while(n!=EOS && n!='a'){
        comptador++;
        cin>>n;
    }
    return comptador;
}

int main()
{
    cout << "Entra una frase: ";
    int quantitat=comptador_caracters();
    cout<<"Hi ha "<<quantitat<<"(s) abans de la primera 'a'"<<endl;
    return 0;
}
