#include <iostream>
using namespace std;

//aquest programa mesura el canvi, el descompte i el preu final d'un producte
int main(){
cout << "preu?" << endl;
double preu_inicial;
cin >> preu_inicial;
cout << "Quin descompte vols aplicar?" << endl;
int descompte;
cin >> descompte;
cout << "Quant t'han pagat?" << endl;
double paga;
cin >> paga;
double preu_final = preu_inicial - (preu_inicial*descompte/100);
double canvi = paga - preu_final;
cout << "El preu final són  " << preu_final << " euros" << "i li has de tornar " << canvi << " euros."<<endl;

return 0;
}
