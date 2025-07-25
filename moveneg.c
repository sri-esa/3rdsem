#include <stdio.h>
void move(int arr[], int n) {
    int temp[100];
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}
void disp(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[50],s;
    printf("Enter the number of elements:");
    scanf("%d",&s);
    printf("Enter the elements of an array:\n");
    for(int i=0;i<s;i++){
        scanf("%d",&arr[i]);
    }
    printf("Original array:\n");
    disp(arr, s);

    move(arr, s);

    printf("Modified array (negatives at end):\n");
    disp(arr, s);

    return 0;
}
