//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 12/11/2020
//Última modificación: 30/11/2020
//Archivo: Enemigo.h

#pragma once
#include <iostream>
#include "Entidad.h"
using namespace std;

class Heroe;

class Enemigo: public Entidad{

    public:

        Enemigo(){};
        Enemigo(int i);

        void Atacar(Heroe *heroe); //Inflingir daño al héroe
        void Morir(); //Eliminar de lista de enemigos

        string getEstado(){return estado;};  //Obtener estado (vivo o muerto)
        int getIndice(){return indice;}; //Obtener índice en lista de enemigos
        string getTipo(){return tipo;}; //Obtener tipo
        void setIndice(int i){indice = i;}; //Establecer índice
        void Mover(); //Mover al enemigo
        void Lastimar(int dano); //Inflingirse daño
        
    private:

        void setTipo(string t){tipo = t;}; //Establecer tipo
        void setEstado(string e){estado = e;}; //Establecer estado

        int indice; //Posición en lista de enemigos
        string tipo; //Tipo de enemigo
        string estado; //Vivo o muerto
;};
