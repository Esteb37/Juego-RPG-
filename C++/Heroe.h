#pragma once
#include <iostream>
using namespace std;

class Enemigo;
class Objeto;

class Heroe{

    public:
        Heroe(){
          cout<<"Nombre: ";
          cin>>nombre;
          vida = 40;
          fuerza = 5;
          vidas = 3;
          rango = 5;
          velocidad = 5;
          x = 25;
          y = 25;
        ;};
        void Defender(); //Aumentar defensas
        void Buscar(); //Buscar enemigos en el mapa
        void Mover(); //Mover a través del mapa
        void Lastimar(int dano); //Inflingirse daño

        void Atacar(Enemigo *enemigo); //Inflingir daño a un enemigo
        void Analizar(Enemigo enemigo); //Obtener atributos del enemigo

        float getVida(){return vida;}; //Obtener vida
        float getX(){return x;};
        float getY(){return y;}; //Obtener posición
        float getFuerza(){return fuerza;}; //Obtener fuerza
        int getRango(){return rango;}; //Obtener rango
        int getVelocidad(){return velocidad;}; //Obtener velocidad
        string getNombre(){return nombre;}; //Obtener nombre


    private:
      int vidas; //Número de vidas disponibles
      float vida; //Puntaje de salud
      float x,y; //Posición
      float fuerza; //Daño que puede hacer
      int rango; //Distancia de ataque
      int velocidad; //Lugares que puede recorrer en un turno
      string nombre; //Nombre del jugador
      //Objeto inventario[3]; //Inventario de objetos
;};
