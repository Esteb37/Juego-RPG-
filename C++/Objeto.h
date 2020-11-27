//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 12/11/2020
//Última modificación: 26/11/2020
//Archivo: Objeto.h

#pragma once
#include <iostream>
using namespace std;

class Heroe;

class Objeto{

    public:

        Objeto(){
          setPosicion(rand()%50,rand()%50);
          int t = rand()%3;
          switch(t){
            case 0:
              setTipo("Poción de Vida");
              setEfecto(5);
              break;
            case 1:
              setTipo("Botas de Velocidad");
              setEfecto(2);
              break;
            case 2:
              setTipo("Armadura de Malla");
              setEfecto(3);
              break;
          }
        ;};
        void Recoger(Heroe *heroe); //Agrega al inventario del héroe
        void Usar(Heroe *heroe); //Aplicar efectos sobre el héroe
        void Eliminar(Heroe *heroe); //Eliminar del inventario del héroe

        string getTipo(){return tipo;}; //Obtener tipo
        int getIndice(){return indice;}; //Obtener índice
        float getX(){return x;};
        float getY(){return y;}; //Obtener posición
        float getEfecto(){return efecto;}; //Obtener efecto

    private:

        void setTipo(string t){tipo = t;}; //Establecer tipo
        void setIndice(int i){indice = i;}; //Establecer índice
        void setPosicion(int x_,int y_){x=x_;y=y_;}; //Establecer posición
        void setEfecto(int e){efecto = e;}; //Establecer efecto
        int indice; //Índice en lista de inventario
        float x,y; //Posición
        float efecto; //Tamaño de efecto a aplicar
        string tipo; //Tipo de objeto
;};
