#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkList {
    int data;
    struct LinkList* next;
} LinkList;

typedef struct Stack {
    LinkList* top;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
}

bool isEmpty(Stack* stack) {
    return stack == NULL;
}

bool push(Stack* stack, int val) {
    LinkList* newNode = (LinkList*) malloc(sizeof(LinkList));
    if (newNode == NULL) {
        printf("allocation failed");
        return -1;
    }
    
    newNode->data = val;
    newNode->next = stack->top;
    stack->top = newNode;
    return true;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("stack is empty.");
        return -1;
    }

    LinkList* temp = stack->top;
    int val = temp->data;
    stack->top = temp->next;
    free(temp);
    return val;
}

int main() {
    Stack stack;
    initStack(&stack);
    
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    
    printf("%d", pop(&stack));
    printf("%d", pop(&stack));
    printf("%d", pop(&stack));
    push(&stack, 5);
    printf("%d", pop(&stack));
    
    return true;
}
