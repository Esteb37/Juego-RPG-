//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 30/11/2020
//Última modificación: 30/11/2020
//Archivo: Enemigo.cpp

/*
  Clase que representa los enemigos del jugador, dividiso en distintos
  tipos con características únicas
*/
#include "Enemigo.h"
#include "Heroe.h"


/*
  Constructor que genera un enemigo de tipo y posición aleatorios
  y le asigna un índice según su posición en la lista de enemigos
*/
Enemigo::Enemigo(int i){
   //Colocar posición en un lugar aleatorio
  setPosicion(rand()%50,rand()%50);

  //Establecer estado actual como vivo
  setEstado("vivo");

  //Establecer índice en la lista de enemigos
  setIndice(i);
  int t = rand()%3;

 //Determinar el tipo de enemigo de forma aleatoria y asignar
 //sus características según lo seleccionado
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
}


/*
  Ataca al héroe y le inflinge daño según su fuerza si éste se
  encuentra dentro del rango de ataque
  @param heroe - El objeto del héroe a atacar
  @return
*/
void Enemigo::Atacar(Heroe *heroe){

  //Indicar que se realiza la acción de ataque
  cout<<"Enemigo #"<<indice+1<<" ha atacado. ";

   //Si el héroe se encuentra en el rango de ataque, inflingirle daño
  if(abs(heroe->getX()-x)<=rango&&abs(heroe->getY()-y)<=rango){
     heroe->Lastimar(fuerza);

     //Indicar ataque y vida restante
     cout<<"Te ha hecho "<<fuerza<<" de daño. Tu vida restante es "<<heroe->getVida()<<endl;
  }
  else{
      cout<<"Ha fallado."<<endl;
  }

}


/*
  Mueve al enemigo en una dirección aleatoria según su velocidad
  @param
  @return
*/
void Enemigo::Mover(){

    //Indicar movimiento
    cout<<"Enemigo #"<<indice+1<<" se ha movido."<<endl;

    //Definir dirección aleatoriamente
    int dir = rand()%4;

    //Mover hacia la dirección seleccionada según sea su velocidad
    switch(dir){

        //Arriba
        case 0:
            y-=velocidad;
            break;

        //Abajo
        case 1:
            y+=velocidad;
            break;

        //Izquierda
        case 2:
            x-=velocidad;
            break;

        //Derecha
        case 3:
            x+=velocidad;
            break;
    }

}


/*
  Inflinge daño al enemigo, restando los puntos correspondientes
  de su puntaje de vida
  @param dano - La cantidad de daño a Inflingir
  @return
*/
void Enemigo::Lastimar(int dano){

    vida-=dano;

}


/*
  Cambia el estado del enemigo a "muerto" para no ser considerado
  dentro de los enemigos que realizan acciones
  @param
  @return
*/
void Enemigo::Morir(){
    setEstado("muerto");
}
