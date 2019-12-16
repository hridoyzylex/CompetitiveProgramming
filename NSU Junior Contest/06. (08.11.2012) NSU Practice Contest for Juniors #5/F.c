#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year,month,day,w,c,a;
    char *weekday[]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};

    scanf("%d%d%d",&year,&month,&day);

    a = (14-month)/12;
    year = year - a;
    month = month+12 * a-2;
    c = year/100;
    year = year%100;
    w =(c/4-2*c+year+year/4+((13*month-1)/5)+day)%7;

    printf("%s",weekday[w]);
}
