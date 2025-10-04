#include <malloc.h>

#ifndef STACK_H
#define STACK_H

typedef double ElementType;

typedef struct Node {
    ElementType value;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
}

ElementType peek(Stack* s) {
    return s->top->value;
}

void push(Stack* s, ElementType v) { 
    Node* n = (Node*) malloc(sizeof(Node));

    n->value = v;
    n->next = s->top;

    s->top = n;
}

int pop(Stack* s, ElementType* out) {
    if (s->top == NULL) {
        printf("Stack underflow");
        return -1; //Pilha vazia
    }
    
    *out = s->top->value;
    Node* erase = s->top;
    s->top = s->top->next;

    free(erase);
    return 1;
}

int isEmpty(Stack *s) {
    return (s->top == NULL);
}

int sizeStack(Stack* s) {
    Node* n = s->top;
    int count = 0;

    while (n != NULL) {
        count++;
        n = n->next;
    } 

    free(n);

    return count;
}

int printStack(Stack *s) {
    Node* n = s->top;

    while (n != NULL) {
        printf("%f ", n->value);
        n = n->next;
    } 
    free(n);
}

void freeStack(Stack *s) {
    Node* n = s->top;

    while (s->top != NULL) {
        n = s->top;
        s->top = s->top->next;

        free(n);
    } 
    n = NULL;
    s = NULL;
}

#endif