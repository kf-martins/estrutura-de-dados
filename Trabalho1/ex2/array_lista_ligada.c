#include <stdio.h>
#include "array_lista_ligada.h"

int indiceLista(TipoElemento v) {
    if (v < 0) v = -v;
    return v % 10;
}

void inicializarArrayListaLigada(ArrayListaLigada* arr) {
    for (int i = 0; i < MAX; ++i) {
        inicializarListaLigCirc(&arr->listas[i]);
    }
}

void destruirArrayListaLigada(ArrayListaLigada* arr) {
    for (int i = 0; i < MAX; ++i) {
        freeLista(&arr->listas[i]);
    }
}

bool inserirArrayListaLigada(ArrayListaLigada* arr, TipoElemento valor) {
    int idx = indiceLista(valor);
    return inserirOrd(&arr->listas[idx], valor);
}

bool buscarArrayListaLigada(ArrayListaLigada* arr, TipoElemento valor) {
    int idx = indiceLista(valor);
    return buscaSentinelaOrd(&arr->listas[idx], valor) != NULL;
}

bool removerArrayListaLigada(ArrayListaLigada* arr, TipoElemento valor) {
    int idx = indiceLista(valor);
    return removerValor(&arr->listas[idx], valor);
}

void printArrayListaLigada(ArrayListaLigada* arr) {
    for (int i = 0; i < MAX; ++i) {
        printf("arr[%d] = ", i);
        printListaLigCirc(&arr->listas[i]);
    }
}
