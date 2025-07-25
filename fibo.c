#include <stdio.h>
void fibo(unsigned int n){
    if(n==0)
        return;
    unsigned int a=0,b=1,next;
     printf("Fibonacci Series (%u terms):\n", n);

    if (n >= 1) printf("%u ", a);
    if (n >= 2) printf("%u ", b);
    for(unsigned int i=2;i<n;i++){
        next=a+b;
        printf("%u ", next);
        a=b;
        b=next;
    }
    printf("\n");
}
int main()
{
    unsigned int n;
    printf("Enter number of terms (max 47): ");
    scanf("%u", &n);
    fibo(n);
    return 0;
}