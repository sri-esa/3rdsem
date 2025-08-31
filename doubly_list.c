#include <stdio.h>
#include <stdlib.h>

struct dnode {
    int data;
    struct dnode *r; // Renamed 'next' to 'r'
    struct dnode *l; // Renamed 'prev' to 'l'
};

struct dnode *h = NULL; // Renamed 'head' to 'h'

// Function to create a new node
struct dnode* createNode(int value) {
    struct dnode *newNode = (struct dnode*)malloc(sizeof(struct dnode));
    if (!newNode) exit(1);
    newNode->data = value;
    newNode->r = NULL;
    newNode->l = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(int value) {
    struct dnode *newNode = createNode(value);
    if (!h) {
        h = newNode;
        return;
    }
    newNode->r = h;
    h->l = newNode;
    h = newNode;
}

// Insert at the end
void insertAtEnd(int value) {
    struct dnode *newNode = createNode(value);
    if (!h) {
        h = newNode;
        return;
    }
    struct dnode *temp = h;
    while (temp->r) temp = temp->r;
    temp->r = newNode;
    newNode->l = temp;
}

// Insert at a given position
void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    struct dnode *newNode = createNode(value);
    struct dnode *temp = h;
    for (int i = 1; i < position - 1 && temp; i++) {
        temp = temp->r;
    }

    if (!temp) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    if (!temp->r) {
        temp->r = newNode;
        newNode->l = temp;
    } else {
        newNode->r = temp->r;
        temp->r->l = newNode;
        temp->r = newNode;
        newNode->l = temp;
    }
}

// Delete from the beginning
void deleteFromBeginning() {
    if (!h) {
        printf("List is empty.\n");
        return;
    }
    struct dnode *temp = h;
    h = h->r;
    if (h) h->l = NULL;
    free(temp);
}

// Delete from the end
void deleteFromEnd() {
    if (!h) {
        printf("List is empty.\n");
        return;
    }
    if (!h->r) {
        free(h);
        h = NULL;
        return;
    }
    struct dnode *temp = h;
    while (temp->r) temp = temp->r;
    if (temp->l) temp->l->r = NULL;
    free(temp);
}

// Delete from a given position
void deleteAtPosition(int position) {
    if (position < 1 || !h) {
        printf("Invalid position or list is empty.\n");
        return;
    }
    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    struct dnode *temp = h;
    for (int i = 1; i < position && temp; i++) {
        temp = temp->r;
    }

    if (!temp) {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp->l) temp->l->r = temp->r;
    if (temp->r) temp->r->l = temp->l;
    free(temp);
}

// Reverse the list
void reverseList() {
    struct dnode *temp = NULL;
    struct dnode *current = h;

    while (current) {
        temp = current->l;
        current->l = current->r;
        current->r = temp;
        current = current->l;
    }

    if (temp) h = temp->l;
    printf("List reversed.\n");
}

// Display the elements
void displayList() {
    struct dnode *temp = h;
    if (!h) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->r;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, position, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct dnode *c = NULL; // 'c' is the current/tail pointer
    int item;
    for (int i = 1; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &item);

        if (i == 1) {
            h = createNode(item);
            c = h;
        } else {
            struct dnode *new = createNode(item);
            new->l = c;
            c->r = new;
            c = new;
        }
    }

    do {
        printf("\nDoubly Linked List Operations\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete at a position\n");
        printf("7. Reverse list\n");
        printf("8. Display list\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);displayList();
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);displayList();
                break;
            case 3:
                printf("Enter value and position:\n");
                scanf("%d %d", &value, &position);
                insertAtPosition(value, position);displayList();
                break;
            case 4:
                deleteFromBeginning();displayList();
                break;
            case 5:
                deleteFromEnd();displayList();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);displayList();
                break;
            case 7:
                reverseList();displayList();
                break;
            case 8:
                displayList();
                break;
            case 9:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 9);

    struct dnode *temp;
    while (h) {
        temp = h;
        h = h->r;
        free(temp);
    }
    return 0;
}
