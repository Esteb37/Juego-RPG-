//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 12/11/2020
//Última modificación: 30/11/2020
//Archivo: Objeto.h

#pragma once
#include <iostream>
using namespace std;

class Heroe;

class Objeto{

    public:

        Objeto(){};
        Objeto(int i);
        
        int getTipo(){return tipo;}; //Obtener tipo
        string getNombre(){return nombre;}; //Obtener nombre
        int getIndice(){return indice;}; //Obtener índice
        float getX(){return x;};
        float getY(){return y;}; //Obtener posición
        float getEfecto(){return efecto;}; //Obtener efecto
        void setIndice(int i){indice = i;}; //Establecer índice
        string getEstado(){return estado;}; //Obtener estado
        void setEstado(string e){estado = e;}; //Establecer estado
        void setNombre(string n){nombre = n;}; //Establecer nombre
        
    private:

        void setTipo(int t){tipo = t;}; //Establecer tipo
        void setPosicion(int x_,int y_){x=x_;y=y_;}; //Establecer posición
        void setEfecto(int e){efecto = e;}; //Establecer efecto
        int indice; //Índice en lista de inventario
        float x,y; //Posición
        float efecto; //Tamaño de efecto a aplicar
        int tipo; //Tipo de objeto
        string nombre; //Nombre del objeto
        string estado; //Suelto, recogido o usado
;};
