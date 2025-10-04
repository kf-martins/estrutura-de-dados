#include <stdio.h>

#include "static_fila_ex4.h"

void adicionarDoc(Fila* f) {
    Spooler sp;
    
    int p;
    printf("\nDigite a quantidade de paginas: ");
    scanf("%d", &p);
    
    sp.paginas = p;
    sp.id = idCount;

    if(push(f, sp)) {
        printf("\nDocumento inserido!\nID: %d\nPAGINAS: %d", sp.id, sp.paginas);
    }
}

void imprimirDoc(Fila* f) {
    Spooler sp = pop(f);
    printf("\nImprimindo documento...\nID: %d\nPAGINAS: %d", sp.id, sp.paginas);
}

/* Inputs de exemplo
1
10
1
20
1
30
2
2
2
0

*/

int main(int argc, char** argv) {

    Fila spooler;
    initFila(&spooler);

    char c;
    do {   
        printf("\n1. Adionar documento para imprimir");
        printf("\n2. Imprimir documento");
        printf("\n0. Sair");
        printf("\n>");
        scanf("%c", &c);
        
        switch (c) {        
        case '1':
            adicionarDoc(&spooler);
            break;
        case '2':
            imprimirDoc(&spooler);
            break;
        default:
            break;
        }
    } while (c != '0');

    return 0;
}
