#include <stdio.h>
#include "stack.h"

int main(int argc, char argv[]) {

    Stack *stack = (Stack*) malloc(sizeof(Stack*));
    stack->top = NULL;
    
    for(int i = 0; i < 10; i++){
        push(stack, i);
    }
    printStack(stack);
    printf("\n%d ", size(stack));
    printf("\n%d ", &stack);
    printf("\n%d ", stack);

    freeStack(stack);

    // free(stack);

    return 0;
}
