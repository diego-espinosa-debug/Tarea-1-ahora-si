#ifndef Cola_h
#define Cola_h

typedef struct Cola Cola;

Cola * CreateQueue(void);

void * colapushfront(Cola * Cola, void * data);

void * popcurrentcola(Cola * Cola, void * data);

int * retirarcola(Cola * Cola, void * data);

int * devueltaLibro(Cola * Cola, void * data);

char * poseeLibro(Cola * Cola);

int estaVacia(Cola * cola);



#endif /* Cola_h */
