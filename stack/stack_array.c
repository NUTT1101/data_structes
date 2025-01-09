#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
  int* data;
  int top;
  int capcity;
} Stack;

void initStack(Stack* stack, int cap) {
    stack->data = (int*)malloc(sizeof(int) * cap);
    stack->top = -1;
    stack->capcity = cap;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top + 1 == stack->capcity;
}

bool push(Stack* stack, int val) {
    if (isFull(stack)) {
        printf("stack is full.");
        return false;
    }
    
    stack->data[++stack->top] = val;
    return true;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("stack is empty");
        return -1;
    }
    
    return stack->data[stack->top--];
}

int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("stack is empty.");
        return -1;
    }
    
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    initStack(&stack, 100);
    
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    
    printf("%d", pop(&stack));
    printf("%d", pop(&stack));
    printf("%d", pop(&stack));
    return 0;
}
