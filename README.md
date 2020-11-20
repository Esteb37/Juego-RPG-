# Proyecto
## Pensamiento Computacional para Ingeniería
### Esteban Padilla Cerdio
#### A01703068

---------------------------------------------------------

Descripción:

El siguiente proyecto utilizará la interfaz de texto de C++ para crear un videojuego tipo RPG por turnos, con un mapa que recorrer, enemigos contra los cuales luchar y objetos que recoger para mejorar las estadísticas del jugador. Este juego servirá como una demostración de la programación orientada a objetos, en conjunto con conceptos tales como herencia y polimorfismo. 

---------------------------------------------------------

Documentación:


  Heroe: -> El personaje del jugador
  
      float getX()
      float getY() //Obtener posición
      float getVida() //Obtener vida
      float getFuerza() //Obtener fuerza
      int getRango() //Obtener rango
      int getVelocidad() //Obtener velocidad

      void Lastimar(int dano) //Inflingirse daño
      void Mover(int x_, int y_) //Mover a través del mapa
      void Defender() //Aumentar defensas
      void Buscar() //Buscar enemigos en el mapa

      void Atacar(Enemigo *enemigo); //Inflingir daño a un enemigo
      void Analizar(Enemigo enemigo); //Obtener atributos del enemigo

      string getNombre(){return nombre;}; //Obtener nombre
      void agregarObjeto(Objeto *objeto); //Añadir objeto a inventario
      
  ----------------------------
  
  Enemigo: -> Entidades hostiles del juego
  
        float getX()
        float getY() //Obtener posición
        float getVida() //Obtener vida
        float getFuerza() //Obtener fuerza
        int getRango() //Obtener rango
        int getVelocidad() //Obtener velocidad

        void Lastimar(int dano) //Inflingirse daño
        void Mover(int x_, int y_) //Mover a través del mapa
        void Atacar(Heroe *heroe) //Inflingir daño al héroe
        void Morir() //Eliminar de lista de enemigos

        string getEstado(){return estado;}  //Obtener estado (vivo o muerto)
        int getIndice(){return indice;} //Obtener índice en lista de enemigos
        string getTipo(){return tipo;} //Obtener tipo
        
  ----------------------------      
  
  Objeto: -> Elemento utilizable por el jugador, que se encontrará al rededor del mapa
  
        void Recoger(Heroe *heroe) //Agrega al inventario del héroe
        void Usar(Heroe *heroe) //Aplicar efectos sobre el héroe
        void Eliminar(Heroe *heroe) //Eliminar del inventario del héroe

        string getTipo() //Obtener tipo
        int getIndice() //Obtener índice
        float getX()
        float getY() //Obtener posición
        float getEfecto() //Obtener efecto
   
  ---------------------------- 
  
  Inventario: -> Menú de objetos disponibles para el jugador tras ser recogidos
  
        void agregarObjeto(Objeto *objeto) //Añadir objeto al inventario
        void eliminarObjeto(int indice) //Eliminar objeto del inventario
        void abrir() //Mostrar objetos en el inventario
        void vaciar() //Eliminar todos los objetos

        int getTamano() //Obtener el tamaño actual del inventario
        Objeto * getObjetos() // //Obtener la lista de objetos
        int getCapacidad() //Obtener la capacidad máxima
