#include "cola.h"
#include <stdlib.h>
#include <assert.h>

typedef struct Nodo Nodo;

struct Nodo{
  char NombreRes[50];
  struct Nodo* next;
};

struct Queue{
  Nodo *head;
  Nodo *tail;
};

Nodo * createNode(void * data) {
  Nodo * new = (Node *)malloc(sizeof(Node));
  assert(new != NULL);
  new->data = data;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

Queue* CreateQueue(){
  //Queue* reservas =  
  
}

