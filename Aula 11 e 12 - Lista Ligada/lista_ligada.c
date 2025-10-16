#include "lista_ligada.h"
#include <stdio.h> 
#include <stdlib.h>

void inicializarListaLigada(ListaLigada* l) {
    l->inicio = NULL;
    // l->inicio->ant = NULL;
}

int tamanho(ListaLigada* l){
    No* end  = l->inicio;
    int size = 0;

    while(end != NULL) {
        size++;
        end = end->prox;
    }

    return size;
}

No* buscaSeq(ListaLigada* l, TipoElemento e, No** ant) {
    No* atual = l->inicio;
    No* prev = NULL;

    while (atual != NULL && atual->chave < e) {
        prev = atual;
        atual = atual->prox;
    }

    if (ant) *ant = prev;

    if (atual != NULL && atual->chave == e)
        return atual;

    return NULL;
}

bool inserir(ListaLigada* l, TipoElemento e) {
    if(!l)
        return false;

    No *ant, *i;

    i = buscaSeq(l, e, &ant);
    if(i != NULL) 
        return false;
    
    i = (No*)malloc(sizeof(No));
    i->chave = e;

    if(ant == NULL) {
        i->prox = l->inicio;
        i->ant = NULL;
        l->inicio = i;

    } else {
        i->prox = ant->prox;
        i->ant = ant;
        ant->prox = i;

    }
    return true;
}

bool removerValor(ListaLigada* l, TipoElemento e) {
    if(!l)
        return false;

    No *i, *ant;
    i = buscaSeq(l, e, &ant);
    if(i == NULL)
        return false;
    
    if(i->ant != NULL)
        i->ant->prox = i->prox;
    else 
        l->inicio = i->prox;

    if(i->prox != NULL)
        i->prox->ant = i->ant;

    free(i);
    return true;
}

TipoElemento removerInd(ListaLigada* l, int i) {
    //TODO
}

void printListaLigada(ListaLigada* l) {
    if(!l || l->inicio == NULL) {
        printf("[]\n");
        return;
    }
    
    No* end = l->inicio;   
    
    printf("[");
    while(end->prox != NULL) {
        printf("%d, ", end->chave);    
        end = end->prox;
    }
    printf("%d]\n", end->chave);
}

