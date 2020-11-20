//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 19/11/2020
//Última modificación: 19/11/2020
//Archivo: Entidad.h

#pragma once
#include <iostream>
using namespace std;

class Entidad{

    public:

        float getX(){return x;};
        float getY(){return y;}; //Obtener posición
        float getVida(){return vida;}; //Obtener vida
        float getFuerza(){return fuerza;}; //Obtener fuerza
        int getRango(){return rango;}; //Obtener rango
        int getVelocidad(){return velocidad;}; //Obtener velocidad

        void Lastimar(int dano); //Inflingirse daño
        void Mover(int x_, int y_); //Mover a través del mapa

    protected:


      void setVida(float v){vida = v;}; //Establecer vida
      void setFuerza(float f){fuerza = f;} //Establecer Fuerza
      void setRango(int r){rango = r;}; //Establecer Rango
      void setVelocidad(int v){velocidad = v;}; //Establecer velocidad
      void setPosicion(int x_,int y_){x = x_;y=y_;}; //Establecer posición

      float vida; //Puntaje de salud
      float x,y; //Posición
      float fuerza; //Daño que puede hacer
      int rango; //Distancia de ataque
      int velocidad; //Lugares que puede recorrer en un turno


;};
