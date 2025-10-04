#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#ifndef bool
    #define bool int
    #define true 1
    #define false 0
    #define error -1
#endif

// typedef void* TipoElemento;k
typedef int TipoElemento; //fazer primeiro com int e depois generalizo.

typedef struct No {
    TipoElemento chave;
    struct No* prox;
    struct No* ant;

} No;

typedef struct ListaLigada {
    No* inicio;

} ListaLigada;

void inicializarListaLigada(ListaLigada* l);

int tamanho(ListaLigada* l);

No* buscaSeq(ListaLigada* l, TipoElemento e, No** ant);

bool inserir(ListaLigada* l, TipoElemento e);

bool removerValor(ListaLigada* l, TipoElemento e);

TipoElemento removerInd(ListaLigada* l, int i); // TODO

void printListaLigada(ListaLigada* l);


#endif