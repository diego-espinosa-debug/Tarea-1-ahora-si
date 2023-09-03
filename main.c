#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "cola.h"
#include "list.h"

//se define el numero maximo de caracteres permitido
#define MAXIMO 50


typedef struct {
  char titulo[51];
  char autor[51];
  char genero[51];
  unsigned int isbn;
  char ubicacion[51];
  char estado[51];
  Cola* reservas;
}LibroInf;

bool verificarLong(const char* ingresado){
  return(strlen(ingresado) <= MAXIMO);
}

void ingreso_de_datos_tipoChar(char* caracteres){
  char auxiliar[MAXIMO+1];
  do{
    
    fgets(auxiliar, MAXIMO+1, stdin);
    auxiliar[strlen(caracteres)-1] = '\0';
    
    if (!verificarLong(auxiliar)){
      printf("Se excede el limite de caracteres permitido intente nuevamente\n");
    }else {
      strcpy(caracteres, auxiliar);
    }
    
  }while(!verificarLong(caracteres));
  
  return;
}


int main(void) {

  List* libros  = createList();
  int intruccion = 0;

  do{
  
    printf("Si desea registrar un libro, escriba 1\n");
    printf("Si desea ver los datos de un libro ingrese 2\n");
    printf("Si desea ver todos los libros inscritos escriba 3\n");
    printf("Si desea reservar un libro, escriba 4\n");
    printf("Si desea cancelar la reserva de un libro, escriba 5\n");
    printf("Si desea retirar un libro, escriba 6\n");
    printf("Si desea devolver un libro, escriba 7\n");
    printf("Si desea ver los libros prestados escriba 8\n");
    printf("Si desea importar libros desde un archivo CSV, escriba 9\n");
    printf("Si desea exportar libros a un archivo CSV, escriba 10\n");
    printf("Si desea terminar el programa ingrese 0");
    scanf("%d", &intruccion);

    switch(intruccion) {
      case 1://registrar libros
        
        printf("");
        LibroInf* nuevo = (LibroInf*)malloc(sizeof(LibroInf));
        nuevo->reservas = CreateQueue();
        
        printf("Ingrese el titulo\n");
        ingreso_de_datos_tipoChar(nuevo->titulo);// para el titulo
        printf("Ingrese el autor\n");
        ingreso_de_datos_tipoChar(nuevo->autor);// para el autor
        printf("Ingrese el género\n");
        ingreso_de_datos_tipoChar(nuevo->genero);// para el genero 
        printf("Ingrese el ISBN\n");
        scanf("%u", &(nuevo->isbn)); // para el isbn
        printf("Ingrese la ubicación\n");
        ingreso_de_datos_tipoChar(nuevo->ubicacion);// para la ubicacion
        
        
        listpushback(libros,nuevo);
        
        break;
      case 2://mostrar datos del libro
        
        printf("Para buscar debera ingresar el titulo y el autor\n");
        
        char tituloBus[51];
        char autorBus[51];
        
        printf("ingrese el titulo\n");
        ingreso_de_datos_tipoChar(tituloBus);
        
        printf("ingrese el autor\n");
        ingreso_de_datos_tipoChar(autorBus);

        // scanf("%50[^,]%50[^,]\n", tituloBus, autorBus); // borrar seguramente

        LibroInf* buscado = firstList(libros);

        if(buscado == NULL) {
          printf("Actualmente no hay libros registrados\n");
          return 0; //no estoy seguro si esto es buena ida (el return 0)
        }

        while(buscado != NULL){
          if(strcmp(buscado->titulo,tituloBus) == 0 && strcmp(buscado->autor,autorBus) == 0){
            printf("EL titulo del libro es %s\n", buscado->titulo);
            printf("EL autor del libro es %s\n", buscado->autor);
            printf("El genero del libro es %s\n", buscado->genero);
            printf("El ISBN del libro es %u\n", buscado->isbn);
            printf("El libro se encuentra en %s\n", buscado->ubicacion);
            printf("El estado del libro es %s\n", buscado->estado);
            //falta mostrar reservas
            break; //de nuevo, no estoy seguro
          }

          buscado = nextList(libros);
          
        }

        if(buscado == NULL){
          printf("El libro que se quiso buscar no se encuentra en la base de datos\n");
        }
        
        break;
      case 3:// mostrar todos los libros
        printf("");
        LibroInf* mostrar = firstList(libros);
        
        while(mostrar != NULL){
          printf("EL titulo del libro es %s\n", mostrar->titulo);
          printf("EL autor del libro es %s\n\n", mostrar->autor);

          mostrar = nextList(libros);
        }
        
      
        break;
      case 4:// reservar libro
        printf("Para reservar el libro tendra que escribir el titulo, autor y el nombre del estudiante\n"); 
        char tituloBus4[51];// le agregamos el 4 para que no haya un error de redefinition 
        char autorBus4[51];// le agregamos el 4 para que no haya un error de redefinition
        char reservando[51];
        printf("ingrese el titulo\n");
        ingreso_de_datos_tipoChar(tituloBus4);
        printf("ingrese el autor\n");
        ingreso_de_datos_tipoChar(autorBus4);
        printf("ingrese el nombre del estudiante que desee reservar el libro\n");
        ingreso_de_datos_tipoChar(reservando);

        LibroInf* buscado4 = firstList(libros);
        
        while(buscado != NULL){
          if(strcmp(buscado4->titulo,tituloBus4) == 0 && strcmp(buscado4->autor,autorBus4) == 0){
            colapushfront(buscado4->reservas,reservando);
            
            break;
          }
          buscado4 = nextList(libros);
        }

        if(buscado4 == NULL){
          printf("no se encontró el libro que se desea reservar\n");
        }
        
        break;
      case 5:// cancelar reserva de libro
        printf("Si desea cancelar la reserva de un libro debera escribir el titulo, autor y el nombre del estudiante\n");
        char tituloBus5[51];// le agregamos el 5 para que no haya un error de redefinition 
        char autorBus5[51];// le agregamos el 5 para que no haya un error de redefinition
        char reservando5[51];// le agregamos el 5 para que no haya un error de redefinition    
        
        printf("ingrese el titulo\n");
        ingreso_de_datos_tipoChar(tituloBus5);
        printf("ingrese el autor\n");
        ingreso_de_datos_tipoChar(autorBus5);
        printf("ingrese el nombre del estudiante que desee cancelar la reserva del libro\n");
        ingreso_de_datos_tipoChar(reservando5);

        // hay que hacer las funciones para quitar la recerva con la cola
        
        break;
      
      case 6:// retirar libro
        
        printf("Para retirar un libro habra que escribir el titulo, autor y el nombre del estudiante que desee retirar el libro\n");   

        char tituloBus6[51];// le agregamos el 6 para que no haya un error de redefinition 
        char autorBus6[51];// le agregamos el 6 para que no haya un error de redefinition
        char reservando6[51];// le agregamos el 6 para que no haya un error de redefinition         
        printf("ingrese el titulo\n");
        ingreso_de_datos_tipoChar(tituloBus6);
        printf("ingrese el autor\n");
        ingreso_de_datos_tipoChar(autorBus6);
        printf("ingrese el nombre del estudiante que desee cancelar la reserva del libro\n");
        ingreso_de_datos_tipoChar(reservando6);

        //hay que hacer las funciones para esto : Si el libro está "Disponible" o si el estudiante es el primero en la cola de reservas para un libro "Reservado", entonces el libro puede ser retirado y su estado cambia a "Prestado". Si el libro ya está "Prestado" o el estudiante no tiene prioridad, se muestra un aviso. Un libro prestado lo tiene el primer estudiante de la cola de reservas.

        
        break;
      case 7://devolver libro
        printf("Para devolver el libro se debera escribir el titulo y autor del libro devuelto\n");        char tituloBus7[51];// le agregamos el 7 para que no haya un error de redefinition 
        char autorBus7[51];// le agregamos el 7 para que no haya un error de redefinition 

        printf("ingrese el titulo\n");
        ingreso_de_datos_tipoChar(tituloBus7);
        printf("ingrese el autor\n");
        ingreso_de_datos_tipoChar(autorBus7);      

        
        break; 
      case 8:// mostrar libros prestados
        //!!!Todo el while es copiado de un mostrar todos los libros como idea, hay que codificarlo!!!!
        while(mostrar != NULL){
          printf("EL titulo del libro es %s\n", mostrar->titulo);
          printf("EL autor del libro es %s\n\n", mostrar->autor);
          printf("Se le presto al estudiante %s"); // hay que hacer el codigo para saber a quien se le presto
          mostrar = nextList(libros);// aca debera ser algo como libros->prestados o algo asi supongo
        }

        break;
      case 9:// Importar libros desde un archivo CSV
        //insertar el codigo para recibir los archivos CSV

        
        printf("libros importados con exito\n");
        break;
      case 10:// Exportar libros a un archivo CSV

        printf("Libros exportados con exito\n");
        break;

      case 0:
        printf("Gracias por utilizar este programa...");
        break;
      default:
        printf("Opcion invalida, ingrese un valor valido");
      
    }
  

  }while(intruccion != 0);

  return 0;
}

