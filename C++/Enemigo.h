//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 12/11/2020
//Última modificación: 26/11/2020
//Archivo: Enemigo.h

#pragma once
#include <iostream>

using namespace std;

class Heroe;

class Enemigo: public Entidad{

    public:

        Enemigo(){
          setPosicion(rand()%50,rand()%50);
          setEstado("vivo");
          int t = rand()%3;
          switch(t){
            case 0:
              setTipo("Caballero");
              setFuerza(5);
              setVelocidad(2);
              setRango(3);
              setVida(10);
              break;
            case 1:
              setTipo("Arquero");
              setFuerza(5);
              setVelocidad(5);
              setRango(10);
              setVida(10);
              break;
            case 2:
              setTipo("Asesino");
              setFuerza(10);
              setVelocidad(6);
              setRango(7);
              setVida(8);
              break;
          }
        ;};

        void Atacar(Heroe *heroe); //Inflingir daño al héroe
        void Morir(); //Eliminar de lista de enemigos

        string getEstado(){return estado;};  //Obtener estado (vivo o muerto)
        int getIndice(){return indice;}; //Obtener índice en lista de enemigos
        string getTipo(){return tipo;}; //Obtener tipo

    private:

        void setTipo(string t){tipo = t;}; //Establecer tipo
        void setIndice(int i){indice = i;}; //Establecer índice
        void setEstado(string e){estado = e;}; //Establecer estado

        int indice; //Posición en lista de enemigos
        string tipo; //Tipo de enemigo
        string estado; //Vivo o muerto
;};
