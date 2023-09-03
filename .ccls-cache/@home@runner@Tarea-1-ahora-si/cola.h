#ifndef Cola_h
#define Cola_h

typedef struct Cola Cola;

Cola * CreateQueue(void);

void * colapushfront(Cola * Cola, void * data);

int estaVacia(Cola * cola);



#endif /* Cola_h */
