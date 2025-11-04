#include <stdio.h>
#include "stack.h"

void criarPilhas(DuasPilhas* p) {
    p->topo1 = -1;
    p->topo2 = TAM_ARRAY;
    p->capacidade = TAM_INICIAL;
    p->exp = 0;
}

void destruirPilha1(DuasPilhas *p) {
    p->topo1 = -1;
}

void destruirPilha2(DuasPilhas *p) {
    p->topo2 = TAM_ARRAY;
}

void destruirPilhas(DuasPilhas* p) {
    p->topo1 = -1;
    p->topo2 = TAM_ARRAY;
    p->capacidade = TAM_INICIAL;
    p->exp = 0;
}

bool garantirEspaco(DuasPilhas* p) {
    if (((p->topo1 + 1) + (TAM_ARRAY - p->topo2)) < p->capacidade)
        return true;

    if (!(p->exp < MAX_EXPANSOES && p->capacidade < TAM_ARRAY))
        return false;

    int nova = p->capacidade + p->capacidade / 2;

    if (nova > TAM_ARRAY) 
        nova = TAM_ARRAY;
    
    p->capacidade = nova;
    p->exp++;

    printf("capacidade estendida para %d (expansoes=%d)\n", p->capacidade, p->exp);
    return true;
}

bool inserir1(DuasPilhas* p, ElementType item) {
    if (!garantirEspaco(p)) 
        return false;
    if (p->topo1 + 1 == p->topo2) 
        return false;
    
    //p->topo1 += 1
    p->topo1++;
    p->itens[p->topo1] = item;

    return true;
}

bool inserir2(DuasPilhas* p, ElementType item) {
    if (!garantirEspaco(p)) 
        return false;
    if (p->topo1 + 1 == p->topo2)
         return false;

    p->topo2--;
    p->itens[p->topo2] = item;

    return true;
}

bool remover1(DuasPilhas* p, ElementType* out) {
    if (p->topo1 == -1) 
        return false;
    *out = p->itens[(p->topo1)--];

    return true;
}

bool remover2(DuasPilhas* p, ElementType* out) {
    if (p->topo2 == TAM_ARRAY) 
        return false;
    *out = p->itens[(p->topo2)++];

    return true;
}

bool isVazia1(DuasPilhas* p) {
    return p->topo1 == -1;
}

bool isVazia2(DuasPilhas* p) {
    return p->topo2 == TAM_ARRAY;
}

int tamanho1(DuasPilhas* p) {
    return p->topo1 + 1;
}

int tamanho2(DuasPilhas* p) {
    return TAM_ARRAY - p->topo2;
}

void printPilha1(DuasPilhas* p) {
	printf("Pilha1 (tam=%d): ", tamanho1(p));
	for (int i = 0; i <= p->topo1; i++) {
		printf("%d ", p->itens[i]);
	}
	printf("\n");
}

void printPilha2(DuasPilhas* p) {
	printf("Pilha2 (tam=%d): ", tamanho2(p));
	for (int i = TAM_ARRAY-1; i > p->topo2-1; i--) {
		printf("%d ", p->itens[i]);
	}
	printf("\n");
}

void printDuasPilhas(DuasPilhas* p) {
	printf("capacidade=%d, expansoes=%d | p1=%d, p2=%d\n", p->capacidade, p->exp, tamanho1(p), tamanho2(p));
	printPilha1(p);
	printPilha2(p);
}