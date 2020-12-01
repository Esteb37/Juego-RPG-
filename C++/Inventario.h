//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 19/11/2020
//Última modificación: 30/11/2020
//Archivo: Inventario.h

#pragma once
#include <iostream>
#include "Objeto.h"
using namespace std;

class Objeto;

class Inventario{

    public:

        Inventario();

        void agregarObjeto(Objeto *objeto); //Añadir objeto al inventario
        void eliminarObjeto(int indice); //Eliminar objeto del inventario
        void Abrir(); //Mostrar objetos en el inventario

        Objeto **getObjetos(){return objetos;}; // //Obtener la lista de objetos
        
        int getTamano(){return tamano;}; //Obtener tamaño
        int getCapacidad(){return capacidad;}; //Obtener capacidad
        
    private:

        void setTamano(int t){tamano = t;}; //Establecer tamaño actual del invnetario
        void setCapacidad(int c){capacidad = c;}; //Establecer capacidad máxima

        int tamano; //Tamaño actual del inventario
        int capacidad; //Capacidad total del inventario
        Objeto *objetos[3]; //Lista con objetos

};
