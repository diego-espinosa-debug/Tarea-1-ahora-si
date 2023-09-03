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

Nodo * createNodo(void * data) {
  Nodo * nuevo = (Nodo *)malloc(sizeof(Nodo));
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

void * colapushfront(Cola * reservas, void * data){
  Nodo * nuevo = createNodo(data);
  if(reservas->head == NULL)
  {
    reservas->head = nuevo;
    reservas->tail = nuevo;
    nuevo->next = NULL;
  }else {
    nuevo->next = reservas->head;
    reservas->head = nuevo;
  }
}


void * popcurrentcola(Cola * reservas, void * data){
  reservas->current = reservas->head;
  Nodo* aux = reservas->head;
  
  if(reservas->head == reservas->tail){
    free(reservas->current);
    reservas->head = NULL;
    reservas->tail = NULL;
    reservas->current = NULL;
  }else{
    while(reservas->current != NULL){
      if(strcmp(reservas->current->NombreRes, data) == 0){
        while(aux->next != reservas->current){
           aux = aux->next;
        }
        aux->next = reservas->current->next;
        free(reservas->current);
      } 

      reservas->current = reservas->current->next;
    }
  }
  
  
}


