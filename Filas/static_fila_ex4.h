#ifndef STATIC_FILA_H
#define STATIC_FILA_H

#include <stdio.h>

#define true 1
#define false 0
#define bool int

#define MAX_FILA 50


int idCount = 1;

typedef struct Spooler {
    int id;
    int paginas;
} Spooler;

typedef Spooler ElementType;

typedef struct Fila {
    ElementType registro[MAX_FILA];
    int inicio;
    int nmroElem;

} Fila;

void initFila(Fila* f) {
    f->inicio = 0;
    f->nmroElem = 0;
}

int tamanhoFila(Fila* f) {
    return f->nmroElem;
}

void printFila(Fila* f) {
    int temp = f->inicio;
    for(int i = 0; i < f->nmroElem; i++) {
        printf("%i ", f->registro[temp]);
        temp = (temp + 1) % MAX_FILA;
    }
}

bool push(Fila* f, ElementType e) {
    if(f->nmroElem >= MAX_FILA)
        return false;

    int p = (f->inicio + f->nmroElem++) % MAX_FILA;
    f->registro[p] = e;

    idCount++;

    return true;
}

ElementType pop(Fila* f) {
    if(f->nmroElem == 0) {
        printf("Fila vazia!");
        Spooler a; a.id = 0; a.paginas = 0;
        return a;
    }

    ElementType e = f->registro[f->inicio];

    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->nmroElem--;

    return e;
}

void resetFila(Fila* f){
    initFila(f);
}

#endif