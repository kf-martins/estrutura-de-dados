#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"

typedef struct Paciente {
    char nome[25];
    char sintoma[100];
    int prioridade;
} Paciente;

void adicionarPaciente(Fila* filaAlta, Fila* filaBaixa) {
    printf("== Adicionando paciente ==\n");

    Paciente* p = (Paciente*)malloc(sizeof(Paciente));
    char n[25], sintome[100];
    int prioridade;

    printf("Digite o nome do paciente: ");
    fgets(n, sizeof(n), stdin);
    n[strcspn(n, "\n")] = '\0';

    printf("Digite o sintoma do paciente: ");
    fgets(sintome, sizeof(sintome), stdin);
    sintome[strcspn(sintome, "\n")] = '\0';

    do {
        printf("Prioridade (1 = alta, 0 = baixa): ");
        scanf("%d", &prioridade);
        while(getchar() != '\n');
    } while (prioridade != 0 && prioridade != 1);
 
    strcpy(p->nome, n);
    strcpy(p->sintoma, sintome);
    p->prioridade = prioridade;

    if (prioridade == 1) {
        push(filaAlta, p);
        printf("Paciente com prioridade ALTA adicionado!\n");
    } else {
        push(filaBaixa, p);
        printf("Paciente com prioridade BAIXA adicionado!\n");
    }
}

void atenderPaciente(Fila* filaAlta, Fila* filaBaixa) {
    Paciente *p = NULL;
    if (tamanhoFila(filaAlta) > 0) {
        p = (Paciente*)pop(filaAlta);
        printf("Atendendo paciente (prioridade alta): %s - %s\n", p->nome, p->sintoma);
    } else if (tamanhoFila(filaBaixa) > 0) {
        p = (Paciente*)pop(filaBaixa);
        printf("Atendendo paciente (prioridade baixa): %s - %s\n", p->nome, p->sintoma);
    } else {
        printf("Nenhum paciente na fila!\n");
    }

    if(p != NULL) free(p); //double free or corruption (out)
}

void printElement(ElementType e) {
    Paciente* p = (Paciente*)e;
    printf("%s - %s\n", p->nome, p->sintoma);
}

void exibirFila(Fila* fa, Fila* fb) {
    printf("\n== Exibindo filas ==\n");

    printf("Fila de prioridade alta:\n");
    printFila(fa, printElement);
    printf("\nFila de prioridade baixa:\n");    
    printFila(fb, printElement);
}

int main(int argc, char **argv) {
    Fila filaAlta, filaBaixa;
    initFila(&filaAlta);
    initFila(&filaBaixa);

    int opcao;
    do {
        printf("\n1 - Adicionar paciente\n2 - Atender paciente\n3 - Mostrar filas\n0 - Sair\nOpcao: ");
        scanf("%d", &opcao);
        while(getchar() != '\n');

        switch(opcao) {
            case 1:
                adicionarPaciente(&filaAlta, &filaBaixa);
                break;
            case 2:
                atenderPaciente(&filaAlta, &filaBaixa);
                break;
            case 3:
                exibirFila(&filaAlta, &filaBaixa);
            case 0:
                printf("Saindo\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    resetFila(&filaAlta);
    resetFila(&filaBaixa);

    return 0;
}