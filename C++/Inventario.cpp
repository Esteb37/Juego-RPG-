//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 30/11/2020
//Última modificación: 30/11/2020
//Archivo: Inventario.cpp

#include "Inventario.h"
#include "Objeto.h"

//Constructor
Inventario::Inventario(){
    setTamano(0);
    setCapacidad(3);
}

//Función para añadir objeto al inventario
void Inventario::agregarObjeto(Objeto *objeto){
    
    objetos[tamano] = objeto; //Colocar objeto en índice actual
    
    objeto->setEstado("recogido"); //Cambiar estado
    tamano++;
    
}

//Función para ver objetos en el inventario
void Inventario::Abrir(){
    
    cout<<"\n---------- Tu Inventario -----------\n\n";
    for(int i = 0;i<tamano;i++){
        cout<<i+1<<".- "<<objetos[i]->getNombre()<<"\n\n";
    }
}

//FUnción para marcar un objeto como utilizado
void Inventario::eliminarObjeto(int i){
    
    objetos[i]->setEstado("usado");
    objetos[i]->setNombre(objetos[i]->getNombre()+" (usado)");
    
}