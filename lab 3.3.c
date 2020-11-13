#include "stdio.h"
#include "math.h"
#include "conio.h"

float getNumber(float);
int checkX;

int main() {
    do{
        double  a, b, c;
        float x1, x2, x3, y1, y2, y3, y, p, q, d, u, v, r, fi;
        float const pi = 3.14159265;
        printf ("This cubic equation calculator will help you to find roots of ax^3 + bx^2 + cx + d = 0 \n"
                "Enter values for a, b, c, d and solutions for x will be calculated. \n"
                "Press ESCAPE to exit after finishing of our program or any key to continue.\n"
                "Please, don`t use coma(','), use only dots.\n");

        printf ("\nEnter a: ");
        getNumber(a);

        printf ("\nEnter b: ");
        getNumber(b);

        printf ("\nEnter c: ");
        getNumber(c);

        printf ("\nEnter d: ");
        getNumber(d);

        //y*y*y + p*y + q = 0;
        p = b - (a*a)/3;
        q = (2*a*a*a)/27 - (a*b)/3 + c;
        d = (p*p*p)/27 + (q*q)/4;
        if (d > 0) {

                u = pow( (-q/2 + sqrt(d)), 1./3. );
                v = -p/(3*u);

                y1 = u+v ;
                y2 = y3 =(-(u+v))/2;
                y = (sqrt(2)*(u-v))/2;

                printf("\nx1=%.3f\n",y1-a/3);
                printf("x2=%.3f+i*%.3f\n", y2-a, y);
                printf("x3=%.3f-i*%.3f\n", y3-a, y);

        } else if (d == 0) {
                y1 = 3*q/p;
                y2 = y3 = (-3*q)/(2*p);

                printf("\nx1=%.3f\n",y1-a/3);
                printf("x2=%.3f\n",y2-a/3);
                printf("x3=%.3f\n",y3-a/3);
        } else {
                r = sqrt((-p*p*p)/27);
                fi = acos (-q/(r*2));

                y1 = 2*fabs(pow(r, 1./3.))*cos(fi/3);
                y2 = 2*fabs(pow(r, 1./3.))*cos((fi+2*pi)/3);
                y = 2*fabs(pow(r, 1./3.))*cos((fi+4*pi)/3);

                printf("\nx1=%.3f\n",y1-a/3);
                printf("x2=%.3f\n",y2-a/3);
                printf("x3=%.3f\n",y3-a/3);
        }

    } while (getch() != 27);
return 0;
}

float getNumber(float x){
    do {
        checkX = scanf ("%lf",&x);

        if (checkX != 1) {
            printf("\nPlease, enter a number one more time.\nIf you write symbols after numbers, we use numbers written before symbols.\n");
            fflush (stdin);
        }
    } while (checkX != 1);
    return x;
}

