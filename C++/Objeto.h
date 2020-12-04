//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 12/11/2020
//Última modificación: 30/11/2020
//Archivo: Objeto.h

/*
  Clase para representar los objetos que el jugador puede recoger
  del suelo y utilizar para modificar sus estadísticas básicas
  de juego
*/
#pragma once
#include <iostream>
using namespace std;


//Declaración a futuro
class Heroe;


//Clase objeto
class Objeto{

    public:

        /*
          Constructor default vacío
        */
        Objeto(){};

        /*
          Constructor que asigna un tipo de objeto de forma aleatoria,
          lo coloca en una posición aleatoria en el y le asigna un índice
          según su posición en la lista de objetos
          @param i - El índice de posición
        */
        Objeto(int i);


        /*
          Obtiene el identificador del tipo del objeto
          @param
          @return el número identificador del tipo
        */
        int getTipo(){return tipo;};


        /*
          Obtiene el nombre del tipo del objeto
          @param
          @return el nombre del tipo
        */
        string getNombre(){return nombre;};


        /*
          Obtiene el índice de posición del objeto en la lista
          de objetos en el mapa
          @param
          @return el índice de posición
        */
        int getIndice(){return indice;};


        /*
          Obtiene la posición en X del objeto
          @param
          @return la coordenada en X actual
        */
        float getX(){return x;};


        /*
          Obtiene la posición en Y del objeto
          @param
          @return la coordenada en Y actual
        */
        float getY(){return y;};

        /*
          Obtiene la potencia del efecto que se está aplicando según
          sea su tipo
          @param
          @return la potencia del efecto
        */
        float getEfecto(){return efecto;};


        /*
          Asigna el índice del objeto en la lista de objetos sobre el mapa
          @param i - El índice a asignar
          @return
        */
        void setIndice(int i){indice = i;};


        /*
          Obtiene el estado actual del objeto que puede ser suelto, recogido
          o usado
          @param
          @return el estado actual del objeto
        */
        string getEstado(){return estado;};


        /*
          Asigna el estado actual del objeto que puede ser suelto, recogido
          o usado
          @param e - El estado del objeto
          @return
        */
        void setEstado(string e){estado = e;};


        /*
          Establece el nombre del objeto según sea su tipo
          @param n - El nombre a establecer
          @return
        */
        void setNombre(string n){nombre = n;};

    private:

        /*
          Establece el tipo del objeto para definir sus efectos y su nombre
          @param t - El tipo a establecer
          @return
        */
        void setTipo(int t){tipo = t;};

        /*
          Establece las coordenadas del objeto en el mapa
          @param x - La posición en X
          @param y - La posición en Y
          @return
        */
        void setPosicion(int x_,int y_){x=x_;y=y_;};


        /*
          Establece la potencia del efecto del objeto
          @param e - La potencia a establecer
          @return
        */
        void setEfecto(int e){efecto = e;};


        //Índice en lista de inventario
        int indice;
        //Posición
        float x,y;
        //Tamaño de efecto a aplicar
        float efecto;
        //Tipo de objeto
        int tipo;
        //Nombre del objeto
        string nombre;
        //Suelto, recogido o usado
        string estado;

;};
