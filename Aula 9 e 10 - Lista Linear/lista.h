#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

#include <stdio.h>

#define MAX_LISTA 100001
#define true 0
#define  false 1
#define error -1

typedef int ElementType;

typedef struct {
    ElementType reg[MAX_LISTA+1];
    int nrmoElem;
} Lista;

void initListaLinear(Lista* l) {
    l->nrmoElem = 0;
}

void reiniciarListaLinear(Lista* l) {
    l->nrmoElem = 0;
}

void printLista(Lista* l) {
    for(int i = 0; i < l->nrmoElem; i++) {
        printf("%d ", l->reg[i]);
    }
}

int buscaSequencial(Lista* l, ElementType chave) {
    int i = 0;
    while(i < MAX_LISTA) {
        if (l->reg[i] == chave)
            return i;
        i++;
    }
    return -1;
}

int push(Lista* l, int pos, ElementType e) { 
    if(pos > l->nrmoElem || pos < 0 || l->nrmoElem == MAX_LISTA)
        return false;
    
    for(int j = l->nrmoElem; j > pos; j--)
    l->reg[j] = l->reg[j-1];
    
    l->reg[pos] = e;
    l->nrmoElem++;

    return true;
}

int buscaBinaria(Lista* l, ElementType e) {
    int m, low = 0, high = l->nrmoElem-1;
    
    if(l->reg[low] == e) 
        return low;
    else if(l->reg[high] == e)
        return high;

    while (low <= high) {
        m = (low + high)/2;
        
        if(l->reg[m] == e)
            return m;

        if(l->reg[m] < e)
            low = m+1;
        else high = m-1;
    }
}

int pushOrdenado(Lista* l, ElementType e) { 
    if(l->nrmoElem == MAX_LISTA)
        return false;
    
    int i = l->nrmoElem;

    while(i > 0 && l->reg[i-1] > e) {
        l->reg[i] = l->reg[i-1];
        i--;
    }

    l->reg[i] = e;
    l->nrmoElem++;
    return true;
}

int buscaSentinela(Lista* l, ElementType e) {
    l->reg[l->nrmoElem] = e;
    
    int i;
    for(i = 0; l->reg[i] != e; i++);

    if(i == l->nrmoElem)
        return error;

    return i;
}

ElementType pop(Lista* l, ElementType valor) {
    int i = buscaSentinela(l, valor);

    if(i == false) 
        return error;

    ElementType e = l->reg[i];
    
    for(int j = i; j < l->nrmoElem-1; j++)
        l->reg[j] = l->reg[j+1];

    l->nrmoElem--;

    return e;
}

int bobbleSort(Lista* l) {
    int swap, temp, n = l->nrmoElem;

    for(int i = 0; i < n-1; i++){
        swap = false;
        for(int j = 0; j < n-i-1; j++){
            if(l->reg[j] > l->reg[j+1]) {
                l->reg[j] = temp;     
                l->reg[j] = l->reg[j+1];
                l->reg[j+1] = temp;
                
                swap = true;
            }
        }
        if(!swap)
            break;
    }
}


#endif