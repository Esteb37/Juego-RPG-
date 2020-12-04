//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 19/11/2020
//Última modificación: 30/11/2020
//Archivo: Entidad.h


/*
  Clase virtual padre para representar una entidad viviente dentro del juego
  tal como el héroe o los enemigos.
*/
#pragma once
#include <iostream>
using namespace std;

//Clase Entidad
class Entidad{

    public:

        Entidad(){};
        
        /*
          Obtiene la posición en x
          @param
          @return la posición actual en x
        */
        float getX(){return x;};


        /*
          Obtiene la posición en y
          @param
          @return la posición actual en y
        */
        float getY(){return y;};


        /*
          Obtiene el puntaje de vida de la entidad
          @param
          @return el puntaje de vida actual
        */
        float getVida(){return vida;};


        /*
          Obtiene la fuerza de daño de la entidad
          @param
          @return el puntaje actual de fuerza
        */
        float getFuerza(){return fuerza;};


        /*
          Obtiene el rango de ataque de la entidad
          @param
          @return el puntaje de rango de ataque actual
        */
        int getRango(){return rango;};


        /*
          Obtiene la velocidad de la entidad
          @param
          @return el puntaje de velocidad actual
        */
        int getVelocidad(){return velocidad;};


    protected:

      /*
        Establece el puntaje de vida de la entidad
        @param v - El puntaje de vida a establecer
        @return
      */
      void setVida(float v){vida = v;};


      /*
        Establece el puntaje de fuerza de la entidad
        @param f - El puntaje de fuerza a establecer
        @return
      */
      void setFuerza(float f){fuerza = f;}


      /*
        Establece el puntaje de rango de la entidad
        @param r - El puntaje de rangp a establecer
        @return
      */
      void setRango(int r){rango = r;};


      /*
        Establece el puntaje de velocidad de la entidad
        @param v - El puntaje de velocidad a establecer
        @return
      */
      void setVelocidad(int v){velocidad = v;};


      /*
        Establece las coordenadas en X y Y de la entidad sobre el mapa
        @param x - La posición en x
        @param y - La posición en y
        @return
      */
      void setPosicion(int x_,int y_){x = x_;y=y_;};

      //Puntaje de salud
      float vida;

      //Posición
      float x,y;

      //Daño que puede hacer
      float fuerza;

      //Distancia de ataque
      int rango;

      //Lugares que puede recorrer en un turno
      int velocidad;

;};
