#include <stdio.h>

void main()
{
    char buff[255];
    char text[255];
    FILE *fptr;

    // membuka file
    fptr = fopen("puisi.txt","w");

    // mengambil input dari user
    printf("Inputkan isi file: ");
    fgets(text, sizeof(text), stdin);

    // menulis ke text ke file
    fputs(text, fptr);

    printf("File berhasil ditulis\n");

    // tutup file
    fclose(fptr);
}