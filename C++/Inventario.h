//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 19/11/2020
//Última modificación: 26/11/2020
//Archivo: Inventario.h

#pragma once
#include <iostream>
using namespace std;

class Objeto;

class Inventario{

    public:

        Inventario(){
            setTamano(0);
            setCapacidad(5);
          }

        void agregarObjeto(Objeto *objeto); //Añadir objeto al inventario
        void eliminarObjeto(int indice); //Eliminar objeto del inventario
        void abrir(); //Mostrar objetos en el inventario
        void vaciar(); //Eliminar todos los objetos

        int getTamano(); //Obtener el tamaño actual del inventario
        Objeto * getObjetos(); // //Obtener la lista de objetos
        int getCapacidad(); //Obtener la capacidad máxima

    private:

        void setTamano(int t){tamano = t;}; //Establecer tamaño actual del invnetario
        void setCapacidad(int c){capacidad = c;}; //Establecer capacidad máxima

        int tamano;
        int capacidad;
        Objeto objetos[5];

};
