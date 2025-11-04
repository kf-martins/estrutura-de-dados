#ifndef LISTA_LIGADA_CIRCULAR_H
#define LISTA_LIGADA_CIRCULAR_H

#ifndef bool
    #define bool int
    #define true 1
    #define false 0
    #define error -1
#endif

typedef int TipoElemento; 

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

No* buscaSeq(ListaLigCirc* l, TipoElemento e, No** ant);
No* buscaSentinela(ListaLigCirc* l, TipoElemento e);
No* buscaSentinelaOrd(ListaLigCirc* l, TipoElemento e);

bool inserirOrd(ListaLigCirc* l, TipoElemento e);

bool removerValor(ListaLigCirc* l, TipoElemento e);

TipoElemento removerInd(ListaLigCirc* l, int i);

void printListaLigCirc(ListaLigCirc* l);


#endif