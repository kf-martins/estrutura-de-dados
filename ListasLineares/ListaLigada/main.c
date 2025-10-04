#include <stdio.h>

#include "lista_ligada.h"

int main(){

    ListaLigada l;
    inicializarListaLigada(&l);

    printListaLigada(&l);
 
    for(int i = 0; i <= 20; i++)
        inserir(&l, i);

    printListaLigada(&l);

    printf("\n");

    No* ant, *ind;
    for(int i = 10; i <= 15; i++){
        ind = buscaSeq(&l, i, &ant);
        printf("Next:%d Prev:%d - ", ind->prox->chave, ant->chave); 
    }

    for(int i = 10; i <= 15; i++){
        removerValor(&l, i);
    }

    printf("\n");

    printListaLigada(&l);


    return 0;
}