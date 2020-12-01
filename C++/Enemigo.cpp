//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 30/11/2020
//Última modificación: 30/11/2020
//Archivo: Enemigo.cpp

#include "Enemigo.h"
#include "Heroe.h"

//Constructor
Enemigo::Enemigo(int i){
  setPosicion(rand()%50,rand()%50); //Colocar en un lugar aleatorio
  setEstado("vivo");
  setIndice(i);
  int t = rand()%3; //Determinar el tipo de enemigo de forma aleatoria
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


//Función para mover al enemigo de forma aleatoria
void Enemigo::Mover(){

    cout<<"Enemigo #"<<indice+1<<" se ha movido."<<endl;
    int dir = rand()%4; //Definir dirección aleatoriamente

    switch(dir){

        case 0://arriba
            y-=velocidad;
            break;
        case 1://abajo
            y+=velocidad;
            break;
        case 2://izquierda
            x-=velocidad;
            break;
        case 3://derecha
            x+=velocidad;
            break;
    }

}

//Función para inflingir daño sobre el enemigo
void Enemigo::Lastimar(int dano){

    vida-=dano;

}

//Función para atacar al héroe
void Enemigo::Atacar(Heroe *heroe){

  cout<<"Enemigo #"<<indice+1<<" ha atacado. ";
  if(abs(heroe->getX()-x)<=rango&&abs(heroe->getY()-y)<=rango){ //Si el héroe se encuentra en el rango de ataque 

     heroe->Lastimar(fuerza); //Inflingir daño
     cout<<"Te ha hecho "<<fuerza<<" de daño. Tu vida restante es "<<heroe->getVida()<<endl;
  }
  else{
      cout<<"Ha fallado."<<endl;
  }

}

//Función para marcar enemigo como muerto
void Enemigo::Morir(){
    setEstado("muerto");
}
