#include <stdio.h>
#include "stack.h"

int main(void) {
	DuasPilhas p;
	criarPilhas(&p);

	printf("=== duas Pilhas em um unico array ===\n");
	printDuasPilhas(&p);

	printf("\n-- Inserindo na pilha 1\n");
	for (int i = 0; i < 5; i++) inserir1(&p, i);
	printDuasPilhas(&p);

	printf("\n-- Inserindo na pilha 2\n");
	for (int i = 100; i < 105; i++) inserir2(&p, i);
	printDuasPilhas(&p);

	int v;
	printf("\n-- Removendo 2 de cada pilha\n");
	for (int i = 0; i < 2; i++) 
		if (remover1(&p, &v)) 
			printf("removido p1: %d\n", v);
	for (int i = 0; i < 2; i++) 
		if(remover2(&p, &v)) 
			printf("removido p2: %d\n", v);

	printDuasPilhas(&p);

	printf("\n-- Testando estouros e expansoes (ate o quarto estouro)\n");
	int alvo = 2000; 
	int falhas = 0;
	for (int i = 0; i < alvo; i++) {
		if (!inserir1(&p, 0)) {
			falhas++;
			printf("estouro: capacidade=%d, expansoes=%d (nao tem como expandir se for o 4)\n", p.capacidade, p.exp);
			if (falhas >= 1) 
				break; 
		}
	}
	printDuasPilhas(&p);

	destruirPilhas(&p);
	return 0;
}
