//program to calculate the k-th  root of x with your accuracy

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>


int main(){

    do {
        int check = 1;
        float delta = 1;
        float y = 1;
        float epsilon, x, k, check_mod; // the k-th  root of x

        printf ("This root calculator will help you to find the k-th  root of x with your accuracy\n"
                "\nPress ESCAPE to exit after finishing of our program or enter to continue.\n"
                "Please, don`t use coma(','), use only dots.\n");
    //the k-th checking
        do {
            printf ("\n Input k(it should be greater than 0.1 or less than -0.1)): ");
            check = scanf ("%f",&k);
            fflush (stdin);

            if (check != 1) {
                printf("\nPlease, enter a number one more time.\nIf you write symbols after numbers, we use numbers written before symbols.\n");
                continue;

            } else if (k == 0) {
                printf ("The k-th root shouldn`t be equal ZERO.");
                continue;
        }
        } while (check != 1 || k == 0 || (k < 1e-1 && k > -1e-1));


    //the x checking
        do {
            printf ("\n Input x (it should be greater than 0.0001 or less than -0.0001): ");
            check = scanf ("%f",&x);
            fflush (stdin);

            if (check != 1) {
                printf("\nPlease, enter a number one more time.\nIf you write symbols after numbers, we use numbers written before symbols.\n");
                continue;
            }

            if ((k > 0 && (fmodf(k,2)==0) && x < 0) || (k<0 && fmodf(k,2)==0 && x <= 0) || (k<0 && (fmodf(k,2) !=0) && x==0)){
                printf ("Please, enter other numbers");
                continue;
            }

        } while (check != 1 || ((k > 0 && (fmodf(k,2)==0) && x < 0) || (k<0 && fmodf(k,2)==0 && x <= 0) || (k<0 && (fmodf(k,2) !=0) && x==0)) || (x <= 1e-4 && x >= -1e-4));


    //epsilon checking
        do {
            printf ("\n Input accuracy (it should be greater than 0.0001 or less than 1): ");
            check = scanf ("%f",&epsilon);
            fflush (stdin);

            if (check != 1) {
                printf("\nPlease, enter a number one more time.\nIf you write symbols after numbers, we use numbers written before symbols.\n");
                continue;
            }
        } while (check != 1 || (epsilon <= 1e-4 || epsilon >=1));

        check_mod = fmodf(k,2);

        if (((check_mod == 0) || (check_mod != 0))&& k > 0){

            while (fabsf(delta) >= epsilon){
                delta = ((x/(powf(y,k-1))-y)/k);
                y = y + delta;
        //printf ("\nk = %f,  x= %f, y = %f, delta=%f\n\n", k, x, y, delta);

            }
        } else if (((check_mod == 0) || (check_mod != 0))&& k < 0) {
            while (fabsf(delta) >= epsilon){
                k = fabsf(k);
                delta = ((x/(powf(y,k-1))-y)/k);
                y = y + delta;
                //printf ("\nk = %f,  x= %f, y = %f, delta=%f\n\n", k, x, y, delta);

            }
            y = 1/y;
        }
        printf ("\nThe result is %f\n\n", y);

    } while (getch() != 27);
    return 0;
}

