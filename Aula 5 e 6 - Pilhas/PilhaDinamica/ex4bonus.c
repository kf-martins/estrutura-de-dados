#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include "stack.h"
#include <string.h>

/*
4. Avaliação de expressões pós-fixadas (Notação Polonesa Reversa)
Implemente um programa que leia uma expressão pós-fixada (RPN) e calcule o resultado
usando pilha dinâmica.
Exemplo:
- Expressão: 3 4 * 5 +

*/

double pow(double base, double exp) {
    double result = 1;
    int i;
    int e = (int)exp;
    if (e < 0) {
        for(i = 0; i < -e; i++)
            result *= base;
        return 1.0 / result;
    } else {
        for(i = 0; i < e; i++)
            result *= base;
        return result;
    }
}

int main() {

    char expressao[50];

    Stack stack;
    initStack(&stack);

    printf("\nDigite uma expressao (ex: 8 -2 + 0.5 * 2 ^. Potencia fracionaria nao funciona): ");
    fgets(expressao, sizeof(expressao), stdin);

    char *token = strtok(expressao, " ");

    double a, b, val;

    while (token != NULL) {
        if(isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])) ){
            // sscanf(token, "%f", &val); // nao funcionou com %f
            sscanf(token, "%lf", &val);
            push(&stack, val);

        } else {
            pop(&stack, &b);
            pop(&stack, &a);

            if(token[0] == '+')
                val=a+b;
            else if(token[0] == '-')
                val=a-b;
            else if(token[0] == '*')
                val=a*b;
            else if(token[0] == '/')
                val=a/b;
            else if(token[0] == '^')
                val=pow(a, b);
            else {
                printf("Operador %s desconhecido", token);
                freeStack(&stack);
                return 1;
            }

            push(&stack, val);
        }

        token = strtok(NULL, " ");
    } 
    
    if(sizeStack(&stack) > 1){
        printf("Algo deu errado. Verifique os operadores novamente.\n Stack: [ ");
        printStack(&stack);
        printf("]\n");
    } else {
        pop(&stack, &val);
        printf("\nResultado:  %.2f", val);
    }

    freeStack(&stack);
    return 0;
}
