#include <stdio.h>

// membuat variabel global
int nilai = 9;

void main(){
    // membuat variabel lokal
    int nilai = 7;

    // mencetak variabel
    printf("Nilai: %d\n", nilai);
}