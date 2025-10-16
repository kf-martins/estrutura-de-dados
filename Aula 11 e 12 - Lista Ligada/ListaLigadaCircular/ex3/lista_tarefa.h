#ifndef LISTA_TAREFA_H
#define LISTA_TAREFA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef bool
    #define bool int
    #define true 1
    #define false 0
    #define error -1
#endif

typedef struct Tarefa {
    int id;
    char descricao[100];
    int prioridade; // 1 = alta, 2 = média, 3 = baixa
} Tarefa;

typedef Tarefa TipoElemento; 

typedef struct No {
    TipoElemento chave;
    struct No* prox;
} No;

typedef struct ListaLigadaCircular {
    No* cabeca;
    int tamanho;
} ListaLigCirc;

void inicializarListaLigCirc(ListaLigCirc* l);
void freeLista(ListaLigCirc* l);
int tamanho(ListaLigCirc* l);
bool inserirOrd(ListaLigCirc* l, TipoElemento e);
bool removerTarefaId(ListaLigCirc* l, int id);
void printLista(ListaLigCirc* l);
void buscaDescricao(ListaLigCirc* l, const char* texto);

#endif