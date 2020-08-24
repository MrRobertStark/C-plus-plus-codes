#include<iostream>
#include<string>
using namespace std;
const int MAX_FIL=100;
const int MAX_COL=100;
typedef int Matriu_Enter[MAX_FIL][MAX_COL];
//Entrada: la mesura de la matriu nova
//Sortida: el triangle de tartàlia amb les mesures entrades

void posar_1(Matriu_Enter matriu, int n, int m)
{
    for(int i=0;i<n;i++){
        matriu[i][0]=1;
        matriu[i][i]=1;
    }
}

void tartalia(Matriu_Enter mat,int n,int& m){
    m=1;
    for(int i=2;i<n;i++){
        m=1;
        while(m>0 && m<i){
            mat[i][m]=mat[i-1][m-1]+mat[i-1][m];
            m++;
        }
    }
}

void escriure_matriu(const Matriu_Enter matriu,int n,int m){
    int col=0;
    for(int i=0;i<n;i++){
        col=0;
        while(col<=i){
            cout<<matriu[i][col]<<" ";
            col++;
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"Ara farem el triangle de tartalia. Digue'm les dimensions de la matriu:"<<endl;
    int n,m;
    cin>>n>>m;
    cout<<"Molt be, ara et recreare el triangle de tartalia, mira:"<<endl;
    Matriu_Enter matriu;
    posar_1(matriu,n,m);
    cout<< "Inicialitzant la matriu a 1s em dona aixo: "<<endl;
    escriure_matriu(matriu,n,m);
    cout<<"El seguent pas es omplir els espais buits de la matriu. Per tant tenim:"<<endl;
    tartalia(matriu,n,m);
    escriure_matriu(matriu,n,m);
    cout<<"Tot s'ha inicialitzat perfecte?"<<endl;
    string resposta;
    cin>>resposta;
    if(resposta=="si")cout<<"Molt be"<<endl;
    else cout<<"Torna'm a programar"<<endl;
    return 0;
}
