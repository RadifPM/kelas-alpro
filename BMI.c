#include <stdio.h>
int main(){
    int jk = 3;
    float bmi, bmi2, tb, bb;
    while (jk > 2){
    printf("=======KALKULATOR BMI========\n");
    printf("Masukkan Jenis Kelamin:\n");
    printf("1. Laki-Laki\n");
    printf("2. Perempuan\n");
    printf("Masukkan pilihan: \n");
    scanf("%d", &jk);
    }
    while (tb <= 0 || bb <= 0){
    printf("Masukkan Tinggi Badan: ");
    scanf("%f", &tb);
    printf("Masukkan Berat Badan: ");
    scanf("%f", &bb);
    if (tb <= 0 || bb <= 0)
    {
        printf("Tinggi Badan atau Berat Badan tidak boleh kurang dari nol\n");
    }
    }    
    tb = tb/100;
    bmi2 = tb*tb;
    bmi= bb/bmi2;
    switch (jk){
    case 1:
        if(bmi >= 17 && bmi <= 23){
            printf("BMI anda: %.2f\n", bmi);
            printf("Berat badan anda ideal\n", bmi);
        }else{
            printf("BMI anda: %.2f\n", bmi);
            printf("Berat badan anda tidak ideal\n", bmi);
        }   
        break;
    case 2:
        if (bmi >= 18 && bmi <= 25)
        {
            printf("BMI anda: %.2f\n", bmi);
            printf("Berat badan anda ideal\n", bmi);
        }
        else
        {
            printf("BMI anda: %.2f\n", bmi);
            printf("Berat badan anda tidak ideal\n", bmi);
        }
    break;
    return 0;
    }
}
