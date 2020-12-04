/*
  Proyecto de Programación Orientada a objetos
  @Autor: Esteban Padilla Cerdio
  @Fecha de creación: 12/11/2020
  @Última modificación: 30/11/2020
  @Archivo: Heroe.h
*/

/*
  Clase para representar al personaje principal controlado por
  el jugador y sus interacciones con el ambiente
*/
#pragma once
#include <iostream>
#include "Entidad.h"
#include "Inventario.h"
using namespace std;


//Declaración a futuro de las clases utilizadas por esta clase
class Enemigo;
class Objeto;
class Inventario;


//Clase héroe hereda de Entidad
class Heroe:public Entidad{

    public:
        /*
          Constructor que genera un personaje con características básicas
          y posicionado al centro
        */
        Heroe();

        /*
          Mueve al jugador en una dirección seleccionada según su velocidad
          actual y si no ha colisionado con las esquinas del mapa
          @param
          @return
        */
        void Mover();


        /*
          Inflinge daño a un enemigo seleccionado según la fuerza del jugador
          y el rango de ataque
          @param enemigo - El objeto del enemigo a atacar
          @return
        */
        void Atacar(Enemigo *enemigo);


        /*
          Obtiene y despliega los atributos básicos del enemigo seleccionado
          si está en un rango de visibilidad
          @param enemigo - El objeto del enemigo a Analizar
          @return
        */
        void Analizar(Enemigo enemigo);


        /*
          Inflinge daño al jugador, restando los puntos correspondientes
          de su puntaje de vida
          @param dano - La cantidad de daño a Inflingir
          @return
        */
        void Lastimar(int dano);


        /*
          Recoge un objeto del mapa y lo coloca en el inventario para ser
          utilizado si se encuentra dentro del rango del jugador
          @param objeto - El objeto para añadir al Inventario
          @return
        */
        void Recoger(Objeto *objeto);


        /*
          Utiliza un objeto del inventario para aplicar sus efectos según
          su tipo sobre las características del jugador
          @param i - EL índice del objeto dentro del inventario
          @return
        */
        void Usar(int i);


        /*
          Despliega la lista de objetos que se encuentran dentro del
          inventario con sus índices para ser utilizados
          @param
          @return
        */
        void verInventario();

        /*
          Determina si el juego debería seguir con base en la Cantidad
          de enemigos eliminados y de vidas disponibles del jugador
          @param
          @return un booleano que indica si se debe continuar
        */
        bool continuarJuego(){return continuar;};

        /*
          Obtiene el nombre seleccionado por el jugador
          @param
          @return El nombre del jugador
        */
        string getNombre(){return nombre;};


    private:

      /*
        Establecer el número de vidas disponibles para el jugador
        @param v - Vidas a establecer
        @return
      */
      void setVidas(int v){vidas = v;};


      /*
        Establece el nombre del personaje elegido por el jugador
        @param n - El nombre seleccionado
        @return
      */
      void setNombre(string n){nombre = n;};


      //Número de vidas disponibles
      int vidas;
      //Nombre del jugador
      string nombre;
      //Inventario de objetos
      Inventario inventario;
      //Variable de control para indicar fin del juego
      bool continuar;
      //Enemigos eliminados
      int kills;

;};
