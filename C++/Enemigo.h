//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 12/11/2020
//Última modificación: 30/11/2020
//Archivo: Enemigo.h



/*
  Clase que representa los enemigos del jugador, divididos en distintos
  tipos con características únicas
*/
#pragma once
#include <iostream>
#include "Entidad.h"
using namespace std;

//Declaración a futuro
class Heroe;


//Clase Enemigo hereda de Entidad
class Enemigo: public Entidad{

    public:

        /*
          Constructor por default vacío
        */
        Enemigo(){};


        /*
          Constructor que genera un enemigo de tipo y posición aleatorios
          y le asigna un índice según su posición en la lista de enemigos
        */
        Enemigo(int i);


        /*
          Ataca al héroe y le inflinge daño según su fuerza si éste se
          encuentra dentro del rango de ataque
          @param heroe - El objeto del héroe a atacar
          @return
        */
        void Atacar(Heroe *heroe);

        /*
          Mueve al enemigo en una dirección aleatoria según su velocidad
          @param
          @return
        */
        void Mover();


        /*
          Inflinge daño al enemigo, restando los puntos correspondientes
          de su puntaje de vida
          @param dano - La cantidad de daño a Inflingir
          @return
        */
        void Lastimar(int dano);


        /*
          Cambia el estado del enemigo a "muerto" para no ser considerado
          dentro de los enemigos que realizan acciones
          @param
          @return
        */
        void Morir();


        /*
          Obtiene el estado del enemigo, que puede ser vivo o muerto
          @param
          @return el estado actual del enemigo
        */
        string getEstado(){return estado;};


        /*
          Obtiene el índice que indica en qué posición de la lista de
          enemigos se encuentra
          @param
          @return el índice de posición
        */
        int getIndice(){return indice;};


        /*
          Obtiene el nombre del tipo de enemigo que define sus características
          @param
          @return el nombre de tipo de enemigo
        */
        string getTipo(){return tipo;};


        /*
          Establece el índice de posición del enemigo en la lista de enemigos
          @param i - El índice de posición a establecer
          @return
        */
        void setIndice(int i){indice = i;};


    private:

        /*
          Establece el tipo de enemigo
          @param t - El nombre del tipo
          @return
        */
        void setTipo(string t){tipo = t;};


        /*
          Establecer el estado actual del enemigo, ya sea vivo o muerto
          @param e - El estado del enemigo
          @return
        */
        void setEstado(string e){estado = e;};


        //Posición en lista de enemigos
        int indice;
        //Tipo de enemigo
        string tipo;
        //Vivo o muerto
        string estado;
;};
