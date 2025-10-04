#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include "stack.h"
#include <string.h>

/*
3. Conversão de Notação Infixa para Pós-fixa
Implemente um algoritmo que, utilizando uma pilha dinâmica, converta uma expressão
matemática da notação infixa (ex: a + b * c) para a notação pós-fixa (ex: a b c * +).

*/


int main() {

    char expressao[50];

    Stack stack;
    initStack(&stack);

    printf("Digite uma expressao: ");
    gets(expressao);

    char op;
    char *c = expressao;
    while (*c != '\0') {
        if(isalnum(*c)){
            printf("%c", *c);

        } else if(*c == '('){
            push(&stack, *c);

        } else if(*c == ')'){
            while(peek(&stack) != '(' && !isEmpty(&stack)) {
                pop(&stack, &op);

                if(op != ' ')
                    printf("%c", op);
            }
            pop(&stack, &op);
            
        } else {
            push(&stack, *c);
        }        
        c++;
    } 

    while(!isEmpty(&stack)) {
        pop(&stack, &op);
        printf("%c", op);
    }
    
    freeStack(&stack);
    return 0;
}
