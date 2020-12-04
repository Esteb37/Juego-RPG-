/*
  Proyecto de Programación Orientada a objetos
  @Autor: Esteban Padilla Cerdio
  @Fecha de creación: 12/11/2020
  @Última modificación: 19/11/2020
  @Archivo: main.cpp
*/

#include <iostream>
#include <time.h>
using namespace std;
#include "Entidad.h"
#include "Objeto.h"
#include "Inventario.h"
#include "Heroe.h"
#include "Enemigo.h"

//objeto representativo del personaje principal del jugador
Heroe heroe;

//Cantidad de objetos al rededor del mapa
const int num_objetos = 4;

//Cantidad de enemigos al rededor del mapa
const int num_enemigos = 10;

//Contenedores para los enemigos y los objetos del mapa
Enemigo enemigos[num_enemigos];
Objeto objetos[num_enemigos];

//Variables para utilizar en los inputs;
int inputI;
string inputS;


//Interfaz principal
int main()
{
    //Se evita que los números aleatorios sean iguales en cada iteración
    //del programa
    srand(time(NULL));

    //Indicación de coordenadas de aparición del jugador
    cout<<heroe.getNombre()<<" ha aparecido en las coordenadas "<<heroe.getX()<<","<<heroe.getY()<<"\n\n";

    //Creación de los enemigos de forma aleatoria al rededor del mapa
    for (int i = 0; i < num_enemigos; i++) {
      enemigos[i] = Enemigo(i);
    }

    //Creación de los objetos al rededor del mapa
    for (int i = 0; i < num_objetos; i++) {
      objetos[i] = Objeto(i);
    }

    //Contador del turno actual
    int turno = 0;

    cin.ignore();

    //Ciclo del juego controlado por la cantidad de vidas del jugador
    //o de enemigos en el mapa
    while(heroe.continuarJuego()){

        //Comenzar turno
        turno++;
        cout<<"--------------- Turno #"<<turno<<"-------------------------\n";
        cout<<"\n--------------Turno del Héroe----------------------\n\n";

        //Indicar posición actual del jugador
        cout<<"Posición: "<<heroe.getX()<<","<<heroe.getY()<<endl;

        //Desplegar menú de opciones de acción para el jugador y solicitar
        //acción a realizar
        cout<<"¿Qué quieres hacer?\n\nb - Buscar\na - Analizar\nx - Atacar\nm - Moverte\nr - Recoger objeto\ni - Abrir inventario\n"<<endl; //Menú de opciones
        char input;
        cin>>input;
        cin.ignore();

        //Acciones
        switch(input){
          //-----------Buscar--------------------
            case 'b':

                //Realizar búsqueda de enemigos vivos al rededor del mapa y
                //publicar su índice y posición
                cout<<"\n---------- Buscando Enemigos -----------\n\n";
                for(int i = 0;i<num_enemigos;i++){
                    if(enemigos[i].getEstado()=="vivo"){
                        cout<<"Enemigo #"<<i+1<<" ("<<enemigos[i].getX()<<","<<enemigos[i].getY()<<")\n";
                    }
                }

                //Realizar búsqueda de objetos vivos al rededor del mapa y
                //publicar su índice y posición
                cout<<"\n---------- Buscando Objetos -----------\n\n";
                for(int i = 0;i<num_objetos;i++){
                    if(objetos[i].getEstado()=="suelto"){
                        cout<<"Objeto #"<<i+1<<" ("<<objetos[i].getX()<<","<<objetos[i].getY()<<")\n";
                    }
                }
                break;

            //-----------Analizar--------------------
            case 'a':

                //Selecionar al enemigo a analizar según su índice
                cout<<"¿A qué enemigo quieres analizar?\n";
                cin>>inputI;
                cin.ignore();

                //Desplegar información del enemigo analizado
                heroe.Analizar(enemigos[inputI-1]);
                break;

            //-----------Atacar--------------------
            case 'x':

                //Selecionar al enemigo a atacar según su índice
                cout<<"¿A qué enemigo quieres atacar?\n";
                cin>>inputI;
                cin.ignore();

                //Realizar daño al enemigo seleccionado
                heroe.Atacar(&enemigos[inputI-1]);
                break;

            //-----------Moverse--------------------
            case 'm':

                //Publicar posición previa al movimiento
                cout<<"Posición de : "<<heroe.getX()<<","<<heroe.getY()<<endl;

                //Mover al jugador
                heroe.Mover();

                //Publicar posición posterior al enemigo
                cout<<"Posición de : "<<heroe.getX()<<","<<heroe.getY()<<endl;
                break;

            //-----------Recoger--------------------
            case 'r':

                //Seleccionar objeto que se desea recoger y agregar al
                //inventario
                cout<<"¿Qué objeto deseas recoger?\n";
                cin>>inputI;
                cin.ignore();
                heroe.Recoger(&objetos[inputI-1]); //Recoger objeto
                break;

            //-----------Abrir Inventario-----------
            case 'i':

                //Desplegar objetos en el inventario con su índice
                heroe.verInventario();

                //Seleccionar acción a realizar con el inventario
                cout<<"\n¿Qué quieres hacer?\n\nu - Usar un objeto\tc - Cerrar el inventario\n";
                cin>>inputS;
                cin.ignore();

                //Si se requiere, seleccionar objeto a utilizar según
                //su índice
                if(inputS=="u"){
                    cout<<"\n¿Qué objeto quieres utilizar?\n";
                    cin>>inputI;
                    cin.ignore();

                    //Aplicar efecto del objeto sobre el jugador
                    heroe.Usar(inputI-1);
                }
                break;

            //Si se selecciona una opción que no está en el menú, repetir
            default:
                cout<<"Ingresa una de las opciones del menú.";
                continue;
        }

        cout<<"\nPulsa cualquier tecla para continuar...\n";
        getchar();

        //Turno de acción para los enemigos
        cout<<"----------------Turno de Enemigos--------------------\n"<<endl;

        //Por cada uno de los enemigos, tomar en cuenta solo los que están vivos
        for(int i = 0;i<num_enemigos;i++){
            if(enemigos[i].getEstado() == "vivo"){

                //Seleccionar acción a realizar de forma aleatoria
                int accion = rand()%2;

                //Inflingir daño al héroe
                if(accion == 0){
                    enemigos[i].Atacar(&heroe);
                }

                //Moverse de forma aleatoria
                else if(accion == 1){
                    enemigos[i].Mover();
                }
            }
        }
        cout<<"\nPulsa cualquier tecla para continuar...\n";
        getchar();

    }

    cout<<"El juego ha terminado, gracias por jugar.";
    return 0;
}
