#include <stdio.h>
#include <time.h>
#define SIZE 100000
FILE *fh;
int x;
size_t linearSearch(const int array[], int key, size_t size);
int main(void)
{
    int a[SIZE];
    for (size_t x = 0; x < SIZE; ++x)
    {
        a[x] = 2 * x-1;
    }
    printf("Enter integer search key: ");
    int searchKey;
    scanf("%d", &searchKey);
    fh = fopen("banding.txt", "a");
    clock_t begin = clock();
    size_t index = linearSearch(a, searchKey, SIZE);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    if (index != -1)
    {
        printf("Found value at index %d\n", index);
    printf("Waktu dibutuhkan untuk menjalankan program %lf detik", time_spent);\
    fprintf(fh, "Waktu dibutuhkan untuk menjalankan program sequential search %lf detik\n", time_spent);
    }
    else
    {
        puts("Value not found");
    printf("Waktu dibutuhkan untuk menjalankan program %lf detik", time_spent);
    fprintf(fh, "Waktu dibutuhkan untuk menjalankan program sequential search %lf detik\n", time_spent);
    }
}

size_t linearSearch(const int array[], int key, size_t size)
{
    for (size_t n = 0; n < SIZE; ++n)
    {
        if (array[n] == key)
        {
            return n;
        }
    }
    return -1;
}