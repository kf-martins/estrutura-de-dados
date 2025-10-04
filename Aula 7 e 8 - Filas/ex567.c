#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "static_fila.h"
#include "fila.h"

/*
Kauã Felipe Martins -- 26/09/2025

OS: Linux - Pop!_OS - 22.04 LTS
Comando de compilação: gcc -o ex567 ex567.c -lm

*/

void testeStaticFila(double *outInsert, double *outRemocao){

    clock_t inicio = clock();

    printf("TESTE FILA ESTÁTICA ===============================\n");

    StaticFila filaEstatica;
    initStaticFila(&filaEstatica);

    for(int i = 0; i < MAX_FILA; i++) {
        if(!pushStaticFila(&filaEstatica, i)) {
            printf("Erro: Fila estática cheia no elemento %d\n", i);
            break;
        }
    }

    clock_t fim = clock();

    double tempoFilaEstInsercao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo de inserção fila estática: %.6f segundos\n", tempoFilaEstInsercao);
    printf("Elementos inseridos: %d\n", tamanhoStaticFila(&filaEstatica));

    int elementos_estatica = tamanhoStaticFila(&filaEstatica);

        inicio = clock();
    
    for(int i = 0; i < elementos_estatica; i++) {
        popStaticFila(&filaEstatica);
    }
    
    fim = clock();
    
    double tempoFilaEstRemocao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de remoção fila estática: %.6f segundos\n", tempoFilaEstRemocao);
    printf("Elementos restantes: %d\n", tamanhoStaticFila(&filaEstatica));

    *outInsert = tempoFilaEstInsercao;
    *outRemocao = tempoFilaEstRemocao;
}

void testeFilaDinamica(double *outInsert, double *outRemocao){
printf("\nTESTE FILA DINÂMICA =============================\n");
    
    Fila filaDinamica;
    initFila(&filaDinamica);
    
    clock_t inicio = clock();
    
    for(int i = 0; i < MAX_FILA; i++) {
        push(&filaDinamica, i);
    }
    
    clock_t fim = clock();
    
    double tempoFilaDinInsercao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de inserção fila dinâmica: %.6f segundos\n", tempoFilaDinInsercao);
    printf("Elementos inseridos: %d\n", tamanhoFila(&filaDinamica));
    
    int elementos_dinamica = tamanhoFila(&filaDinamica);
    inicio = clock();
    
    for(int i = 0; i < elementos_dinamica; i++) {
        pop(&filaDinamica);
    }
    
    fim = clock();
    
    double tempoFilaDinRemocao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de remoção fila dinâmica: %.6f segundos\n", tempoFilaDinRemocao);
    printf("Elementos restantes: %d\n", tamanhoFila(&filaDinamica));

    *outInsert = tempoFilaDinInsercao;
    *outRemocao = tempoFilaDinRemocao;
}

int main() {
    
    double tempoFilaEstInsercao, tempoFilaDinInsercao, tempoFilaEstRemocao, tempoFilaDinRemocao;

    testeStaticFila(&tempoFilaEstInsercao, &tempoFilaEstRemocao);
    testeFilaDinamica(&tempoFilaDinInsercao, &tempoFilaDinRemocao);

    printf("\n=== COMPARAÇÃO DE PERFORMANCE ===\n");
    printf("Tempo inserção fila estática:  %.6f segundos\n", tempoFilaEstInsercao);
    printf("Tempo inserção fila dinâmica:  %.6f segundos\n", tempoFilaDinInsercao);
    
    if(tempoFilaEstInsercao < tempoFilaDinInsercao) {
        printf("Fila estática foi %.2fx mais rápida na inserção\n", 
               tempoFilaDinInsercao / tempoFilaEstInsercao);
    } else {
        printf("Fila dinâmica foi %.2fx mais rápida na inserção\n", 
               tempoFilaEstInsercao / tempoFilaDinInsercao);
    }
    
    printf("\nTempo remoção fila estática:   %.6f segundos\n", tempoFilaEstRemocao);
    printf("Tempo remoção fila dinâmica:   %.6f segundos\n", tempoFilaDinRemocao);
    
    if(tempoFilaEstRemocao < tempoFilaDinRemocao) {
        printf("Fila estática foi %.2fx mais rápida na remoção\n", 
               tempoFilaDinRemocao / tempoFilaEstRemocao);
    } else {
        printf("Fila dinâmica foi %.2fx mais rápida na remoção\n", 
               tempoFilaEstRemocao / tempoFilaDinRemocao);
    }
    

    printf("\n=== ANÁLISE DE MEMÓRIA ===\n");
    
    size_t memoriaEstatica = MAX_FILA * sizeof(ElementType) + sizeof(StaticFila);
    size_t memoriaDinamicaTotal = MAX_FILA * sizeof(Elemento) + sizeof(Fila);
    
    printf("Memória fila estática: %zu bytes (%.2f MB)\n", 
           memoriaEstatica, (double)memoriaEstatica / (1024 * 1024));
    printf("Memória fila dinâmica: %zu bytes (%.2f MB)\n", 
           memoriaDinamicaTotal, (double)memoriaDinamicaTotal / (1024 * 1024));
    
    printf("Overhead por elemento:\n");
    printf("- Estática: %zu bytes por elemento\n", sizeof(ElementType));
    printf("- Dinâmica: %zu bytes por elemento (inclui ponteiro)\n", sizeof(Elemento));
    
    printf("\n=== ANÁLISE DOS RESULTADOS ===\n");
    printf("IMPLEMENTAÇÃO QUE DEMOROU MAIS:\n");
    if(tempoFilaDinInsercao > tempoFilaEstInsercao) {
        printf("- Fila DINÂMICA demorou mais na inserção\n");
    } else {
        printf("- Fila ESTÁTICA demorou mais na inserção\n");
    }
    
    printf("\nRAZÕES DA DIFERENÇA NO TEMPO:\n");
    printf("1. FILA ESTÁTICA é mais rápida porque:\n");
    printf("   - Acesso direto ao array (localidade de referência)\n");
    printf("   - Não há chamadas malloc/free durante inserção\n");
    printf("   - Operações aritméticas simples com índices\n");
    printf("   - Memória contígua melhora cache do processador\n");
    
    printf("\n2. FILA DINÂMICA é mais lenta porque:\n");
    printf("   - Cada inserção requer malloc(), alocacao de memoria\n");
    printf("   - Fragmentação de memória\n");
    printf("   - Ponteiros espalham dados pela memória\n");
    printf("   - Overhead de gerenciamento de heap\n");
    
    printf("\n=== VANTAGENS E DESVANTAGENS ===\n");
    printf("FILA ESTÁTICA:\n");
    printf("+ Vantagens:\n");
    printf("  - Performance superior \n");
    printf("  - Melhor localidade de referência\n");
    printf("  - Não há fragmentação de memória\n");
    printf("  - Implementação mais simples\n");
    
    printf("- Desvantagens:\n");
    printf("  - Tamanho fixo definido em tempo de compilação\n");
    printf("  - Pode desperdiçar memória se não usar toda\n");
    printf("  - Pode estourar se exceder capacidade\n");
    printf("  - Aloca toda memória de uma vez (pode falhar)\n");
    
    printf("\nFILA DINÂMICA:\n");
    printf("+ Vantagens:\n");
    printf("  - Cresce conforme necessário\n");
    printf("  - Usa apenas memória necessária\n");
    printf("  - Sem limite fixo de elementos\n");
    printf("  - Mais flexível para diferentes casos de uso\n");
    
    printf("- Desvantagens:\n");
    printf("  - Performance inferior (malloc/free custosos)\n");
    printf("  - Overhead de ponteiros (mais memória por elemento)\n");
    printf("  - Fragmentação de memória\n");
    printf("  - Localidade de referência pior\n");
    printf("  - Risco de vazamentos de memória\n");
    
    return 0;
}