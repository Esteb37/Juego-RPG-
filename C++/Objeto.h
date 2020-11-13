#pragma once
#include <iostream>
using namespace std;

class Heroe;

class Objeto{

    public:

        Objeto(){
          x = rand()%50;
          y = rand()%50;
          int t = rand()%3;
          switch(t){
            case 0:
              tipo = "Poción de Vida";
              efecto = 5;
              break;
            case 1:
              tipo = "Botas de Velocidad";
              efecto = 2;
              break;
            case 2:
              tipo = "Armadura de Malla";
              efecto = 3;
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


        int indice; //Índice en lista de inventario
        float x,y; //Posición
        float efecto; //Tamaño de efecto a aplicar
        string tipo; //Tipo de objeto
;};
