#include <stdio.h>
#include <conio.h>

int main() {
    int day, date, month, year, pr1, leapy;
 	printf("Enter your date and our program will show the weekday.\n");
    do{
        do {
            printf ("Enter your date(dd mm yyyy), this year should be greater than 1900 and less than 2099: ");
            pr1 = scanf("%2d %2d %d", &date, &month, &year);

            if ((year%100 == 0 && year%400 == 0) || (year%100 != 0 && year%4 == 0)) leapy = 1;
            else leapy = 0;

            if  ((pr1 != 3) || (date < 1 || date >31)
                || (month < 1 || month > 12)
                || (year < 1 || year < 1900 || year > 2099)
                || (leapy == 1 && month == 2 && date > 29)
                || (month != 1 && month != 3 && month != 5 && month != 7 && month != 8 && month != 10 && month != 12 && date>30)
                || (leapy == 0 && month == 2 && date > 28)) {

                printf ("Please, write correct date. \n");
                fflush(stdin);

            } else {


                int n;
                if (month > 2) n = 0;
                else if (leapy == 1 && month <= 2) n = 1;
                else n = 2;

                day = (((int)(365.25*year) + (int)(30.56*month) + date + n) % 7);

                switch(day) {
                case 0:
                    printf("Monday \n");
                    break;
                case 1:
                    printf("Tuesday \n");
                    break;
                case 2:
                    printf("Wednesday \n");
                    break;
                case 3:
                    printf("Thursday \n");
                    break;
                case 4:
                    printf("Friday \n");
                    break;
                case 5:
                    printf("Saturday \n");
                    break;
                case 6:
                    printf("Sunday \n");
                    break;
                }
            }
        } while (pr1 != 3);


    } while(getch() != 27);
    return 0;
}
