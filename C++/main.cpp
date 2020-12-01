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

const int num_objetos = 4; //Número de objetos en el mapa
const int num_enemigos = 10; //Número de enemigos en el mapa

Enemigo enemigos[num_enemigos];
Objeto objetos[num_enemigos];

int inputI; //Variable para utilizar en los inputs numéricos
string inputS; //Variable para utilizar en los inputs de texto

int main()
{
    srand(time(NULL)); //Función para evitar que los números aleatorios sean los mismos cada vez
    cout<<heroe.getNombre()<<" ha aparecido en las coordenadas "<<heroe.getX()<<","<<heroe.getY()<<"\n\n"; //Indicar que el jugador ha aparecido
    for (int i = 0; i < num_enemigos; i++) {
      enemigos[i] = Enemigo(i); //Crear los enemigos al rededor del mapa
    }
    for (int i = 0; i < num_objetos; i++) {
      objetos[i] = Objeto(i); //Crear los objetos al rededor del mapa
    }

    int turno = 0; //Contador de turnos

    cin.ignore();
    
    while(heroe.continuarJuego()){
        turno++;
        cout<<"--------------- Turno #"<<turno<<"-------------------------\n";
        cout<<"\n--------------Turno del Héroe----------------------\n\n";
        cout<<"Posición: "<<heroe.getX()<<","<<heroe.getY()<<endl; //Indicar posición actual
        cout<<"¿Qué quieres hacer?\n\nb - Buscar\na - Analizar\nx - Atacar\nm - Moverte\nr - Recoger objeto\ni - Abrir inventario\n"<<endl; //Menú de opciones
        char input;
        cin>>input;
        cin.ignore();
        
        switch(input){
            case 'b':
                //-----------Buscar--------------------
                cout<<"\n---------- Buscando Enemigos -----------\n\n";
                for(int i = 0;i<num_enemigos;i++){
                    if(enemigos[i].getEstado()=="vivo"){
                        cout<<"Enemigo #"<<i+1<<" ("<<enemigos[i].getX()<<","<<enemigos[i].getY()<<")\n"; //Publicar posiciones de todos los enemigos vivos
                    }
                }
                cout<<"\n---------- Buscando Objetos -----------\n\n";
                for(int i = 0;i<num_objetos;i++){
                    if(objetos[i].getEstado()=="suelto"){
                        cout<<"Objeto #"<<i+1<<" ("<<objetos[i].getX()<<","<<objetos[i].getY()<<")\n"; //Publicar posiciones de objetos en el suelo
                    }
                }
                break;
            case 'a':
                //-----------Analizar--------------------
                cout<<"¿A qué enemigo quieres analizar?\n";
                cin>>inputI;
                cin.ignore();
                heroe.Analizar(enemigos[inputI-1]); //Analizar enemigo
                break;
            case 'x':
                //-----------Atacar--------------------
                cout<<"¿A qué enemigo quieres atacar?\n";
                cin>>inputI;
                cin.ignore();
                heroe.Atacar(&enemigos[inputI-1]); //Atacar a enemigo
                break;
            case 'm':
                //-----------Moverse--------------------
                cout<<"Posición de : "<<heroe.getX()<<","<<heroe.getY()<<endl; //Posición actual
                heroe.Mover();
                cout<<"Posición de : "<<heroe.getX()<<","<<heroe.getY()<<endl; //Posición final
                break;
            case 'r':
                //-----------Recoger--------------------
                cout<<"¿Qué objeto deseas recoger?\n";
                cin>>inputI;
                cin.ignore();
                heroe.Recoger(&objetos[inputI-1]); //Recoger objeto
                break;
            case 'i':
                //-----------Abrir Inventario-----------
                heroe.verInventario(); //Ver objetos del inventario
                cout<<"\n¿Qué quieres hacer?\n\nu - Usar un objeto\tc - Cerrar el inventario\n";
                cin>>inputS;
                cin.ignore();
                if(inputS=="u"){
                    cout<<"\n¿Qué objeto quieres utilizar?\n";
                    cin>>inputI;
                    cin.ignore();
                    heroe.Usar(inputI-1); //Usar objeto
                }
                break;
            default:
                cout<<"Ingresa una de las opciones del menú.";
                continue;
        }

        cout<<"\nPulsa cualquier tecla para continuar...\n";
        getchar();

        cout<<"----------------Turno de Enemigos--------------------\n"<<endl;
        for(int i = 0;i<num_enemigos;i++){
            if(enemigos[i].getEstado() == "vivo"){ //Por cada uno de los enemigos vivos
                int accion = rand()%2; //Seleccionar acción aleatoriamente
                if(accion == 0){
                    enemigos[i].Atacar(&heroe); //Atacar al héroe
                }
                else if(accion == 1){
                    enemigos[i].Mover(); //Moverse de forma aleatoria
                }
            }
        }
        cout<<"\nPulsa cualquier tecla para continuar...\n";
        getchar();

    }

    cout<<"El juego ha terminado, gracias por jugar.";
    return 0;
}
