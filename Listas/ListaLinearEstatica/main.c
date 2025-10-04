#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista.h"

/*
4. Comparação de Desempenho
Implemente um programa em C++ que compare o tempo de execução da busca
binária e da busca sequencial com sentinela.
Passos:
a) Crie dois vetores com 100000 posições:

o Vetor A (ordenado): insira os elementos em ordem crescente.
o Vetor B (aleatório): insira elementos em ordem aleatória (sem garantir
ordenação).

b) Realize buscas em ambos os vetores, utilizando:
o Busca sequencial com sentinela
o Busca binária (apenas no vetor ordenado)
c) Meça o tempo de execução das buscas:
o Use a classe high_resolution_clock da biblioteca <chrono>.
o Armazene o instante inicial da busca e o instante final em variáveis.
o Calcule a diferença de tempo total da execução em segundos.

Exemplo de uso:
auto inicio = high_resolution_clock::now();
// chamada da função de busca
auto fim = high_resolution_clock::now();

double tempo = duration_cast<duration<double>>(fim - inicio).count();
d) Compare os resultados:
o Execute buscas para diferentes números (presentes e ausentes no
vetor).
o Registre os tempos medidos para cada tipo de busca.
o Analise em quais situações cada método é mais eficiente.

*/

void preencherVetorOrdenado(Lista* l, int tamanho) {
    for (int i = 1; i <= tamanho; i++) {
        pushOrdenado(l, i);
    }
}

void preencherVetorAleatorio(Lista* l, int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        push(l, i, rand() % (tamanho * 10));
    }
}

void medirTempoBusca(Lista* l, ElementType chave, int (*funcBusca)(Lista*, ElementType), const char* tipoBusca) {
    clock_t inicio = clock();
    int resultado = funcBusca(l, chave);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%s: Chave %d %s. Tempo: %.6f segundos.\n", tipoBusca, chave, resultado != -1 ? "encontrada" : "não encontrada", tempo);
}

int main() {
    int tamanho = 100000;
    Lista A, B;
    initListaLinear(&A);
    initListaLinear(&B);

    preencherVetorOrdenado(&A, tamanho);
    preencherVetorAleatorio(&B, tamanho);

    ElementType chaves[] = {1, tamanho / 2, tamanho, tamanho * 2};
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < numChaves; i++) {
        printf("\nTestando chave: %d\n", chaves[i]);

        medirTempoBusca(&B, chaves[i], buscaSentinela, "Busca Sequencial com Sentinela");

        medirTempoBusca(&A, chaves[i], buscaBinaria, "Busca Binária");
    }

    return 0;
}