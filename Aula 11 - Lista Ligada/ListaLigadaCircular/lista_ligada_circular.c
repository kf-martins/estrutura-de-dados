#include "lista_ligada_circular.h"
#include <stdio.h> 
#include <stdlib.h>


void inicializarListaLigCirc(ListaLigCirc* l) {
    l->cabeca = (No*)malloc(sizeof(No));
    l->cabeca->prox = l->cabeca;

    l->tamanho = 0;
}

void freeLista(ListaLigCirc* l) {
    No* end = l->cabeca->prox;

    while(end != l->cabeca) {
        No* erease = end;
        erease = end;
        end = end->prox;
        free(erease);
    }

    l->cabeca->prox = l->cabeca;
}


int tamanho(ListaLigCirc* l){
    return l->tamanho;
    
    // No* end  = l->cabeca->prox;
    // int size = 0;

    // while(end != l->cabeca){
    //     size++;
    //     end = end->prox;
    // }

    // return size;
}

No* buscaSentinela(ListaLigCirc* l, TipoElemento e) {
    No* atual = l->cabeca->prox;

    l->cabeca->chave = e;

    while(atual->chave != e) 
        atual = atual->prox;

    if(atual != l->cabeca)
        return atual;

    return NULL;
}

No* buscaSentinelaOrd(ListaLigCirc* l, TipoElemento e) {
    No* atual = l->cabeca->prox;
    l->cabeca->chave = e;

    while(atual->chave < e) 
        atual = atual->prox;

    if(atual != l->cabeca)
        return atual;

    return NULL;
}

No* buscaSeqAux(ListaLigCirc* l, TipoElemento e, No** ant) {
    
    No* atual = l->cabeca->prox;
    *ant = l->cabeca;

    while (atual != NULL && atual->chave < e) {
        *ant = atual;
        atual = atual->prox;
    }

    if (atual != l->cabeca && atual->chave == e)
        return atual;

    return NULL;
}


bool inserirOrd(ListaLigCirc* l, TipoElemento e) {
    No *ant, *i;
    
    i = buscaSeqAux(l, e, &ant); 
    if(i != NULL)
        return false;

    i = (No*) malloc(sizeof(No));
    i->chave = e;
    
    i->prox = ant->prox;
    ant->prox = i;

    l->tamanho++;
    return true;
}

bool removerValor(ListaLigCirc* l, TipoElemento e) {
    if(!l)
        return false;

    No *i, *ant;
    i = buscaSeqAux(l, e, &ant);

    if(i == NULL)
        return false;
    
    ant->prox = i->prox;
    l->tamanho--;

    free(i); 
    return true;
}

void printListaLigCirc(ListaLigCirc* l) {
    if(!l || l->cabeca->prox == l->cabeca) {
        printf("[]\n");
        return;
    }
    
    No* end = l->cabeca->prox;   
    
    printf("[");
    while(end->prox != l->cabeca) {
        printf("%d, ", end->chave);    
        end = end->prox;
    }
    printf("%d]\n", end->chave);
}

