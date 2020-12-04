//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 30/11/2020
//Última modificación: 30/11/2020
//Archivo: Inventario.cpp

/*
  Clase para representar el conjunto de objetos en poseción del jugador
  para ser utilizados
*/
#include "Inventario.h"
#include "Objeto.h"

/*
  Constructor que establece el tamaño y la capacidad del
  inventario
*/
Inventario::Inventario(){
    setTamano(0);
    setCapacidad(3);
}

/*
  Agrega un objeto al inventario para poderlo utilizar posteriormente
  @param objeto - El objeto a agregar
  @return
*/
void Inventario::agregarObjeto(Objeto *objeto){

    //Colocar objeto en la lista según el índice actual
    objetos[tamano] = objeto;

    //Cambiar estado del objeto
    objeto->setEstado("recogido");

    //Aumentar cantidad de objetos en el inventario
    tamano++;

}


/*
  Cambia el estado de un objeto del inventario a utilizado para
  que no se vuelva a usar
  @param indice - El índice del objeto en la lista de objetos
  @return
*/
void Inventario::eliminarObjeto(int i){

    //Cambiar estado a usado e indicarlo en su nombre
    objetos[i]->setEstado("usado");
    objetos[i]->setNombre(objetos[i]->getNombre()+" (usado)");

}


/*
  Despliega la lista de objetos junto con su índice, su nombre y
  su estado actual
  @param
  @return
*/
void Inventario::Abrir(){

    //Desplegar todos los objetos del inventario con su índice y nombre
    cout<<"\n---------- Tu Inventario -----------\n\n";
    for(int i = 0;i<tamano;i++){
        cout<<i+1<<".- "<<objetos[i]->getNombre()<<"\n\n";
    }
}
