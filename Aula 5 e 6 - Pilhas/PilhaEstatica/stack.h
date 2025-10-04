#ifndef STACK_H_
#define STACK_H_

#define STACK_MAX_SIZE 50

#define true 1
#define false 0
#define bool int

typedef int ElementType;

typedef struct Stack {
    ElementType items[STACK_MAX_SIZE];
    int top;

} Stack;

void createStack(Stack* stack);
bool push(Stack* stack, ElementType item);
bool pop(Stack* stack, ElementType* item);
bool isEmpty(Stack* stack);
int size(Stack* stack);
bool isFull(Stack* stack);

#endif