#include "Cercle.h"

Cercle::Cercle()
//pre: cert
//post: es construeix un cercle amb els valors per defecte
{
    a_radi=1.0;
}
void Cercle::mostrar_cercle()const
//pre: cert
//post: es mostren les dades de l'objecte cercle
{
    cout<< "CENTRE: ";a_origen.mostrar();cout<<endl;
    cout<< "RADI: "<<a_radi<<endl;
}
bool Cercle::punt_dins_cercle(double x,double y)
//pre: cert
//post: es consulta si el punt entrat per teclat es troba dins del cercle creat
{
    Punt2D p(x,y);
    double dist=a_origen.dist(p);
    return (dist<=a_radi);
}
void Cercle::llegir_dades()
//pre: cert
//post: s'omplen les dades de l'objecte CERCLE entrats per teclat
{
    double radi;
    cout<< "ENTRA EL CENTRE DEL CERCLE X,Y: "<<endl;
    a_origen.llegir();
    cout<< "ENTRA EL RADI (r>0):"<<endl;
    do{
        cin>>radi;
    }while(radi==0);
    a_radi=abs(radi);
}
void Cercle::escalar_cercle()
//pre: cert
//post: es reescala la mida del cercle segons la raó entrat per teclat
{
    cout<< "ENTRA EL FACTOR D'ESCALA:"<<endl;
    double k;
    cin>>k;
    k=abs(k);
    a_radi*=k;
}
void Cercle::moure_cercle()
//pre: cert
//post: es mouen les coordenades de l'origen del cercle
{
    double x,y;
    cout<< "ENTRA EL DESPLACAMENT:"<<endl;
    cin>>x>>y;
    a_origen.desplacar(x,y);
}
