#include <iostream>
#include <time.h>
using namespace std;
#include "Heroe.h"
#include "Enemigo.h"
#include "Objeto.h"



Heroe heroe;

Enemigo enemigos[10];
Objeto objetos[5];

int main()
{
    srand(time(NULL));
    cout<<"\n--------------------\n\n";
    cout<<heroe.getNombre()<<" ha aparecido en las coordenadas "<<heroe.getX()<<","<<heroe.getY()<<endl;
    cout<<"\n--------------------\n\n";
    for (size_t i = 0; i < 10; i++) {
      enemigos[i] = Enemigo();
      cout<<"Ha aparecido un "<<enemigos[i].getTipo()<<" en las coordenadas "<<enemigos[i].getX()<<","<<enemigos[i].getY()<<endl;
    }
    cout<<"\n--------------------\n\n";
    for (size_t i = 0; i < 5; i++) {
      objetos[i] = Objeto();
      cout<<"Ha aparecido una "<<objetos[i].getTipo()<<" en las coordenadas "<<objetos[i].getX()<<","<<objetos[i].getY()<<endl;
    }
    return 0;
}
