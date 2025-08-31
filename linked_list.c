#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) exit(1);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (!head) {
        head = newNode;
        printf("Inserted %d at end.\n", value);
        return;
    }
    struct Node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    printf("Inserted %d at end.\n", value);
}

void deleteElement(int value) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    
    if (head->data == value) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted %d.\n", value);
        return;
    }
    
    struct Node *prev = head;
    struct Node *current = head->next;
    while (current && current->data != value) {
        prev = current;
        current = current->next;
    }
    
    if (!current) {
        printf("Element %d not found.\n", value);
    } else {
        prev->next = current->next;
        free(current);
        printf("Deleted %d.\n", value);
    }
}

void searchElement(int value) {
    struct Node *temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            printf("Element %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found.\n", value);
}

void displayList() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseIterative() {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("List reversed iteratively.\n");
}

struct Node* reverseRecursiveHelper(struct Node* current, struct Node* prev) {
    if (!current) return prev;
    struct Node* next = current->next;
    current->next = prev;
    return reverseRecursiveHelper(next, current);
}

void reverseRecursive() {
    head = reverseRecursiveHelper(head, NULL);
    printf("List reversed recursively.\n");
}

int main() {
    int choice, value;
    
    do {
        printf("\n Linked List Operations \n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete element\n");
        printf("4. Search element\n");
        printf("5. Display list\n");
        printf("6. Reverse list (Iterative)\n");
        printf("7. Reverse list (Recursive)\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                deleteElement(value);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                searchElement(value);
                break;
            case 5:
                displayList();
                break;
            case 6:
                reverseIterative();
                break;
            case 7:
                reverseRecursive();
                break;
            case 8:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);
    
    struct Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
