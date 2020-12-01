//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 12/11/2020
//Última modificación: 30/11/2020
//Archivo: Heroe.h

#pragma once
#include <iostream>
#include "Entidad.h"
#include "Inventario.h"
using namespace std;

class Enemigo;
class Objeto;
class Inventario;


class Heroe:public Entidad{

    public:
        Heroe();
        void Defender(); //Aumentar defensas
        void Buscar(); //Buscar enemigos en el mapa

        void Atacar(Enemigo *enemigo); //Inflingir daño a un enemigo
        void Analizar(Enemigo enemigo); //Obtener atributos del enemigo

        string getNombre(){return nombre;}; //Obtener nombre
    
        void Mover(); //Mover al jugador
        void Lastimar(int dano); //Inflingirse daño
        void Recoger(Objeto *objeto); //Agrega objeto al inventario 
        void Usar(int i); //Aplicar efectos sobre el héroe
        void verInventario(); //Ver objetos en el intercambio
        
        bool continuarJuego(){return continuar;}; //Saber si se cintinúa el juego o si se termina
        
    private:

      void setVidas(int v){vidas = v;}; //Establecer número de vidas
      void setNombre(string n){nombre = n;}; //Establecer nombre

      int vidas; //Número de vidas disponibles
      string nombre; //Nombre del jugador
      Inventario inventario; //Inventario de objetos
      bool continuar; //Variable de control para indicar fin del juego
      int kills;
;};
