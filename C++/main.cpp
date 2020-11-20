//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 12/11/2020
//Última modificación: 19/11/2020
//Archivo: main.cpp


#include <iostream>
#include <time.h>
using namespace std;
#include "Entidad.h"
#include "Objeto.h"
#include "Inventario.h"
#include "Heroe.h"
#include "Enemigo.h"

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
