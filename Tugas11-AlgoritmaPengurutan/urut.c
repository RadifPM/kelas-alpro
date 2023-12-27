#include <stdio.h>
#define MAX 7

void tampilkanArray(int A[], int n){
    for (int j = 0; j < n; j++)
    {
        printf("A[%d] = %d\n", j, A[j]);
    }
}

int main(){
    int A[MAX] = {101, 23, 45, 78, 64, 32, 21};
    int j, k;
    int temp;
    printf("Sebelum pengurutan:\n");
    tampilkanArray(A, MAX);

    for (j = 0; j < MAX-1; j++)
    {
        for (k = MAX-1; k>=(j+1); k--)
        {
            if (A[k]<A[k-1])
            {
                temp = A[k];
                A[k] = A[k-1];
                A[k-1] = temp;
            }
            
        }
        
    }
    printf("\n");
    printf("Setelah pengurutan:\n");
    tampilkanArray(A, MAX);
    return 0;
}