#include<stdio.h>

#define TRUE	1
#define FALSE   0

int monthDays[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *m[]=
{
	" ",
	"JANUARY",
	"FEBUARY",
	"MARCH",
	"APRIL",
	"MAY",
	"JUNE",
	"JULY",
	"AUGUST",
	"SEPTEMBER",
	"OCTOBER",
	"NOVEMBER",
	"DECEMBER"
};




int daycode(int year)
{
	int day_code;
	int da1, da2, da3;

	da1 = (year - 1.)/ 4.0;
	da2 = (year - 1.)/ 100.;
	da3 = (year - 1.)/ 400.;
	day_code = (year + da1 - da2 + da3) %7;
	return day_code;
}




void calendar(int year, int day_code)
{
	int month, d;
	for ( month=1;month<=12;month++ )
	{printf("\n\n");
    	printf("%s", m[month]);

    	printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );


    	for (d=1;d<=1+day_code*5;d++)
    	{
        	printf(" ");
    	}

    	for (d=1;d<=monthDays[month]; d++ )
    	{
        	printf("%2d", d );


        	if ( ( d + day_code ) % 7 > 0 )
            	printf("   " );
        	else
            	printf("\n" );
    	}

        	day_code = ( day_code + monthDays[month] ) % 7;
        	printf("\n\n");
	}

}
int leap(int year)
{
	if(year% 4==FALSE&&year%100!=FALSE||year%400==FALSE)
	{

    	monthDays[2]=29;
    	return TRUE;
	}
	else
	{
    	monthDays[2]=28;
    	return FALSE;
	}
}

int main(void)
{
	int year, day_code, leap_year;

	printf("Please enter a year : ");
	scanf("%d", &year);

	printf("");

day_code =daycode(year);

	leap(year);

	calendar(year, day_code);

	printf("\n");
}
