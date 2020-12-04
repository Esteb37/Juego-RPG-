//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 19/11/2020
//Última modificación: 30/11/2020
//Archivo: Inventario.h

/*
  Clase para representar el conjunto de objetos en poseción del jugador
  para ser utilizados
*/
#pragma once
#include <iostream>
#include "Objeto.h"
using namespace std;


//Declaración a futuro
class Objeto;


//Clase Inventario
class Inventario{

    public:
        /*
          Constructor que establece el tamaño y la capacidad del
          inventario
        */
        Inventario();


        /*
          Agrega un objeto al inventario para poderlo utilizar posteriormente
          @param objeto - El objeto a agregar
          @return
        */
        void agregarObjeto(Objeto *objeto);


        /*
          Cambia el estado de un objeto del inventario a utilizado para
          que no se vuelva a usar
          @param indice - El índice del objeto en la lista de objetos
          @return
        */
        void eliminarObjeto(int indice);

        /*
          Despliega la lista de objetos junto con su índice, su nombre y
          su estado actual
          @param
          @return
        */
        void Abrir();


        /*
          Regresa un apuntador al arreglo en donde se encuentran los
          objetos del jugador
          @param
          @return el apuntador al arreglo de objetos
        */
        Objeto **getObjetos(){return objetos;};


        /*
          Obtiene la cantidad de objetos en el inventario
          @param
          @return la cantidad actual de objetos en el invnetario
        */
        int getTamano(){return tamano;};


        /*
          Obtiene el número máximo de objetos que puede tener el inventario
          @param
          @return el número máximo de objetos
        */
        int getCapacidad(){return capacidad;};

    private:

        /*
          Establece la cantidad de objetos actuales que tiene el inventario
          @param t - La cantidad de objetos
          @return
        */
        void setTamano(int t){tamano = t;};

        /*
          Establece la capacidad máxima del inventario
          @param c - La capacidad máxima a establecer
          @return
        */
        void setCapacidad(int c){capacidad = c;};

        //Tamaño actual del inventario
        int tamano;

        //Capacidad total del inventario
        int capacidad;

        //Lista con objetos
        Objeto *objetos[3];


};
