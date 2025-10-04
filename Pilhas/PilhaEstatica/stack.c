#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void createStack(Stack* stack) {
    stack->top = -1;
} 

int size(Stack* stack) {
    return stack->top + 1;
}

bool push(Stack* stack, ElementType item) {
    if (isFull(stack))
        return false;

    stack->items[++(stack->top)] = item; 
    return true;
}

bool pop(Stack* stack, ElementType* item) {
    if (!isEmpty(stack)) {
        *item = stack->items[(stack->top)--];
        return true;
    }
    return false;
}

// Ex01
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Ex02
bool isFull(Stack* stack) {
    return stack->top >= STACK_MAX_SIZE - 1;
}

