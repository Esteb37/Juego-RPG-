//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 30/11/2020
//Última modificación: 30/11/2020
//Archivo: Heroe.cpp


#include "Heroe.h"
#include "Enemigo.h"

//Constructor
Heroe::Heroe(){

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
    continuar = true;
    kills = 0;
}
//Función para mover al jugador
void Heroe::Mover(){
    while(true){
        cout<<"Ingresar dirección: (wasd):\n";
        char dir;
        cin>>dir;
        cin.ignore();
        switch(dir){

            case 'w':
                if(y-velocidad>=0) y-=velocidad; //Subir 
                else cout<<"Te has encontrado con una pared.\n";
                break;
            case 's':
                if(y+velocidad<=50) y+=velocidad; //Bajar
                else cout<<"Te has encontrado con una pared.\n";
                break;
            case 'a':
                if(x-velocidad>=0) x-=velocidad; //Izquierda
                else cout<<"Te has encontrado con una pared.\n";
                break;
            case 'd':
                if(x+velocidad<=50) x+=velocidad; //derecha
                else cout<<"Te has encontrado con una pared.\n";
                break;
            default:
                cout<<"Utiliza las teclas WASD";
                continue;
                break;
        };
        break;
    }
}

//Función para atacar a un enemigo
void Heroe::Atacar(Enemigo *enemigo){

    if(abs(enemigo->getX()-x)<=rango&&abs(enemigo->getY()-y)<=rango){ //Si el enemigo se encuentra dentro del rango de ataque
        cout<<"Vida de Enemigo #"<<enemigo->getIndice()+1<<": "<<enemigo->getVida()<<endl; //Vida actual del enemigo
        enemigo->Lastimar(fuerza); //Inflingir daño al enemigo
        cout<<"¡Has atacado!"<<endl;
        if(enemigo->getVida()<=0){
            cout<<"Lo has asesinado, buen trabajo.\n";
            enemigo->Morir(); //Eliminar al enemigo de la lista de enemigos vivos
            kills+=1;
            if(kills>=10) continuar = false;
        }
        else cout<<"Vida de Enemigo #"<<enemigo->getIndice()+1<<": "<<enemigo->getVida()<<endl; //Vida final del enemigo
        
    }
    else cout<<"Ese enemigo está demasiado lejos.\n";
}

//Función para analizar características de un enemigo
void Heroe::Analizar(Enemigo enemigo){

    if(abs(enemigo.getX()-x)<=10&&abs(enemigo.getY()-y)<=10){ //Si el enemigo se encuentra dentro del rango de búsqueda
        cout<<"Enemigo #"<<enemigo.getIndice()+1<<":"<<endl;
        cout<<"Tipo: "<<enemigo.getTipo()<<endl;
        cout<<"Posición: "<<enemigo.getX()<<","<<enemigo.getY()<<endl;
        cout<<"Vida: "<<enemigo.getVida()<<endl;
        cout<<"Fuerza: "<<enemigo.getFuerza()<<endl;
    }
    else cout<<"Ese enemigo está demasiado lejos.\n";
}

//Función para causar daño al enemigo
void Heroe::Lastimar(int dano){

    vida-=dano;
    
    if(vida<=0){ //Si se pierde toda la salud, quitar una vida
        vidas--;
        cout<<"Tu salud ha caído demasiado, has perdido una vida. Te quedan "<<vidas<<"vidas.";
        vida = 40;
    }

    if(vidas==0){ //Si se pierden todas las vidas, terminar juego
        cout<<"GAME OVER"<<endl;
        continuar = false;
    }


}


//Función para ver inventario
void Heroe::verInventario(){
 
    inventario.Abrir(); //Abrir inventario y ver objetos
    
}


//Función para recoger objeto
void Heroe::Recoger(Objeto *objeto){
    if(objeto->getEstado()=="suelto"){ //Si el objeto no se ha recogido
        if(abs(objeto->getX()-x)<=5&&abs(objeto->getY()-y)<=5){ //Si el objeto está dentro del rango de alcance
            if(inventario.getTamano()<=inventario.getCapacidad()) //Si el inventario no está lleno
            {
                inventario.agregarObjeto(objeto); //Agregar objeto a inventario
                cout<<"Has recogido un/a "<<objeto->getNombre()<<"\n";
            }
            else cout<<"Tu inventario está lleno\n";
        }
        else cout<<"El objeto está demasiado lejos.\n";
    }
    else cout<<"Ese objeto ya no está disponible.\n";
}


//Función para usar objeto
void Heroe::Usar(int i){
    Objeto *objeto = inventario.getObjetos()[i]; //Obtener el objeto del inventario
    
    if(objeto->getEstado()!="usado"){ //Si el objeto no ha sido utilizado
       switch(objeto->getTipo()){ //Según el tipo de objeto realizar una acción diferente
        case 0:
            vida+=objeto->getEfecto();
            cout<<"\nSe te ha otorgado "<<objeto->getEfecto()<<" de vida. Tu vida ahora es "<<vida<<"\n";
            break;
        case 1:
            velocidad+=objeto->getEfecto();
            cout<<"\nSe te ha otorgado "<<objeto->getEfecto()<<" de velocidad. Tu velocidad ahora es "<<velocidad<<"\n";
            break;
        case 2:
            rango+=objeto->getEfecto();
            cout<<"\nSe te ha otorgado "<<objeto->getEfecto()<<" de rango. Tu rango ahora es "<<rango<<"\n";
            break;
        case 3:
            fuerza+=objeto->getEfecto();
            cout<<"\nSe te ha otorgado "<<objeto->getEfecto()<<" de fuerza. Tu fuerza ahora es "<<fuerza<<"\n";
            break;
        }
    }
    else cout<<"Ese objeto ya ha sido utilizado\n";
    inventario.eliminarObjeto(i); //Marcar objeto como usado
}
