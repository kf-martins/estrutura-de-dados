#ifndef STACK_H
#define STACK_H

#define true 1
#define false 0
#define bool int

typedef int ElementType;

#define TAM_INICIAL 10
#define TAM_ARRAY (TAM_INICIAL * 4) // Seria multiplicado por 3.375, mas precisa ser inteiro.
#define MAX_EXPANSOES 3

typedef struct DuasPilhas{
    ElementType itens[TAM_ARRAY];
    int topo1;
    int topo2;
    int capacidade;
    int exp;
    
} DuasPilhas;

void criarPilhas(DuasPilhas* p);
void destruirPilha1(DuasPilhas *p);
void destruirPilha2(DuasPilhas *p);
void destruirPilhas(DuasPilhas* p);

bool inserir1(DuasPilhas* p, ElementType item);
bool inserir2(DuasPilhas* p, ElementType item);

bool remover1(DuasPilhas* p, ElementType* out);
bool remover2(DuasPilhas* p, ElementType* out);

bool isVazia1(DuasPilhas* p);
bool isVazia2(DuasPilhas* p);

int tamanho1(DuasPilhas* p);
int tamanho2(DuasPilhas* p);

void printPilha1(DuasPilhas* p);
void printPilha2(DuasPilhas* p);
void printDuasPilhas(DuasPilhas* p);

#endif