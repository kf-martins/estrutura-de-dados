#include <stdio.h>
// #include "Tarefa.c"
#include "lista_ligada_circular.c"

void printMenu() {
    printf("===== MENU =====\n");
    printf("1. Adicionar tarefa");
    printf("2. Listar tarefas");
    printf("3. Remover tarefa");
}

int main() {
    ListaLigCirc l;
    inicializarListaLigCirc(&l);

    int a = 10;
    inserirOrd(&l, a);
    inserirOrd(&l, 20);

    printListaLigCirc(&l);

    freeLista(&l);


    return 0;
}