#pragma once
#include <iostream>
using namespace std;

class Heroe;

class Enemigo{

    public:

        Enemigo(){
          x = rand()%50;
          y = rand()%50;
          estado = "vivo";
          int t = rand()%3;
          switch(t){
            case 0:
              tipo = "Caballero";
              fuerza = 5;
              velocidad = 2;
              rango = 3;
              vida = 10;
              break;
            case 1:
              tipo = "Arquero";
              fuerza = 5;
              velocidad = 5;
              rango = 10;
              vida = 10;
              break;
            case 2:
              tipo = "Asesino";
              fuerza = 10;
              velocidad = 6;
              rango = 7;
              vida = 8;
          }
        ;};
        void Mover(); //Moverse a través del mapa
        void Atacar(Heroe *heroe); //Inflingir daño al héroe
        void Lastimar(float dano); //Inflingirse daño
        void Morir(); //Eliminar de lista de enemigos

        string getEstado(){return estado;};  //Obtener estado (vivo o muerto)
        int getIndice(){return indice;}; //Obtener índice en lista de enemigos
        float getVida(){return vida;}; //Obtener vida
        float getX(){return x;};
        float getY(){return y;}; //Obtener posición
        float getFuerza(){return fuerza;}; //Obtener fuerza
        int getRango(){return rango;}; //Obtener rango
        int getVelocidad(){return velocidad;}; //Obtener velocidad
        string getTipo(){return tipo;}; //Obtener tipo

    private:

        int indice; //Posición en lista de enemigos
        float vida; //Salud
        float x,y; //Posición
        float fuerza; //daño que puede realizar
        int velocidad; //Distancia que puede recorrer en un turno
        int rango; //Distancia de ataque
        string tipo; //Tipo de enemigo
        string estado; //Vivo o muerto
;};
