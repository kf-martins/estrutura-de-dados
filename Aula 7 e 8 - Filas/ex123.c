#include <stdio.h>

#include "static_fila.h"

int main(int argc, char** argv) {

    StaticFila f;
    initStaticFila(&f);

    printf("Fila inciada\nFila: ");
    printStaticFila(&f);

    for(int i = 1; i <= 5; i++) {
        printf("\nAdicionando o valor %d\nFila: ", i);
        pushStaticFila(&f, i);    
        printStaticFila(&f);
    }

    printf("\nValores adicionados na fila\nFila: ");

    printStaticFila(&f);

    printf("\nRemovendo valores na fila\n\n");
    for(int i = 1; i <= 5; i++) {
        int e = pop(&f);
        printf("\nValor removido: %d\nFila: ", e);
        printStaticFila(&f);
    }

    return 0;
}
