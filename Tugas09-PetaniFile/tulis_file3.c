#include <stdio.h>

void main()
{
    char buff[255];
    char text[255];
    FILE *fptr;

    // membuka file untuk ditulis
    fptr = fopen("puisi.txt","w");

    for(int i = 0; i < 5; i++){

        // mengambil input dari user
        printf("Isi baris ke-%d: ", i);
        fgets(text, sizeof(text), stdin);

        // menulis ke text ke file
        fputs(text, fptr);
    }

    printf("File berhasil ditulis\n");

    // tutup file setelah ditulis
    fclose(fptr);

    // buka kembali file untuk dibaca
    fptr = fopen("puisi.txt","r");

    // baca isi file dengan gets lalu simpan ke buff
    while(fgets(buff, sizeof(buff), fptr)){
        printf("Isi filenya sekarang: %s", buff);
    }

    // tutup file
    fclose(fptr);
}