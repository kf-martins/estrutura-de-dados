#include <iostream>
#include "Stack.hpp"

using namespace std;

int main(int, char **) {
    Stack *stack = new Stack(5);

    for(int i = 0; i < stack->maxSize; i++) {
        void* x = new int(i);
        
        if(stack->push((void*)x)) {
            cout << "Stack is full!" << endl;
        }
    }
    int *x;

    for(int i = 0; i < stack->maxSize; i++) {
        x = (int*)stack->pop();
        cout << *x << endl;
    }

    delete x;
    delete stack;
    return 0;
}
