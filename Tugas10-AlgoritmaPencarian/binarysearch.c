#include <stdio.h>

int main(){
    int BIL[10] = {13, 12, 14, 11, 10, 16, 15, 18, 19, 20};
    int max=BIL[0], min=BIL[0];
    for (int j = 0; j < 10; j++)
    {
        if (BIL[j]>max){
            max = BIL[j];
        }
        if (BIL[j]< min)
        {
            min = BIL[j];
        }
    }
     printf("Nilai maksimal: %d\n", max);
        printf("Nilai minimal: %d\n", min);
        return 0;
}