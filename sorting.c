#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    
    while (i < j) {
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        while (arr[j] > pivot && j > low) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    
    return j;
}

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int n) {
    quickSortHelper(arr, 0, n - 1);
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int inputArray(int arr[], int max_size) {
    int n;
    printf("Enter the number of elements (max %d): ", max_size);
    scanf("%d", &n);
    
    if (n > max_size || n <= 0) {
        printf("Invalid number of elements!\n");
        return 0;
    }
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    return n;
}

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int temp_arr[MAX_SIZE];
    int n = 0;
    int choice;
    
    printf("=== SORTING ALGORITHMS PROGRAM ===\n\n");
    
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Input Array\n");
        printf("2. Bubble Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Insertion Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Display Current Array\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                n = inputArray(arr, MAX_SIZE);
                if (n > 0) {
                    printf("Array entered successfully!\n");
                    printf("Array: ");
                    printArray(arr, n);
                }
                break;
                
            case 2:
                if (n == 0) {
                    printf("Please input an array first!\n");
                    break;
                }
                copyArray(arr, temp_arr, n);
                printf("Original Array: ");
                printArray(temp_arr, n);
                bubbleSort(temp_arr, n);
                printf("After Bubble Sort: ");
                printArray(temp_arr, n);
                break;
                
            case 3:
                if (n == 0) {
                    printf("Please input an array first!\n");
                    break;
                }
                copyArray(arr, temp_arr, n);
                printf("Original Array: ");
                printArray(temp_arr, n);
                selectionSort(temp_arr, n);
                printf("After Selection Sort: ");
                printArray(temp_arr, n);
                break;
                
            case 4:
                if (n == 0) {
                    printf("Please input an array first!\n");
                    break;
                }
                copyArray(arr, temp_arr, n);
                printf("Original Array: ");
                printArray(temp_arr, n);
                insertionSort(temp_arr, n);
                printf("After Insertion Sort: ");
                printArray(temp_arr, n);
                break;
                
            case 5:
                if (n == 0) {
                    printf("Please input an array first!\n");
                    break;
                }
                copyArray(arr, temp_arr, n);
                printf("Original Array: ");
                printArray(temp_arr, n);
                quickSort(temp_arr, n);
                printf("After Quick Sort: ");
                printArray(temp_arr, n);
                break;
                
            case 6:
                if (n == 0) {
                    printf("No array has been entered yet!\n");
                } else {
                    printf("Current Array: ");
                    printArray(arr, n);
                }
                break;
                
            case 7:
                printf("Thank you for using the sorting program!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a number between 1-7.\n");
        }
    }
    
    return 0;
}