#include <iostream>
#include <string>

using namespace std;

int main()
{
    string entrada,sortida;
    cin>>entrada;
    cin>>sortida;
    if(entrada>sortida)cout<< "Entrada es major";
    else if(entrada==sortida)cout<< "Son iguals";
    else cout<< "La sortida es major";
    return 0;
}
