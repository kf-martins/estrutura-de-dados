#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
#define bool int

// #ifndef ElementType
// #define ElementType int
// #endif

typedef void* ElementType;
//se eu deixar como ponteiro, ele pode retorar qualuqer tipo -> posso atribuir um ponteiro para uma struct -> ex 8 e 9

typedef void (*PrintFunc)(ElementType); // usar isso para implementar a funcao print manualmente -> Nao tem uma funcao generalizada para printar todos os elementos

typedef struct aux {
    ElementType registro;
    struct aux* prox;
} Elemento;

typedef struct Fila {
    Elemento* inicio;
    Elemento* fim;

    int tamanho;
} Fila;

void initFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;

    f->tamanho = 0;
}

int tamanhoFila(Fila* f) {

    return f->tamanho;    
}

void printFila(Fila* f, PrintFunc printElement) {
    Elemento* end = f->inicio;
    while (end != NULL) {
        printElement(end->registro);
        end = end->prox;
    }
}

void push(Fila* f, ElementType e) {
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->registro = e;
    novo->prox = NULL;

    if(f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    f->tamanho++;
}

ElementType pop(Fila* f) {
    if(f->inicio == NULL) {
        printf("Fila vazia!");
        return NULL;
    }

    ElementType e = f->inicio->registro;
    
    Elemento* erease = f->inicio;
    f->inicio = f->inicio->prox;
    
    if(f->inicio == NULL)
        f->fim = NULL;

    free(erease);
    f->tamanho--;

    return e;
}

void resetFila(Fila* f){
    Elemento* end = f->inicio;
    while (end != NULL) {
        Elemento* erease = end;
        end = end->prox;
        free(erease);
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

#endif