#include <iostream>

using namespace std;

void Hanoi (int n,char from,char to,char aux)
{
    if(n>0){
        Hanoi(n-1,from,aux,to);
        cout<< "Move disk to "<<from<<" to "<<to<<endl;
        Hanoi(n-1,aux,to,from);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    Hanoi(4,'a','c','b');
    cout<< "Final del programa";
    return 0;
}
