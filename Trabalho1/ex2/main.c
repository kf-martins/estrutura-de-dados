/* Demonstra ArrayListaLigada: insere por ultimo algarismo, busca e remove por bucket. */

#include <stdio.h>
#include <stdlib.h>
#include "array_lista_ligada.h"

int main(void) {
	ArrayListaLigada arr;
	inicializarArrayListaLigada(&arr);

	int valores[] = {10, 21, 32, 43, 54, 65, 76, 87, 98, 109, 5, 15, 25, 35, 45, 100, 200, 11, 1, 0, -19, -2};
	int n = sizeof(valores)/sizeof(valores[0]);

	printf("Inserindo %d valores (ordenados por ultimo algarismo) ...\n", n);
	for (int i = 0; i < n; ++i) inserirArrayListaLigada(&arr, valores[i]);

	printf("\nEstado inicial das 10 listas:\n");
	printArrayListaLigada(&arr);

	int extras[] = {40, 30, 20, 50, 90, 70};
	int m = sizeof(extras)/sizeof(extras[0]);
	for (int i = 0; i < m; ++i) inserirArrayListaLigada(&arr, extras[i]);

	printf("\nApos inserir extras:\n");
	printArrayListaLigada(&arr);

	int probes[] = {29, 30, 45, -19, 77};
	int q = sizeof(probes)/sizeof(probes[0]);
	printf("\nBuscas: \n");
	for (int i = 0; i < q; ++i) {
		int v = probes[i];
		printf("buscar %d -> %s\n", v, buscarArrayListaLigada(&arr, v) ? "encontrado" : "nao encontrado");
	}

	int removals[] = {30, 45, -19, 200, 111};
	int r = sizeof(removals)/sizeof(removals[0]);
	printf("\nRemocoes: \n");
	for (int i = 0; i < r; ++i) {
		int v = removals[i];
		printf("remover %d -> %s\n", v, removerArrayListaLigada(&arr, v) ? "ok" : "nao encontrado");
	}

	printf("\nApos remocoes:\n");
	printArrayListaLigada(&arr);

	destruirArrayListaLigada(&arr);
	return 0;
}

