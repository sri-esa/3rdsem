#include <stdio.h>

int miss(int arr[], int n) {
    int a = 0;
    for (int i = 0; i < n; i++) {
        a += arr[i];
    }

    int b = (n + 2) * (n + 1) / 2;//sum of first (n+1) numbers
    return b - a;
}

int main() {
    int arr[50],s;
    printf("Enter the number of elements:");
    scanf("%d",&s);
    printf("Enter the elements of an array:\n");
    for(int i=0;i<s;i++){
        scanf("%d",&arr[i]);
    }
    int m = miss(arr, s);
    
    printf("The missing number is: %d\n", m);
    return 0;
}
