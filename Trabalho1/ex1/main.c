#include <stdio.h>
#include "stack.h"

void printPilha1(DuasPilhas* p) {
	printf("Pilha1 [base->topo] (tam=%d): ", tamanho1(p));
	for (int i = 0; i <= p->topo1; i++) {
		printf("%d ", p->itens[i]);
	}
	printf("\n");
}

void printPilha2(DuasPilhas* p) {
	printf("Pilha2 [topo->base] (tam=%d): ", tamanho2(p));
	for (int i = TAM_ARRAY; i > p->topo2; i--) {
		printf("%d ", p->itens[i]);
	}
	printf("\n");
}

void printDuasPilhas(DuasPilhas* p) {
	printf("capacidade=%d, expansoes=%d | p1=%d, p2=%d\n", p->capacidade, p->exp, tamanho1(p), tamanho2(p));
	printPilha1(p);
	printPilha2(p);
}

int main(void) {
	DuasPilhas p;
	criarPilhas(&p);

	printf("=== Apresentacao das Duas Pilhas em um unico array ===\n");
	printDuasPilhas(&p);

	printf("\n-- Inserindo na pilha 1\n");
	for (int i = 1; i <= 5; ++i) inserir1(&p, i);
	printDuasPilhas(&p);

	printf("\n-- Inserindo na pilha 2\n");
	for (int i = 100; i <= 104; ++i) inserir2(&p, i);
	printDuasPilhas(&p);

	int v;
	printf("\n-- Removendo 2 de cada pilha\n");
	for (int i = 0; i < 2; ++i) 
		if (remover1(&p, &v)) 
			printf("removido p1: %d\n", v);
	for (int i = 0; i < 2; ++i) 
		if(remover2(&p, &v)) 
			printf("removido p2: %d\n", v);

	printDuasPilhas(&p);

	printf("\n-- Testando estouros e expansoes (ate o quarto estouro)\n");
	int inseridos = tamanho1(&p) + tamanho2(&p);
	int alvo = 2000; 
	int falhas = 0;
	for (int i = 0; i < alvo; ++i) {
		if (!inserir1(&p, 0)) {
			falhas++;
			printf("estouro %d: capacidade=%d, expansoes=%d (nao tem como expandir se for o 4)\n", falhas, p.capacidade, p.exp);
			if (falhas >= 1) 
				break; 
		}
	}
	printDuasPilhas(&p);

	destruirPilhas(&p);
	return 0;
}
