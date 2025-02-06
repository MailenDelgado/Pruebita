#include "PilaEst.h"
#include <string.h>
#define PILALLENA -1
#define OK 1
#define PILAVACIA 0
#define MIN(X,Y) (X)<(Y)?(X):(Y)


void crearPilaEstatica(tpila *p){
    p->tope=TAM;
}

int ponerEnPila(tpila *p, const void * dato, unsigned tam){
    if(p->tope < (tam + sizeof(unsigned)) ){
        return PILALLENA;
    }
    ///1º debo mover el tope hacia atras, luego guardar el dato
    p->tope-=tam;

    memcpy(p->vec+p->tope, dato, tam);

    p->tope-=sizeof(unsigned);

    memcpy(p->vec+p->tope, &tam, sizeof(unsigned));

    return OK;
}

int sacardePila(tpila *p, void * dato, unsigned tam){
    if(p->tope == TAM){
        return PILAVACIA;
    }

    unsigned tamdato;
    ///traigo el peso del dato en la pila

    memcpy(&tamdato, p->vec+p->tope, sizeof(unsigned));

    p->tope+=sizeof(unsigned);

    memcpy(dato, p->vec+p->tope, MIN(tamdato,tam));

    p->tope+=tamdato; ///SI RESULTA QUE SOLO TRAJO UN PEDACITO DEL DATO IGUAL EL RESTO QUEDARÁ COMO BASURA


    return OK;
}

int pilaLlena(const tpila *p,unsigned tam){///-> se asegura que hay espacio para ese dato

        if(p->tope < tam+sizeof(tam)){
            return 1;
        }
    else
        return 0;
}

int pilavacia(const tpila *p){
    if (p->tope == TAM){
        return 1;
    }
    else
        return 0;
}

void vaciarpila(tpila *p){ ///igual a crearpila pones el tope al final
    p->tope = TAM;
}

int verTope(const tpila *p, void *datotraido, unsigned tamdato){ ///como sacar de pila pero sin modificar el tope.
    if(p->tope==TAM){
        return PILAVACIA;
    }
    unsigned tamdatopila;

    memcpy(&tamdatopila,p->vec+p->tope,sizeof(unsigned));

    memcpy(datotraido,p->vec+p->tope+sizeof(unsigned),MIN(tamdatopila,tamdato));


    return OK;

}
