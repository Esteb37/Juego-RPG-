# Proyecto
## Pensamiento Computacional para Ingeniería
### Esteban Padilla Cerdio
#### A01703068

---------------------------------------------------------

## Descripción:

El siguiente proyecto utilizará la interfaz de texto de C++ para crear un videojuego tipo RPG por turnos, con un mapa que recorrer, enemigos contra los cuales luchar y objetos que recoger para mejorar las estadísticas del jugador. Este juego servirá como una demostración de la programación orientada a objetos, en conjunto con conceptos tales como herencia y polimorfismo. 

---------------------------------------------------------

## Correciones:

Se colocaron todos los getters y setters correctamente en todas las clases

Se incluyó composición (entre el héroe y el inventario) y agregación (entre el inventario y los objetos) en las relaciones de clases

El estilo cumple con las normas y estándares: listar normas y estándares

---------------------------------------------------------

# Documentación:


  Heroe: -> El personaje del jugador
  
      /*
          Constructor que genera un personaje con características básicas
          y posicionado al centro
        */
        Heroe();

        /*
          Mueve al jugador en una dirección seleccionada según su velocidad
          actual y si no ha colisionado con las esquinas del mapa
          @param
          @return
        */
        void Mover();


        /*
          Inflinge daño a un enemigo seleccionado según la fuerza del jugador
          y el rango de ataque
          @param enemigo - El objeto del enemigo a atacar
          @return
        */
        void Atacar(Enemigo *enemigo);


        /*
          Obtiene y despliega los atributos básicos del enemigo seleccionado
          si está en un rango de visibilidad
          @param enemigo - El objeto del enemigo a Analizar
          @return
        */
        void Analizar(Enemigo enemigo);


        /*
          Inflinge daño al jugador, restando los puntos correspondientes
          de su puntaje de vida
          @param dano - La cantidad de daño a Inflingir
          @return
        */
        void Lastimar(int dano);


        /*
          Recoge un objeto del mapa y lo coloca en el inventario para ser
          utilizado si se encuentra dentro del rango del jugador
          @param objeto - El objeto para añadir al Inventario
          @return
        */
        void Recoger(Objeto *objeto);


        /*
          Utiliza un objeto del inventario para aplicar sus efectos según
          su tipo sobre las características del jugador
          @param i - EL índice del objeto dentro del inventario
          @return
        */
        void Usar(int i);


        /*
          Despliega la lista de objetos que se encuentran dentro del
          inventario con sus índices para ser utilizados
          @param
          @return
        */
        void verInventario();

        /*
          Determina si el juego debería seguir con base en la Cantidad
          de enemigos eliminados y de vidas disponibles del jugador
          @param
          @return un booleano que indica si se debe continuar
        */
        bool continuarJuego(){return continuar;};

        /*
          Obtiene el nombre seleccionado por el jugador
          @param
          @return El nombre del jugador
        */
        string getNombre(){return nombre;};
      
  ----------------------------
  
  Enemigo: -> Entidades hostiles del juego
  
        /*
          Constructor por default vacío
        */
        Enemigo(){};


        /*
          Constructor que genera un enemigo de tipo y posición aleatorios
          y le asigna un índice según su posición en la lista de enemigos
        */
        Enemigo(int i);


        /*
          Ataca al héroe y le inflinge daño según su fuerza si éste se
          encuentra dentro del rango de ataque
          @param heroe - El objeto del héroe a atacar
          @return
        */
        void Atacar(Heroe *heroe);

        /*
          Mueve al enemigo en una dirección aleatoria según su velocidad
          @param
          @return
        */
        void Mover();


        /*
          Inflinge daño al enemigo, restando los puntos correspondientes
          de su puntaje de vida
          @param dano - La cantidad de daño a Inflingir
          @return
        */
        void Lastimar(int dano);


        /*
          Cambia el estado del enemigo a "muerto" para no ser considerado
          dentro de los enemigos que realizan acciones
          @param
          @return
        */
        void Morir();


        /*
          Obtiene el estado del enemigo, que puede ser vivo o muerto
          @param
          @return el estado actual del enemigo
        */
        string getEstado(){return estado;};


        /*
          Obtiene el índice que indica en qué posición de la lista de
          enemigos se encuentra
          @param
          @return el índice de posición
        */
        int getIndice(){return indice;};


        /*
          Obtiene el nombre del tipo de enemigo que define sus características
          @param
          @return el nombre de tipo de enemigo
        */
        string getTipo(){return tipo;};


        /*
          Establece el índice de posición del enemigo en la lista de enemigos
          @param i - El índice de posición a establecer
          @return
        */
        void setIndice(int i){indice = i;};
        
  ----------------------------      
  
  Objeto: -> Elemento utilizable por el jugador, que se encontrará al rededor del mapa
  
        /*
          Constructor default vacío
        */
        Objeto(){};

        /*
          Constructor que asigna un tipo de objeto de forma aleatoria,
          lo coloca en una posición aleatoria en el y le asigna un índice
          según su posición en la lista de objetos
          @param i - El índice de posición
        */
        Objeto(int i);


        /*
          Obtiene el identificador del tipo del objeto
          @param
          @return el número identificador del tipo
        */
        int getTipo(){return tipo;};


        /*
          Obtiene el nombre del tipo del objeto
          @param
          @return el nombre del tipo
        */
        string getNombre(){return nombre;};


        /*
          Obtiene el índice de posición del objeto en la lista
          de objetos en el mapa
          @param
          @return el índice de posición
        */
        int getIndice(){return indice;};


        /*
          Obtiene la posición en X del objeto
          @param
          @return la coordenada en X actual
        */
        float getX(){return x;};


        /*
          Obtiene la posición en Y del objeto
          @param
          @return la coordenada en Y actual
        */
        float getY(){return y;};

        /*
          Obtiene la potencia del efecto que se está aplicando según
          sea su tipo
          @param
          @return la potencia del efecto
        */
        float getEfecto(){return efecto;};


        /*
          Asigna el índice del objeto en la lista de objetos sobre el mapa
          @param i - El índice a asignar
          @return
        */
        void setIndice(int i){indice = i;};


        /*
          Obtiene el estado actual del objeto que puede ser suelto, recogido
          o usado
          @param
          @return el estado actual del objeto
        */
        string getEstado(){return estado;};


        /*
          Asigna el estado actual del objeto que puede ser suelto, recogido
          o usado
          @param e - El estado del objeto
          @return
        */
        void setEstado(string e){estado = e;};


        /*
          Establece el nombre del objeto según sea su tipo
          @param n - El nombre a establecer
          @return
        */
        void setNombre(string n){nombre = n;};
   
  ---------------------------- 
  
  Inventario: -> Menú de objetos disponibles para el jugador tras ser recogidos
  
        /*
          Constructor que establece el tamaño y la capacidad del
          inventario
        */
        Inventario();


        /*
          Agrega un objeto al inventario para poderlo utilizar posteriormente
          @param objeto - El objeto a agregar
          @return
        */
        void agregarObjeto(Objeto *objeto);


        /*
          Cambia el estado de un objeto del inventario a utilizado para
          que no se vuelva a usar
          @param indice - El índice del objeto en la lista de objetos
          @return
        */
        void eliminarObjeto(int indice);

        /*
          Despliega la lista de objetos junto con su índice, su nombre y
          su estado actual
          @param
          @return
        */
        void Abrir();


        /*
          Regresa un apuntador al arreglo en donde se encuentran los
          objetos del jugador
          @param
          @return el apuntador al arreglo de objetos
        */
        Objeto **getObjetos(){return objetos;};


        /*
          Obtiene la cantidad de objetos en el inventario
          @param
          @return la cantidad actual de objetos en el invnetario
        */
        int getTamano(){return tamano;};


        /*
          Obtiene el número máximo de objetos que puede tener el inventario
          @param
          @return el número máximo de objetos
        */
        int getCapacidad(){return capacidad;};
