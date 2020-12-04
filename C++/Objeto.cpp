//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 30/11/2020
//Última modificación: 30/11/2020
//Archivo: Objeto.cpp


/*
  Clase para representar los objetos que el jugador puede recoger
  del suelo y utilizar para modificar sus estadísticas básicas
  de juego
*/
#include "Objeto.h"
#include "Heroe.h"

/*
  Constructor que asigna un tipo de objeto de forma aleatoria,
  lo coloca en una posición aleatoria en el y le asigna un índice
  según su posición en la lista de objetos
  @param i - El índice de posición
*/
Objeto::Objeto(int i){
  //Colocar objeto en un lugar aleatorio
  setPosicion(rand()%50,rand()%50);

  //Establecer índice en la lista de objetos del mapa
  setIndice(i);

  //Establecer tipo de objeto
  setTipo(i);

  //Establecer el tipod e objeto y su potencia según su índice
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

  //Establecer el objeto como suelto
  setEstado("suelto");
};
