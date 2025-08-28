#include <stdio.h>
#include <stdlib.h>

// Global pointers for the linked list
struct Node *h = NULL; // Head of the list

struct Node {
    int data;
    struct Node *link;
};

// Function to insert a node at a given position
void Insert(int position, int value) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    p->data = value;
    p->link = NULL;

    if (position == 1) {
        p->link = h;
        h = p;
        return;
    }

    struct Node *temp = h;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            free(p);
            return;
        }
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(p);
        return;
    }

    p->link = temp->link;
    temp->link = p;
}

// Function to delete a node at a given position
void Delete(int position) {
    if (position < 1 || h == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    if (position == 1) {
        struct Node *temp = h;
        h = h->link;
        free(temp);
        return;
    }

    struct Node *prev = h;
    for (int i = 1; i < position - 1; i++) {
        if (prev->link == NULL) {
            printf("Position out of bounds.\n");
            return;
        }
        prev = prev->link;
    }

    if (prev->link == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node *temp_del = prev->link;
    prev->link = temp_del->link;
    free(temp_del);
}

// Function to reverse the linked list
void reverse() {
    struct Node *prev = NULL;
    struct Node *current = h;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    h = prev;
}

// Function to traverse and display the linked list
void traverseAndDisplay() {
    struct Node *temp = h;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    int choice, position, value;

    // Use a do-while loop to repeatedly show the menu
    do {
        printf("\n*** Linked List Operations ***\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Reverse the list\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the position and value to insert: ");
                scanf("%d %d", &position, &value);
                Insert(position, value);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                Delete(position);
                break;
            case 3:
                reverse();
                printf("List reversed.\n");
                break;
            case 4:
                traverseAndDisplay();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Clean up any remaining nodes before exiting (optional but good practice)
    struct Node *current = h;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->link;
        free(temp);
    }
    h = NULL;

    return 0;
}