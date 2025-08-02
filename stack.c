#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

void push(int item) {
    if (top == MAXSIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = item;
    printf("%d pushed to stack\n", item);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top == -1) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return stack[top];
}

void display() {
    if (top == -1) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1) printf("Popped element: %d\n", item);
                break;
            case 3:
                item = peek();
                if (item != -1) printf("Top element: %d\n", item);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
