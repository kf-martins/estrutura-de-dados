// template<typename T>
typedef struct Stack {
    int top;
    int maxSize;
    void** items;
    
    Stack(int size) {
        items = new void*[size];
        maxSize = size;
        top = -1;
    }

    ~Stack() {
        delete[] items;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool push(void* item) {
        if(isFull())
            return false;
        items[++top] = item;
        return true;
    }
    
    void* pop() {
        if(isEmpty())
            return nullptr;
        return items[top--];
    }

} Stack;
