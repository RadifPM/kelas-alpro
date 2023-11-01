#include <stdio.h>
#include <math.h>

double fungsi(double x){
    return 6*pow(x,2)+5;  
}

int n;
double atas, bawah, dx, c, hasilintegral;

int main(){
    printf("Masukkan nilai N: "); scanf("%d", &n);
    printf("Masukkan batas bawah integral: "); scanf("%lf", &bawah);
    printf("Masukkan batas atas integral: "); scanf("%lf", &atas);

    dx =(atas - bawah)/n;
    c = fungsi(bawah) + fungsi(atas); 

    for (int i = 1; i < n; i++) {
        c += 2 * fungsi(bawah + i*dx);
    }
    hasilintegral = (dx/2) * c;

    printf("Hasil integral metode trapezoid adalah: %lf\n", hasilintegral);
    double integralnumerik = ((6.0/3.0) * pow(atas,3) + (5.0 * atas)) - ((6.0 / 3.0) * pow(bawah, 3) + (5.0 * bawah));
    printf("Hasil integral metode analitik: %lf\n", integralnumerik); 
}