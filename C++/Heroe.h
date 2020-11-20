//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 12/11/2020
//Última modificación: 19/11/2020
//Archivo: Heroe.h

#pragma once
#include <iostream>

using namespace std;

class Enemigo;
class Objeto;
class Inventario;

class Heroe:public Entidad{

    public:
        Heroe(){
          cout<<"Nombre: ";
          string n;
          cin>>n;
          setNombre(n);
          setVida(45);
          setFuerza(5);
          setVidas(3);
          setRango(5);
          setVelocidad(5);
          setPosicion(45,45);

        ;};
        void Defender(); //Aumentar defensas
        void Buscar(); //Buscar enemigos en el mapa

        void Atacar(Enemigo *enemigo); //Inflingir daño a un enemigo
        void Analizar(Enemigo enemigo); //Obtener atributos del enemigo

        string getNombre(){return nombre;}; //Obtener nombre
        void agregarObjeto(Objeto *objeto); //Añadir objeto a inventario

    private:

      void setVidas(int v){vidas = v;}; //Establecer número de vidas
      void setNombre(string n){nombre = n;}; //Establecer nombre

      int vidas; //Número de vidas disponibles
      string nombre; //Nombre del jugador
      Inventario inventario; //Inventario de objetos
;};
