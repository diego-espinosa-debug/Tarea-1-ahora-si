#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

#include "list.h"
#include "cola.h"
//se define el numero maximo de caracteres permitido
#define MAXIMO 50

typedef struct{
  char ubicacion[51];
  char estado[51];
  Queue* reservas = createQueue ();
}libroSit;

typedef struct{
  char titulo[51];
  char autor[51];
  char genero[51];
  unsigned int isbn;
  libroSit situacion;
}LibroInf;

bool verificarLong(const char* ingresado){
  return(strlen(ingresado) <= MAXIMO);
}

void ingreso_de_datos_tipoChar(char* caracteres){
  do{
    
    fgets(caracteres, MAXIMO+1, stdin);
    caracteres[strlen(caracteres)-1] = 'O';
    
    if (!verificarLong(caracteres)){
      printf("Se excede el limite de caracteres permitido\n");
    }
    
  }while(!verificarLong(caracteres));
  return;
}

void inicializador(libroinf* nuevo){
  nuevo->titulo = NULL;
  nuevo->autor = NULL;
  nuevo->genero = NULL;
  nuevo->isbn = 0;
  nuevo->situacion->ubicacion = NULL;
  strcpy(nuevo->situacion->estado,"Disponible");
}


int main(void) {

  List* libros  = createList();

  
  int intruccion = 0;
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
  scanf("%d", &intruccion);
  char auxiliar[MAXIMO+1];// se usara esta varible para ingresar a la funcion que comprobara el maximo de caracteres
  switch(intruccion) {
    case 1://registrar libros
      LibroInf* nuevo = (LibroInf*) malloc(sizeof(LibroInf));

      inicializador(&nuevo);
      
    /*  scanf("%[^,]%[^,]%[^,]%u%[^,]%[^,]%[^,]", nuevo->titulo, nuevo->autor, nuevo->genero, &(nuevo->isbn), nuevo->situacion->ubicacion, nuevo->situacion->estado, nuevo->situacion->reserva);
    */  
      printf("Ingrese el titulo, autor, género, ISBN, ubicacion\n");
      ingreso_de_datos_tipoChar(nuevo->titulo);// para el titulo
      nuevo->autor = ingreso_de_datos_tipoChar(nuevo->autor);// para el autor
      nuevo->genero = ingreso_de_datos_tipoChar(nuevo->genero);// para el genero 
      scanf("%s", &(nuevo->isbn));
      nuevo->situacion->ubicacion = ingreso_de_datos_tipoChar(auxiliar);// para la ubicacion
      
      
      listpushback(libros,nuevo);
      
      break;
    case 2://mostrar datos del libro
      printf("Escribir el titulo y autor del libro que desee ver");
      
      char tituloBus[51];
      char autorBus[51] = ingreso_de_datos_tipoChar(tituloBus);
      
      tituloBus[51] = ingreso_de_datos_tipoChar(auxiliar);
        
      scanf("%50[^,]%50[^,]", tituloBus, autorBus);

      LibroInf* buscado = firstList(libros);

      if(buscado == NULL) {
        printf("Actualmente no hay libros registrados");
        return 0; //no estoy seguro si esto es buena ida (el return 0)
      }

      while(buscado != NULL){
        if(strcmp(buscado->titulo,tituloBus) == 0 && strcmp(buscado->autor,autorBus) == 0){
          printf("EL titulo del libro es %s\n", buscado->titulo);
          printf("EL autor del libro es %s\n", buscado->autor);
          printf("El genero del libro es %s\n", buscado->genero);
          printf("El ISBN del libro es %u\n", buscado->isbn);
          printf("El libro se encuentra en %s\n", buscado->situacion->ubicacion);
          printf("El estado del libro es %s\n", buscado->situacion->estado);
          //falta mostrar reservas
          break; //de nuevo, no estoy seguro
        }

        buscado = nextList(libros);
        
      }

      if(buscado == NULL){
        printf("El libro que se quiso buscar no se encuentra en la base de datos");
      }
      break;
    case 3:// mostrar todos los libros
      LibroInf* mostrar = firstList(libros);

      while(mostrar != NULL){
        printf("EL titulo del libro es %s\n", mostrar->titulo);
        printf("EL autor del libro es %s\n\n", mostrar->autor);

        mostrar = nextList(libros);
      }
      
    
      break;
    case 4:// reservar libro
      printf("Favor de escribir el titulo y autor del libro, ademas del nombre de quien desee reservar el libro\n"); 
      char tituloBus[51];
      char autorBus[51];
      char reservando[51];
      scanf("%50[^,]%50[^,]%50[^,]", tituloBus, autorBus, reservando);

      LibroInf* buscado = firstList(libros);
      
      while(buscado != NULL){
        if(strcmp(buscado->titulo,tituloBus) == 0 && trcmp(buscado->autor,autorBus) == 0){
          colapushfront(buscado->situacion->reservas,reservando);
          break;
        }
        buscado = nextList(libros);
      }

      if(buscado == NULL){
        printf("no se encontró el libro que se desea reservar\n");
      }
      
      break;
    case 5:// cancelar reserva de libro
      printf("Favor de escribir el titulo y autor del libro, ademas del nombre de quien desee cancelar la reserva del libro");            
      break;
    
    case 6:// Retirar libro
      printf("Favor de escribir el titulo y autor del libro, ademas del nombre de quien desee cancelar la reserva del libro");   
      
      break;
    case 7://devolver libro
      printf("Favor de escribir el titulo y autor del libro devuelto");   
      
      break; 
    case 8:// mostrar libros prestados

      break;
    case 9:// Importar libros desde un archivo CSV
      //insertar el codigo para recibir los archivos CSV
      printf("libros importados con exitos");
      break;
    case 10:// Exportar libros a un archivo CSV
      break;
  }
  
  return 0;
}

