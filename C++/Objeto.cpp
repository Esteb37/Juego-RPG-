//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 30/11/2020
//Última modificación: 30/11/2020
//Archivo: Objeto.cpp

#include "Objeto.h"
#include "Heroe.h"

//Constructor
Objeto::Objeto(int i){
  setPosicion(rand()%50,rand()%50); //Colocar objeto en un lugar aleatorio
  setIndice(i);
  setTipo(i);
  switch(i){
    case 0:
      setNombre("Poción de Vida");
      setEfecto(10);
      break;
    case 1:
      setNombre("Botas de Velocidad");
      setEfecto(2);
      break;
    case 2:
      setNombre("Arco de Distancia");
      setEfecto(3);
      break;
    case 3:
      setNombre("Espada de Poder");
      setEfecto(5);
      break;
  }
  setEstado("suelto");
};
       