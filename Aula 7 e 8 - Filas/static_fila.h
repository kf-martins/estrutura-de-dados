#ifndef STATIC_FILA_H
#define STATIC_FILA_H

#include <stdio.h>

#define true 1
#define false 0
#define bool int

#define MAX_FILA 500000

typedef int ElementType;

typedef struct StaticFila {
    ElementType registro[MAX_FILA];
    int inicio;
    int nmroElem;

} StaticFila;

void initStaticFila(StaticFila* f) {
    f->inicio = 0;
    f->nmroElem = 0;
}

int tamanhoStaticFila(StaticFila* f) {
    return f->nmroElem;
}

void printStaticFila(StaticFila* f) {
    int temp = f->inicio;
    for(int i = 0; i < f->nmroElem; i++) {
        printf("%i ", f->registro[temp]);
        temp = (temp + 1) % MAX_FILA;
    }
}

bool pushStaticFila(StaticFila* f, ElementType e) {
    if(f->nmroElem >= MAX_FILA)
        return false;

    int p = (f->inicio + f->nmroElem++) % MAX_FILA;
    f->registro[p] = e;

    return true;
}

ElementType popStaticFila(StaticFila* f) {
    if(f->nmroElem == 0) {
        printf("Fila vazia!");
        return -1;
    }

    ElementType e = f->registro[f->inicio];

    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->nmroElem--;

    return e;
}

void resetStaticFila(StaticFila* f){
    initStaticFila(f);
}

#endif