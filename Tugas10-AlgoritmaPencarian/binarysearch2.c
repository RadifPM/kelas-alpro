#include <stdio.h>
#include <time.h>
#define SIZE 100000
FILE *fh;
size_t binarySearch(const int b[], int searchKey, size_t low, size_t high);
int main()
{
    int a[SIZE];
    int LOW = 0;
    int HIGH = 100000;
    for (size_t x = 0; x < SIZE; ++x)
    {
        a[x] = 2 * x - 1;
    }
    printf("Enter integer search key: ");
    int searchKey;
    scanf("%d", &searchKey);
    fh = fopen("banding.txt", "a");
    clock_t begin = clock();
    size_t index = binarySearch(a, searchKey, LOW, HIGH);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    if (index != -1)
    {
        printf("Found value at index %d\n", index);
        printf("Waktu dibutuhkan untuk menjalankan program %lf detik", time_spent);
        fprintf(fh, "Waktu dibutuhkan untuk menjalankan program binary search %lf detik\n", time_spent);
        fclose(fh);
    }
    else
    {
        puts("Value not found");
        printf("Waktu dibutuhkan untuk menjalankan program %lf detik", time_spent);
        fprintf(fh, "Waktu dibutuhkan untuk menjalankan program binary search %lf detik\n", time_spent);
        fclose(fh);
    }
}

size_t binarySearch(const int b[], int searchKey, size_t low, size_t high)
{
    while (low <= high)
    {
        size_t middle = (low + high) / 2;
        if (searchKey == b[middle])
        {
            return middle;
        }
        else if (searchKey < b[middle])
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }
    return -1;
}