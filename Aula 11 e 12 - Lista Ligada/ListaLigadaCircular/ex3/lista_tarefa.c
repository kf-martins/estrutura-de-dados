#include "lista_tarefa.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>



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
    free(l->cabeca);
    
    l->cabeca = NULL;
    l->tamanho = 0;

}

int tamanho(ListaLigCirc* l){
    return l->tamanho;
}

No* buscaSeqAuxTarefaPrioridade(ListaLigCirc* l, TipoElemento e, No** ant) {
    l->cabeca->chave.prioridade = e.prioridade;

    No* atual = l->cabeca->prox;
    *ant = l->cabeca;

    while (atual != l->cabeca && atual->chave.prioridade < e.prioridade) {
        *ant = atual;
        atual = atual->prox;
    }

    if (atual != l->cabeca && atual->chave.prioridade == e.prioridade)
        return atual;

    return NULL;
}

No* buscaSeqAuxIdTarefa(ListaLigCirc* l, int id, No** ant) {
    l->cabeca->chave.id = id;
    
    No* atual = l->cabeca->prox;
    *ant = l->cabeca;

    while (atual != l->cabeca && atual->chave.id != id) {
        *ant = atual;
        atual = atual->prox;
    }

    if (atual != l->cabeca && atual->chave.id == id)
        return atual;

    return NULL;
}

void buscaDescricao(ListaLigCirc* l, const char* texto) {
    
    No* atual = l->cabeca->prox;
    bool e = false;

    printf("===== TAREFAS ENCONTRADAS =====\n");
    while(atual != l->cabeca) {
        if(strstr(atual->chave.descricao, texto) != NULL) {
            printf("ID: %d | Prioridade: %d | Descricao: %s\n", atual->chave.id, atual->chave.prioridade, atual->chave.descricao);
            e = true;
        }
        atual = atual->prox;
    }   
    if(!e) {
        printf("Nenhuma tarefa encontrada!");
    }
    printf("============================================\n");
}


bool inserirOrd(ListaLigCirc* l, TipoElemento e) {
    No *ant, *i;
    
    i = buscaSeqAuxTarefaPrioridade(l, e, &ant); 
    // if(i != NULL) 
    //     return false;

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
    i = buscaSeqAuxTarefaPrioridade(l, e, &ant);

    if(i == NULL)
        return false;
    
    ant->prox = i->prox;
    l->tamanho--;

    free(i); 
    return true;
}

bool removerTarefaId(ListaLigCirc* l, int id) {
    if(!l)
        return false;

    No *i, *ant;
    i = buscaSeqAuxIdTarefa(l, id, &ant);
    if(i == NULL)
        return false;

 
    ant->prox = i->prox;
    l->tamanho--;

    free(i);
    return true;
}

void printLista(ListaLigCirc* l) {
    if (!l || l->cabeca->prox == l->cabeca) {
        printf("Lista de tarefas vazia.\n");
        return;
    }
    
    No* atual = l->cabeca->prox;
    printf("===== LISTA DE TAREFAS =====\n");
    while(atual != l->cabeca) {
        printf("ID: %d | Prioridade: %d | Descricao: %s\n", 
               atual->chave.id, 
               atual->chave.prioridade, 
               atual->chave.descricao);
        atual = atual->prox;
    }
    printf("=============================\n");
}

