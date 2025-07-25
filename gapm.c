#include <stdio.h>
#include <math.h>

// Function to get next gap
int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int arr1[], int m, int arr2[], int n) {
    int gap = nextGap(m + n);
    int i, j;

    while (gap > 0) {
        // Compare elements in the first array
        for (i = 0; i + gap < m; i++) {
            if (arr1[i] > arr1[i + gap]) {
                int temp = arr1[i];
                arr1[i] = arr1[i + gap];
                arr1[i + gap] = temp;
            }
        }

        // Compare elements between both arrays
        for (j = gap > m ? gap - m : 0; i < m && j < n; i++, j++) {
            if (arr1[i] > arr2[j]) {
                int temp = arr1[i];
                arr1[i] = arr2[j];
                arr2[j] = temp;
            }
        }

        // Compare elements in the second array
        if (j < n) {
            for (j = 0; j + gap < n; j++) {
                if (arr2[j] > arr2[j + gap]) {
                    int temp = arr2[j];
                    arr2[j] = arr2[j + gap];
                    arr2[j + gap] = temp;
                }
            }
        }

        gap = nextGap(gap);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
}

int main() {
    int arr1[50],s1,arr2[50],s2;
    printf("Enter the number of elements for array 1:");
    scanf("%d",&s1);
    printf("Enter the elements of an array 1:\n");
    for(int i=0;i<s1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter the number of elements for array 2:");
    scanf("%d",&s2);
    printf("Enter the elements of an array 2:\n");
    for(int i=0;i<s2;i++){
        scanf("%d",&arr2[i]);
    }
    merge(arr1, s1, arr2, s2);

    printf("\nAfter Merging:\n");
    printArray(arr1, s1);
    printArray(arr2, s2);

    return 0;
}
