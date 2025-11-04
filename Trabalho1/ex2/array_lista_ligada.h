#ifndef ARRAY_LISTA_LIGADA_H
#define ARRAY_LISTA_LIGADA_H

#include "lista_ligada_circular.h"

#define MAX 10

typedef struct {
    ListaLigCirc listas[MAX];
} ArrayListaLigada;

void inicializarArrayListaLigada(ArrayListaLigada* arr);

void destruirArrayListaLigada(ArrayListaLigada* arr);

bool inserirArrayListaLigada(ArrayListaLigada* arr, TipoElemento valor);

bool buscarArrayListaLigada(ArrayListaLigada* arr, TipoElemento valor);

bool removerArrayListaLigada(ArrayListaLigada* arr, TipoElemento valor);

void printArrayListaLigada(ArrayListaLigada* arr);

#endif