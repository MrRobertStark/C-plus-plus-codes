#include <iostream>
using namespace std;

int main(){

    cout.setf(ios::fixed);
    cout.precision(2);
    cout<< "Preu venda [> 0]: ";
    double preu_venda;
    cin>> preu_venda;
    cout<< "% IVA [>= 0]: ";
    double impost;
    cin>>impost;
    double import_base = preu_venda/(1+impost/100);
    double import_impost = preu_venda-import_base;
    double import_total = preu_venda;
    cout<< "Import base: "<<import_base<<endl;
    cout<< "Import " << impost<< "% IVA: "<<import_impost<<endl;
    cout<< "Import total: "<<import_total<<endl;
    return 0;

}
