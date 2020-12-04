//Proyecto de Programación Orientada a objetos
//Autor: Esteban Padilla Cerdio
//Fecha de creación: 30/11/2020
//Última modificación: 30/11/2020
//Archivo: Heroe.cpp

/*
  Clase para representar al personaje principal controlado por
  el jugador y sus interacciones con el ambiente
*/
#include "Heroe.h"
#include "Enemigo.h"

/*
  Constructor que genera un personaje con características básicas
  y posicionado al centro
*/
Heroe::Heroe(){

    //Solicitarle al jugador un nombre
    cout<<"Nombre: ";
    string n;
    cin>>n;

    //Asignar características básicas del jugador
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


/*
  Mueve al jugador en una dirección seleccionada según su velocidad
  actual y si no ha colisionado con las esquinas del mapa
  @param
  @return
*/
void Heroe::Mover(){
    while(true){

        //Solicitar la dirección hacia la que se desea mover
        cout<<"Ingresar dirección: (wasd):\n";
        char dir;
        cin>>dir;
        cin.ignore();

        //Mover al jugador según la dirección seleccionada y su velocidad
        //Si se encuentra una pared, impedir el movimiento
        switch(dir){

            //Subir
            case 'w':
                if(y-velocidad>=0) y-=velocidad;
                else cout<<"Te has encontrado con una pared.\n";
                break;

             //Bajar
            case 's':
                if(y+velocidad<=50) y+=velocidad;
                else cout<<"Te has encontrado con una pared.\n";
                break;

            //Izquierda
            case 'a':
                if(x-velocidad>=0) x-=velocidad;
                else cout<<"Te has encontrado con una pared.\n";
                break;

            //derecha
            case 'd':
                if(x+velocidad<=50) x+=velocidad;
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


/*
  Inflinge daño a un enemigo seleccionado según la fuerza del jugador
  y el rango de ataque
  @param enemigo - El objeto del enemigo a atacar
  @return
*/
void Heroe::Atacar(Enemigo *enemigo){

    //Si el enemigo se encuentra dentro del rango de ataque
    if(abs(enemigo->getX()-x)<=rango&&abs(enemigo->getY()-y)<=rango){

        //Desplegar la vida actual del enemigo
        cout<<"Vida de Enemigo #"<<enemigo->getIndice()+1<<": "<<enemigo->getVida()<<endl;

        //Inflingir daño al enemigo
        enemigo->Lastimar(fuerza);
        cout<<"¡Has atacado!"<<endl;

        //Si la vida dek enemigo se elinina por completo, eliminar de la
        //lista de enemigos vivos y aumentar el puntaje del jugador
        if(enemigo->getVida()<=0){
            cout<<"Lo has asesinado, buen trabajo.\n";
            enemigo->Morir();
            kills+=1;

            //Si el jugador obtiene diez puntos, terminar el juego
            if(kills>=10) continuar = false;
        }

        //Desplegar la vida del enemigo después del ataque, si no se ha muerto
        else cout<<"Vida de Enemigo #"<<enemigo->getIndice()+1<<": "<<enemigo->getVida()<<endl;

    }

    else cout<<"Ese enemigo está demasiado lejos.\n";
}


/*
  Obtiene y despliega los atributos básicos del enemigo seleccionado
  si está en un rango de visibilidad
  @param enemigo - El objeto del enemigo a Analizar
  @return
*/
void Heroe::Analizar(Enemigo enemigo){

    //Si el enemigo se encuentra dentro del rango de búsqueda
    if(abs(enemigo.getX()-x)<=10&&abs(enemigo.getY()-y)<=10){

        //Desplegar la información básica del enemigo
        cout<<"Enemigo #"<<enemigo.getIndice()+1<<":"<<endl;
        cout<<"Tipo: "<<enemigo.getTipo()<<endl;
        cout<<"Posición: "<<enemigo.getX()<<","<<enemigo.getY()<<endl;
        cout<<"Vida: "<<enemigo.getVida()<<endl;
        cout<<"Fuerza: "<<enemigo.getFuerza()<<endl;
    }
    else cout<<"Ese enemigo está demasiado lejos.\n";
}


/*
  Inflinge daño al jugador, restando los puntos correspondientes
  de su puntaje de vida
  @param dano - La cantidad de daño a Inflingir
  @return
*/
void Heroe::Lastimar(int dano){

    vida-=dano;

    //Si se pierde toda la salud, quitar una vida
    if(vida<=0){
        vidas--;
        cout<<"Tu salud ha caído demasiado, has perdido una vida. Te quedan "<<vidas<<"vidas.";
        vida = 40;
    }

    //Si se pierden todas las vidas, terminar juego
    if(vidas==0){
        cout<<"GAME OVER"<<endl;
        continuar = false;
    }
}


/*
  Recoge un objeto del mapa y lo coloca en el inventario para ser
  utilizado si se encuentra dentro del rango del jugador
  @param objeto - El objeto para añadir al Inventario
  @return
*/
void Heroe::Recoger(Objeto *objeto){

    //Si el objeto no se ha recogido
    if(objeto->getEstado()=="suelto"){

        //Si el objeto está dentro del rango de alcance
        if(abs(objeto->getX()-x)<=5&&abs(objeto->getY()-y)<=5){

            //Si el inventario no está lleno
            if(inventario.getTamano()<=inventario.getCapacidad())
            {
                 //Agregar objeto a inventario
                inventario.agregarObjeto(objeto);
                cout<<"Has recogido un/a "<<objeto->getNombre()<<"\n";
            }
            else cout<<"Tu inventario está lleno\n";
        }
        else cout<<"El objeto está demasiado lejos.\n";
    }
    else cout<<"Ese objeto ya no está disponible.\n";
}


/*
  Utiliza un objeto del inventario para aplicar sus efectos según
  su tipo sobre las características del jugador
  @param i - EL índice del objeto dentro del inventario
  @return
*/
void Heroe::Usar(int i){

    //Obtener el objeto del inventario
    Objeto *objeto = inventario.getObjetos()[i];

    //Si el objeto no ha sido utilizado
    if(objeto->getEstado()!="usado"){

      //Según el tipo de objeto afectar una característica del jugador
      //distinta, según la potencia del efecto
       switch(objeto->getTipo()){
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

    //Marcar objeto como usado
    inventario.eliminarObjeto(i);
}


/*
  Despliega la lista de objetos que se encuentran dentro del
  inventario con sus índices para ser utilizados
  @param
  @return
*/
void Heroe::verInventario(){

    //Abrir inventario y ver objetos
    inventario.Abrir();

}
