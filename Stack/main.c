#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

bool invertArray(int* array, int size) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    createStack(stack);

    for (int i = 0; i < size; i++) {
        if(!push(stack, array[i]))
            return false;
    }

    for (int i = 0; i < size; i++) {
        if(!pop(stack, &array[i]))
            return false;    
    }

    free(stack);

    return true;
}

void Exemplo1() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));

    createStack(stack);

    for (int i = 0; i < 10; i++) {
        push(stack, i);
    }

    int item;
    while (!isEmpty(stack)) {

        if(pop(stack, &item)) {
            printf("%d\n", item);
            
        } else {   
            printf("Erro ao fazer o pop na stack\n");
            return;
        }
    }

    free(stack);
}

void Exercicio3() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    
    if(!invertArray(array, size)) {
        printf("Erro ao inverter a array\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

void Exercicio4() {
    char expressao[50];
    printf("Digite uma expressao matematica: ");
    fgets(expressao, sizeof(expressao), stdin);

    Stack* stack = (Stack*) malloc(sizeof(Stack));
    createStack(stack);

    ElementType temp;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char ch = expressao[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(stack, ch);

        } else if(ch == ')' || ch == '}' || ch == ']') {
            pop(stack, &temp);
        }
    }

    if(size(stack) != 0) 
        printf("A expressao nao eh valida.");
    else 
        printf("A expressao eh valida.");

    free(stack);
}

void Exercicio5() {
    int n; 
    int r;
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    createStack(stack);

    printf("Digite um numero para ser convertido: ");
    scanf("%d", &n);

    while(n > 0) {
        r = n % 2;
        push(stack, r);
        n /= 2;
    }

    ElementType i;

    printf("O numero em binario eh: ");
    while(!isEmpty(stack)) {
       if(pop(stack, &i)) {
           printf("%d", i);
       }
    }
    printf("\n");

    free(stack);
}


int main() {
    // Exemplo1();
    // Exercicio3();
    // Exercicio4();
    Exercicio5();

    return 0;
}
