#include "cola.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct Nodo Nodo;

struct Nodo{
  char NombreRes[50];
  struct Nodo* next;
};

struct Cola{
  Nodo *head;
  Nodo *tail;
  Nodo *current;
};

typedef struct Cola Cola;

Nodo * createNode(void * data) {
  Nodo * nuevo = (Nodo *)malloc(sizeof(Node));
  assert(nuevo != NULL);
  strcpy(nuevo->NombreRes,data);
  nuevo->next = NULL;
  return nuevo;
}

Cola * CreateQueue(){
  Cola * reserva = (Cola*) malloc(sizeof(Cola));
  reserva->head = NULL;
  reserva->tail = NULL;
  reserva->current = NULL;
  return reserva;
}

/*void * colapushfront(Queue )
 
  
}*/

