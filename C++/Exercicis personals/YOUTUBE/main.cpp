#include <iostream>
#include <windows.h>
#include <shellapi.h>

using namespace std;

int main()
{
    cout << "DIGUE'M UNA ADRECA DE YOUTUBE QUE JO TE LA POSO: " << endl;
    string url="https://youtu.be/",codi;cin>>codi;

    //#ifdef_WIN32

    url+=codi;
    ShellExecute(0,0,url.c_str(),0,0,SW_SHOW);

    //#endif

    cout<<"GAUDEIX DE LA MUSICA!"<<endl;
    return 0;
}
