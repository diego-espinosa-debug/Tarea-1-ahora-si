#include "cola.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Nodo Nodo;

struct Nodo{
  char NombreRes[50];
  struct Nodo* next;
};

struct Queue{
  Nodo *head;
  Nodo *tail;
  Nodo *current;
};

typedef Queue Queue;

Nodo * createNode(void * data) {
  Nodo * nuevo = (Nodo *)malloc(sizeof(Node));
  assert(nuevo != NULL);
  strcpy(nuevo->NombreRes,data);
  nuevo->next = NULL;
  return nuevo;
}

Queue * CreateQueue(){
  Queue * reserva = (Queue*) malloc(sizeof(Queue));
  reserva->head = NULL;
  reserva->tail = NULL;
  reserva->current = NULL;
  return reserva;
}

void * colapushfront(Queue )
 
  
}

