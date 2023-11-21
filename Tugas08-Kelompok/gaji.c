#include <stdio.h>
int golongan, jam, gaji, gaji2, lembur, ceklembur, upahlembur, gajilembur;
char nama[20];
int calcGaji(int gaji, int lembur, int upahlembur){
    gaji2 = gaji*1.5;
    upahlembur = upahlembur*lembur;
    gajilembur = gaji2 + upahlembur;
}

void displayGaji(){
    printf("Nama Karyawan: %s", nama);
    printf("\nGolongan karyawan: %d\n", golongan);
    if (lembur>0)
    {
        printf("Total gaji yang anda dapatkan adalah Rp%d\n", gaji2);
        printf("Dengan tambahan gaji sebesar Rp%d\n", upahlembur);
        printf("Maka total gaji yang anda dapatkan adalah Rp%d\n", gajilembur);
    }else{
    printf("Total Gaji yang anda dapatkan adalah Rp%d\n", gaji);
    }
}
int main(){
    printf("====================GAJI KARYAWAN===================\n");
    printf("| Golongan | Gaji Tetap | Upah Lembur per jam (Rp) |\n");
    printf("|    1     |   500.000  |            5000          |\n");
    printf("|    2     |   300.000  |            3000          |\n");
    printf("|    3     |   250.000  |            2000          |\n");
    printf("|    4     |   100.000  |            1500          |\n");    
    printf("|    5     |   50.000   |            1000          |\n");
    printf("====================================================\n");
    printf("Masukkan nama karyawan: ");
    gets(nama);
    printf("Masukkan golongan karyawan: ");
    scanf("%d", &golongan);
    printf("Masukkan jam kerja karyawan: ");    
    scanf("%d", &jam);
    if (jam - 150 > 0)
    {
        lembur = jam - 150;
    }
    switch (golongan)
    {
    case 1:
        gaji = 500000;
        upahlembur = 5000;
        if (lembur>0)
        {
            calcGaji(gaji, lembur, upahlembur);
        }
        break;
    case 2:
        gaji = 300000;
        upahlembur = 3000;
        if (lembur>0)
        {
            calcGaji(gaji, lembur, upahlembur);
        }
        break;
        case 3:
        gaji = 250000;
        upahlembur = 3000;
        if (lembur>0)
        {
            calcGaji(gaji, lembur, upahlembur);
        }
        break;
        case 4:
        gaji = 100000;
        upahlembur = 1500;
        if (lembur>0)
        {
            calcGaji(gaji, lembur, upahlembur);
        }
        break;
        case 5:
        gaji = 50000;
        upahlembur = 1000;
        if (lembur>0)
        {
            calcGaji(gaji, lembur, upahlembur);
        }
        break;
    default:
    printf("Golongan yang anda masukkan tidak valid");
        break;
    }
    displayGaji();
}