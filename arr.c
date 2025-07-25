#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void insertAt(int arr[], int *size, int index, int value) {
    if (*size >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    if (index < 0 || index > *size) {
        printf("Invalid index.\n");
        return;
    }

    // Shift elements to the right
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void deleteAt(int arr[], int *size, int index) {
    if (*size == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    if (index < 0 || index >= *size) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted successfully.\n");
}

void linearSearch(int arr[], int size, int key) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d.\n", key, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }
}

void findMinMax(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    printf("Minimum Element: %d\n", min);
    printf("Maximum Element: %d\n", max);
}

void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX];
    int size = 0;
    int choice, index, value, key;

    // Initial array input
    printf("Enter initial number of elements (max %d): ", MAX);
    scanf("%d", &size);

    if (size > MAX || size < 0) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at index\n");
        printf("2. Delete from index\n");
        printf("3. Linear search\n");
        printf("4. Find max and min\n");
        printf("5. Display array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index to insert (0 to %d): ", size);
                scanf("%d", &index);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAt(arr, &size, index, value);
                break;

            case 2:
                printf("Enter index to delete (0 to %d): ", size - 1);
                scanf("%d", &index);
                deleteAt(arr, &size, index);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &key);
                linearSearch(arr, size, key);
                break;

            case 4:
                findMinMax(arr, size);
                break;

            case 5:
                displayArray(arr, size);
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
