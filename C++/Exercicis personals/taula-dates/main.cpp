#include <iostream>
#include<string>
using namespace std;
bool es_nombre(char data)
//pre
//post
{
    return(data>='0'&&data<='10');
}
int main()
{
    cout << "Entra un caracter:" << endl;
    char num1,num2;
    cin>>num1>>num2;
    cout<<"He intentat una suma: "<<num1+num2<<endl;
    return 0;
}
