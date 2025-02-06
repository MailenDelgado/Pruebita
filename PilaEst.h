#ifndef PILAEST_H_INCLUDED
#define PILAEST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAM 100


typedef struct{
    char vec[TAM];
    int tope;
}tpila;

///Primitivas PILA Estatica
void crearPilaEstatica(tpila *p);
int ponerEnPila(tpila *p, const void * dato, unsigned tam);
int sacardePila(tpila *p, void * dato, unsigned tam);
int pilaLlena(const tpila *p,unsigned tam); ///-> se asegura que hay espacio para ese dato
void vaciarpila(tpila *p);
int pilavacia(const tpila *p);
int verTope(const tpila *p, void *datotraido, unsigned tamdato);


#endif // PILAEST_H_INCLUDED
