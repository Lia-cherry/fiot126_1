//program to calculate the k-th  root of x with your accuracy

#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(){
    int check_K, check_X, check_E;
    float delta = 1;
    float y1 = 1;
    float epsilon, x, k, y; // the k-th  root of x
    do {
        printf ("This root calculator will help you to find the k-th  root of x with your accuracy\n"
                "\nPress ESCAPE to exit after finishing of our program or any key to continue.\n"
                "Please, don`t use coma(','), use only dots.\n");
    //the k-th checking
        do {
            printf ("\nEnter k: ");
            check_K = scanf ("%f",&k);

            if (check_K != 1) {
                printf("\nPlease, enter a number one more time.\nIf you write symbols after numbers, we use numbers written before symbols.\n");
                fflush (stdin);
            } else if (k == 0) {
            printf ("The k-th root shouldn`t be equal ZERO.");
        }
        } while (check_K != 1 || k == 0);


    //the x checking
        do {
            printf ("\nEnter x: ");
            check_X = scanf ("%f",&x);

            if (check_X != 1) {
                printf("\nPlease, enter a number one more time.\nIf you write symbols after numbers, we use numbers written before symbols.\n");
                fflush (stdin);
            /*} else if ((k > 0 && k%2.0==0 && x < 0) || (k<0 && k%2.0==0 && x <= 0) || (k<0 && k%2.0==1 && x==0)){
            printf ("Please, enter other numbers"); */
        }
        } while (check_X != 1);


    //epsilon checking
        do {
            printf ("\nEnter accuracy: ");
            check_E = scanf ("%f",&epsilon);

            if (check_E != 1) {
                printf("\nPlease, enter a number one more time.\nIf you write symbols after numbers, we use numbers written before symbols.\n");
                fflush (stdin);
            }
        } while (check_E != 1);

        do {
            delta = ((x/(pow(y1,k-1))-y1)/k);
            y = y1 + delta;
        } while (fabs(delta) < epsilon);

        printf ("\nThe %f-th root of %f = %f\n\n", k, x, y);


    } while (getch() != 27);
    return 0;
}



