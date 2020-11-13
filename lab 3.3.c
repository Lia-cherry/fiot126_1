#include "stdio.h"

float getNumber(float);
int checkX;

int main() {
    int a;
    printf ("This cubic equation calculator will help you to find roots of ax3 + bx2 + cx + d = 0 \n"
            "Enter values for a, b, c, d and solutions for x will be calculated. \n");
    getNumber(a);
return 0;
}

float getNumber(float x){
    do {
        checkX = scanf ("%lf",&x);

        if (checkX != 1) {
            printf("\nPlease, enter numbers...\nIf you write symbols after numbers, we use numbers written before symbols.\n");
            fflush (stdin);
        }
    } while (checkX != 1);
    return x;
}
