#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_tarefa.h"

int id_counter = 1;

static void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void printMenu() {
    printf("\n===== MENU DE OPCOES =====\n");
    printf("1. Adicionar Tarefa\n");
    printf("2. Remover Tarefa por ID\n");
    printf("3. Listar Todas as Tarefas\n");
    printf("4. Buscar Tarefa por Descricao\n");
    printf("0. Sair\n");
    printf("===========================\n");
    printf("Escolha uma opcao: ");
}

void adicionarTarefa(ListaLigCirc* l) {
    Tarefa nova_tarefa;
    nova_tarefa.id = id_counter++;

    printf("Digite a descricao da tarefa: ");
    if (fgets(nova_tarefa.descricao, sizeof(nova_tarefa.descricao), stdin) == NULL) {
        printf("Entrada invalida.\n");
        return;
    }
    // remove \n final, se presente
    nova_tarefa.descricao[strcspn(nova_tarefa.descricao, "\n")] = '\0';

    printf("Digite a prioridade (1-Alta, 2-Media, 3-Baixa): ");
    if (scanf("%d", &nova_tarefa.prioridade) != 1) {
        printf("Prioridade invalida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    if (inserirOrd(l, nova_tarefa)) {
        printf("Tarefa adicionada com sucesso!\n");
    } else {
        printf("Erro ao adicionar tarefa.\n");
    }
}

void removerTarefa(ListaLigCirc* l) {
    int id;
    printf("Digite o ID da tarefa a ser removida: ");
    if (scanf("%d", &id) != 1) {
        printf("ID invalido.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    if (removerTarefaId(l, id)) {
        printf("Tarefa removida com sucesso!\n");
    } else {
        printf("Tarefa com ID %d nao encontrada.\n", id);
    }
}

void buscarTarefaPorDescricao(ListaLigCirc* l) {
    char texto[100];
    printf("Digite o texto para buscar na descricao: ");
    if (fgets(texto, sizeof(texto), stdin) == NULL) {
        printf("Entrada invalida.\n");
        return;
    }
    texto[strcspn(texto, "\n")] = '\0';

    buscaDescricao(l, texto);
}

int main() {
    ListaLigCirc lista_de_tarefas;
    inicializarListaLigCirc(&lista_de_tarefas);

    int escolha;
    do {
        printMenu();
        if (scanf("%d", &escolha) != 1) {
            printf("Opcao invalida.\n");
            limparBuffer();
            continue;
        }
        limparBuffer();

        switch (escolha) {
            case 1:
                adicionarTarefa(&lista_de_tarefas);
                break;
            case 2:
                removerTarefa(&lista_de_tarefas);
                break;
            case 3:
                printLista(&lista_de_tarefas);
                break;
            case 4:
                buscarTarefaPorDescricao(&lista_de_tarefas);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (escolha != 0);

    freeLista(&lista_de_tarefas);
    return 0;
}